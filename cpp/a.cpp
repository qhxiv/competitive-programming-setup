#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

int n, a[21];
bool x[21], ok = true;
ll res = LLONG_MAX;
ll sum = 0;

void Try() {
    ll tmp = 0;
    for (int i = 1; i <= n; ++i) {
        if (x[i]) tmp += a[i];
    }
    res = min(res, abs(tmp - (sum - tmp)));
}

void generate() {
    int i = n;
    while (i > 0 && x[i] == 1) {
        x[i] = 0;
        --i;
    }
    if (i == 0) ok = false;
    else x[i] = 1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    while (ok) {
        Try();
        generate();
    }
    cout << res;
}