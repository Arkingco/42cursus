#include<stdio.h>
#include<limits.h>
#include"ft_printf.h"

int main()
{
	char *a = malloc(sizeof(char) * INT_MAX + 1);
	for(int i=0; i<INT_MAX; ++i)
	{
		a[i] = '0';
	}
	printf("123%d123%s", 999, a);
}