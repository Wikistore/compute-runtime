#
# Copyright (C) 2020 Intel Corporation
#
# SPDX-License-Identifier: MIT
#

set(L0_SRCS_TOOLS_SYSMAN_RAS
    ${CMAKE_CURRENT_SOURCE_DIR}/ras.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ras.h
    ${CMAKE_CURRENT_SOURCE_DIR}${BRANCH_DIR_SUFFIX}/ras_imp.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ras_imp.h
    ${CMAKE_CURRENT_SOURCE_DIR}/os_ras.h
)


target_sources(${L0_STATIC_LIB_NAME}
    PRIVATE
    ${L0_SRCS_TOOLS_SYSMAN_RAS}
    ${CMAKE_CURRENT_SOURCE_DIR}/CMakeLists.txt
)

add_subdirectories()

# Make our source files visible to parent
set_property(GLOBAL PROPERTY L0_SRCS_TOOLS_SYSMAN_RAS ${L0_SRCS_TOOLS_SYSMAN_RAS})
