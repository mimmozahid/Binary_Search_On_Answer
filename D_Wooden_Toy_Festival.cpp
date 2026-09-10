#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve ()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &x : v) cin >> x;

    sort (v.begin(), v.end());

    auto ok = [&](int time)
    {
        int worker = 1, l = 0;
        for (int r = 0; r < n; r++)
        {
            if (v[r]-v[l] > 2*time)
            {
                worker++;
                l = r;
            }
        }
        
        return worker <= 3;
    };

    int l = 0, r = 1e9, ans;

    while (l <= r)
    {
        int mid = l + (r-l)/2;
        if (ok(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
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