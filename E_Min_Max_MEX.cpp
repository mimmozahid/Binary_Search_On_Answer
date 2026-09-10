#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve ()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (auto &i : v) cin >> i;

    // auto ok = [&](ll mid)
    // {
    //     ll as = 0;
    //     set<ll> st;
    //     ll mex = 0;
    //     for (int i = 0; i < n; i++)
    //     {
    //         bool fnd = false;

    //         if (mex == v[i])
    //         {
    //             st.insert (v[i]);
    //             fnd = true;
    //         }
    //         else
    //         {
    //             st.insert (v[i]);
    //         }

    //         ll p = mex;
    //         if (fnd)
    //         {
    //             while (st.find (p) != st.end())
    //             {
    //                 p++;
    //             }
    //             mex = p;
    //             fnd = false;
    //         }
            
    //         if (mex == mid)
    //         {
    //             as++;
    //             mex = 0;
    //             st.clear();
    //         }
    //     }

    //     if (as >= k)
    //        return true;
        
    //     return false;
    // };

    auto ok = [&](int mid)
    {
        ll as = 0;
        vector<int> frq(mid, 0);
        int cnt = mid;

        for (auto i : v)
        {
            if (i < mid && !frq[i])
            {
                cnt--;
                frq[i] = 1;
            }
            
            if (!cnt)
            {
                as++;
                fill (frq.begin (), frq.end (), 0);
                cnt = mid;
            }
        }
        return as >= k;
    };

    ll l = 0, r = n+1, ans = 0;
    while (l + 1 < r)
    {
        ll mid = l + (r - l)/2;
        if (ok (mid))
        {
            ans = mid;
            l = mid;
        }
        else
            r = mid;
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