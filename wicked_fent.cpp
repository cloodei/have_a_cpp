#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <numeric>
using namespace std;
using ll = long long;

int tree[20], n = 10;

void update(int index, int value) {
    while (index <= n) {
        tree[index] += value;
        index += (index & (-index));
    }
}

int getSum(int index) {
    int res = 0;
    while (index > 0) {
        res += tree[index];
        index -= (index & (-index));
    }

    return res;
}

int main() {
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        update(a[i], 1);
    }
    for (int i = 1; i <= n; ++i) {
        cout << i << ": " << getSum(a[i - 1]) << "\n";
    }

    return 0;
}
