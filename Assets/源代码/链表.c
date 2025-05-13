#include <stdio.h>
#include <stdlib.h>

// ��������ڵ�ṹ��
typedef struct _node
{
    int value;
    struct _node *next;
} Node;

// �����������ṹ�壨����ͷβָ�룩
typedef struct _list
{
    Node *head;
    Node *tail; // ����βָ�룬����ÿ�δ�ͷ����
} List;

// ��������
void add(List *plist, int number);
void print(List *pList);
void found(List *list, int number);
void deleteNode(List *list, int number);

int main(void)
{
    List list;
    int number;
    list.head = list.tail = NULL; // ��ʼ��ͷβָ��Ϊ��

    do
    {
        scanf("%d", &number);
        if (number != -1)
        { // �����-1����ӵ�����
            add(&list, number);
        }
    } while (number != -1);
    print(&list);

    printf("��Ҫ���ĸ����֣�");
    scanf("%d", &number);
    found(&list, number);

    deleteNode(&list, number);
    printf("ɾ����\n");
    print(&list);

    return 0;
}

// ����β����ӽڵ�ĺ���
void add(List *plist, int number)
{
    Node *p = (Node *)malloc(sizeof(Node)); // ��̬�����ڴ�
    if (!p)
    { // ����ڴ�����Ƿ�ɹ� [[4]]
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    p->value = number;
    p->next = NULL; // �½ڵ�ʼ����Ϊ���һ���ڵ� [[8]]

    if (plist->tail)
    {                          // �����������β�ڵ�
        plist->tail->next = p; // ���½ڵ����ӵ�ԭβ�ڵ��next
        plist->tail = p;       // ����βָ��ָ���½ڵ�
    }
    else
    {                                  // �������Ϊ�գ��״���ӣ�
        plist->head = plist->tail = p; // ͷβָ���ָ���½ڵ�
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
            printf("�ҵ���\n");
            isFound = 1;
            break;
        }
    }
    if (!isFound)
    {
        printf("û�ҵ�\n");
    }
}

void deleteNode(List *list, int number)
{
    Node *q = NULL;       // ǰ���ڵ�
    Node *p = list->head; // ��ǰ�ڵ�

    while (p != NULL)
    { // ��������ֱ��ĩβ
        if (p->value == number)
        {
            if (q != NULL)
            { // ��ͷ�ڵ�
                q->next = p->next;
            }
            else
            { // ͷ�ڵ�
                list->head = p->next;
            }
            free(p); // �ͷ��ڴ�
            return;  // ɾ���ɹ��󷵻�
        }
        q = p;       // ����ǰ���ڵ�
        p = p->next; // �ƶ�����һ���ڵ�
    }
}
