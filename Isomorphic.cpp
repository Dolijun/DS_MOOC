//
// Created by Mr.D on 2022/7/31.
//
#include<iostream>

#define Null -1

using namespace std;

struct tree_node {
    char name;
    int left;
    int right;
    int parent;
};
typedef tree_node *tree;

struct tree_info {
    int len;
    tree t;
    int root;
};



tree_info *build_tree();
int isomorphic(tree t1, int p1, tree t2, int p2);

int main() {
    //// 建树
    tree_info *t1 = build_tree();
    tree_info *t2 = build_tree();

    //// 比较
    if (t1->len != t2->len) {
        cout << "No";
        return 0;
    }
    if(t1->len == 0 and t2->len == 0){
        cout << "Yes";
        return 0;
    }
    if(isomorphic(t1->t, t1->root, t2->t,t2->root))
        cout << "Yes";
    else
        cout << "No";
    return 0;
}


//// 建树
tree_info *build_tree() {
    tree_info *info = (tree_info *) malloc(sizeof(tree_info));
    cin >> info->len;
    info->t = (tree) malloc(info->len * sizeof(tree_node));
    //// 建树
    for (int i = 0; i < info->len; i++) {
        info->t[i].name = Null;
        info->t[i].left = Null;
        info->t[i].right = Null;
        info->t[i].parent = Null;
        char name;
        char left;
        char right;
        cin >> name >> left >> right;
        info->t[i].name = name;
        info->t[i].left = left == '-' ? Null : int(left - '0');
        info->t[i].right = right == '-' ? Null : int(right - '0');
    }
    //// 记录父节点
    for (int i = 0; i < info->len; i++) {
        if (info->t[i].left != Null) info->t[info->t[i].left].parent = i;
        if (info->t[i].right != Null) info->t[info->t[i].right].parent = i;
    }
    //// 记录根节点
    for (int i = 0; i < info->len; i++)
        if (info->t[i].parent == Null) {
            info->root = i;
            break;
        }
    return info;
}

//// 从根节点遍历
int isomorphic(tree t1, int p1, tree t2, int p2) {
    if (t1[p1].name != t2[p2].name) return 0;
    if (t1[p1].left == Null and t1[p1].right == Null and t2[p2].left == Null and t2[p2].right == Null) return 1;

    if (t1[p1].left != Null and t1[p1].right == Null and t2[p2].left != Null and t2[p2].right == Null)
        return isomorphic(t1, t1[p1].left, t2, t2[p2].left);
    if (t1[p1].left != Null and t1[p1].right == Null and t2[p2].left == Null and t2[p2].right != Null)
        return isomorphic(t1, t1[p1].left, t2, t2[p2].right);
    if (t1[p1].left == Null and t1[p1].right != Null and t2[p2].left != Null and t2[p2].right == Null)
        return isomorphic(t1, t1[p1].right, t2, t2[p2].left);
    if (t1[p1].left == Null and t1[p1].right != Null and t2[p2].left == Null and t2[p2].right != Null)
        return isomorphic(t1, t1[p1].right, t2, t2[p2].right);

    if (t1[p1].left != Null and t1[p1].right != Null and t2[p2].left != Null and t2[p2].right != Null) {
        if (t1[t1[p1].left].name == t2[t2[p2].left].name)
            return isomorphic(t1, t1[p1].right, t2, t2[p2].right) & isomorphic(t1, t1[p1].left, t2, t2[p2].left);
        if (t1[t1[p1].left].name == t2[t2[p2].right].name)
            return isomorphic(t1, t1[p1].left, t2, t2[p2].right) & isomorphic(t1, t1[p1].right, t2, t2[p2].left);
        return 0;
    }
    return 0;
}
