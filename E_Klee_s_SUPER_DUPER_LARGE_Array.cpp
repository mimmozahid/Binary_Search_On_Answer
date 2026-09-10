#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll sum (ll f, ll s)
{
    if (f == s) return f;
    
    return ((f+s)*(s-f+1))/2LL;
}

void solve ()
{
    ll n, k;
    cin >> n >> k;

    auto ok1 = [&](ll mid)
    {
        if (sum (k, mid) <= sum (mid+1, k+n-1))
            return true;
        else
            return false;
    };

    auto ok2 = [&](ll mid)
    {
        if (sum (k, mid-1) >= sum (mid, k+n-1))
            return true;
        else
            return false;
    };

    ll l = k, r = k+n;
    while (l + 1 < r)
    {
        ll mid = l+ (r-l)/2;

        if (ok1(mid))
            l = mid;
        else
            r = mid;
    }

    ll l2 = k, r2 = k+n;
    while (l2+1 < r2)
    {
        ll mid = l2 + (r2-l2)/2;

        if (ok2(mid))
            r2 = mid;
        else
            l2 = mid;
    }

    cout << min (sum (l+1, n+k-1)-sum(k, l), sum (k, r2-1)-sum (r2, n+k-1)) << endl;
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