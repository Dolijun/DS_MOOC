//
// Created by Mr.D on 2022/7/26.
//
#include "iostream"

#define MaxSize 10

using namespace std;

struct TreeNode{
    int data = 0;
    TreeNode * right = nullptr;
    TreeNode * left = nullptr;
};
typedef TreeNode *BinNode;

//先序迭代遍历
void PreOrderTraversal(BinNode BT){
    BinNode T = BT;
    Stack S = CreatStack(MaxSize);
    while(T || !IsEmpty(S)){
        while(T){
            cout << T->data;
            Push(S, T);
            T = T->left;
        }
        if(!IsEmpty(S)){
            T = Pop(S);
            T = T->right;
        }
    }
}

// 后序遍历
void PostOrderTraversal(BinNode BT){
    BinNode T = BT;
    Stack S = CreatStack(MaxSize);
    while(T || !IsEmpty(S)){
        while(T){
            Push(S, T);
            T = T->right;
        }
        if(!IsEmpty(S)){
            T = Pop(S);
            cout << T->data;
            T = T->left;
        }
    }
}
