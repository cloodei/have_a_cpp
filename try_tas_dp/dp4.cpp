#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

using ll = long long;

int dp[5001][5001], n;
string r, s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> s;
    r = s;
    reverse(r.begin(), r.end());

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (s[i - 1] == r[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

    cout << (n - dp[n][n]);
    return 0;
}
