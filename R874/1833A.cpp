//
// Created by Jeson Vendetta Xie on 2023/5/24.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, len, ans;
    char s[110];
//    map<string, bool> mp;
    bool vis[210][210];
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &len);
        scanf("%s", s + 1);
        memset(vis, false, sizeof vis);
        ans = 0;
        for (int i = 2; i <= len; ++i) {
            if (!vis[s[i - 1]][s[i]]) {
                ++ans;
                vis[s[i - 1]][s[i]] = true;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}