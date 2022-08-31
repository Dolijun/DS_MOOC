#include<iostream>
#include <malloc.h>

using namespace std;

typedef struct ListNode {
    int c;
    int e;
    ListNode *next;
} LN;

// ??????§Ø????
LN *get_poly();

// ???????????
LN *poly_mul(LN *poly1, LN *poly2);

// // ???????????
LN *poly_add(LN *poly1, LN *poly2);

int main() {
    // ?????????
    LN *poly1 = get_poly();
    LN *poly2 = get_poly();

    // ???????????
    LN *mul_result;
    mul_result = poly_mul(poly1, poly2);
    for (LN *item = mul_result; item != nullptr; item = item->next) {
        if(item->next){
            cout << item->c << " " << item->e << " ";
        }else {
            cout << item->c << " " << item->e;
        }
    }

    // ???????????
    LN *add_result = nullptr;
    add_result = poly_add(poly1, poly2);
    cout << endl;
    for (LN *item = add_result; item != nullptr; item = item->next) {
        if(item->next){
            cout << item->c << " " << item->e << " ";
        }else{
            cout << item->c << " " << item->e;
        }
    }

    return 0;
}
// ?????????????

LN *get_poly() {
    int N;
    cin >> N;
    LN *head;
    LN *rear;
    LN *p;
    for (int i = 0; i < N; i++) {
        int c;
        int e;
        cin >> c;
        cin >> e;
        p = (LN *) malloc(sizeof(LN));
        p->next = nullptr;
        p->c = c;
        p->e = e;
        if (i == 0) {
            head = p;
            rear = p;
        } else {
            rear->next = p;
            rear = p;
        }
    }

    rear->next = nullptr;
    return head;
}

LN *poly_mul(LN *poly1, LN *poly2) {
    LN *result = nullptr;
//    for (LN *temp1 = poly1; temp1 != nullptr; temp1 = temp1->next) {
//        cout << temp1->c << " " << temp1->e << endl;
//    }
//    for (LN *temp2 = poly2; temp2 != nullptr; temp2 = temp2->next) {
//        cout << temp2->c << " " << temp2->e << endl;
//    }

    for (LN *temp1 = poly1; temp1 != nullptr; temp1 = temp1->next) {
        for (LN *temp2 = poly2; temp2 != nullptr; temp2 = temp2->next) {
            // ??¨®????????????
            int c = temp1->c * temp2->c;
            int e = temp1->e + temp2->e;
            // ?§Ø???????
            if (result == nullptr) {
                LN *temp_new = (LN *) malloc(sizeof(LN));
                temp_new->c = c;
                temp_new->e = e;
                temp_new->next = nullptr;
                result = temp_new;
            } else {
                for (LN *temp = result; temp != nullptr; temp = temp->next) {
                    if (temp->e == e) {
                        temp->c += c;
                        break;
                    } else if ((temp->e > e) & (!temp->next)) {
                        LN *temp_new = (LN *) malloc(sizeof(LN));
                        temp_new->c = c;
                        temp_new->e = e;
                        temp_new->next = temp->next;
                        temp->next = temp_new;
                        break;
                    } else if ((temp->e > e) & (temp->next->e < e)) {
                        LN *temp_new = (LN *) malloc(sizeof(LN));
                        temp_new->c = c;
                        temp_new->e = e;
                        temp_new->next = temp->next;
                        temp->next = temp_new;
                        break;
                    }
                }
            }

        }
    }
    // È¥³ý0
    while (result->c == 0) {
        LN *item = result;
        result = result->next;
        free(item);
    }
    for (LN *item = result; item != nullptr; item = item->next) {
        while (item->next and (item->next->c == 0)) {
            LN *p = item->next;
            item->next = p->next;
            free(p);
        }
    }

    return result;
}

LN *poly_add(LN *poly1, LN *poly2) {
    LN *temp1 = poly1;
    LN *temp2 = poly2;
    LN *head;
    LN *rear;


    int flag = 0;
    while (1) {
        if (!temp1) {
            flag = 1;
            break;
        } else if (!temp2) {
            flag = 2;
            break;
        }

        LN *p = (LN *) malloc(sizeof(LN));
        p->next = nullptr;
        if (head == nullptr) {
            head = p;
        } else {
            rear->next = p;
        }

        rear = p;
        if (temp1->e > temp2->e) {
            p->c = temp1->c;
            p->e = temp1->e;
            temp1 = temp1->next;
        } else if (temp1->e < temp2->e) {
            p->c = temp2->c;
            p->e = temp2->e;
            temp2 = temp2->next;
        } else if (temp1->e == temp2->e) {
            p->c = temp1->c + temp2->c;
            p->e = temp1->e;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }
    LN *temp;
    if (flag == 1) {
        temp = temp2;
    } else if (flag == 2) {
        temp = temp1;
    }

    for (; temp != nullptr; temp = temp->next) {
        LN *p = (LN *) malloc(sizeof(LN));
        rear->next = p;
        rear = p;
        p->c = temp->c;
        p->e = temp->e;

    }

    return head;
}
