import gabryos.kernel.printk
import gabryos.ui.emoji
#define panic(*panic_text);
printk_crit("KERNEL PANIC!");
printk_crit("%mode MODE");
printk_crit("PROCESS: %procs");
printk_crit("Kernel panic - not syncing: %panic_text");
printk("🐯", according_to_the_number_of_cpu_cores_or how_many_cpus_it_has);
cpu.halt_all();
/** agora dá para usar panic("algo…");
Tipo panic("teste"); que sai isso:
KERNEL PANIC!
TEST MODE
PROCESS: teste.mpl
Kernel panic - not syncing: teste
🐯🐯🐯🐯🐯 */
emoji.ui();
kernel.printk();
#end
#kernel
#panic
static __kernel { (knl(__panic)); }
LICENSE("gabryOS LICENSE 1.0");

