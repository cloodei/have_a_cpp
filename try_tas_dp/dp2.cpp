#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
using namespace std;

using ll = long long;

struct thing {
    ll weight, value;
};

ll dp[103][100'005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, W;
    cin >> n >> W;

    vector<thing> a(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i].weight >> a[i].value;

    for (int i = 1; i <= n; ++i)
        for (int w = 1; w <= W; ++w)
            if (a[i].weight <= w)
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - a[i].weight] + a[i].value);
            else
                dp[i][w] = dp[i - 1][w];

    cout << dp[n][W];
    return 0;
}
