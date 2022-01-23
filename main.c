#include<stdio.h>
#include<stdarg.h>

// 가변 인자를 사용하는데 쓰이는 매크로가 몇 가지 존재합니다.

// va_start
// va_arg
// va_list
// va_end

#define get_type_sizeof(type) return_get_type_size(sizeof(type))

int return_get_type_size(int type_size)
{
	return type_size;
}

int va_test(int num, ...)
{
	int sum;
	int i;
	int arg;
	va_list ap;
	

	va_start(ap, num);
	i = 0;
	sum = 0;
	while(i < num)
	{
		arg = va_arg(ap, int);
		sum += arg;
		++i;
	}
	va_end(ap);
	return (sum);
}

int main()
{
	int a;
	printf("%d \n %p", va_test(4, 10, 15, 10, 5), &a);

	
}