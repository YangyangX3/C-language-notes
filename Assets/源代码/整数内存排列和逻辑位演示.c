#include <stdio.h>
#include <stdint.h>

// 检测字节序的函数
void check_endianness() {
    uint32_t num = 0x12345678;
    uint8_t *p = (uint8_t *)&num;
    
    printf("数字 0x%x 在内存中的存储顺序:\n", num);
    for(int i = 0; i < sizeof(num); i++) {
        printf("地址 %p: 0x%02x\n", p+i, *(p+i));
    }
    
    if (*p == 0x78) {
        printf("\n这是小端机器 (Little-Endian)\n");
    } else {
        printf("\n这是大端机器 (Big-Endian)\n");
    }
}

// 位运算演示（不受字节序影响）
void bit_operation_demo() {
    uint32_t num = 0b00000000000000000000000000000101; // 5
    printf("\n位运算演示 (数字5):\n");
    printf("原始值: 0x%08x\n", num);
    printf("右移2位: 0x%08x\n", num >> 2);
    printf("左移1位: 0x%08x\n", num << 1);
}

int main() {
    printf("=== 字节序和位运算演示 ===\n");
    check_endianness();
    bit_operation_demo();
    
    printf("\n关键结论:\n");
    printf("1. 字节序只影响多字节数据的内存存储顺序\n");
    printf("2. 位运算操作的是逻辑位顺序，与字节序无关\n");
    printf("3. 在小端机器上，低位字节存储在低地址\n");
    
    return 0;
}
