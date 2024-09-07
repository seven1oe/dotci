#include <linux/init.h>
#include <linux/module.h>
#include <linux/pci.h>
#include <linux/slab.h>
#include <linux/interrupt.h>
#include <linux/dma-mapping.h>
#include <sound/initval.h>
#include <linux/delay.h>
#include <linux/kthread.h>
#include <linux/kernel.h>
#include <asm/signal.h>
#include <linux/delay.h>
#include <linux/sched.h>
#include <linux/sched/signal.h>
static int my_init(void)
{
	struct task_struct *task;
	int signum = SIGKILL;
	struct kernel_siginfo info;
	memset(&info, 0, sizeof(struct kernel_siginfo));
	info.si_signo = signum;
	while(1)
	{
		for_each_process(task)
		{
			/* find a sleep process */
			if (strncmp(task->comm, "sleep", 5) == 0)
			{	
				int ret = send_sig_info(signum, &info, task);
				if (ret < 0)
				{
				  printk(KERN_INFO "error sending signal\n");
				}
				else 
				{
					printk(KERN_INFO "Target has been killed\n");
				}
			}
		}
	}
	return 0;
}
   
static void my_exit(void)
{
    printk(KERN_INFO "Exit driver.\n");

    return;
}
   
module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Shubham Dubey <shubham0d@protonmail.coms>");
MODULE_DESCRIPTION("Kill process from kernel module");