//
// Created by Mr.D on 2022/7/30.
//

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print(List L); /* 细节在此不表；空链表将输出NULL */

List Merge(List L1, List L2);

int main() {
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

/* 你的代码将被嵌在这里 */
List Merge(List L1, List L2) {
    List head = (List) malloc(sizeof(struct Node));
    head->Next = NULL;
    List rear = head;
    List ptr1 = L1->Next;
    List ptr2 = L2->Next;
    while (1) {
        if (ptr1 == NULL && ptr2 == NULL) break;
        else if(ptr1 == NULL){
            rear->Next = ptr2;
            break;
        }else if(ptr2 == NULL){
            rear->Next = ptr1;
            break;
        }else if(ptr1->Data <= ptr2->Data){
            rear->Next = ptr1;
            rear = ptr1;
            ptr1 = ptr1->Next;
        }else{
            rear->Next = ptr2;
            rear = ptr2;
            ptr2 = ptr2->Next;
        }
    }
    L1->Next = NULL;
    L2->Next = NULL;
    return head;
}


