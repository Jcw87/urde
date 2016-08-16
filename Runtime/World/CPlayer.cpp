#include "CPlayer.hpp"
#include "CActorParameters.hpp"
#include "CMorphBall.hpp"
#include "CPlayerGun.hpp"

namespace urde
{

static CModelData MakePlayerAnimRes(ResId resId, const zeus::CVector3f& scale)
{
    return CAnimRes(resId, 0, scale, 0, true);
}

CPlayer::CPlayer(TUniqueId uid, const zeus::CTransform& xf, const zeus::CAABox& aabb, unsigned int resId,
                 const zeus::CVector3f& playerScale, float f1, float f2, float f3, float f4, const CMaterialList& ml)
: CPhysicsActor(uid, true, "CPlayer", CEntityInfo(kInvalidAreaId, CEntity::NullConnectionList),
                xf, MakePlayerAnimRes(resId, playerScale), ml, aabb, SMoverData(f1), CActorParameters::None(), f2, f3)
{
    x768_morphball.reset(new CMorphBall(*this, f4));
}

bool CPlayer::IsTransparent() const
{
}

void CPlayer::Update(float, CStateManager& mgr)
{
}

bool CPlayer::IsPlayerDeadEnough() const
{
}

void CPlayer::AsyncLoadSuit(CStateManager& mgr)
{
    x490_gun->AsyncLoadSuit(mgr);
}

void CPlayer::LoadAnimationTokens()
{
}

bool CPlayer::CanRenderUnsorted(CStateManager& mgr) const
{
}

const CDamageVulnerability& CPlayer::GetDamageVulnerability(const zeus::CVector3f& v1,
                                                            const zeus::CVector3f& v2,
                                                            const CDamageInfo& info) const
{
}

const CDamageVulnerability& CPlayer::GetDamageVulnerability() const
{
}

zeus::CVector3f CPlayer::GetHomingPosition(CStateManager& mgr, float) const
{
}

zeus::CVector3f CPlayer::GetAimPosition(CStateManager& mgr, float) const
{
}

void CPlayer::FluidFXThink(CActor::EFluidState, CScriptWater& water, CStateManager& mgr)
{
}

zeus::CVector3f CPlayer::GetDamageLocationWR() const
{
}

float CPlayer::GetPrevDamageAmount() const
{
}

float CPlayer::GetDamageAmount() const
{
}

bool CPlayer::WasDamaged() const
{
}

void CPlayer::TakeDamage(bool, const zeus::CVector3f&, float, EWeaponType, CStateManager& mgr)
{
}

void CPlayer::Accept(IVisitor& visitor)
{
}

CHealthInfo& CPlayer::HealthInfo(CStateManager& mgr)
{
}

bool CPlayer::IsUnderBetaMetroidAttack(CStateManager& mgr) const
{
}

rstl::optional_object<zeus::CAABox> CPlayer::GetTouchBounds() const
{
}

void CPlayer::Touch(CActor&, CStateManager& mgr)
{
}

void CPlayer::UpdateScanningState(const CFinalInput& input, CStateManager& mgr, float)
{
}

void CPlayer::ValidateScanning(const CFinalInput& input, CStateManager& mgr)
{
}

void CPlayer::SetScanningState(EPlayerScanState, CStateManager& mgr)
{
}

bool CPlayer::GetExplorationMode() const
{
}

bool CPlayer::GetCombatMode() const
{
}

void CPlayer::RenderGun(CStateManager& mgr, const zeus::CVector3f&) const
{
}

void CPlayer::Render(CStateManager& mgr) const
{
}

void CPlayer::RenderReflectedPlayer(CStateManager& mgr) const
{
}

void CPlayer::PreRender(CStateManager& mgr, const zeus::CFrustum&)
{
}

void CPlayer::CalculateRenderBounds()
{
}

void CPlayer::AddToRenderer(const zeus::CFrustum&, CStateManager&)
{
}

void CPlayer::ComputeFreeLook(const CFinalInput& input)
{
}

void CPlayer::UpdateFreeLook(float dt)
{
}

float CPlayer::GetMaximumPlayerPositiveVerticalVelocity(CStateManager&) const
{
}

void CPlayer::ProcessInput(const CFinalInput&, CStateManager&)
{
}

bool CPlayer::GetFrozenState() const
{
}

void CPlayer::Think(float, CStateManager&)
{
}

void CPlayer::PreThink(float, CStateManager&)
{
}

void CPlayer::AcceptScriptMsg(EScriptObjectMessage, TUniqueId, CStateManager&)
{
}

void CPlayer::SetVisorSteam(float, float, float, u32, bool)
{
}

void CPlayer::UpdateFootstepBounds(const CFinalInput& input, CStateManager&, float)
{
}

u16 CPlayer::GetMaterialSoundUnderPlayer(CStateManager& mgr, const u16*, int, u16)
{
}

u16 CPlayer::SfxIdFromMaterial(const CMaterialList&, const u16*, u16)
{
}

void CPlayer::UpdateCrosshairsState(const CFinalInput&)
{
}

void CPlayer::UpdateVisorTransition(float, CStateManager& mgr)
{
}

void CPlayer::UpdateVisorState(const CFinalInput&, float, CStateManager& mgr)
{
}

void CPlayer::ForceGunOrientation(const zeus::CTransform&, CStateManager& mgr)
{
}

void CPlayer::UpdateDebugCamera(CStateManager& mgr)
{
}

CFirstPersonCamera& CPlayer::GetFirstPersonCamera(CStateManager& mgr)
{
}

void CPlayer::UpdateGunTransform(const zeus::CVector3f&, float, CStateManager& mgr, bool)
{
}

void CPlayer::DrawGun(CStateManager& mgr)
{
}

void CPlayer::HolsterGun(CStateManager& mgr)
{
}

bool CPlayer::GetMorphballTransitionState() const
{
}

void CPlayer::UpdateGrappleArmTransform(const zeus::CVector3f&, CStateManager& mgr, float)
{
}

void CPlayer::ApplyGrappleForces(const CFinalInput& input, CStateManager& mgr, float)
{
}

bool CPlayer::ValidateFPPosition(const zeus::CVector3f& pos, CStateManager& mgr)
{
}

void CPlayer::UpdateGrappleState(const CFinalInput& input, CStateManager& mgr)
{
}

void CPlayer::ApplyGrappleJump(CStateManager& mgr)
{
}

void CPlayer::BeginGrapple(zeus::CVector3f&, CStateManager& mgr)
{
}

void CPlayer::BreakGrapple(CStateManager& mgr)
{
}

void CPlayer::PreventFallingCameraPitch()
{
}

void CPlayer::OrbitCarcass(CStateManager&)
{
}

void CPlayer::OrbitPoint(EPlayerOrbitType, CStateManager& mgr)
{
}

zeus::CVector3f CPlayer::GetHUDOrbitTargetPosition() const
{
}

void CPlayer::SetOrbitState(EPlayerOrbitState, CStateManager& mgr)
{
}

void CPlayer::SetOrbitTargetId(TUniqueId)
{
}

void CPlayer::UpdateOrbitPosition(float, CStateManager& mgr)
{
}

void CPlayer::UpdateOrbitZPosition()
{
}

void CPlayer::UpdateOrbitFixedPosition()
{
}

void CPlayer::SetOrbitPosition(float, CStateManager& mgr)
{
}

void CPlayer::UpdateAimTarget(CStateManager& mgr)
{
}

void CPlayer::UpdateAimTargetTimer(float)
{
}

bool CPlayer::ValidateAimTargetId(TUniqueId, CStateManager& mgr)
{
}

bool CPlayer::ValidateObjectForMode(TUniqueId, CStateManager& mgr) const
{
}

TUniqueId CPlayer::FindAimTargetId(CStateManager& mgr)
{
}

TUniqueId CPlayer::CheckEnemiesAgainstOrbitZone(const std::vector<TUniqueId>&, EPlayerZoneInfo,
                                                EPlayerZoneType, CStateManager& mgr) const
{
}

TUniqueId CPlayer::FindOrbitTargetId(CStateManager& mgr)
{
}

void CPlayer::UpdateOrbitableObjects(CStateManager& mgr)
{
}

TUniqueId CPlayer::FindBestOrbitableObject(const std::vector<TUniqueId>&, EPlayerZoneInfo, CStateManager& mgr) const
{
}

void CPlayer::FindOrbitableObjects(const std::vector<TUniqueId>&, std::vector<TUniqueId>&, EPlayerZoneInfo,
                                   EPlayerZoneType, CStateManager& mgr, bool) const
{
}

bool CPlayer::WithinOrbitScreenBox(const zeus::CVector3f&, EPlayerZoneInfo, EPlayerZoneType) const
{
}

bool CPlayer::WithinOrbitScreenEllipse(const zeus::CVector3f&, EPlayerZoneInfo) const
{
}

void CPlayer::CheckOrbitDisableSourceList(CStateManager& mgr)
{
}

void CPlayer::CheckOrbitDisableSourceList() const
{
}

void CPlayer::RemoveOrbitDisableSource(TUniqueId)
{
}

void CPlayer::AddOrbitDisableSource(CStateManager& mgr, TUniqueId)
{
}

void CPlayer::UpdateOrbitPreventionTimer(float)
{
}

void CPlayer::UpdateOrbitModeTimer(float)
{
}

void CPlayer::UpdateOrbitZone(CStateManager& mgr)
{
}

void CPlayer::UpdateOrbitInput(const CFinalInput& input, CStateManager& mgr)
{
}

void CPlayer::UpdateOrbitSelection(const CFinalInput& input, CStateManager& mgr)
{
}

void CPlayer::UpdateOrbitOrientation(CStateManager& mgr)
{
}

void CPlayer::UpdateOrbitTarget(CStateManager& mgr)
{
}

float CPlayer::GetOrbitMaxLockDistance(CStateManager& mgr) const
{
}

float CPlayer::GetOrbitMaxTargetDistance(CStateManager& mgr) const
{
}

bool CPlayer::ValidateOrbitTargetId(TUniqueId, CStateManager& mgr) const
{
}

bool CPlayer::ValidateCurrentOrbitTargetId(CStateManager& mgr)
{
}

bool CPlayer::ValidateOrbitTargetIdAndPointer(TUniqueId, CStateManager& mgr) const
{
}

zeus::CVector3f CPlayer::GetBallPosition() const
{
}

zeus::CVector3f CPlayer::GetEyePosition() const
{
}

float CPlayer::GetEyeHeight() const
{
}

float CPlayer::GetStepUpHeight() const
{
}

float CPlayer::GetStepDownHeight() const
{
}

void CPlayer::Teleport(const zeus::CTransform& xf, CStateManager& mgr, bool)
{
}

zeus::CTransform CPlayer::CreateTransformFromMovementDirection() const
{
}

const CCollisionPrimitive& CPlayer::GetCollisionPrimitive() const
{
}

zeus::CTransform CPlayer::GetPrimitiveTransform() const
{
}

bool CPlayer::CollidedWith(TUniqueId, const CCollisionInfoList&, CStateManager& mgr)
{
}

float CPlayer::GetActualFirstPersonMaxVelocity() const
{
}

void CPlayer::SetMoveState(EPlayerMovementState, CStateManager& mgr)
{
}

float CPlayer::JumpInput(const CFinalInput& input, CStateManager& mgr)
{
}

float CPlayer::TurnInput(const CFinalInput& input) const
{
}

float CPlayer::StrafeInput(const CFinalInput& input) const
{
}

float CPlayer::ForwardInput(const CFinalInput& input, float) const
{
}

void CPlayer::ComputeMovement(const CFinalInput& input, CStateManager& mgr, float)
{
}

float CPlayer::GetWeight() const
{
}

float CPlayer::GetDampedClampedVelocityWR() const
{
}

}