#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t, ks = 1;
    cin >> t;
    while (t--) {
        ll e, p, k, r;
        cin >> e >> p >> k >> r;
        ll ini = e - (p * k);
        ll swp = 0, temp, dif;
        ll red = p * k;
        if (ini <= 0) {
            ll kutta = e / p;
            if (e % p != 0)
                kutta++;
            printf ("Case %d: %lld\n", ks++, kutta);
            swp = 0;
            continue;
        }
        else {
            swp = 1;
            temp = ini + r;
            temp = temp - (p*k);
            if (temp >= ini) {
                printf ("Case %d: -1\n", ks++);
                continue;
            }
            else  {
                dif = ini - temp;
                if (temp >= 0) {
                    swp += (ini / dif);
                    if (swp >= 2)
                        red += ((swp-1)*dif);
                }
            }
        }
        ll ans = swp * k;
        ll remn = e - red;
        if (remn > 0)
            remn += r;
        ans += (remn / p);
        if (remn % p != 0 )
            ans++;
        printf ("Case %d: %lld\n", ks++, ans);
    }
    return 0;
}
