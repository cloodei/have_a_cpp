#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

using ll = long long;

struct thing {
    ll weight, value;
};

ll dp[131072];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, W, V = 0;
    cin >> n >> W;

    memset(dp, 0x70, sizeof(dp));
    vector<thing> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].weight >> a[i].value;
        V += a[i].value;
    }

    dp[0] = 0;
    for (int i = 1; i <= n; ++i)
        for (int v = V; v >= a[i].value; --v)
            dp[v] = min(dp[v], dp[v - a[i].value] + a[i].weight);

    ll ans = 0;
    for (int v = 1; v <= V; ++v)
        if (dp[v] <= W)
            ans = v;

    cout << ans;
    return 0;
}
