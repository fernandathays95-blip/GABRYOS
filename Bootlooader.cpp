#include <common.h>
#include <command.h>
#include <config.h>
#include <environment.h>
#include <asm/io.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/crm_regs.h>
#include <asm/arch/sys_proto.h>
void dram_init_pre(void)
{
}
int dram_init(void)
{
    return 0;
}
void preloader_init_stage1(void)
{
}
void preloader_init_stage2(void)
{
}
void board_early_init_f(void)
{
    preloader_init_stage1();
    preloader_init_stage2();
}
int board_init(void)
{
    dram_init_pre();
    dram_init();
   
    env_set("stdout", "serial");
    env_set("stdin", "serial");
   
    env_set("ethaddr", "11:22:33:44:55:66");
    return 0;
}
int display_dram_info(void)
{
    return 0;
}
int check_boot_mode(void)
{
    return 0;
}
int board_late_init(void)
{
    return 0;
}
void preloader_console_init(void)
{
}
void main_loop(void)
{
}
void show_boot_progress(int progress)
{
}
void bootloader_entry(void)
{
    board_early_init_f();
    board_init();
   
    // Mais código de bootloader real...
    // Checagem de dispositivos de armazenamento
    // Descompactação do kernel
    // Carregamento do kernel para a RAM
    // Pulo para a entrada do kernel.
    // ...
   
    main_loop();
