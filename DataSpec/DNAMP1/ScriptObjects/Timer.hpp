#pragma once

#include "../../DNACommon/DNACommon.hpp"
#include "IScriptObject.hpp"
#include "Parameters.hpp"

namespace DataSpec::DNAMP1 {
struct Timer : IScriptObject {
  AT_DECL_DNA_YAMLV
  String<-1> name;
  Value<float> startTime;
  Value<float> maxRandomAddition;
  Value<bool> resetToZero;
  Value<bool> startImmediately;
  Value<bool> active;
};
} // namespace DataSpec::DNAMP1
