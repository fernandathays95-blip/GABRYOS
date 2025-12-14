static __bootloader(__bl(init_all_cpus));
static __bootloader(__bl(CPU1));
static __bootloader(__bl(bits: 64));
static __bootloader(__bl(init {.c, .br, .BR, .brasil, .mpl}));
bl(__boot__)
bl(__init__)
bl(__loadfile__)
bl(__initk__)
