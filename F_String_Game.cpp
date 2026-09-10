#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string t, p;
    cin >> t >> p;

    int n = t.size(), m = p.size();

    int x;
    vector<int> idx;
    while (cin >> x)
    {
        idx.push_back (x);
    }
    
    auto ok = [&](int mid)
    {
        bool flg = false;
        vector<bool> del(n+1);
        for (int i = 0; i < mid; i++)
        {
            del[idx[i]] = true;
        }
        
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            if (t[i] == p[j] & !del[i+1])
            {
                j++;
            }

            if (m == j)
            {
                flg = true;
                break;
            }
        }
        return flg;
    };

    int l = 0, r = n-1, ans = 0;
    while (l <= r)
    {
        int mid = l + (r-l)/2;

        if (ok(mid))
        {
            ans = mid;
            l = mid+1;
        }
        else
            r = mid-1;
    }

    cout << ans << endl;

    return 0;
}