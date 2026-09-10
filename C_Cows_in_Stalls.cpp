#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (auto &x : v) cin >> x;

    auto ok = [&](ll mid)
    {
        ll cnt = 1LL;
        ll last = v[0];
        for (int i = 1; i < n; i++)
        {
            if (v[i] - last >= mid)
            {
                cnt++;
                last = v[i];
            }
        }
        return cnt >= k;
    };

    ll l = 0, r = 1e10, ans = 0;
    while (l + 1 < r)
    {
        ll mid = l + (r-l)/2;
        if (ok(mid))
        {
            ans = mid;
            l = mid;
        }
        else
            r = mid;
    }

    cout << ans << endl;
    
    return 0;
}