#pragma once

#include "View.hpp"
#include "boo/graphicsdev/IGraphicsDataFactory.hpp"

#include "FontCache.hpp"

namespace specter {
class ViewResources;

class TextView : public View {
public:
  enum class Alignment { Left, Center, Right };
  struct RenderGlyph {
    zeus::CVector3f m_pos[4];
    zeus::CMatrix4f m_mv;
    zeus::CVector3f m_uv[4];
    zeus::CColor m_color;
    // char _dummy[48];

    RenderGlyph& operator=(const RenderGlyph& other) {
      m_pos[0] = other.m_pos[0];
      m_pos[1] = other.m_pos[1];
      m_pos[2] = other.m_pos[2];
      m_pos[3] = other.m_pos[3];
      m_mv = other.m_mv;
      m_uv[0] = other.m_uv[0];
      m_uv[1] = other.m_uv[1];
      m_uv[2] = other.m_uv[2];
      m_uv[3] = other.m_uv[3];
      m_color = other.m_color;
      return *this;
    }

    RenderGlyph(int& adv, const FontAtlas::Glyph& glyph, const zeus::CColor& defaultColor);
  };
  struct RenderGlyphInfo {
    uint32_t m_char;
    std::pair<int, int> m_dims;
    int m_adv;
    bool m_space = false;

    RenderGlyphInfo(uint32_t ch, int width, int height, int adv)
    : m_char(ch), m_dims(width, height), m_adv(adv), m_space(iswspace(ch) != 0) {}
  };

private:
  size_t m_capacity;
  size_t m_curSize = 0;
  hecl::VertexBufferPool<RenderGlyph>::Token m_glyphBuf;
  boo::ObjToken<boo::IShaderDataBinding> m_shaderBinding;
  const FontAtlas& m_fontAtlas;
  Alignment m_align;
  int m_width = 0;

  friend class MultiLineTextView;
  static int DoKern(FT_Pos val, const FontAtlas& atlas);

  void _commitResources(size_t capacity);

public:
  class Resources {
    friend class ViewResources;
    friend class TextView;
    friend class MultiLineTextView;

    hecl::VertexBufferPool<RenderGlyph> m_glyphPool;

    void updateBuffers() { m_glyphPool.updateBuffers(); }

    FontCache* m_fcache = nullptr;
    boo::ObjToken<boo::IShaderPipeline> m_regular;
    boo::ObjToken<boo::IShaderPipeline> m_subpixel;

    void init(boo::IGraphicsDataFactory::Context& ctx, FontCache* fcache);

    void destroy() {
      m_glyphPool.doDestroy();
      m_regular.reset();
      m_subpixel.reset();
    }
  };

  TextView(ViewResources& res, View& parentView, const FontAtlas& font, Alignment align = Alignment::Left,
           size_t capacity = 256);
  TextView(ViewResources& res, View& parentView, FontTag font, Alignment align = Alignment::Left,
           size_t capacity = 256);

  std::vector<RenderGlyph>& accessGlyphs() { return m_glyphs; }
  const std::vector<RenderGlyph>& accessGlyphs() const { return m_glyphs; }

  void typesetGlyphs(std::string_view str, const zeus::CColor& defaultColor = zeus::skWhite);
  void typesetGlyphs(std::wstring_view str, const zeus::CColor& defaultColor = zeus::skWhite);
  void invalidateGlyphs();

  void colorGlyphs(const zeus::CColor& newColor);
  void colorGlyphsTypeOn(const zeus::CColor& newColor, float startInterval = 0.2, float fadeTime = 0.5);
  void think() override;

  void resized(const boo::SWindowRect& root, const boo::SWindowRect& sub) override;
  void draw(boo::IGraphicsCommandQueue* gfxQ) override;

  int nominalWidth() const override { return m_width; }
  int nominalHeight() const override { return m_fontAtlas.FT_LineHeight() >> 6; }

  std::pair<int, int> queryGlyphDimensions(size_t pos) const;
  size_t reverseSelectGlyph(int x) const;
  int queryReverseAdvance(size_t idx) const;
  std::pair<size_t, size_t> queryWholeWordRange(size_t idx) const;

private:
  std::vector<RenderGlyph> m_glyphs;
  std::vector<RenderGlyphInfo> m_glyphInfo;
};

} // namespace specter
