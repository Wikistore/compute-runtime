/*
 * Copyright (C) 2018-2020 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 */

#include "opencl/test/unit_test/ult_config_listener.h"

#include "execution_environment/execution_environment.h"
#include "memory_manager/memory_manager.h"
#include "unit_tests/helpers/default_hw_info.h"
#include "unit_tests/helpers/ult_hw_config.h"
#include "opencl/source/platform/platform.h"

void NEO::UltConfigListener::OnTestStart(const ::testing::TestInfo &testInfo) {
    referencedHwInfo = *platformDevices[0];
    auto executionEnvironment = constructPlatform()->peekExecutionEnvironment();
    executionEnvironment->prepareRootDeviceEnvironments(1);
    executionEnvironment->setHwInfo(*platformDevices);
    executionEnvironment->calculateMaxOsContextCount();
    executionEnvironment->initGmm();
}
void NEO::UltConfigListener::OnTestEnd(const ::testing::TestInfo &testInfo) {
    // Clear global platform that it shouldn't be reused between tests
    platformsImpl.clear();
    MemoryManager::maxOsContextCount = 0u;

    // Ensure that global state is restored
    UltHwConfig expectedState{};
    static_assert(sizeof(UltHwConfig) == 7 * sizeof(bool), ""); // Ensure that there is no internal padding
    EXPECT_EQ(0, memcmp(&expectedState, &ultHwConfig, sizeof(UltHwConfig)));
    EXPECT_EQ(0, memcmp(&referencedHwInfo, platformDevices[0], sizeof(HardwareInfo)));
}