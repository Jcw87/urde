#pragma once
#include "RetroTypes.hpp"
#include "zeus/CVector3f.hpp"
#include "Character/CharacterCommon.hpp"
#include "Weapon/WeaponCommon.hpp"

namespace urde
{
class CPatterned;
class CDamageInfo;

enum class EKnockBackType
{
    Direct,
    Radius
};

enum class EKnockBackVariant
{
    Small,
    Medium,
    Large
};

enum class EKnockBackWeaponType
{
    Invalid = -1,
    Power,
    PowerCharged,
    PowerComboed,
    PowerComboedDirect,
    Wave,
    WaveCharged,
    WaveComboed,
    WaveComboedDirect,
    Ice,
    IceCharged,
    IceComboed,
    IceComboedDirect,
    Plasma,
    PlasmaCharged,
    PlasmaComboed,
    Missile,
    Bomb,
    PowerBomb,
    Phazon
};

enum class EKnockBackCharacterState
{
    Alive,
    Dead,
    FrozenAlive,
    FrozenDead
};

enum class EKnockBackAnimationState
{
    Invalid = -1,
    None,
    Flinch,
    KnockBack,
    Hurled,
    Fall
};

enum class EKnockBackAnimationFollowUp
{
    Invalid = -1,
    None,
    Freeze,
    Shock,
    Burn,
    PhazeOut,
    Death,
    ExplodeDeath,
    IceDeath,
    FireDeath,
    Disintegrate
};

class CKnockBackController
{
public:
    struct KnockBackParms
    {
        EKnockBackAnimationState x0_animState;
        EKnockBackAnimationFollowUp x4_animFollowup;
        float x8_followupMagnitude;
        float xc_;
    };
private:
    friend class CPatterned;
    EKnockBackVariant x0_variant;
    KnockBackParms x4_activeParms;
    EWeaponType x14_deferWeaponType = EWeaponType::None;
    EKnockBackAnimationState x18_minAnimState = EKnockBackAnimationState::None;
    EKnockBackAnimationState x1c_maxAnimState = EKnockBackAnimationState::Fall;
    u32 x20_impulseDurationIdx = 0;
    rstl::reserved_vector<std::pair<float, float>, 4> x24_;
    zeus::CVector3f x50_impulseDir;
    float x5c_impulseMag = 0.f;
    float x60_impulseRemTime = 0.f;
    float x64_flinchRemTime = 0.f;
    float x68_deferRemTime = 0.f;
    u32 x6c_ = 0;
    u32 x70_ = 0;
    u32 x74_ = 0;
    pas::ESeverity x7c_severity = pas::ESeverity::One;
    std::bitset<4> x80_availableStates;
    union
    {
        struct
        {
            bool x81_24_autoResetImpulse : 1; // t
            bool x81_25_enableFreeze : 1; // t
            bool x81_26_enableShock : 1;
            bool x81_27_enableBurn : 1; // t
            bool x81_28_enableFireDeath : 1; // t
            bool x81_29_enableExplodeDeath : 1; // t
            bool x81_30_enableDisintegrate : 1; // t
            bool x81_31_ : 1; // t
            bool x82_24_ : 1; // t
            bool x82_25_inDeferredKnockBack : 1;
            bool x82_26_ : 1;
        };
        u32 dummy = 0;
    };
    void ApplyImpulse(float dt, CPatterned& parent);
    bool TickDeferredTimer(float dt);
    EKnockBackCharacterState GetKnockBackCharacterState(CPatterned& parent);
    void ValidateState(CPatterned& parent);
    float CalculateExtraHurlVelocity(CStateManager& mgr, float magnitude, float kbResistance);
    void DoKnockBackAnimation(const zeus::CVector3f& backVec, CStateManager& mgr, CPatterned& parent, float magnitude);
    void ResetKnockBackImpulse(CPatterned& parent, const zeus::CVector3f& backVec, float magnitude);
    void DoDeferredKnockBack(CStateManager& mgr, CPatterned& parent);
    EKnockBackWeaponType GetKnockBackWeaponType(const CDamageInfo& info, EWeaponType wType, EKnockBackType type);
    void SelectDamageState(CPatterned& parent, const CDamageInfo& info, EWeaponType wType, EKnockBackType type);
public:
    explicit CKnockBackController(EKnockBackVariant variant);
    void SetKnockBackVariant(EKnockBackVariant v) { x0_variant = v; }
    void DeferKnockBack(EWeaponType tp) { x14_deferWeaponType = tp; x68_deferRemTime = 0.05f; }
    void sub80233d40(int i, float f1, float f2);
    void SetAutoResetImpulse(bool b);
    void SetImpulseDurationIdx(u32 i) { x20_impulseDurationIdx = i; }
    void SetAnimationStateRange(EKnockBackAnimationState a, EKnockBackAnimationState b)
    { x18_minAnimState = a; x1c_maxAnimState = b; }
    void Update(float dt, CStateManager& mgr, CPatterned& parent);
    void KnockBack(const zeus::CVector3f& backVec, CStateManager& mgr, CPatterned& parent,
                   const CDamageInfo& info, EKnockBackType type, float magnitude);
    void SetEnableFreeze(bool b) { x81_25_enableFreeze = b; }
    const KnockBackParms& GetActiveParms() const { return x4_activeParms; }
    EKnockBackVariant GetVariant() const { return x0_variant; }
};

}