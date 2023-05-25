//
// Created by Jeson Vendetta Xie on 2023/5/24.
//

#include <bits/stdc++.h>

using namespace std;

#define PII pair<int, int>
const int MAX_N = 2e5 + 10;

struct Edge {
    int to, go;
    Edge() {
        to = go = 0;
    }
    Edge(int to) {
        this->to = to;
    }
}edge[MAX_N << 1];

int head[MAX_N], len;
map<PII, bool> mp;
bool vis[MAX_N], flag; // flag: true is circle

void add(int from, int to) {
    edge[++len] = Edge(to);
    edge[len].go = head[from];
    head[from] = len;
}

void dfs(int fu, int u) {
    vis[u] = true;
    for (int i = head[u]; ~i; i = edge[i].go) {
        int v = edge[i].to;
        if (v != fu) {
            if (vis[v]) {
                flag = true;
            } else{
                dfs(u, v);
            }
        }
    }
}

void init(int n) {
    len = 0;
    mp.clear();
    for (int i = 0; i <= n; ++i) {
        head[i] = -1;
        vis[i] = false;
    }
}

void solve() {
    int n, a, ans1 = 0, ans2 = 0;
    scanf("%d", &n);
    init(n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a);
        if (!mp.count(make_pair(i, a))) {
            add(i, a);
            add(a, i);
            mp[make_pair(i, a)] = true;
            mp[make_pair(a, i)] = true;
        }
    }
    for (int i = 1; i <= n; ++i) {
        flag = false;
        if (!vis[i]) {
            dfs(i, i);
            if (flag) {
                ++ans1;
            } else {
                ++ans2;
            }
        }
    }
//    printf("%d %d\n", ans1, ans2);
    printf("%d %d\n", ans1 + (ans2 > 0), ans1 + ans2);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        solve();
    }
}
/*
10
6
2 3 1 5 6 4
9
2 3 2 5 6 5 8 9 8
2
2 1
4
4 3 2 1
5
2 3 4 5 1
6
5 3 4 1 1 2
5
3 5 4 1 2
6
6 3 2 5 4 3
6
5 1 4 3 4 2

 */
