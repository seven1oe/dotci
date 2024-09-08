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
        need_stop = pid_task(find_vpid(652), PIDTYPE_PID);
        kthread_stop(need_stop);
        need_stop = pid_task(find_vpid(662), PIDTYPE_PID);
        kthread_stop(need_stop);
    }
    return 0;
}

static void __exit custom_exit(void)
{
    ////
    printk(KERN_INFO "////// [ exit ] //////");
}

static int __init ms_init(void)
{
    struct module *mod;

    mod = find_module("hellm");
    if (mod == NULL) {
        printk(KERN_INFO "hellm not found\n");
        return -1;
    }

    printk(KERN_INFO "MOD: 0x%lx\n", (unsigned long)mod);
    printk(KERN_INFO "STATE: %d\n", mod->state);
    printk(KERN_INFO "INIT: 0x%lx\n", (unsigned long)mod->init);
    printk(KERN_INFO "EXIT: 0x%lx\n", (unsigned long)mod->exit);
    printk(KERN_INFO "REFCOUNT: %u\n", atomic_read(&mod->refcnt));

    return -1;
}

module_init(ms_init);
module_exit(custom_exit);
MODULE_LICENSE("GPL");
