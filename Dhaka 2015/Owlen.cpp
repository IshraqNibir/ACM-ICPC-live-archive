#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, ks=1;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        map <char,int> my;
        for(int i=0; i<s.length(); i++) {
            my[s[i]]++;
        }
        int mn=10000000;
        for(int i=97; i<=122; i++) {
            char ch=i;
            mn=min(mn,my[ch]);
        }
        printf("Case %d: %d\n",ks++, mn);
    }
    return 0;
}
