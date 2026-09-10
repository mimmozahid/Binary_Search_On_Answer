#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve ()
{
    ll h, n;
    cin >> h >> n;
    vector<ll> a(n), c(n);
    for (auto &i : a) cin >> i;
    for (auto &i : c) cin >> i;

    auto ok = [&](ll mid)  //! greedy part...
    {
        ll cnt = 0;
        for (int i = 0; i < n; i++)
        {
            cnt += (1+(mid - 1)/c[i]) * a[i];
            cnt = min (cnt, h);
        }
        
        return cnt == h;
    };

    ll l = 0, r = 1e12, ans = 0;
    while (l+1 < r)
    {
        ll mid = l + (r-l)/2;
        if (ok(mid))
        {
            ans = mid;
            r = mid;
        }
        else
            l = mid;
    }

    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--)
        solve ();
    
    return 0;
}