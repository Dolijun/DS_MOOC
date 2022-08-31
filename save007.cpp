//
// Created by Mr.D on 2022/8/27.
//
#include "iostream"


using namespace std;

struct point {
    int x;
    int y;
    bool used;
};

using ptr = point *;

int dist(ptr p1, ptr p2) {
    return (p1->x - p2->x) * (p1->x - p2->x) + (p2->y - p1->y) * (p2->y - p1->y);

}

bool available(ptr p1, ptr p2, double dis) {
    return dist(p1, p2) <= dis * dis;
}

bool win(ptr p, double dis) {
    if (p->x + dis >= 50 or p->x - dis <= -50)
        return true;
    if (p->y + dis >= 50 or p->y - dis <= -50)
        return true;
    return false;
}

bool DFS(ptr p, ptr ps, double dis, int N) {
    p->used = true;
    if (win(p, dis))
        return true;
    for (int i = 0; i < N; i++) {
        if (available(p, &ps[i], dis) and !ps[i].used)
            if (DFS(&ps[i], ps, dis, N))
                return true;
    }
    return false;
}


int main() {
    int N;
    int dis;
    point p;
    p.x = 0;
    p.y = 0;
    p.used = true;
    cin >> N >> dis;
    ptr points = (ptr) malloc(sizeof(point) * N);
    for (int i = 0; i < N; i++)
        cin >> points[i].x >> points[i].y;
    if (win(&p, dis + 7.5)) {
        cout << "Yes";
        return 0;
    }
    for (int i = 0; i < N; i++) {
        if (available(&p, &points[i], dis + 7.5)) {
            if (DFS(&points[i], points, dis, N)) {
                cout << "Yes";
                return 0;
            }
        }
    }
    cout << "No";
    return 0;
}
