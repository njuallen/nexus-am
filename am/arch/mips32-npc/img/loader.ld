MEMORY {
  ddr : ORIGIN = 0x10000000, LENGTH = 128M
}

SECTIONS {
  .text : {
    *(loader)
    *(.text)
    etext = .;
    _etext = .;
  } > ddr
  .data : {
    *(.data)
    edata = .;
    _edata = .;
  } > ddr
  .bss : {
    *(.bss*)
    *(.sbss)
    *(.scommon)
    end = .;
    _end = .;
  } > ddr
  _heap_start = ALIGN(4096);
  _stack_pointer = ORIGIN(ddr) + LENGTH(ddr);
  _heap_end = _stack_pointer - 4 * 1024 * 1024;
}
