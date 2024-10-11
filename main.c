#include "monitor.h"
#include "descriptor_tables.h"
#include "timer.h"
#include "multiboot.h"
#include "ide.h"
#include "fs.h"

extern void jump_usermode();
extern void testyl();
extern void testy();

void test_user_function()
{
	unsigned short *buffer;
	buffer = (unsigned short*) 0xB8000;

	unsigned char color = 7 | 0 << 4;

	char* str = "Hello World From User Mode!";

	int index = 0;
	
	while(str[index] != '\0')
	{
		buffer[index] = (unsigned short) str[index] | (unsigned short) color << 8;
		index++;
	}
}	

int main(unsigned int ebx)
{
    // Initialise all the ISRs and segmentation
    init_descriptor_tables();

    // Initialise the screen (by clearing it)
    monitor_clear();

    monitor_write("FreeCOSWN Operating System\nFreeCOSWN Kernel 1.0.0\n");

    //monitor_write("Disk Driver Initialized: \n");

    ata_init();

    const int DRIVE = ata_get_drive_by_model("QEMU HARDDISK");
    const uint32 LBA = 0;
    const uint8 NO_OF_SECTORS = 1;
    char* buf;

	monitor_write("\nFreeCOSWN Copyright (C) 2024\n");

	jump_usermode();

    while(1);
}
