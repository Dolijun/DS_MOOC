//
// Created by Mr.D on 2022/8/24.
//
#include "iostream"

#define max_size 200
#define min(a, b) ((a) < (b) ? (a) : (b))
using namespace std;

struct heap_node {
    bool is_leaf;
    int freq;
    char name;
    heap_node *left;
    heap_node *right;
};
typedef heap_node * huffman;

struct min_heap {
    heap_node *data;
    int size;
    int capacity;
};

typedef min_heap *heap;

void down(heap h, int idx, heap_node data);

void up(heap h, int idx, heap_node data);

heap_node pop_heap(heap h);

void add_heap(heap h, heap_node data);

huffman build_huffman(heap h);

heap_node null_node;


heap build_heap(int N) {
    //// malloc
    min_heap *h = (min_heap *) malloc(sizeof(min_heap));
    h->data = (heap_node *) malloc((max_size + 1) * sizeof(heap_node));
    h->size = 0;
    h->capacity = max_size;
    h->data[0].freq = -1;

    //// cin
    for (int i = 0; i < N; i++) {
        h->size++;
        cin >> h->data[h->size].name >> h->data[h->size].freq;
        h->data[h->size].is_leaf = true;
        h->data[h->size].left = nullptr;
        h->data[h->size].right = nullptr;
    }
    for (int i = N / 2; i > 0; i--)
        down(h, i, h->data[i]);

    return h;
}

void down(heap h, int idx, heap_node data) {
    if (idx * 2 + 1 <= h->size) {
        if (h->data[idx * 2].freq < h->data[idx * 2 + 1].freq) {
            if (h->data[idx * 2].freq < data.freq) {
                h->data[idx] = h->data[idx * 2];
                down(h, idx * 2, data);
            } else {
                h->data[idx] = data;
                return;
            }
        } else {
            if (h->data[idx * 2 + 1].freq < data.freq) {
                h->data[idx] = h->data[idx * 2 + 1];
                down(h, idx * 2 + 1, data);
            } else {
                h->data[idx] = data;
                return;
            }
        }

    } else if (idx * 2 <= h->size) {
        if (h->data[idx * 2].freq < data.freq) {
            h->data[idx] = h->data[idx * 2];
            down(h, idx * 2, data);
        } else {
            h->data[idx] = data;
            return;
        }
    } else {
        h->data[idx] = data;
        return;
    }
}

void up(heap h, int idx, heap_node data) {
    while (idx / 2) {
        if (h->data[idx / 2].freq > data.freq) {
            h->data[idx] = h->data[idx / 2];
            idx = idx / 2;
        } else {
            h->data[idx] = data;
            break;
        }
        h->data[idx] = data;
    }
}

void add_heap(heap h, heap_node data) {
    h->data[++h->size] = data;
    up(h, h->size, data);
}

heap_node pop_heap(heap h) {
    if (h->size) {
        heap_node out = h->data[1];
        if (h->size > 1)
            down(h, 1, h->data[h->size--]);
        else
            h->size--;
        return out;
    }else{
        return null_node;
    }

}

huffman build_huffman(heap h){

    do{
        heap_node temp1 = pop_heap(h);
        if(temp1.freq == -1) {
            cout << "error";
            break;
        }
        heap_node temp2 = pop_heap(h);
        if(temp2.freq == -1){
            cout <<
        }

    }while(1)
}

int main() {
    null_node.freq = -1;
    int N;
    cin >> N;
    heap h = build_heap(N);
    huffman h_t = build_huffman(h);


        return 0;
}