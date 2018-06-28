#ifndef __URDE_CINTERPOLATIONCAMERA_HPP__
#define __URDE_CINTERPOLATIONCAMERA_HPP__

#include "CGameCamera.hpp"

namespace urde
{

class CInterpolationCamera : public CGameCamera
{
    TUniqueId x188_targetId = kInvalidUniqueId;
    float x18c_time = 0.f;
    float x190_maxTime = 0.f;
    zeus::CTransform x194_;
    zeus::CVector3f x1c4_lookPos;
    float x1d0_positionSpeed = 0.f;
    float x1d4_rotationSpeed = 0.f;
    float x1d8_ = 0.f;
    bool x1d8_24_sinusoidal : 1;
    float x1dc_closeInAngle = M_PIF * 2.f;

    bool InterpolateSinusoidal(zeus::CTransform& xf, const zeus::CVector3f& targetOrigin,
                               const zeus::CVector3f& lookPos, float maxTime, float curTime);
    bool InterpolateWithDistance(zeus::CTransform& xf, const zeus::CVector3f& targetOrigin,
                                 const zeus::CVector3f& lookPos, float positionSpeed,
                                 float rotationSpeed, float dt, float maxTime, float curTime);
public:
    CInterpolationCamera(TUniqueId uid, const zeus::CTransform& xf);
    void Accept(IVisitor& visitor);
    void AcceptScriptMsg(EScriptObjectMessage, TUniqueId, CStateManager&);
    void ProcessInput(const CFinalInput&, CStateManager& mgr);
    void Render(const CStateManager&) const;
    void Reset(const zeus::CTransform&, CStateManager& mgr);
    void Think(float, CStateManager &);
    void SetInterpolation(const zeus::CTransform& xf, const zeus::CVector3f& lookPos,
                          float maxTime, float positionSpeed, float rotationSpeed,
                          TUniqueId camId, bool sinusoidal, CStateManager& mgr);
    void DeactivateInterpCamera(CStateManager&);
};

}

#endif // __URDE_CINTERPOLATIONCAMERA_HPP__
