/*=================================
            Libraries
=================================*/

#include  <nusys.h>
#include "config.h"

/*=================================
	    	Rom2Ram
Read data from the ROM and transfer 
        it to the RAM.
=================================*/
void Rom2Ram(void *from_addr, void *to_addr, s32 seq_size)
{
    // Cannot transfer if size is an odd number, so make it even
    if(seq_size & 0x00000001) 
        seq_size++;

    nuPiReadRom((u32)from_addr, to_addr, seq_size);
}