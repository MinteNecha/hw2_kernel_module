#include <linux/kernel.h>
#include <linux/string.h>
#include "libEncrypt.h"

static void reverse_string(char *str){
	if(!str) return;

	int i, j;
	char temp;
	int len = strlen(str);

	for(i=0, j = len - 1;i<j; i++, j--){
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
}

void reverse_and_print_kernel(char *sn, char *sur, char *names){
	reverse_string(sn);
	reverse_string(names);
	reverse_string(sur);

	pr_info("Reversed student number: %s\n", sn);
	pr_info("Reversed name: %s\n", names);
	pr_info("Reversed surname: %s\n", sur);
}

EXPORT_SYMBOL(reverse_and_print_kernel);
