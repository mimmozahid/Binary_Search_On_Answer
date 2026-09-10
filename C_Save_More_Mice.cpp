#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve ()
{
    ll n, k;
    cin >> n >> k;

    vector<ll> v(n+1);
    for (int i = 0; i < k; i++)
    {
        int x;
        cin >> x;
        v[x]++;
    }
    
    auto ok = [&](ll mid)
    {
        ll cnt = 0;
        for (int i = 0; i < mid; i++)
        {
            if (v[i] <= cnt) return false;
            cnt += (n-v[i]);
        }
        return true;
    };

    ll l = 1, r = n-1, ans = 0;
    while (l <= r)
    {
        ll mid = l + (r-l)/2;
        if (ok (mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }

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