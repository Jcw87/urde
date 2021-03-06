#pragma once

#include <string_view>

#include "Runtime/GCNTypes.hpp"
#include "Runtime/World/CActor.hpp"

namespace metaforce {

class CScriptCameraWaypoint : public CActor {
  float xe8_hfov;
  u32 xec_;

public:
  CScriptCameraWaypoint(TUniqueId uid, std::string_view name, const CEntityInfo& info, const zeus::CTransform& xf,
                        bool active, float hfov, u32);

  void Accept(IVisitor& visitor) override;
  void AcceptScriptMsg(EScriptObjectMessage, TUniqueId, CStateManager&) override;
  void AddToRenderer(const zeus::CFrustum&, CStateManager&) override {}
  void Render(CStateManager&) override {}
  TUniqueId GetRandomNextWaypointId(CStateManager& mgr) const;
  float GetHFov() const { return xe8_hfov; }
};

} // namespace metaforce
