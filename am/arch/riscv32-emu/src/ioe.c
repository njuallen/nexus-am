#include <am.h>
#include <riscv32-emu.h>
#include <klib.h>

void _ioe_init() { };
unsigned long _uptime() { return 0; };
int _read_key() { return 0; }
void _draw_rect(const uint32_t *pixels, int x, int y, int w, int h) { };
void _draw_sync() { };
_Screen _screen;
