#include <stdio.h>
#include <stdlib.h>

// 必须写在结构体前面！！
#define OK 1
#define ERROR 0
typedef int Status;
typedef int SElemType;

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef struct{
    SElemType *base;
    SElemType *top;
    int stacksize;
}SqStack;

Status InitStack(SqStack *S)
{
    S->base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if(!S->base) return ERROR;
    S->top = S->base;
    S->stacksize = STACK_INIT_SIZE;
    return OK;
}

Status StackEmpty(SqStack *S)
{
    if(S->top == S->base)
        return OK;
    return ERROR;
}

Status Push(SqStack *S, SElemType e)
{
    if(S->top - S->base >= S->stacksize)
    {
        SElemType *newbase = (SElemType *)realloc(S->base,
            (S->stacksize + STACKINCREMENT)*sizeof(SElemType));
        if(!newbase) return ERROR;
        S->base = newbase;
        S->top = S->base + S->stacksize;
        S->stacksize += STACKINCREMENT;
    }
    *(S->top) = e;
    S->top++;
    return OK;
}

Status Pop(SqStack *S, SElemType *e)
{
    if(StackEmpty(S))
        return ERROR;
    S->top--;
    *e = *(S->top);
    return OK;
}

Status GetTop(SqStack *S, SElemType *e)
{
    if(StackEmpty(S))
        return ERROR;
    *e = *(S->top - 1);
    return OK;
}

void DestroyStack(SqStack *S)
{
    free(S->base);
    S->base = NULL;
    S->top = NULL;
    S->stacksize = 0;
}

int main(void)
{
    SqStack st;
    Status ret;
    SElemType val;

    ret = InitStack(&st);
    if(ret == OK)
        printf("栈初始化成功\n");

    Push(&st, 10);
    Push(&st, 20);
    Push(&st, 30);

    GetTop(&st, &val);
    printf("栈顶元素：%d\n", val);

    Pop(&st, &val);
    printf("弹出元素：%d\n", val);

    GetTop(&st, &val);
    printf("新栈顶：%d\n", val);

    DestroyStack(&st);
    return 0;
}


// //判断栈是否为空
// int StackEmpty(SqStack S){
//     //若栈为空，返回TRUE；否则返回FALSE
//     if (S.top = S.base)
//         return TRUE;
//     else 
//         return FALSE;
// }

// //求顺序栈长度
// int StackLength(SqStack S){

//     return S.top -S.base;
// }

// //清空顺序栈
// int ClearStack(SqStack S){
//     if (S.base ) S.top = S.base;
//     return OK;
// }

// //销毁顺序栈
// int DestroyStack(SqStack S) {
//     if(S.base) {
//         delete S.base;
//         S.stacksize = 0;
//         S.base =S.top = NULL;
//     }
//     return OK;
// }

