#ifndef __RISCV32_EMU__
#define __RISCV32_EMU__

#define MEM_START ((char *)0x10000000)
#define MEM_END ((char *)0x18000000)

#define DEVICE_START MEM_END
#define DEVICE_END ((char *)0x18100000)

#define COUNTER_START DEVICE_END
#define COUNTER_END ((char *)0x18101000)

#define TRAP_OFFSET 0
#define PUTC_OFFSET 4

#endif
