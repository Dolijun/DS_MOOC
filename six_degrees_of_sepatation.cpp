//
// Created by Mr.D on 2022/8/27.
//
//#include<bits/stdc++.h>
#include "vector"
#include "iostream"
#include "queue"
#include "cstdio"

using namespace std;

using p = pair<int, int>;

void add_edge(vector<p> *mp, int a, int b) {
    mp[a].emplace_back(b, 0);
    mp[b].emplace_back(a, 0);
}

int BFS(vector<p> *mp, int i, int N) {
    int sum = 1;
    static queue<p> q;
    bool visited[N + 1];
    for (int k = 1; k <= N; k++)
        visited[k] = false;
    visited[i] = true;
    q.emplace(i, 0);
    while (!q.empty()) {
        p cur = q.front();
        q.pop();
        for (auto &v: mp[cur.first]) {
            if (visited[v.first])
                continue;
            visited[v.first] = true;

            if (cur.second < 6) {
                sum++;
                q.emplace(v.first, cur.second + 1);
            }
        }
    }
    printf("%d: %.2f%%\n", i, sum * 100.0 / N);

}


int main() {
    int N;
    int M;
    int a, b;
    cin >> N >> M;

    vector<p> mp[N + 1];
    for (int i = 1; i <= M; i++) {
        cin >> a >> b;
        add_edge(mp, a, b);
    }

    for (int i = 1; i <= N; i++)
        BFS(mp, i, N);

    return 0;
}

