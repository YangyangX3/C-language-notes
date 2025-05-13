#include <stdio.h>

// 定义一个名为 TrafficLight 的枚举类型
// 它包含三个可能的常量：RED, YELLOW, GREEN
enum TrafficLight
{
    RED,    // 默认值为 0
    YELLOW, // 默认值为 1
    GREEN   // 默认值为 2
};

// 也可以显式指定值
enum Status
{
    PENDING = 1,    // PENDING 的值是 1
    PROCESSING,     // PROCESSING 的值是 2 (前一个 + 1)
    COMPLETED = 10, // COMPLETED 的值是 10
    FAILED          // FAILED 的值是 11 (前一个 + 1)
};

int main(void)
{
    // 声明一个 TrafficLight 类型的变量
    enum TrafficLight currentLight;

    // 给变量赋值
    currentLight = 1;

    // 使用枚举常量进行判断
    if (currentLight == YELLOW)
    {
        printf("当前信号灯是黄灯 (值: %d)\n", currentLight); // 输出 1
    }
    else if (currentLight == RED)
    {
        printf("当前信号灯是红灯 (值: %d)\n", currentLight);
    }
    else
    {
        printf("当前信号灯是绿灯 (值: %d)\n", currentLight);
    }

    // 枚举用在 switch 语句中非常方便
    printf("使用 switch 判断灯的状态: ");
    switch (currentLight)
    {
    case RED:
        printf("红灯停！\n");
        break; // 不要忘记 break!
    case YELLOW:
        printf("黄灯请注意！\n");
        break;
    case GREEN:
        printf("绿灯行！\n");
        break;
    // default 不是必须的，但可以处理预期外的值
    default:
        printf("未知的信号灯状态！\n");
    }

    enum Status currentStatus = FAILED;
    printf("当前状态: %d\n", currentStatus); // 输出 11

    return 0;
}
