//
// Created by Mr.D on 2022/8/24.
//
#include "iostream"
#include "algorithm"

using namespace std;

void in_order_traversal(int seq_in[], int root, int len, int seq_out[]);

void in_order_traversal(int seq_in[], int root, int len, int seq_out[]) {
    static int idx = 0;
    int left = root * 2 + 1;
    int right = root * 2 + 2;
    if (left < len)
        in_order_traversal(seq_in, left, len, seq_out);
    seq_out[root] = seq_in[idx++];
    if (right < len)
        in_order_traversal(seq_in, right, len, seq_out);
}


int main() {
    int len;
    cin >> len;
    int seq_in[len];
    int seq_out[len];
    for (int i = 0; i < len; i++)
        cin >> seq_in[i];
    sort(seq_in, seq_in + len);
    in_order_traversal(seq_in, 0, len, seq_out);
    for (int i = 0; i < len; i++)
        if (i)
            cout << " " << seq_out[i];
        else
            cout << seq_out[i];
}
