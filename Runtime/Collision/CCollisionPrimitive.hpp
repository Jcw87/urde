#ifndef __URDE_CCOLLISIONPRIMITIVE_HPP__
#define __URDE_CCOLLISIONPRIMITIVE_HPP__

#include "Collision/CMaterialList.hpp"
#include "CRayCastResult.hpp"
#include "zeus/CAABox.hpp"

#include <functional>

namespace urde
{

class COBBTree;
class CInternalRayCastStructure;
class CMaterialFilter;
class CCollisionPrimitive
{
    CMaterialList x8_material;
public:
    class Type
    {
        std::function<void(u32)> x0_setter;
        const char* x4_info;
    public:
        Type() = default;
        Type(std::function<void(unsigned int)> setter, const char * info)
            : x0_setter(setter),
              x4_info(info)
        {
        }

        const char* GetInfo() const
        {
            return x4_info;
        }

        std::function<void(u32)> GetSetter() const
        {
            return x0_setter;
        }
    };

    CCollisionPrimitive()=default;
    CCollisionPrimitive(const CMaterialList& list);
    virtual u32 GetTableIndex() const=0;
    virtual void SetMaterial(const CMaterialList&);
    virtual const CMaterialList& GetMaterial() const;
    virtual zeus::CAABox CalculateAABox(const zeus::CTransform&) const=0;
    virtual zeus::CAABox CalculateLocalAABox() const=0;
    virtual FourCC GetPrimType() const=0;
    virtual ~CCollisionPrimitive() {}
    virtual CRayCastResult CastRayInternal(const CInternalRayCastStructure&) const=0;
    CRayCastResult CastRay(const zeus::CVector3f&, const zeus::CVector3f&, float, const CMaterialFilter&,
                           const zeus::CTransform&) const;


    static void InitBeginTypes();
    static void InitAddType(const Type& tp);
    static void InitEndTypes();

    static void InitBeginColliders();
    static void InitAddCollider(const Type& tp);
};

}

#endif // __URDE_CCOLLISIONPRIMITIVE_HPP__