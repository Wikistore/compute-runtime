#
# Copyright (C) 2019-2020 Intel Corporation
#
# SPDX-License-Identifier: MIT
#

set(L0_SRCS_TOOLS_SYSMAN_STANDBY
    ${CMAKE_CURRENT_SOURCE_DIR}/standby.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/standby.h
    ${CMAKE_CURRENT_SOURCE_DIR}/standby_imp.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/standby_imp.h
    ${CMAKE_CURRENT_SOURCE_DIR}/os_standby.h
)

target_sources(${L0_STATIC_LIB_NAME}
    PRIVATE
    ${L0_SRCS_TOOLS_SYSMAN_STANDBY}
        ${CMAKE_CURRENT_SOURCE_DIR}/CMakeLists.txt
)

if(UNIX)
    add_subdirectory(linux)
else()
    add_subdirectory(windows)
endif()

# Make our source files visible to parent
set_property(GLOBAL PROPERTY L0_SRCS_TOOLS_SYSMAN_STANDBY ${L0_SRCS_TOOLS_SYSMAN_STANDBY})