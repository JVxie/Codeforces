//
// Created by JVxie on 2023/5/30.
//

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 2e5 + 10;

struct Edge {
    int to, id, go;
}edge[MAX_N << 1];

int len, head[MAX_N], id[MAX_N], dp[MAX_N];

void add(int u, int v, int i) {
    edge[++len] = {v, i, head[u]};
    head[u] = len;
}

void init(int n) {
    len = 0;
    for (int i = 0; i <= n; ++i) {
        head[i] = -1;
        id[i] = 0;
        dp[i] = 0;
    }
    for (int i = 0; i <= (n << 1); ++i) {
        edge[i] = {0, 0, 0};
    }
}

void dfs(int u) {
    for (int i = head[u]; ~i; i = edge[i].go) {
        int v = edge[i].to, idv = edge[i].id;
        if (!dp[v]) {
            dp[v] = dp[u] + (idv <= id[u]);
            id[v] = idv;
            dfs(v);
        }
    }
}

void solve() {
    int n, ans = 0, u, v;
    scanf("%d", &n);
    init(n);

    for (int i = 1; i < n; ++i) {
        scanf("%d %d", &u, &v);
        add(u, v, i);
        add(v, u, i);
    }
    dp[1] = 1;
    dfs(1);
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, dp[i]);
    }
    printf("%d\n", ans);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}