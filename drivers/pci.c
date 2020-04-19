
#include <types.h>
#include <cpu/port.h>
#include <kernel/kprintf.h>
#include <drivers/pci.h>
#include <mm/mm.h>


pci_device **pci_devices = 0;
u32 devs = 0;

pci_driver **pci_drivers = 0;
u32 drivs = 0;


void add_pci_device(pci_device *pdev)
{
	pci_devices[devs] = pdev;
	devs ++;
	return;
}

u16 pci_read_word(u8 bus, u8 slot, u8 func, u8 offset)
{
	u32 address;
    u32 lbus = (u32)bus;
    u32 lslot = (u32)slot;
    u32 lfunc = (u32)func;
    u16 tmp = 0;
    address = (u32)((lbus << 16) | (lslot << 11) |
              (lfunc << 8) | (offset & 0xfc) | ((u32)0x80000000));
    outw(0xCF8, address);
    tmp = (u16)((inw(0xCFC) >> ((offset & 2) * 8)) & 0xffff);
    return (tmp);
}

void pci_write_word(u16 bus, u16 slot, u16 func, u16 offset,u16 value) {
    u32 address = (u32)((bus << 16) | (slot << 11) |
              (func << 8) | (offset & 0xfc) | ((u32)0x80000000));;

    outw(0xCF8,address);
    outw(0xCFC,value);
}



u16 get_vendor_id(u16 bus, u16 device, u16 function)
{
        u32 r0 = pci_read_word(bus,device,function,0);
        return r0;
}

u16 get_device_id(u16 bus, u16 device, u16 function)
{
        u32 r0 = pci_read_word(bus,device,function,2);
        return r0;
}

u16 get_class_id(u16 bus, u16 device, u16 function)
{
        u32 r0 = pci_read_word(bus,device,function,0xb);
        return (r0 & ~0x00FF) >> 8;
}

u16 get_subclass_id(u16 bus, u16 device, u16 function)
{
        u32 r0 = pci_read_word(bus,device,function,0xA);
        return (r0 & ~0xFF00);
}



void pci_probe()
{

        for(u32 slot = 0; slot < 32; slot++)
        {
         for(u32 function = 0; function < 8; function++)
            {
                u16 vendor = pci_read_word(0, slot, function,0);
                //dlog("degub = %x", vendor);
                if(vendor != 0xFFFF) 
                {
                    u16 device = get_device_id(0, slot, function);
                    u16 class = get_class_id(0, slot, function);
                    dlog("vendor: %x device: %x class: %x\n", vendor, device, class);
                    pci_device *pdev = (pci_device *)kmalloc(sizeof(pci_device));
                    pdev->vendor = vendor;
                    pdev->device = device;
                    pdev->func = function ;
                    pdev->driver = 0;
                    add_pci_device(pdev);
                }
            }
        }
    
}

 u16 pci_check_vendor(u16 bus, u16 slot)
 {
    u16 vendor,device;
        /* check if device is valid */
    if ((vendor = pci_read_word(bus,slot,0,0)) != 0xFFFF) {
       device = pci_read_word(bus,slot,0,2);
       /* valid device */
    } return (vendor);
 }


void pci_init()
{
	devs = drivs = 0;
	pci_devices = (pci_device **)kmalloc(32 * sizeof(pci_device));
	pci_drivers = (pci_driver **)kmalloc(32 * sizeof(pci_driver));
	pci_probe();
	kprintf("PCI driver support loaded.\n");
	//_kill();
}

void pci_register_driver(pci_driver *driv)
{
	pci_drivers[drivs] = driv;
	drivs ++;
	return;
}

void pci_proc_dump(u8 *buffer)
{
	for(int i = 0; i < devs; i++)
	{
		pci_device *pci_dev = pci_devices[i];
		if(pci_dev->driver)
			kprintf("[%x:%x:%x] => \n", pci_dev->vendor, pci_dev->device, pci_dev->func);// pci_dev->driver->name
		else
			kprintf("[%x:%x:%x]\n", pci_dev->vendor, pci_dev->device, pci_dev->func);
	}
}