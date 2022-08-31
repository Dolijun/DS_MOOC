//
// Created by Mr.D on 2022/8/26.
//
#include "iostream"
#include "queue"

using namespace std;

struct adj_node {
    int num;
    adj_node *next;
};

using adj_list = adj_node *;

adj_list *create_adj_list(int N);

bool check_connection(adj_list *adj, int num1, int num2);

bool add_connection(adj_list *adj, int num1, int num2);

void get_connections(adj_list *adj, int N);

adj_list create_node(int num);

void add_bi_connection(adj_list *adj, int num1, int num2);

void get_connection_set(adj_list *adj, int num, bool flag[], int N);

void get_connection_set_d(adj_list *adj, int num, bool flag[], int N, bool visited[]);


adj_list *create_adj_list(int N) {
    adj_list *adj = (adj_list *) malloc(sizeof(adj_list) * N);
    for (int i = 0; i < N; i++)
        adj[i] = nullptr;
    return adj;
}

adj_list create_node(int num) {
    adj_list temp = (adj_list) malloc(sizeof(adj_node));
    temp->num = num;
    temp->next = nullptr;
    return temp;
}

bool check_connection(adj_list *adj, int num1, int num2) {
    adj_list l = adj[num1];
    while (l) {
        if (l->num == num2)
            return true;
        else
            l = l->next;
    }
    return false;
}

bool add_connection(adj_list *adj, int num1, int num2) {
    bool first = true;
    if (num1 == num2)
        return false;
    adj_list l = adj[num1];
    if (adj[num1] == nullptr) {
        adj[num1] = create_node(num2);
    } else {
        while (l != nullptr) {
            if (first) {
                if (l->num > num2) {
                    adj_list temp = create_node(num2);
                    temp->next = adj[num1];
                    adj[num1] = temp;
                    return true;
                }
                first = false;
            }
            if (l->next == nullptr or l->next->num > num2) {
                adj_list temp = create_node(num2);
                temp->next = l->next;
                l->next = temp;
                return true;
            } else
                l = l->next;
        }
    }
    return true;
}

void add_bi_connection(adj_list *adj, int num1, int num2) {
    if (add_connection(adj, num1, num2))
        add_connection(adj, num2, num1);
}

void get_connection_set_d(adj_list *adj, int num, bool flag[], int N, bool visited[]) {
    flag[num] = true;
    visited[num] = true;
    cout << num << " ";
    for (adj_list l = adj[num]; l != nullptr; l = l->next) {
        if (!visited[l->num]) {
            get_connection_set_d(adj, l->num, flag, N, visited);
        }
    }

}

void get_connection_set(adj_list *adj, int num, bool flag[], int N) {
    queue<int> q;
    bool visited[N];
    for (int i = 0; i < N; i++)
        visited[i] = false;
    flag[num] = true;
    visited[num] = true;
    cout << "{ ";
    cout << num << " ";
    q.push(num);
    while (!q.empty()) {
        num = q.front();
        q.pop();
        for (adj_list l = adj[num]; l != nullptr; l = l->next) {
            if (!visited[l->num]) {
                flag[l->num] = true;
                visited[l->num] = true;
                cout << l->num << " ";
                q.push(l->num);
            }
        }
    }
    cout << "}" << endl;
}

void get_connections(adj_list *adj, int N) {
    bool flag[N];
    for (int i = 0; i < N; i++)
        flag[i] = false;
    bool visited[N];
    for (int i = 0; i < N; i++)
        visited[i] = false;
    for (int i = 0; i < N; i++)
        if (!flag[i]) {
            cout << "{ ";
            get_connection_set_d(adj, i, flag, N, visited);
            cout << "}" << endl;
        }
    for (int i = 0; i < N; i++)
        flag[i] = false;
    for (int i = 0; i < N; i++)
        if (!flag[i]) {
            get_connection_set(adj, i, flag, N);
        }

}


int main() {
    int N;
    int iter;
    int num1, num2;
    cin >> N;
    cin >> iter;
    adj_list *adj = create_adj_list(N);

    for (int i = 0; i < iter; i++) {
        cin >> num1 >> num2;
        add_bi_connection(adj, num1, num2);
    }

    get_connections(adj, N);

}