#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll n, t;
    cin >> n >> t;

    vector<ll> v(n);
    for (auto &x : v) cin >> x;

    auto ok = [&](ll secend)
    {
        ll cnt = 0;

        for (int i = 0; i < n; i++)
        {
            cnt += secend/v[i];
            if (cnt >= t)
                return true;
        }
        
        return false;
    };


    ll l = 1, r = 1e18, ans = 0, mid = 0;

    while (l <= r)
    {
        mid = l+(r-l)/2;
        if (ok (mid))
        {
            ans = mid;
            r = mid-1;
        }
        else
            l = mid+1;
    }
    cout << ans << endl;
    
    return 0;
}