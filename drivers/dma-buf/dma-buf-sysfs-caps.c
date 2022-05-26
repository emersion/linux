// SPDX-License-Identifier: GPL-2.0-only
/*
 * DMA-BUF sysfs capabilities.
 *
 * Copyright (C) 2022 Simon Ser
 */

#include <linux/kobject.h>
#include <linux/sysfs.h>

#include "dma-buf-sysfs-caps.h"

static ssize_t sync_file_import_export_show(struct kobject *kobj,
					    struct kobj_attribute *attr,
					    char *buf)
{
	return sysfs_emit(buf, "1\n");
}

static struct kobj_attribute dma_buf_sync_file_import_export_attr =
	__ATTR_RO(sync_file_import_export);

static struct attribute *dma_buf_caps_attrs[] = {
	&dma_buf_sync_file_import_export_attr.attr,
	NULL,
};

const struct attribute_group dma_buf_caps_group = {
	.name = "caps",
	.attrs = dma_buf_caps_attrs,
};
