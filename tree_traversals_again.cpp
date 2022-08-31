//
// Created by Mr.D on 2022/8/1.
//
#include "iostream"
#include "queue"
#include "stack"

struct tree_node {
    int value;
    tree_node *left;
    tree_node *right;
};
using ptr_tree = tree_node *;

using namespace std;

class my_tree {

public:
    int init_data() {
        stack<int> s;
        int len;
        int val_posi = 0;
        int idx_posi = 0;
        string opt;
        int data;
        posi = 0;
        flag = 0;


        cin >> len;
//        cout << len;
        val_seq = (int *) malloc((len + 1) * sizeof(int));
        sta_val_seq = (int *) malloc((len + 1) * sizeof(int));
        sta_idx_seq = (int *) malloc((len + 1) * sizeof(int));
//        val_seq = (int *) malloc((len) * sizeof(int));
//        sta_val_seq = (int *) malloc((len) * sizeof(int));
//        sta_idx_seq = (int *) malloc((len) * sizeof(int));
//        (len + 1) *

        //// 键盘读入 val序列
        for (int i = 0; i < len * 2; i++) {
            cin >> opt;
            if (opt[1] == 'u') {
                cin >> data;
                s.push(data);
                val_seq[val_posi++] = data;
            } else {
                sta_val_seq[idx_posi++] = s.top();
                s.pop();
            }
        }

        //// 生成idx序列
        for (int i = 0; i < len; i++) {
            sta_idx_seq[sta_val_seq[i]] = i;
        }

        //// 建树
        t = build_tree(0, len - 1);


        //// 后续遍历
        post_traversal(t);

        return 0;
    }

    ptr_tree build_tree(int left, int right) {
        if (left > right) return NULL;
        else {
            ptr_tree ptr = (ptr_tree) malloc(sizeof(tree_node));
            ptr->value = val_seq[posi++];
            ptr->left = build_tree(left, sta_idx_seq[ptr->value] - 1);
            ptr->right = build_tree(sta_idx_seq[ptr->value] + 1 , right);
            return ptr;
        }
    }

    int post_traversal(ptr_tree p) {
        if (p) {
            post_traversal(p->left);
            post_traversal(p->right);
            if (flag == 0) {
                cout << p->value;
                flag = 1;
            } else {
                cout << " " << p->value;
            }
        } else return 0;
        return 0;
    }


private:
    int *val_seq; //// 存初始顺序
    int *sta_val_seq;  //// 存push pop后的顺序
    int *sta_idx_seq;
    ptr_tree t;
    int posi;
    int flag = 0;

};

int main() {
    my_tree *hello = new my_tree;
    hello->init_data();

    return 0;
}
