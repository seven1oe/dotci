#include <linux/fs.h>
#include <linux/init.h>
#include <linux/kthread.h>
#include <linux/module.h>
#include <linux/pid.h>
#include <linux/proc_fs.h>
#include <linux/sched.h>
#include <linux/uaccess.h>
#include <linux/delay.h>

int init_module(void)
{
    printk(KERN_INFO "////// [ init ] //////");
    {
        struct task_struct* need_stop;
        // need_stop = pid_task(find_vpid(652), PIDTYPE_PID);
        // kthread_stop(need_stop);
        // need_stop = pid_task(find_vpid(662), PIDTYPE_PID);
        // kthread_stop(need_stop);
    }
	msleep(2000);
    return 0;
}

void cleanup_module(void)
{
    ////
    printk(KERN_INFO "////// [ exit ] //////");
}

MODULE_LICENSE("GPL");
