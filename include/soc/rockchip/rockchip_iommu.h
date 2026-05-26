/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Stub helpers used by the Rockchip MPP driver on mainline kernels.
 *
 * The Rockchip BSP rockchip-iommu driver exports extra control helpers
 * (enable/disable/mask_irq/force_reset) that mainline's drivers/iommu
 * /rockchip-iommu.c does not. MPP calls into these during init but
 * tolerates -ENODEV failures, falling back to the standard iommu_*
 * APIs for the actual mapping. Providing always-stubbed inlines keeps
 * MPP buildable against mainline.
 */
#ifndef __SOC_ROCKCHIP_IOMMU_H
#define __SOC_ROCKCHIP_IOMMU_H

#include <linux/errno.h>
#include <linux/types.h>

struct device;

static inline int rockchip_iommu_enable(struct device *dev)
{
	return -ENODEV;
}

static inline int rockchip_iommu_disable(struct device *dev)
{
	return -ENODEV;
}

static inline int rockchip_pagefault_done(struct device *master_dev)
{
	return 0;
}

static inline void __iomem *rockchip_get_iommu_base(struct device *dev, int idx)
{
	return NULL;
}

static inline bool rockchip_iommu_is_enabled(struct device *dev)
{
	return false;
}

static inline void rockchip_iommu_mask_irq(struct device *dev) { }
static inline void rockchip_iommu_unmask_irq(struct device *dev) { }

static inline int rockchip_iommu_force_reset(struct device *dev)
{
	return -ENODEV;
}

#endif /* __SOC_ROCKCHIP_IOMMU_H */
