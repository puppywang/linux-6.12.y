/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright 2022, The Chromium OS Authors. All rights reserved.
 *
 * Mainline only ships rockchip_pmu_block()/unblock(); the BSP MPP driver
 * also expects per-device PD on/off, idle-request, QoS save/restore and a
 * debug dump helper. Those have no mainline implementation, so they are
 * always stubbed here regardless of CONFIG_ROCKCHIP_PM_DOMAINS — MPP
 * tolerates -ENOTSUPP from them and falls back to genpd auto power-up
 * via the standard runtime PM path.
 */
#ifndef __SOC_ROCKCHIP_PM_DOMAINS_H__
#define __SOC_ROCKCHIP_PM_DOMAINS_H__

#include <linux/errno.h>

struct device;

#if IS_REACHABLE(CONFIG_ROCKCHIP_PM_DOMAINS)
int rockchip_pmu_block(void);
void rockchip_pmu_unblock(void);
#else
static inline int rockchip_pmu_block(void) { return 0; }
static inline void rockchip_pmu_unblock(void) { }
#endif

/* BSP-only helpers — always stubbed on mainline. */
static inline int rockchip_pmu_pd_on(struct device *dev) { return -ENOTSUPP; }
static inline int rockchip_pmu_pd_off(struct device *dev) { return -ENOTSUPP; }
static inline bool rockchip_pmu_pd_is_on(struct device *dev) { return true; }
static inline int rockchip_pmu_idle_request(struct device *dev, bool idle) { return -ENOTSUPP; }
static inline int rockchip_save_qos(struct device *dev) { return -ENOTSUPP; }
static inline int rockchip_restore_qos(struct device *dev) { return -ENOTSUPP; }
static inline void rockchip_dump_pmu(void) { }

#endif
