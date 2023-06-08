//
// Created by JVxie on 2023/5/25.
//

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 2e5 + 10;

char s[MAX_N];
int ans[MAX_N];
stack<pair<char, int>> s1, s2;

void clearStack() {
    while (!s1.empty()) {
        s1.pop();
    }
    while (!s2.empty()) {
        s2.pop();
    }
}

bool reverseCheck(int n) {
    for (int i = 1; i <= n; ++i) {
        ans[i] = 0;
        if (s[i] == ')') {
            s1.push({s[i], i});
        } else {
            if (s1.empty()) {
                s2.push({s[i], i});
            } else {
                s1.pop();
            }
        }
    }
    return s1.empty() && s2.empty();
}


void solve() {
    int n;
    scanf("%d %s", &n, s + 1);
    clearStack();
    bool flag = reverseCheck(n);
    clearStack();
    if (flag) {
        printf("1\n");
        for (int i = 1; i <= n; ++i) {
            ans[i] = 1;
        }
    } else {
        for (int i = 1; i <= n; ++i) {
            ans[i] = 0;
            if (s[i] == '(') {
                s1.push({s[i], i});
            } else {
                if (s1.empty()) {
                    s2.push({s[i], i});
                } else {
                    pair<char, int> tmp = s1.top();
                    s1.pop();
                    ans[tmp.second] = ans[i] = 1;
                }
            }
        }
        if (s1.size() != s2.size()) {
            printf("-1\n");
            return;
        } else {
            if (s1.empty() && s2.empty()) {
                printf("1\n");

            } else {
                printf("2\n");
                while (!s1.empty()) {
                    pair<char, int> tmp = s1.top();
                    s1.pop();
                    ans[tmp.second] = 2;
                }
                while (!s2.empty()) {
                    pair<char, int> tmp = s2.top();
                    s2.pop();
                    ans[tmp.second] = 2;
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        printf("%d ", ans[i]);
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