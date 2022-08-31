//
// Created by Mr.D on 2022/7/30.
//
#include<stack>
#include<iostream>

using namespace std;
struct Node {
    int data;
    Node *next;
};
typedef Node *List;

struct Conf {
    int s_capacity;
    int seq_len;
    int seq_nums;
};

List read_list(Conf conf);

int main() {

    //// 读取序列配置
    Conf conf;
    cin >> conf.s_capacity >> conf.seq_len >> conf.seq_nums;

    //// 循环检测
    for (int i = 0; i < conf.seq_nums; i++) {
        List in_list = read_list(conf);
        List ptr = in_list->next;
        int j = 1;
        stack<int> s;
        while (j <= conf.seq_len + 1) {
            // 出栈情况
            if (!s.empty() and s.top() == ptr->data) {
                s.pop();
                ptr = ptr->next;
            } else if (s.size() < conf.s_capacity and j <= conf.seq_len) s.push(j++);
            else break;
        }
        if (!s.empty()) cout << "NO" << endl;
        else cout << "YES" << endl;
    }

    return 0;
}

// 读输入序列
List read_list(Conf conf) {
    List head = (List) malloc(sizeof(Node));
    head->data = NULL;
    head->next = NULL;
    List rear = head;

    for (int i = 0; i < conf.seq_len; i++) {
        List ptr = (List) malloc(sizeof(Node));
        cin >> ptr->data;
        ptr->next = NULL;
        rear->next = ptr;
        rear = ptr;
    }

    return head;
}

