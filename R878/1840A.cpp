//
// Created by JVxie on 2023/6/6.
//

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 110;

char s[MAX_N];

void solve() {
    int n;
    scanf("%d %s", &n, s + 1);
    for (int i = 1; i <= n;) {
        for (int j = i + 1; j <= n; ++j) {
            if (s[i] == s[j]) {
                printf("%c", s[i]);
                i = j + 1;
                break;
            }
        }
    }
    printf("\n");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}