#include <am.h>
#include <riscv32-emu.h>
#include <klib.h>

extern char _end;
extern int main();

#define STKSHIFT 17

_Area _heap;

volatile static int *halt_addr = (int *)((char *)DEVICE_START + TRAP_OFFSET);
volatile static char *putc_addr = (char *)DEVICE_START + PUTC_OFFSET;

void _putc(char ch) {
  *putc_addr = ch;
}

void _printstr(char *str) {
  while(*str)
    _putc(*str++);
}

void _halt(int code) {
  *halt_addr = code;
  while(1);
}

// memory mapping

void _trm_init() {
  _heap.start = (void *)(((uintptr_t)&_end + 63) & -64) + (2 << STKSHIFT);
  _heap.end = MEM_END;
  int ret = main();
  _halt(ret);
}
