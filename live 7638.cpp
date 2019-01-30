#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int high = 1e6+5;

bitset<high>bs;

int prm[high], plen=0 , par[high], visited[high] , ar[high];

void CLR()
{
    for(int i=0; i<high; i++)
    {
        par[i] = i;
        visited[i] = 0;
    }
}

void sieve()
{
    LL i, j;

    bs.set();
    bs[0] = bs[1] = 0;

    for(i=2; i<high; i++)
    {
        if(bs[i])
        {
            prm[plen++] = i;

            for(j=2*i; j<high; j+=i)
            {
                bs[j] = 0;
            }
        }
    }

    //for(i=0; i<100; i++) cout << prm[i] << "; ";
}

int findd(int n)
{
    if(n == par[n]) return n;
    return par[n] = findd(par[n]);
}

void unionn(int a , int b)
{
    int u = findd(a);
    int v = findd(b);

    if( u == v ) return;
    else par[v] = u;
}

void Facto(int n)
{
    int x = n;

    for(int i=0; prm[i] * prm[i] <= n; i++)
    {
        if(n % prm[i] == 0)
        {
            while(n % prm[i] == 0)
            {
                n /= prm[i];
            }

            unionn(x , prm[i]);
        }
    }

    if(n > 1)
    {
        unionn(x , n);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    sieve();
    int X , N , i , test, tc=0;
    cin >> test;
    while(test--)
    {
        CLR();

        cin >> N;

        int cnt = 0;

        for(i=1; i<=N; i++)
        {
            cin >> X;

            ar[i] = X;

            if(X == 1) cnt+=1;

            if(!bs[X])
            {
                Facto(X);
            }
        }

        for(i=1; i<=N; i++)
        {
            if(ar[i] > 1)
            {
                int lastParent = findd(ar[i]);

                if(!visited[lastParent]) cnt+=1;

                visited[lastParent] = 1;
            }
        }

        cout << "Case " << ++tc << ": " << cnt << "\n";
    }

    return 0;
}
