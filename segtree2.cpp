#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
using namespace std;

using ll = long long;

struct node {
    ll macks, prefix, suffix, sum;
};

int x, y;
node tree[200002];
vector<ll> a;

void build(int id, int l, int r) {
    if (l == r) {
        tree[id].macks = a[l];
        tree[id].prefix = a[l];
        tree[id].suffix = a[l];
        tree[id].sum = a[l];
        return;
    }

    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);

    tree[id].sum = tree[id * 2].sum + tree[id * 2 + 1].sum;
    tree[id].prefix = max(tree[id * 2].prefix, tree[id * 2].sum + tree[id * 2 + 1].prefix);
    tree[id].suffix = max(tree[id * 2 + 1].suffix, tree[id * 2 + 1].sum + tree[id * 2].suffix);
    tree[id].macks = max(tree[id * 2].macks, max(tree[id * 2].suffix + tree[id * 2 + 1].prefix, tree[id * 2 + 1].macks));
}

node getSum(int id, int l, int r) {
    if (l >= x && r <= y) {
        // inside [x, y]
        return tree[id];
    }
    //cout << 2 << " ";

    if (l > y || r < x) {
        // out of bounds
        node zeroed = {-200000, -200000, -200000, -200000};
        zeroed.sum = 0;
        return zeroed;
    }
    //cout << 3 << " ";

    // if (l == r) {

    // }

    int mid = (l + r) / 2;
    node left  = getSum(id * 2, l, mid);
    node right = getSum(id * 2 + 1, mid + 1, r);

    node res;
    res.sum = left.sum + right.sum;
    res.prefix = max(left.prefix, left.sum + right.prefix);
    res.suffix = max(right.suffix, right.sum + left.suffix);
    res.macks = max(left.macks, max(left.suffix + right.prefix, right.macks));
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    a.push_back(-1);
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    build(1, 1, n);
    int m;
    cin >> m;
    while (m--) {
        cin >> x >> y;
        cout<< getSum(1, 1, n).macks << endl;
    }

    return 0;
}
