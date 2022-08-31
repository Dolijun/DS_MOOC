//
// Created by Mr.D on 2022/8/23.
//
#include "iostream"

using namespace std;

struct node {
    int value;
    node *left = NULL;
    node *right = NULL;
};

typedef node *tree_node;

//// build tree
tree_node insert_node(tree_node t, int value) {
    if (t == NULL) {
        tree_node temp = (tree_node) malloc(sizeof(node));
        temp->value = value;
        temp->left = NULL;
        temp->right = NULL;
        t = temp;
        return t;
    } else if (t->value > value)
        if (t->left)
            insert_node(t->left, value);
        else {
            tree_node temp = (tree_node) malloc(sizeof(node));
            temp->value = value;
            temp->right = NULL;
            temp->left = NULL;
            t->left = temp;
            return t;
        }
    else if (t->value < value)
        if (t->right)
            insert_node(t->right, value);
        else {
            tree_node temp = (tree_node) malloc(sizeof(node));
            temp->left = NULL;
            temp->right = NULL;
            temp->value = value;
            t->right = temp;
            return t;
        }
    else {
        cout << "ERROR Insert" << endl;
        return NULL;
    }
}

tree_node buile_tree(int N) {
    int value = 0;
    tree_node tree = NULL;
    for (int i = 0; i < N; i++) {
        cin >> value;
        if (tree == NULL)
            tree = insert_node(tree, value);
        else
            insert_node(tree, value);
    }
    return tree;
}

//// compare tree
bool compare_tree(tree_node tree1, tree_node tree2) {
    if (tree1 == NULL and tree2 == NULL)
        return true;
    if (tree1 == NULL or tree2 == NULL)
        return false;
    if (tree1->value == tree2->value) {
        if (!compare_tree(tree1->left, tree2->left))
            return false;

        if (!compare_tree(tree1->right, tree2->right))
            return false;
    } else
        return false;
    return true;
}


//// free tree
void free_tree(tree_node t) {
    if (t->left)
        free_tree(t->left);
    if (t->right)
        free_tree(t->right);
    free(t);
}

int main() {
    int N;
    int L;
    int flag = true;
    while (1) {
        cin >> N;
        if (N == 0)
            break;
        cin >> L;
        tree_node tree1 = buile_tree(N);
        for (int i = 0; i < L; i++) {
            tree_node tree2 = buile_tree(N);
            if (compare_tree(tree1, tree2)) {
                if (flag) {
                    cout << "Yes";
                    flag = false;
                } else
                    cout << "\n" << "Yes";
            } else {
                if (flag) {
                    cout << "No";
                    flag = false;
                } else
                    cout << "\n" << "No";
            }

            free_tree(tree2);
        }
        free_tree(tree1);
    }
}