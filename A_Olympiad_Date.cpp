#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve ()
{
    int n;
    cin >> n;
    vector<int> v(n), sr;
    for (auto &x : v) cin >> x;

    bool flg = false;
    map<int, int> mp;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        mp[v[i]]++;
        if (!flg && mp[0] >= 3 && mp[1] >= 1 && mp[2] >= 2 && mp[3] >= 1 && mp[5] >= 1)
        {
            flg = true;
            ans = i;
            break;
        }
    }
    
    if (flg) cout << ans+1 << endl;
    else cout << 0 << endl;
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