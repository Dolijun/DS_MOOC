//
// Created by Mr.D on 2022/8/24.
//
#include "iostream"

using namespace std;

struct hnode {
    int *data;
    int size;
    int capacity;
};

typedef hnode *heap;

void insert_heap(heap h, int data);

void route(heap h, int idx);

void insert_heap(heap h, int data) {
    if (h->size >= h->capacity) {
        cout << "heap overflow";
        return;
    }
    if (h->size) {
        h->data[++h->size] = data;
        int counter = h->size;
        while (counter / 2) {
            if (h->data[counter / 2] > data) {
                h->data[counter] = h->data[counter / 2];
                counter = counter / 2;
            } else
                break;
        }
        h->data[counter] = data;
    } else
        h->data[++h->size] = data;
}

void route(heap h, int idx) {
    while (idx) {
        cout << h->data[idx];
        if (idx / 2)
            cout << " ";
        idx = idx / 2;
    }
}

int main() {
    int len_data;
    int len_out;
    cin >> len_data >> len_out;
    heap h = (heap) malloc(sizeof(hnode));
    h->data = (int *) malloc(sizeof(int) * (len_data + 1));
    h->size = 0;
    h->capacity = len_data;
    h->data[0] = -10001;
    for (int i = 1; i < len_data + 1; i++) {
        int data;
        cin >> data;
        insert_heap(h, data);
    }
    for (int i = 0; i < len_out; i++) {
        int idx;
        cin >> idx;
        route(h, idx);
        if (i + 1 < len_out)
            cout << "\n";
    }
    return 0;
}