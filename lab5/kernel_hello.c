#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/utsname.h>

static int __init init_hello(void)
{
	//struct utsname unameData;
	//uname(&unameData);

	printk("[COMP3120]: Hello, Kernel!\n");
	printk("[COMP3120]: My name is Kim Da Eun\n");
//	printk("[COMP3120]: My kernel version is 4.9.70\n");
	printk("[COMP3120]: My kernel version is %s\n",utsname()->release);

	return 0;
}

static void __exit exit_hello(void)
{
	printk("[COMP3120] Good bye, Kernel\n");
}

module_init(init_hello);
module_exit(exit_hello);
MODULE_LICENSE("GPL");
