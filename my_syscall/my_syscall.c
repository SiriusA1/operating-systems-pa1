#include <linux/syscalls.h>
#include <linux/kernel.h>
SYSCALL_DEFINE1(conor_syscall, char *, str) {
	long len = strnlen_user(str, 32);
	char buff[(int)len];
	char* temp;
	int reps = 0;
	printk("HERE'S THE LEN: %d\n", (int)len);
	if (str == NULL || (int)len > 32)  {
		return -1;
	} else {
	       	printk("before: %s\n", str);
		if(copy_from_user(buff, str, (int)len))
			return -EFAULT;
		temp = &buff[0];
		while(*temp) {
			if (*temp == 'a' || *temp == 'e' 
					|| *temp == 'i' 
					|| *temp == 'o' || *temp == 'u') {
				*temp = 'X';
				reps++;
			}
			temp++;
		}
		if(copy_to_user(str, buff, (int)len))
			return -EFAULT;
		printk("after: %s\n", str);
		return reps;
	}
}
