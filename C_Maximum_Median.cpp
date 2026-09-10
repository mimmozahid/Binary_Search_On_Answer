#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for (auto &x : v) cin >> x;

    sort (v.begin(), v.end());

    auto ok = [&](int mid)
    {
        ll cnt = 0;
        
        for (int i = (n/2); i < n; i++)
        {
            cnt += (mid > v[i] ? mid-v[i] : 0);
        }
        
        return cnt <= k;
    };

    int l = 1, r = 2e9, ans;

    while (l <= r)
    {
        int mid = l + (r-l)/2;
        if (ok (mid))
        {
            ans = mid;
            l = mid+1;
        }
        else
        {
            r = mid-1;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}