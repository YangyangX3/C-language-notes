#include <stdio.h>

int main(void)
{
    // 读取文件示例
    FILE *fp = fopen("output.txt", "r");
    if (fp)
    {
        int num;
        // 添加错误检查
        if (fscanf(fp, "%d", &num) == 1)
        {
            printf("从output.txt读取的数字: %d\n", num);
        }
        else
        {
            printf("output.txt文件格式错误\n");
        }
        fclose(fp);
    }
    else
    {
        printf("无法打开文件output.txt，请检查文件是否存在\n");
    }

    // 演示写入和读取文件
    FILE *fp_out = fopen("output.txt", "w+"); // 以读写模式打开文件
    if (fp_out)
    {
        // 写入内容
        fprintf(fp_out, "%d\n", 3);
        fprintf(fp_out, "这是写入文件的第一行。\n");
        fprintf(fp_out, "写入一个数字: %d\n", 42);

        // 重置文件指针到开头
        rewind(fp_out);

        // 读取并打印文件内容
        printf("\n文件内容:\n");
        char buffer[256];
        while (fgets(buffer, sizeof(buffer), fp_out) != NULL)
        {
            printf("%s", buffer);
        }

        fclose(fp_out); // 关闭文件
        printf("\n已成功写入并读取 output.txt\n");
    }
    else
    {
        printf("无法创建或打开文件 output.txt\n");
    }

    return 0;
}
