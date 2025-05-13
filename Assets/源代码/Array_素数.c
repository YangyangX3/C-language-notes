#include <stdio.h>
#include <math.h>

// 判断一个数是否为素数的函数
int isPrimeNumber(int n) {
    if (n <= 1) return 0;  // 0和1不是素数
    if (n <= 3) return 1;  // 2和3是素数
    if (n % 2 == 0 || n % 3 == 0) return 0;  // 2和3的倍数不是素数
    
    // 只需要检查到sqrt(n)，以6为中心的奇数
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;
    }
    return 1;
}

int main()
{
    const int maxNumber = 100;  // 扩大范围以展示算法效率
    int isPrime[maxNumber];
    
    // 初始化数组，假设所有数都是素数
    for (int i = 0; i < maxNumber; i++) {
        isPrime[i] = 1;
    }
    
    // 0和1特殊处理：它们不是素数
    isPrime[0] = isPrime[1] = 0;
    
    // 埃拉托斯特尼筛法：只需要检查到sqrt(maxNumber)
    for (int x = 2; x * x < maxNumber; x++) {
        if (isPrime[x]) {
            // 将x的倍数标记为非素数（从x*x开始，因为更小的倍数已被标记）
            for (int i = x * x; i < maxNumber; i += x) {
                isPrime[i] = 0;
            }
        }
    }
    
    // 输出所有素数
    printf("使用埃拉托斯特尼筛法找出的素数：\n");
    int count = 0;
    for (int i = 2; i < maxNumber; i++) {
        if (isPrime[i]) {
            printf("%d ", i);
            count++;
            // 每10个数换一行，增强可读性
            if (count % 10 == 0) {
    printf("\n");
            }
            }
        }
    printf("\n\n共找到%d个素数\n", count);
    
    // 验证我们的isPrimeNumber函数是否正确
    printf("\n使用isPrimeNumber函数验证素数：\n");
    for (int i = 2; i < 50; i++) {  // 验证一部分数
        if (isPrimeNumber(i)) {
            printf("%d是素数\n", i);
        }
    }

    return 0;
}