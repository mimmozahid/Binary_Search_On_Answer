#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int m, n;
    cin >> m >> n;
    vector<tuple<int, int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[i] = make_tuple(a, b, c);
        // v[i] = {a, b, c};
    }
    
    vector<int> ans_a(n);
    auto ok = [&](int time)
    {
        vector<int> may(n);
        int has = m;
        for (int i = 0; i < n; i++)
        {
            auto [t, z, y] = v[i];
            
            int total, make_ball, remain, curr;

            total = (t*z)+y;
            make_ball = time/total;
            remain = time%total;

            curr = (make_ball*z) + min (z, remain/t);
            curr = min (curr, has);
            has -= curr;
            may[i] = curr;
        }
        
        if (!has)
        {
            ans_a = may;
        }

        return !has;
    };

    int l = 0, r = 1e8, ans = 0;
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

    for (auto x : ans_a) cout << x << " ";
    cout << endl;
    
    return 0;
}