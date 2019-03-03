#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
vector <int> v,v1,v2,temp;
int kutta = 0;

void decToBinary(ll n)
{
    int binaryNum[1000];
    int i = 0;
    while (n > 0) {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
    for (int j=i-1; j >= 0; j--) {
        if (kutta == 0)
            v1.pb(binaryNum[j]);
        else
            v.pb(binaryNum[j]);
    }
}

ll binToDecimal()
{
    int bilai = temp.size()-1;
    ll ans = 0;
    for (int i=0; i<temp.size(); i++) {
        ans += (temp[i]* 1LL<<bilai);//pow(2,bilai));
        bilai--;
    }
    return ans;
}

int main()
{
    int t, ks = 1;
    cin >> t;
    while (t--) {
        ll a, b;
        cin >> a >> b;
        kutta = 0;
        decToBinary(b);
        kutta = 1;
        decToBinary(a);
        int dif = v1.size()-v.size();
        for (int i=1; i<=dif; i++) {
            v2.pb(0);
        }
        for (int i=0; i<v.size(); i++) {
            v2.pb(v[i]);
        }
        int cnt = 0;
        ll prvs = 0;
        for (int i=v2.size()-1; i>=0; i--) {
            if (v2[i] == 1) {
                ll pwr = 1LL << cnt;//pow(2,cnt);
                if (pwr-prvs <= b-a) {
                    temp.pb(0);
                    prvs += pwr;
                }
                else
                    temp.pb(1);
            }
            else {
                temp.pb(0);
            }
            cnt++;
        }
        reverse(temp.begin(),temp.end());
        ll ans1 = binToDecimal();
        temp.clear();
        cnt = 0;
        prvs = 0;
        for (int i=v2.size()-1; i>=0; i--) {
            ll pwr1 = 0;
            if (v2[i] == 0) {
               pwr1 = 1LL << cnt;//pow(2,cnt);
               if (pwr1-prvs <= b-a) {
                    temp.pb(1);
               }
               else
                   temp.pb(0);
            }
            else {
                temp.pb(1);
                pwr1 = 1LL << cnt;//pow(2,cnt);
                prvs += pwr1;
            }
            cnt++;
        }
        reverse(temp.begin(),temp.end());
        ll ans2 = binToDecimal();
        printf("Case %d: %lld %lld\n",ks++, ans2, ans1);
        temp.clear();
        v1.clear();
        v2.clear();
        v.clear();
    }
    return 0;
}
