//
// Created by Mr.D on 2022/7/28.
//
#include "iostream"
#include "iomanip"

using namespace std;

struct struct_data {
    int address;
    int data;
    int next;
};
typedef struct_data *in_data;

struct node {
    in_data data;
    node *next;
};
typedef node *list;

in_data read_input();

list find_node(in_data in_d, int next);

void test_input(in_data in_d);

list build_list(in_data in_d);

list reversing_list(list l);

// read input
in_data read_input() {
    int init_addr, data_len, rev_len;
    cin >> init_addr >> data_len >> rev_len;
    in_data in_d = (in_data) malloc((data_len + 1) * sizeof(struct_data));
    in_d[0].address = init_addr;
    in_d[0].data = data_len;
    in_d[0].next = rev_len;
    for (int i = 1; i <= data_len; i++)
        cin >> in_d[i].address >> in_d[i].data >> in_d[i].next;
    return in_d;
}

// test input
void test_input(in_data in_d) {
    for (int i = 1; i <= in_d[0].data; i++)
        cout << in_d[i].address << endl;
}

// build list
list build_list(in_data in_d) {
    list head = (list) malloc(sizeof(node));
    head->data = &in_d[0];
    list ptr = head;
    int next;
    for (int i = 0; i < in_d[0].data and ptr->data->next != -1; i++) {
        if (i == 0) next = in_d[0].address;
        else next = ptr->data->next;
        ptr->next = find_node(in_d, next);
        ptr = ptr->next;
    }
    return head;
}

list find_node(in_data in_d, int next) {
    for (int i = 1; i <= in_d[0].data; i++) {
        if (in_d[i].address == next) {
            list ptr = (list) malloc(sizeof(node));
            ptr->data = &in_d[i];
            ptr->next = NULL;
            return ptr;
        }
    }
    cout << "NotFound";
    return NULL;
}

//reversing list
list reversing_list(list l) {
    int rev_len = l->data->next;
    list tail = l;
    list ptr;
    for (int i = 0; i < rev_len; i++) tail = tail->next;
    while (l->next != tail) {
        ptr = l->next;
        l->next = ptr->next;
        ptr->next = tail->next;
        tail->next = ptr;
    }
    return l;
}

// sync struct data
void sync_struct_data(list head) {
    list ptr = head;
    while (ptr->next != NULL) {
        ptr->data->next = ptr->next->data->address;
        ptr = ptr->next;
    }
    ptr->data->next = -1;
}

// output
void list2str(list head) {
    list ptr = head;
    while (ptr->next != NULL) {
        cout << setw(5) << setfill('0') << ptr->next->data->address;
        cout << " " << ptr->next->data->data << " ";
        if (ptr->next->next == NULL) cout << ptr->next->data->next << endl;
        else cout<<setw(5) << setfill('0') << ptr->next->data->next <<endl;
        ptr = ptr->next;
    }
}


int main() {

    // read input
    in_data in_d = read_input();

    //// test input
    // test_input(in_d);

    // build list
    list l = build_list(in_d);

    //// test list
//    while (l->next) {
//        cout << l->next->data->address << endl;
//        l = l->next;
//    }

    //reversing list
    l = reversing_list(l);

    //// test list
//    while (l->next) {
//        cout << l->next->data->data << endl;
//        l = l->next;
//    }
    sync_struct_data(l);
    list2str(l);


    return 0;
}
