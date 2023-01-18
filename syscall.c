#include <unistd.h>
#include <stdio.h>
int conor_syscall(char *str) {
	return syscall(548, str);
}
int main() {
	char *string1 = "adjkgnasjkgnsjnfjkasnajksgasgssdagsgasgs";
	char *string2 = "my goodness hello";
	printf("Here's String 1 (before): %s\n", string1);
	printf("Here's String 2 (before): %s\n", string2);
	long ret1 = conor_syscall(string1);
	long ret2 = conor_syscall(string2);
	printf("Return value 1: %d\n", (int)ret1);
	printf("Return value 2: %d\n", (int)ret2);
	printf("Here's String 1 (after): %s\n", string1);
	printf("Here's String 2 (after): %s\n", string2);
	return 0;
}
