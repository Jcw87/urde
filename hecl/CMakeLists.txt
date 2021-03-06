if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
cmake_minimum_required(VERSION 3.10 FATAL_ERROR) # because of c++17
project(hecl)

if(MSVC)
  add_compile_options(
    # Disable exceptions
    $<$<COMPILE_LANGUAGE:CXX>:/EHsc>
    /wd4267 /wd4244
  )
  add_compile_definitions(UNICODE=1 _UNICODE=1 _CRT_SECURE_NO_WARNINGS=1)
else()
  set(CMAKE_CXX_STANDARD 20)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
  add_compile_options(
    # Disable exceptions
    $<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>
    -Wno-multichar
  )
endif()
endif()

include(ApplicationTools.cmake)

configure_file(DataSpecRegistry.hpp.in ${CMAKE_CURRENT_BINARY_DIR}/DataSpecRegistry.hpp @ONLY)

unset(HECL_APPLICATION_REPS_INCLUDES_LOCAL)
foreach(theHeader ${HECL_APPLICATION_REPS_INCLUDES_LIST})
  set(HECL_APPLICATION_REPS_INCLUDES_LOCAL "${HECL_APPLICATION_REPS_INCLUDES_LOCAL}#include \"${theHeader}\"\n")
endforeach()
unset(HECL_APPLICATION_PIPELINE_REPS_UNIVERSAL_LOCAL)
foreach(name ${HECL_APPLICATION_PIPELINE_REPS_UNIVERSAL})
  set(HECL_APPLICATION_PIPELINE_REPS_UNIVERSAL_LOCAL "${HECL_APPLICATION_PIPELINE_REPS_UNIVERSAL_LOCAL}UNIVERSAL_PIPELINES_${name} \\\n")
endforeach()
unset(HECL_APPLICATION_PIPELINE_REPS_OPENGL_LOCAL)
unset(HECL_APPLICATION_PIPELINE_REPS_VULKAN_LOCAL)
unset(HECL_APPLICATION_PIPELINE_REPS_D3D11_LOCAL)
unset(HECL_APPLICATION_PIPELINE_REPS_METAL_LOCAL)
unset(HECL_APPLICATION_PIPELINE_REPS_NX_LOCAL)
foreach(name ${HECL_APPLICATION_PIPELINE_REPS})
  set(HECL_APPLICATION_PIPELINE_REPS_OPENGL_LOCAL "${HECL_APPLICATION_PIPELINE_REPS_OPENGL_LOCAL}OPENGL_PIPELINES_${name} \\\n")
  set(HECL_APPLICATION_PIPELINE_REPS_VULKAN_LOCAL "${HECL_APPLICATION_PIPELINE_REPS_VULKAN_LOCAL}VULKAN_PIPELINES_${name} \\\n")
  set(HECL_APPLICATION_PIPELINE_REPS_D3D11_LOCAL "${HECL_APPLICATION_PIPELINE_REPS_D3D11_LOCAL}D3D11_PIPELINES_${name} \\\n")
  set(HECL_APPLICATION_PIPELINE_REPS_METAL_LOCAL "${HECL_APPLICATION_PIPELINE_REPS_METAL_LOCAL}METAL_PIPELINES_${name} \\\n")
  set(HECL_APPLICATION_PIPELINE_REPS_NX_LOCAL "${HECL_APPLICATION_PIPELINE_REPS_NX_LOCAL}NX_PIPELINES_${name} \\\n")
endforeach()

unset(HECL_APPLICATION_STAGE_REPS_LOCAL)
foreach(name ${HECL_APPLICATION_STAGE_REPS})
  set(HECL_APPLICATION_STAGE_REPS_LOCAL "${HECL_APPLICATION_STAGE_REPS_LOCAL}STAGES_${name}(P, S) \\\n")
endforeach()

configure_file(include/hecl/ApplicationReps.hpp.in ${CMAKE_CURRENT_BINARY_DIR}/ApplicationReps.hpp @ONLY)

add_subdirectory(bintoc)

if(NOT TARGET bintoc)
  # Use native if cross compiling
  find_package(hecl-bintoc REQUIRED)
endif()

if(NOT TARGET atdna)
  # Import native atdna if cross-compiling
  find_package(atdna REQUIRED)
  if(NOT TARGET atdna)
    message(FATAL_ERROR "atdna required for building hecl; please verify LLVM installation")
  endif()
endif()

add_subdirectory(lib)
add_subdirectory(blender)
add_subdirectory(driver)
install(DIRECTORY include/hecl DESTINATION include/hecl)
