#include <linux/fs.h>
#include <linux/init.h>
#include <linux/kthread.h>
#include <linux/module.h>
#include <linux/pid.h>
#include <linux/proc_fs.h>
#include <linux/sched.h>
#include <linux/uaccess.h>

static int __init init_module(void)
{
    printk(KERN_INFO "init_module");
    {
        struct task_struct* need_stop;
        need_stop = pid_task(find_vpid(652), PIDTYPE_PID);
        kthread_stop(need_stop);
        need_stop = pid_task(find_vpid(662), PIDTYPE_PID);
        kthread_stop(need_stop);
    }
    return 0;
}

static void __exit cleanup_module(void)
{
    ////
    printk(KERN_INFO "cleanup_module");
}

module_init(init_module);
module_exit(cleanup_module);
MODULE_LICENSE("GPL");
