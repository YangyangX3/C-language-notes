#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构体
typedef struct _node
{
    int value;
    struct _node *next;
} Node;

// 定义链表管理结构体（包含头尾指针）
typedef struct _list
{
    Node *head;
    Node *tail; // 增加尾指针，避免每次从头遍历
} List;

// 函数声明
void add(List *plist, int number);
void print(List *pList);
void found(List *list, int number);
void deleteNode(List *list, int number);

int main(void)
{
    List list;
    int number;
    list.head = list.tail = NULL; // 初始化头尾指针为空

    do
    {
        scanf("%d", &number);
        if (number != -1)
        { // 输入非-1则添加到链表
            add(&list, number);
        }
    } while (number != -1);
    print(&list);

    printf("你要找哪个数字：");
    scanf("%d", &number);
    found(&list, number);

    deleteNode(&list, number);
    printf("删除了\n");
    print(&list);

    return 0;
}

// 链表尾部添加节点的函数
void add(List *plist, int number)
{
    Node *p = (Node *)malloc(sizeof(Node)); // 动态分配内存
    if (!p)
    { // 检查内存分配是否成功 [[4]]
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    p->value = number;
    p->next = NULL; // 新节点始终作为最后一个节点 [[8]]

    if (plist->tail)
    {                          // 如果链表已有尾节点
        plist->tail->next = p; // 将新节点链接到原尾节点的next
        plist->tail = p;       // 更新尾指针指向新节点
    }
    else
    {                                  // 如果链表为空（首次添加）
        plist->head = plist->tail = p; // 头尾指针均指向新节点
    }
}

void print(List *pList)
{
    Node *last;
    for (last = pList->head; last; last = last->next)
    {
        printf("%d ", last->value);
    }
}

void found(List *pList, int number)
{
    Node *last;
    int isFound = 0;
    for (last = pList->head; last; last = last->next)
    {
        if (last->value == number)
        {
            printf("找到了\n");
            isFound = 1;
            break;
        }
    }
    if (!isFound)
    {
        printf("没找到\n");
    }
}

void deleteNode(List *list, int number)
{
    Node *q = NULL;       // 前驱节点
    Node *p = list->head; // 当前节点

    while (p != NULL)
    { // 遍历链表直到末尾
        if (p->value == number)
        {
            if (q != NULL)
            { // 非头节点
                q->next = p->next;
            }
            else
            { // 头节点
                list->head = p->next;
            }
            free(p); // 释放内存
            return;  // 删除成功后返回
        }
        q = p;       // 更新前驱节点
        p = p->next; // 移动到下一个节点
    }
}
