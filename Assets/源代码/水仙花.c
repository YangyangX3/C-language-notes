#include <stdio.h>

#include <stdio.h>

int main()
{
	int n;
	// 读取用户输入的n值（3-7位数）
	scanf("%d", &n);
	if (n >= 3 && n <= 7)
	{
		int i = 1, frist = 1;
		// 计算起始值10^(n-1)
		while (i < n)
			frist *= 10, i++;
		i = frist;
		// 遍历所有n位数
		while (i <= frist * 10)
		{
			int t = i, sum = 0;
			// 计算各位数字的n次方和
			do
			{
				int d = t % 10, s = 1, cnt = n;
				while (cnt--)
					s *= d; // 计算d的n次方
				sum += s;
			} while (t = t / 10);
			// 输出符合条件的水仙花数
			if (sum == i)
				printf("%d\n", i);
			i++;
		}
	}
	return 0;
}
