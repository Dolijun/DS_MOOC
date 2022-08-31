//
// Created by Mr.D on 2022/8/26.
//
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode {
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

void PreorderTraversal(BinTree BT); /* 先序遍历，由裁判实现，细节不表 */
void InorderTraversal(BinTree BT);  /* 中序遍历，由裁判实现，细节不表 */

BinTree Insert(BinTree BST, ElementType X);

BinTree Delete(BinTree BST, ElementType X);

Position Find(BinTree BST, ElementType X);

Position FindMin(BinTree BST);

Position FindMax(BinTree BST);

int main() {
    BinTree BST, MinP, MaxP, Tmp;
    ElementType X;
    int N, i;

    BST = NULL;
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d", &X);
        BST = Insert(BST, X);
    }
    MinP = FindMin(BST);
    MaxP = FindMax(BST);
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d", &X);
        Tmp = Find(BST, X);
        if (Tmp == NULL) printf("%d is not found\n", X);
        else {
            printf("%d is found\n", Tmp->Data);
            if (Tmp == MinP) printf("%d is the smallest key\n", Tmp->Data);
            if (Tmp == MaxP) printf("%d is the largest key\n", Tmp->Data);
        }
    }
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d", &X);
        BST = Delete(BST, X);
    }

    return 0;
}

/* 你的代码将被嵌在这里 */

BinTree create_node(ElementType X) {
    BinTree BST = (BinTree) malloc(sizeof(struct TNode));
    BST->Data = X;
    BST->Right = NULL;
    BST->Left = NULL;
    return BST;
}

Position Find(BinTree BST, ElementType X) {
    if (!BST)
        return NULL;
    if (BST->Data == X) {
        return BST;
    } else if (BST->Data > X) {
        return Find(BST->Left, X);
    } else
        return Find(BST->Right, X);
}

Position FindMin(BinTree BST) {
    if(!BST)
        return NULL;
    if (BST->Left)
        return FindMin(BST->Left);
    else
        return BST;
}

Position FindMax(BinTree BST) {
    if(!BST)
        return NULL;
    if (BST->Right)
        return FindMax(BST->Right);
    else
        return BST;
}

BinTree Insert(BinTree BST, ElementType X) {
    if (BST)
        if (X < BST->Data)
            BST->Left = Insert(BST->Left, X);
        else
            BST->Right = Insert(BST->Right, X);
    else
        return create_node(X);
    return BST;
}


BinTree Delete(BinTree BST, ElementType X) {
    if(BST)
        if (X == BST->Data) {
            if (BST->Right) {
                BinTree min_ = FindMin(BST->Right);
                BST->Data = min_->Data;
                BST->Right = Delete(BST->Right, min_->Data);
                return BST;
            } else if (BST->Left) {
                BinTree max_ = FindMax(BST->Left);
                BST->Data = max_->Data;
                BST->Left = Delete(BST->Left, max_->Data);
                return BST;
            } else {
                free(BST);
                return NULL;
            }
        } else if ((X > BST->Data) && (BST->Right != NULL)) {
            BST->Right = Delete(BST->Right, X);
            return BST;
        }
        else if((X < BST->Data) && (BST->Left != NULL)) {
            BST->Left = Delete(BST->Left, X);
            return BST;
        }
    printf("Not Found\n");
    return BST;
}