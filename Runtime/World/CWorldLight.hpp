#pragma once

#include "Runtime/Graphics/CLight.hpp"
#include <zeus/CVector3f.hpp>

namespace metaforce {
class CWorldLight {
public:
  enum class EWorldLightType {
    LocalAmbient,
    Directional,
    Custom,
    Spot,
    Spot2,
    LocalAmbient2,
  };

private:
  EWorldLightType x0_type = EWorldLightType::Spot2;
  zeus::CVector3f x4_color;
  zeus::CVector3f x10_position;
  zeus::CVector3f x1c_direction;
  float x28_q = 0.f;
  float x2c_cutoffAngle = 0.f;
  float x30_ = 0.f;
  bool x34_castShadows = false;
  float x38_ = 0.f;
  EFalloffType x3c_falloff = EFalloffType::Linear;
  float x40_ = 0.f;

public:
  explicit CWorldLight(CInputStream& in);

  CWorldLight(const CWorldLight&) = default;
  CWorldLight& operator=(const CWorldLight&) = default;

  CWorldLight(CWorldLight&&) = default;
  CWorldLight& operator=(CWorldLight&&) = default;

  EWorldLightType GetLightType() const { return x0_type; }
  const zeus::CVector3f& GetDirection() const { return x1c_direction; }
  const zeus::CVector3f& GetPosition() const { return x10_position; }
  bool DoesCastShadows() const { return x34_castShadows; }

  CLight GetAsCGraphicsLight() const;
};

} // namespace metaforce
