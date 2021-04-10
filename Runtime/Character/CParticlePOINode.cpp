#include "Runtime/Character/CParticlePOINode.hpp"

#include "Runtime/Character/CAnimSourceReader.hpp"

namespace metaforce {

CParticlePOINode::CParticlePOINode() : CPOINode("root", EPOIType::Particle, CCharAnimTime(), -1, false, 1.f, -1, 0) {}

CParticlePOINode::CParticlePOINode(CInputStream& in) : CPOINode(in), x38_data(in) {}

CParticlePOINode CParticlePOINode::CopyNodeMinusStartTime(const CParticlePOINode& node,
                                                          const CCharAnimTime& startTime) {
  CParticlePOINode ret = node;
  ret.x1c_time -= startTime;
  return ret;
}

} // namespace metaforce
