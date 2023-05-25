//
// Created by Jeson Vendetta Xie on 2023/5/24.
//

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 2e5 + 10;

int a[MAX_N];

int main() {
    int T, n;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
        }
        sort(a + 1, a + 1 + n);
        bool opt = a[1] & 1, flag = true;
        int firstOdd = -1, firstEven = -1;
        if (opt) {
            firstOdd = a[1];
        } else {
            firstEven = a[1];
        }
        for (int i = 2; i <= n; ++i) {
            if (a[i] & 1) {
                if (!opt) {
                    if (firstOdd == -1 || firstOdd >= a[i]) {
                        flag = false;
                        break;
                    }
                }
                if (firstOdd == -1) {
                    firstOdd = a[i];
                }
            } else {
                if (opt) {
                    if (firstOdd == -1 || firstOdd >= a[i]) {
                        flag = false;
                        break;
                    }
                }
                if (firstEven == -1) {
                    firstEven = a[i];
                }
            }
        }
        printf("%s\n", flag ? "YES" : "NO");
    }
    return 0;
}