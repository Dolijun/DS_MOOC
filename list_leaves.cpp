//
// Created by Mr.D on 2022/8/1.
//
#include"iostream"
#include "queue"

#define Null -1

using namespace std;

struct tree_node {
    int left;
    int right;
    int parent;
};
using tree = tree_node *;

struct tree_info {
    int len;
    tree t;
    int root;
};


tree_info *build_tree();

void LevelTraverse(tree_info *info);

int main() {
    LevelTraverse(build_tree());
    return 0;
}

////建树
tree_info *build_tree() {
    tree_info *info = (tree_info *) malloc(sizeof(tree_info));
    cin >> info->len;
    tree t = (tree) malloc(info->len * sizeof(tree_node));
    for (int i = 0; i < info->len; i++) {
        char left, right;
        t[i].left = Null;
        t[i].right = Null;
        t[i].parent = Null;
        cin >> left >> right;
        t[i].left = left == '-' ? Null : (int) (left - '0');
        t[i].right = right == '-' ? Null : (int) (right - '0');
    }
    info->t = t;
    //// 记录父节点
    for (int i = 0; i < info->len; i++) {
        if (info->t[i].left != Null) info->t[info->t[i].left].parent = i;
        if (info->t[i].right != Null) info->t[info->t[i].right].parent = i;
    }

    for (int i = 0; i < info->len; i++)
        if (t[i].parent == Null) {
            info->root = i;
        }
    return info;
}

//// 遍历
void LevelTraverse(tree_info *info) {
    queue<int> q;
    int flag;
    int flag_t = 0;
    q.push(info->root);
    while (!q.empty()) {
        flag = 0;
        int posi = q.front();
        q.pop();
//        cout << posi << "hello" << endl;
        if (info->t[posi].left != Null) {
            q.push(info->t[posi].left);
            flag++;
        }
        if (info->t[posi].right != Null) {
            q.push(info->t[posi].right);
            flag++;
        }
        if (flag == 0 and flag_t == 0) {
            cout << posi;
            flag_t ++;
        } else if (flag == 0)
            cout << " " << posi ;
//
    }
}