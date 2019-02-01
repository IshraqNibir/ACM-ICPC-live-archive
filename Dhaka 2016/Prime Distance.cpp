#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 100005
#define mod 1000000007
int ara[sz];
ll jacky[sz],rifa[sz],tani[sz];
vector<int>v;
ll power(ll x, ll y,  ll m)
{
    if (y == 0)
        return 1;
    ll p = power(x, y/2, m) % m;
    p = (p * p) % m;

    return (y%2 == 0)? p : (x * p) % m;
}

ll modInverse(ll a, ll m)
{
     ll p = power(a, m-2, m);
     return p;
}

void sieve()
{
    int i,j,root;
    for(i=2;i<=sz;i++){
        ara[i]=1;
    }
    root=sqrt(sz);
    for(i=2;i<=root;i++){
        if(ara[i]==1){
            for(j=2;i*j<=sz;j++){
                ara[i*j]=0;
            }
        }
    }
    for(int i=2;i<=sz;i++)
        if(ara[i]==1)
            v.push_back(i);
}

void precal_for_2()
{
    memset(jacky,0,sizeof(jacky));
    ll prvs=0;
    for(int i=1;i<=sz;i++)
    {
        if(ara[i-1]==1) {
            prvs++;
            jacky[i] = ((jacky[i-1]%mod) + (prvs%mod))%mod;
        }
        else
            jacky[i] = ((jacky[i-1]%mod) + (prvs%mod))%mod;
    }
}

void precal_for_3()
{
    memset(rifa,0,sizeof(rifa));
    for(int i=2;i<v.size();i++)
    {
        for(int j=0;j<i;j++)
        {
            int pr=v[i]-v[j];
            if(ara[pr])
                rifa[v[i]+1]++;
        }
    }
    ll prv=0;
    for(int i=6;i<=sz;i++) {
        if(rifa[i]>0) {
            prv = ((prv%mod) +  (rifa[i]%mod))%mod;
            rifa[i] = ((rifa[i-1]%mod) + (prv%mod))%mod;
        }
        else
            rifa[i] = ((rifa[i-1]%mod) + (prv%mod))%mod;
    }
}

void count_four()
{
    ll prvs=1;
    memset(tani,0,sizeof(tani));
    for(int i=4;i<=sz;i++)
    {
        ll jog=((prvs%mod) * ((prvs+1)%mod) * (modInverse(2, mod)%mod))%mod;
        tani[i]=((tani[i-1]%mod) + (jog%mod))%mod;
        prvs++;
    }
}

int main()
{
    int i,j,t,ks=1;
    sieve();
    precal_for_2();
    precal_for_3();
    count_four();
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        ll one=n;
        ll two=((jacky[n]%mod) * ((m-1)%mod))%mod;
        ll three=((m-2) * (m-1))/2%mod;
        three=((three%mod)*(rifa[n]%mod))%mod;
        ll four=0;
        if(n>=8)
            four=(((n-8+1)%mod) * (tani[m]%mod))%mod;
        ll ans1=((one%mod) + (two%mod))%mod;
        ll ans2=((three%mod) + (four%mod))%mod;
        ll ans=((ans1%mod) + (ans2%mod))%mod;
        printf("Case %d: %lld\n",ks++,ans%mod);
    }
    return 0;
}

