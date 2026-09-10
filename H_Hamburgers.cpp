#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    ll n_b, n_s, n_c;
    ll p_b, p_s, p_c;
    ll rob;

    cin >> s;
    cin >> n_b >> n_s >> n_c;
    cin >> p_b >> p_s >> p_c;
    cin >> rob;

    ll B = 0, S = 0, C = 0;
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (s[i] == 'B') B++;
        else if (s[i] == 'C') C++;
        else if (s[i] == 'S') S++;
    }

    auto ok = [&](ll mid)
    {
        ll needb = max (0LL, (B*mid) - n_b);
        ll needc = max (0LL, (C*mid) - n_c);
        ll needs = max (0LL, (S*mid) - n_s);

        ll total_cost = needb*p_b + needc*p_c + needs*p_s;

        return total_cost <= rob;
    };


    ll l = 0, r = 1e14, ans = 0;
    while (l+1 < r)
    {
        ll mid = l + (r-l)/2;

        if (ok (mid))
        {
            ans = mid;
            l = mid;
        }
        else
            r = mid;
    }

    cout << ans << endl;
    
    return 0;
}