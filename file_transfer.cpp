//
// Created by Mr.D on 2022/8/25.
//
#include "iostream"

using namespace std;

bool check_connection(int cp_set[], int cp1, int cp2);

void add_connection(int cp_set[], int cp1, int cp2);

int find_root(int cp_set[], int cp1);

int find_root(int cp_set[], int cp1) {
    while (cp_set[cp1] > 0)
        cp1 = cp_set[cp1];
    return cp1;
}

bool check_connection(int cp_set[], int cp1, int cp2) {
    int root1 = find_root(cp_set, cp1);
    int root2 = find_root(cp_set, cp2);
    return root1 == root2;
}

void add_connection(int cp_set[], int cp1, int cp2) {
    int root1 = find_root(cp_set, cp1);
    int root2 = find_root(cp_set, cp2);
    if (root1 == root2)
        return;
    else if (cp_set[root1] >= cp_set[root2]) {
        cp_set[root2] += cp_set[root1];
        cp_set[root1] = root2;
    } else {
        cp_set[root1] += cp_set[root2];
        cp_set[root2] = root1;
    }
}

int main() {
    int N;
    cin >> N;
    int cp_set[N];
    for (int i = 0; i < N; i++)
        cp_set[i] = -1;
    char opt;
    int cp1;
    int cp2;

    while (1) {
        cin >> opt;
        if (opt == 'S')
            break;
        cin >> cp1 >> cp2;
        cp1 -= 1;
        cp2 -= 1;
        if (opt == 'C')
            if (check_connection(cp_set, cp1, cp2))
                cout << "yes" << endl;
            else
                cout << "no" << endl;
        else if (opt == 'I')
            add_connection(cp_set, cp1, cp2);
    }
    int counter = 0;
    for (int i = 0; i < N; i++)
        if (cp_set[i] < 0)
            counter++;
    if(counter != 1)
        cout << "There are " << counter << " components." << endl;
    else
        cout << "The network is connected." << endl;
    return 0;
}
