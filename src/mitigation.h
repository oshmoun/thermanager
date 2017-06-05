#ifndef _MITIGATION_H_
#define _MITIGATION_H_

#include "list.h"

struct mitigation {
	struct list resources;
	struct list fallback_resources;
	int level;
	struct list_node list_node;
};

struct mitigation *mitigation_create(int level);
void mitigation_destroy(struct mitigation *m);

void mitigation_add_resource(struct mitigation *m,
		const char *name, const char *target_value, const char *fallback);
void mitigation_activate(struct mitigation *m);
void mitigation_deactivate(struct mitigation *m);

#endif
