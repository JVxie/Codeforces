//
// Created by JVxie on 2023/5/25.
//

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 3e5 + 10;

char s[MAX_N];

void solve() {
    scanf("%s", s + 1);
    int n = strlen(s + 1), l = 1, r = 1;
    s[0] = '0', s[n + 1] = '1';
    while (l <= n && r <= n) {
        if (s[l] == '?') {
            --l;
        }
        if (s[r] == '?') {
            ++r;
        }
        if (s[l] != '?' && s[r] != '?') {
            if (s[l] == '0' && s[r] == '0') {
                for (int i = l + 1; i < r; ++i) {
                    s[i] = '0';
                }
            } else if (s[l] == '0' && s[r] == '1') {
                for (int i = l + 1; i < r; ++i) {
                    s[i] = '0';
                }
            } else if (s[l] == '1' && s[r] == '0') {
                for (int i = l + 1; i < r; ++i) {
                    s[i] = '0';
                }
            } else {
                for (int i = l + 1; i < r; ++i) {
                    s[i] = '1';
                }
            }
            l = r = r + 1;
        }
    }
    s[0] = '\0', s[n + 1] = '\0';
    printf("%s\n", s + 1);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}