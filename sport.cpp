#include <bits/stdc++.h>
using namespace std;

using Pair = pair<int, int>;
#define inf 1'000'000'000

int main(void)
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<Pair> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i].first;
    for (int i = 0; i < n; ++i)
        cin >> a[i].second;
    sort(a.begin(), a.end(), [&](const auto &x, const auto &y)
         { return x.first + x.second < y.first + y.second; });

    vector<int> mn(n + 1, inf);
    for (int i = n - 1; i >= 0; --i)
    {
        mn[i] = min(mn[i + 1], a[i].first);
    }
    for (int i = 0; i < n; ++i)
    {
        if (k < mn[i])
        {
            cout << i << '\n';
            return 0;
        }
        k -= a[i].first + a[i].second;
    }
    cout << n << '\n';

    return 0;
}