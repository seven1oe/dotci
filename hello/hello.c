#include <linux/fs.h>
#include <linux/init.h>
#include <linux/kthread.h>
#include <linux/module.h>
#include <linux/pid.h>
#include <linux/proc_fs.h>
#include <linux/sched.h>
#include <linux/uaccess.h>

static int __init custom_init(void)
{
    printk(KERN_INFO "////// [ init ] //////");
    {
        struct task_struct* need_stop;
        // need_stop = pid_task(find_vpid(652), PIDTYPE_PID);
        // kthread_stop(need_stop);
        // need_stop = pid_task(find_vpid(662), PIDTYPE_PID);
        // kthread_stop(need_stop);
    }
    return -1;
}

static void __exit custom_exit(void)
{
    ////
    printk(KERN_INFO "////// [ exit ] //////");
}

module_init(custom_init);
module_exit(custom_exit);
MODULE_LICENSE("GPL");
