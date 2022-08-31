#include<iostream>
#include<string.h>
#include<malloc.h>
#include "stack"
//push������pop�������ڵģ�һ����Ҷ�ڵ����û�����������м�ڵ㡣
//��Ҷ�ڵ��û�����������м�ڵ�: 
//push push pop, ��Ϊ��Ҷ�ڵ�����, ֮��ȥ��������push pop; 
//��Ҷ�ڵ�: pop push pop,
#define Maxlen 100
using namespace std;
typedef struct TreeNode *BinTree;

struct TreeNode {
    int Data;
    BinTree Left;
    BinTree Right;
};

BinTree BinTreeBuild(int left, int right, int PreOrder[], int InOrder[]);

void PostOrderTraversal(BinTree BT);

int main() {
    int len = 0;
    cin >> len;
    stack<int> s;
    BinTree BT = NULL;
    string c;
    int data = 0;
    int PreOrder[Maxlen] = {0};//��ʽdata��i = 1��ʼ
    int InOrder[Maxlen] = {0};
    int i = 1;
    int j = 1;
    int k = 1;

    for (; i <= 2 * len; i++) {
        cin >> c;
        if (c[1] == 'u') {
            cin >> data;
            s.push(data);
            PreOrder[j++] = data;
        } else {
            data = s.top();
            s.pop();
            InOrder[k++] = data;
        }
    }

    BT = BinTreeBuild(1, len, PreOrder, InOrder);
    PostOrderTraversal(BT);
}

BinTree BinTreeBuild(int left, int right, int PreOrder[], int InOrder[]) {
    if (left > right) {
        return NULL;
    }
    BinTree BT = (TreeNode *) malloc(sizeof(TreeNode));
    static int PreOrderPosition = 1;
    BT->Data = PreOrder[PreOrderPosition++];
    int i = left;
    for (; i <= right; i++) {
        if (BT->Data == InOrder[i]) {
            break;
        }
    }

    BT->Left = BinTreeBuild(left, i - 1, PreOrder, InOrder);
    BT->Right = BinTreeBuild(i + 1, right, PreOrder, InOrder);
    return BT;
}

void PostOrderTraversal(BinTree BT) {
    static int flag = 0;
    if (BT) {
        PostOrderTraversal(BT->Left);
        PostOrderTraversal(BT->Right);
        if (flag) {
            cout << " " << BT->Data;
        } else {
            cout << BT->Data;
            flag++;
        }

    } else return;
}
