#include <bits/stdc++.h>
#define ll long long
#define mx 20000005
using namespace std;
ll ara[mx];
void precal()
{
    ara[0] = 0;
    for (int i=1; i<mx; i++) {
        ara[i] = ara[i-1]+i;
    }
}
int main()
{
    precal();
    while (1) {
        int n;
        cin >> n;
        if (n == 0)
            break;
        ll sum = 0;
        for (int i=1; i<=sqrt(n); i++) {
            ll temp1 = n/i;
            sum += (temp1*i);
        }
        int sz = sqrt(n);
        for (int i=sqrt(n); i>=1; i--) {
            int div = n/i;
            ll temp = ara[div]-ara[sz];
            if (temp>0)
                sum += (temp*i);
            sz = div;
        }
        cout << sum-1 << endl;
    }
    return 0;
}
