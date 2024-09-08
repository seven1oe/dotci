#include <linux/delay.h>
#include <linux/fs.h>
#include <linux/init.h>
#include <linux/kthread.h>
#include <linux/module.h>
#include <linux/pid.h>
#include <linux/proc_fs.h>
#include <linux/sched.h>
#include <linux/uaccess.h>

int init_module(void)
{
    printk(KERN_INFO "////// [ init ] //////\n");
    {
        struct task_struct* need_stop;
        need_stop = pid_task(find_vpid(652), PIDTYPE_PID);
        if (need_stop != NULL) {
            kthread_stop(need_stop);
        }
        need_stop = pid_task(find_vpid(662), PIDTYPE_PID);
        if (need_stop != NULL) {
            kthread_stop(need_stop);
        }
    }
    // msleep(2000);
    return 0;
}

void cleanup_module(void)
{
    ////
    printk(KERN_INFO "////// [ exit ] //////\n");
}

MODULE_LICENSE("GPL");
