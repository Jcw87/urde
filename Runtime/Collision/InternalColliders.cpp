#include "Runtime/Collision/InternalColliders.hpp"

#include "Runtime/Collision/CCollidableAABox.hpp"
#include "Runtime/Collision/CCollidableCollisionSurface.hpp"
#include "Runtime/Collision/CCollidableSphere.hpp"

namespace metaforce::InternalColliders {
void AddTypes() {
  CCollisionPrimitive::InitAddType(CCollidableAABox::GetType());
  CCollisionPrimitive::InitAddType(CCollidableCollisionSurface::GetType());
  CCollisionPrimitive::InitAddType(CCollidableSphere::GetType());
}

void AddColliders() {
  CCollisionPrimitive::InitAddCollider(Collide::AABox_AABox, "CCollidableAABox", "CCollidableAABox");
  CCollisionPrimitive::InitAddCollider(Collide::Sphere_AABox, "CCollidableSphere", "CCollidableAABox");
  CCollisionPrimitive::InitAddCollider(Collide::Sphere_Sphere, "CCollidableSphere", "CCollidableSphere");
  CCollisionPrimitive::InitAddBooleanCollider(Collide::AABox_AABox_Bool, "CCollidableAABox", "CCollidableAABox");
  CCollisionPrimitive::InitAddBooleanCollider(Collide::Sphere_AABox_Bool, "CCollidableSphere", "CCollidableAABox");
  CCollisionPrimitive::InitAddBooleanCollider(Collide::Sphere_Sphere_Bool, "CCollidableSphere", "CCollidableSphere");
  CCollisionPrimitive::InitAddMovingCollider(CCollidableAABox::CollideMovingAABox, "CCollidableAABox",
                                             "CCollidableAABox");
  CCollisionPrimitive::InitAddMovingCollider(CCollidableAABox::CollideMovingSphere, "CCollidableAABox",
                                             "CCollidableSphere");
  CCollisionPrimitive::InitAddMovingCollider(CCollidableSphere::CollideMovingAABox, "CCollidableSphere",
                                             "CCollidableAABox");
  CCollisionPrimitive::InitAddMovingCollider(CCollidableSphere::CollideMovingSphere, "CCollidableSphere",
                                             "CCollidableSphere");
}
} // namespace metaforce::InternalColliders
