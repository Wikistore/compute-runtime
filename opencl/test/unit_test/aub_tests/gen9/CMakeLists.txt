#
# Copyright (C) 2018-2020 Intel Corporation
#
# SPDX-License-Identifier: MIT
#

if(TESTS_GEN9)
  target_sources(igdrcl_aub_tests PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/aub_tests_configuration_gen9.cpp
    ${NEO_SOURCE_DIR}/opencl/test/unit_test/gen9/unit_test_helper_gen9.cpp
  )
  add_subdirectories()
endif()
