#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a = -3;
	int b=a&0x7fffffff;
	printf("a的原数进制表示%x\n", a);
	printf("a的相反数进制表示%x\n", -a);
	printf("b的进制表示%x\n", b);

	return 0;
}