#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/moduleparam.h>
#include "libEncrypt.h"

static char *studentnumber = "d_num";
static char *names = "d_names";
static char *surname = "d_surname";
static int age = 0;

module_param(studentnumber, charp, S_IRUGO);
module_param(names, charp, S_IRUGO);
module_param(surname, charp, S_IRUGO);
module_param(age, int, S_IRUGO);

extern void reverse_and_print_kernel(char *sn, char *sur, char *names);

static int __init userDetails_init(void){
	printk(KERN_INFO "StudentNumber: %s\n", studentnumber);
	printk(KERN_INFO "Names: %s\n", names);
	printk(KERN_INFO "Surname: %s\n", surname);
	printk(KERN_INFO "Age: %d\n", age);
	reverse_and_print_kernel(studentnumber, surname, names);
	
	return 0;
}

static void __exit userDetails_exit(void){
	printk(KERN_INFO "Goodbye %s, this module is cleared\n", names);
}

module_init(userDetails_init);
module_exit(userDetails_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("JEFF");
