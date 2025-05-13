#include <stdio.h>
#include <stdlib.h>

int main()
{
	//	/*
	int number;
	int *a;
	int i;
	printf("请输入数量：");
	scanf("%d", &number);
	a = (int *)malloc(number * sizeof(int));
	printf("malloc's valut is :%p", a);
	for (i = 0; i < number; i++)
	{
		scanf("%d", &a[i]);
		printf("%p\n", &a[i]);
	}
	for (i = number - 1; i >= 0; i--)
	{
		printf("%d ", a[i]);
	}

	free(a);
	free(++a);
	free(a);
	//	*/

	// int大小根据cpu架构改变
	printf("\n%d", sizeof(int));
	// 内存地址大小根据编译器位数改变
	printf("\n%d", sizeof(int *));

	// 最大可分配内存
	void *p;
	int cnt = 0;
	while (p = malloc(100 * 1024 * 1024))
	{
		cnt++;
	}
	printf("分配给了%0.2 lfGB的空间\n", cnt * 100 / 1024.0);
	return 0;
}
