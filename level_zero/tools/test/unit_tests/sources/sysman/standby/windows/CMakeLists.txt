#
# Copyright (C) 2020 Intel Corporation
#
# SPDX-License-Identifier: MIT
#

if(WIN32)
    target_sources(${TARGET_NAME}
        PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/CMakeLists.txt
            ${CMAKE_CURRENT_SOURCE_DIR}/test_sysman_standby.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/mock_standby.h
    )
endif()
