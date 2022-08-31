//
// Created by Mr.D on 2022/8/26.
//
#include<bits/stdc++.h>
using namespace std;

typedef pair<double, int> pi;

const int N = 5005;
const int M = 200005;
const double eps = 1e-8;
const double inf = 1e15;

int n, m, sz, cnt, last[N], rev_last[N], rt[N], fa[N];
double W, dis[N];
bool vis[N];
vector<int> dfn;
struct edge{int from, to, next; double w; bool is_tree_edge;}e[M * 2];
struct tree{int l, r, h, val; double key;}t[M * 10];

void addedge(int u, int v, double w)
{
    e[++cnt].from = u; e[cnt].to = v; e[cnt].w = w; e[cnt].next = last[u]; last[u] = cnt;
    e[++cnt].from = v; e[cnt].to = u; e[cnt].w = w; e[cnt].next = rev_last[v]; rev_last[v] = cnt;
}

int newnode(double key, int val)
{
    sz++; t[sz].key = key; t[sz].val = val; t[sz].h = 1;
    return sz;
}

int merge(int x, int y)
{
    if (!x || !y) return x + y;
    if (t[x].key > t[y].key) swap(x, y);
    int z = ++sz; t[z] = t[x];
    t[z].r = merge(t[z].r, y);
    if (t[t[z].l].h < t[t[z].r].h) swap(t[z].l, t[z].r);
    t[z].h = t[t[z].r].h + 1;
    return z;
}

void dijkstra()
{
    priority_queue<pi, vector<pi>, greater<pi> > que;
    for (int i = 1; i <= n; i++) dis[i] = inf;
    dis[n] = 0; que.push(make_pair(0, n));
    while (!que.empty())
    {
        int x = que.top().second; que.pop();
        while (!que.empty() && vis[x]) x = que.top().second, que.pop();
        if (vis[x]) break;
        vis[x] = 1;
        for (int i = rev_last[x]; i; i = e[i].next)
            if (dis[x] + e[i].w < dis[e[i].to])
            {
                dis[e[i].to] = dis[x] + e[i].w;
                que.push(make_pair(dis[e[i].to], e[i].to));
            }
    }
}

void build_SPT(int x)
{
    vis[x] = 1; dfn.push_back(x);
    for (int i = rev_last[x]; i; i = e[i].next)
        if (!vis[e[i].to] && fabs(dis[x] + e[i].w - dis[e[i].to]) < eps)
        {
            fa[e[i].to] = x;
            build_SPT(e[i].to);
            e[i].is_tree_edge = e[i ^ 1].is_tree_edge = 1;
        }
}

void build_heap()
{
    for (int i = 2; i <= cnt; i += 2)
    {
        int x = e[i].from, y = e[i].to;
        if (!e[i].is_tree_edge && vis[x] && vis[y])
            rt[x] = merge(rt[x], newnode(dis[y] - dis[x] + e[i].w, y));
    }
    for (int i = 1; i < dfn.size(); i++)
        rt[dfn[i]] = merge(rt[dfn[i]], rt[fa[dfn[i]]]);
}

int solve()//这是求1到n的k短路
{
    priority_queue<pi, vector<pi>, greater<pi> > que;
    int ans = 0;
    if (dis[1] < W + eps) W -= dis[1], ans++;
    if (rt[1]) que.push(make_pair(t[rt[1]].key, rt[1]));
    while (!que.empty())
    {
        double w = que.top().first; int x = que.top().second; que.pop();
        if (w + dis[1] > W) break;
        W -= w + dis[1]; ans++;
        if (t[x].l) que.push(make_pair(t[t[x].l].key + w - t[x].key, t[x].l));//替换
        if (t[x].r) que.push(make_pair(t[t[x].r].key + w - t[x].key, t[x].r));//替换
        if (rt[t[x].val]) que.push(make_pair(t[rt[t[x].val]].key + w, rt[t[x].val]));//加边
    }
    return ans;
}

int main()
{
    scanf("%d%d%lf", &n, &m, &W);
    cnt = 1;
    for (int i = 1; i <= m; i++)
    {
        int x, y; double w; scanf("%d%d%lf", &x, &y, &w);
        if (x != n) addedge(x, y, w);
    }
    dijkstra();
    memset(vis, 0, sizeof(vis));
    build_SPT(n);
    build_heap();
    printf("%d\n", solve());
    return 0;
}