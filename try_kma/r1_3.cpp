#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
using namespace std;

using ll = long long;

ll n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    vector<ll> a1 = { 1 }, a2 = { 2 }, a3 = { 3 };

    if (n < 4) {
        cout << n;
        return 0;
    }

    ll curr1 = 0, curr2 = 0, curr3 = 0, sum1 = 0, sum2 = 0, sum3 = 0;
    while (true) {
        if (curr1 == 0 || curr1 < a1.size() - 1) {
            if (a1[curr1] * 3 + 1 < n) {
                a1.push_back(a1[curr1] * 3 + 1);
                sum1 += a1[curr1] * 3 + 1;
            }
            if (a1[curr1] * 5 + 1 < n) {
                a1.push_back(a1[curr1] * 5 + 1);
                sum1 += a1[curr1] * 5 + 1;
            }
            if (a1[curr1] * 7 + 1 < n) {
                a1.push_back(a1[curr1] * 7 + 1);
                sum1 += a1[curr1] * 7 + 1;
            }
        }

        if (curr2 == 0 || curr2 < a2.size() - 1) {
            if (a2[curr2] * 3 + 1 < n) {
                a2.push_back(a2[curr2] * 3 + 1);
                sum2 += a2[curr2] * 3 + 1;
            }
            if (a2[curr2] * 5 + 1 < n) {
                a2.push_back(a2[curr2] * 5 + 1);
                sum2 += a2[curr2] * 5 + 1;
            }
            if (a2[curr2] * 7 + 1 < n) {
                a2.push_back(a2[curr2] * 7 + 1);
                sum2 += a2[curr2] * 7 + 1;
            }
        }


        if (curr3 == 0 || curr3 < a3.size() - 1) {
            if (a3[curr3] * 3 + 1 < n) {
                a3.push_back(a3[curr3] * 3 + 1);
                sum3 += a3[curr3] * 3 + 1;
            }
            if (a3[curr3] * 5 + 1 < n) {
                a3.push_back(a3[curr3] * 5 + 1);
                sum3 += a3[curr3] * 5 + 1;
            }
            if (a3[curr3] * 7 + 1 < n) {
                a3.push_back(a3[curr3] * 7 + 1);
                sum3 += a3[curr3] * 7 + 1;
            }
        }

        if (curr1 == a1.size() && curr2 == a2.size() && curr3 == a3.size())
            break;

        curr1++;
        curr2++;
        curr3++;
    }

    cout << max(max(sum1, sum2), sum3);

    return 0;
}
