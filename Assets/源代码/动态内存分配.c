#include <stdio.h>
#include <stdlib.h>

int main()
{
	//	/*
	int number;
	int *a;
	int i;
	printf("������������");
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

	// int��С����cpu�ܹ��ı�
	printf("\n%d", sizeof(int));
	// �ڴ��ַ��С���ݱ�����λ���ı�
	printf("\n%d", sizeof(int *));

	// ���ɷ����ڴ�
	void *p;
	int cnt = 0;
	while (p = malloc(100 * 1024 * 1024))
	{
		cnt++;
	}
	printf("�������%0.2 lfGB�Ŀռ�\n", cnt * 100 / 1024.0);
	return 0;
}
