#pragma once

#include <cstddef>
#include <memory>
#include <string>
#include <utility>

#include "specter/Control.hpp"

#include <boo/IWindow.hpp>

namespace specter {
class TextView;
class ViewResources;

class TextField : public ITextInputView {
  bool m_hasTextSet = false;
  bool m_hasMarkSet = false;
  std::string m_textStr;
  std::string m_deferredTextStr;
  std::string m_deferredMarkStr;
  std::unique_ptr<TextView> m_text;
  std::unique_ptr<TextView> m_errText;

  SolidShaderVert m_verts[41];
  VertexBufferBindingSolid m_vertsBinding;

  int m_nomWidth = 0;
  int m_nomHeight = 0;

  bool m_hasSelectionClear = false;
  bool m_hasSelectionSet = false;
  bool m_hasCursorSet = false;
  size_t m_selectionStart = 0;
  size_t m_deferredSelectionStart = 0;
  size_t m_selectionCount = 0;
  size_t m_deferredSelectionCount = 0;

  size_t m_markReplStart = 0;
  size_t m_deferredMarkReplStart = 0;
  size_t m_markReplCount = 0;
  size_t m_deferredMarkReplCount = 0;

  size_t m_markSelStart = 0;
  size_t m_deferredMarkSelStart = 0;
  size_t m_markSelCount = 0;
  size_t m_deferredMarkSelCount = 0;

  size_t m_cursorPos = 0;
  size_t m_deferredCursorPos = SIZE_MAX;
  size_t m_cursorFrames = 0;
  size_t m_clickFrames = 15;
  size_t m_clickFrames2 = 15;
  size_t m_errorFrames = 360;

  size_t m_dragStart = 0;
  size_t m_dragging = 0;

  bool m_active = false;
  bool m_error = false;

  enum class BGState { Inactive, Hover, Disabled } m_bgState = BGState::Inactive;
  void setInactive();
  void setHover();
  void setDisabled();
  void refreshBg();

public:
  TextField(ViewResources& res, View& parentView, IStringBinding* strBind);
  ~TextField() override;

  std::string_view getText() const { return m_textStr; }
  void setText(std::string_view str);

  void clipboardCopy() override;
  void clipboardCut() override;
  void clipboardPaste() override;

  void mouseDown(const boo::SWindowCoord&, boo::EMouseButton, boo::EModifierKey) override;
  void mouseUp(const boo::SWindowCoord&, boo::EMouseButton, boo::EModifierKey) override;
  void mouseMove(const boo::SWindowCoord&) override;
  void mouseEnter(const boo::SWindowCoord&) override;
  void mouseLeave(const boo::SWindowCoord&) override;
  void specialKeyDown(boo::ESpecialKey, boo::EModifierKey, bool) override;

  bool hasMarkedText() const override;
  std::pair<int, int> markedRange() const override;
  std::pair<int, int> selectedRange() const override;
  void setMarkedText(std::string_view str, const std::pair<int, int>& selectedRange,
                     const std::pair<int, int>& replacementRange) override;
  void unmarkText() override;

  std::string substringForRange(const std::pair<int, int>& range, std::pair<int, int>& actualRange) const override;
  void insertText(std::string_view str, const std::pair<int, int>& range) override;
  int characterIndexAtPoint(const boo::SWindowCoord& point) const override;
  boo::SWindowRect rectForCharacterRange(const std::pair<int, int>& range,
                                         std::pair<int, int>& actualRange) const override;

  void think() override;
  void resized(const boo::SWindowRect& rootView, const boo::SWindowRect& sub) override;
  void draw(boo::IGraphicsCommandQueue* gfxQ) override;

  int nominalWidth() const override { return m_nomWidth; }
  int nominalHeight() const override { return m_nomHeight; }

  void setActive(bool active) override;
  void setCursorPos(size_t pos);
  void setErrorState(std::string_view message);
  void clearErrorState();

  void setSelectionRange(size_t start, size_t count);
  void clearSelectionRange();

  void setMultiplyColor(const zeus::CColor& color) override;

private:
  void _setCursorPos();
  void _reallySetCursorPos(size_t pos);
  void _setSelectionRange();
  void _reallySetSelectionRange(size_t start, size_t len);
  void _reallySetMarkRange(size_t start, size_t len);
  void _clearSelectionRange();
  void _setText();
  void _setMarkedText();
};

} // namespace specter
