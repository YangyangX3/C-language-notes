# 编译器配置
CC = gcc
CFLAGS = -Wall -Wextra

# 文件配置
TARGET = main.exe
SRCS = main.c max.c
OBJS = $(SRCS:.c=.o)

# 默认目标
all: $(TARGET)

# 链接目标文件
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# 自动编译.c文件
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# 清理生成文件
clean:
	del $(TARGET) *.o
	@echo "已清理所有生成文件！"

.PHONY: all clean
