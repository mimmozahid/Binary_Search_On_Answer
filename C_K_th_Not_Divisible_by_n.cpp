#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve ()
{
    int n, k;
    cin >> n >> k;

    auto ok = [&](int mid)
    {
        return (mid - (mid/n)) >= k;
    };

    int l = 1, r = 2e9, ans = 0;
    while (l <= r)
    {
        int mid = l + (r-l)/2;

        if (ok(mid))
        {
            ans = mid;
            r = mid-1;
        }
        else
            l = mid+1;
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