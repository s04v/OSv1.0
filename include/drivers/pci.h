#ifndef _PCI_
#define _PCI_

#include <types.h>

struct __pci_driver;

typedef struct {
	u32 vendor;
	u32 device;
	u32 func;
	struct __pci_driver *driver;
} pci_device;

typedef struct {
	u32 vendor;
	u32 device;
	u32 func;
} pci_device_id;

typedef struct __pci_driver {
	pci_device_id *table;
	char *name;
	u8 (*init_one)(pci_device *);
	u8 (*init_driver)(void);
	u8 (*exit_driver)(void);
} pci_driver;

extern void pci_init();
extern void pci_proc_dump(u8 *buffer);

#endif