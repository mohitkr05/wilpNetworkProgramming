#include <linux/module.h>
#include <linux/kernel.h>

int int_module(void){
	printk(KERN_INFO "Hello Kernel 1.\n");
	return 0
}

void cleanup_module{
	printk(KERN_INFO "Goodbye Kernel 1. \n");
	
}
