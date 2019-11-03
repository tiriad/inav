/*
 * This file is part of INAV Project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * Alternatively, the contents of this file may be used under the terms
 * of the GNU General Public License Version 3, as described below:
 *
 * This file is free software: you may copy, redistribute and/or modify
 * it under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or (at your
 * option) any later version.
 *
 * This file is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
 * Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see http://www.gnu.org/licenses/.
 */

#pragma once

#include "config/parameter_group.h"
#include "common/time.h"

typedef struct rpmFilterConfig_s {
    uint8_t gyro_filter_enabled;
    uint8_t dterm_filter_enabled;

    uint8_t  gyro_harmonics;
    uint8_t  gyro_min_hz;
    uint16_t gyro_q;

    uint8_t  dterm_harmonics;
    uint8_t  dterm_min_hz;
    uint16_t dterm_q;

} rpmFilterConfig_t;

PG_DECLARE(rpmFilterConfig_t, rpmFilterConfig);

#define RPM_FILTER_UPDATE_RATE_HZ 300
#define RPM_FILTER_UPDATE_RATE_US (1000000.0f / RPM_FILTER_UPDATE_RATE_HZ)

void rpmFiltersInit(void);
void rpmFilterUpdateTask(timeUs_t currentTimeUs);
float rpmFilterGyroApply(uint8_t axis, float input);