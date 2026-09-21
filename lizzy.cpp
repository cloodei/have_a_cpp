#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
using namespace std;

using ll = long long;

vector<int> lis(vector<int> const& a) {
    const int n = a.size();
    vector<int> d, p(n);

    for (int i = 0; i < n; i++) {
        auto it = lower_bound(d.begin(), d.end(), a[i]);
        p[i] = it - d.begin();
        if (it == d.end())
            d.push_back(a[i]);
        else
            *it = a[i];
    }

    int l = d.size() - 1;
    vector<int> subseq;
    for (int i = n - 1; i >= 0 && l >= 0; i--)
        if (p[i] == l)
            subseq.push_back(a[i]), l--;

    reverse(subseq.begin(), subseq.end());
    return subseq;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> a = { 8, 3, 4, 6, 5, 2, 0, 7, 9, 1 };
    auto res = lis(a);
    for (int i = 0; i < res.size(); ++i)
        cout << res[i] << " ";

    return 0;
}
