#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll n, x, y;
    cin >> n >> x >> y;

    ll mn = min (x, y);

    auto ok = [&](ll time)
    {
        if ((time/x + time/y) >= (n-1))
        {
            return true;
        }
        return false;
    };

    ll l = 0, r = 2e9, ans = 0;
    while (l <= r)
    {
        ll mid = l + (r-l)/2;
        
        if (ok(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }

    cout << ans + mn << endl;
    
    return 0;
}