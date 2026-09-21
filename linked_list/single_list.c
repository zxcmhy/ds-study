#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构体
typedef struct ListNode
{
    int data;               // 存储数据
    struct ListNode *next;  // 指向下一个节点的指针
} ListNode;

/**
 * @brief 创建新节点
 * @param val 节点存放的值
 * @return 返回新节点指针
 */
ListNode* createNode(int val)
{
    ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
    if (newNode == NULL)
    {
        perror("malloc fail");
        exit(-1);
    }
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

/**
 * @brief 头插：在链表头部插入节点
 * @param head 链表头指针的地址（二级指针）
 * @param val 插入的值
 */
void headInsert(ListNode **head, int val)
{
    ListNode *newNode = createNode(val);
    newNode->next = *head;
    *head = newNode;
}

/**
 * @brief 尾插：在链表尾部插入节点
 * @param head 链表头指针的地址
 * @param val 插入的值
 */
void tailInsert(ListNode **head, int val)
{
    ListNode *newNode = createNode(val);
    // 空链表
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    // 找到尾节点
    ListNode *cur = *head;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = newNode;
}

/**
 * @brief 遍历打印链表所有元素
 * @param head 链表头指针
 */
void printList(ListNode *head)
{
    ListNode *cur = head;
    while (cur != NULL)
    {
        printf("%d -> ", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}

/**
 * @brief 删除第一个值等于val的节点
 * @param head 链表头指针地址
 * @param val 需要删除的值
 */
void deleteVal(ListNode **head, int val)
{
    if (*head == NULL)
    {
        return;
    }
    ListNode *del = NULL;
    // 要删的是头节点
    if ((*head)->data == val)
    {
        del = *head;
        *head = (*head)->next;
        free(del);
        return;
    }
    ListNode *cur = *head;
    // 找到待删节点的前驱
    while (cur->next != NULL && cur->next->data != val)
    {
        cur = cur->next;
    }
    if (cur->next == NULL)
    {
        printf("未找到该元素\n");
        return;
    }
    del = cur->next;
    cur->next = cur->next->next;
    free(del);
}

/**
 * @brief 销毁整条链表，释放内存
 * @param head 链表头指针地址
 */
void destroyList(ListNode **head)
{
    ListNode *cur = *head;
    while (cur != NULL)
    {
        ListNode *next = cur->next;
        free(cur);
        cur = next;
    }
    *head = NULL;
}

int main(void)
{
    ListNode *head = NULL;

    tailInsert(&head, 10);
    tailInsert(&head, 20);
    tailInsert(&head, 30);
    printf("尾插10,20,30：");
    printList(head);

    headInsert(&head, 5);
    printf("头插5：");
    printList(head);

    deleteVal(&head,20);
    printf("删除20：");
    printList(head);

    destroyList(&head);
    printf("销毁后：");
    printList(head);

    return 0;
}