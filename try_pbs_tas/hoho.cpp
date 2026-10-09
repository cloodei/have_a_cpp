#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
using namespace std;

using ll = long long;

struct thing {
    int x, pos;
};

void swap(thing& a, thing& b) {
    thing t;
    t.x = a.x;
    t.pos = a.pos;

    a.x = b.x;
    a.pos = b.pos;

    b.x = t.x;
    b.pos = t.pos;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<thing> a(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].x;
        a[i].pos = i;
    }

    sort(a.begin(), a.end(), [](auto& a, auto& b) {
        return a.x > b.x;
    });

    thing some1 = a[0], some2 = a[1], some3 = a[2];
    if (some1.pos > some2.pos)
        swap(some1, some2);
    if (some1.pos > some3.pos)
        swap(some1, some3);
    if (some2.pos > some3.pos)
        swap(some2, some3);

    cout << some1.x + 2 * some2.x + 3 * some3.x;
    return 0;
}
