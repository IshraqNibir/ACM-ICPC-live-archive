#include <bits/stdc++.h>
using namespace std;
bool right(char ch)
{
    if(ch=='>' || ch=='}' || ch==']' || ch==')')
        return true;
    else
        return false;
}
bool left(char ch)
{
    if(ch=='<' || ch=='{' || ch=='[' || ch=='(')
        return true;
    else
        return false;
}
bool check(char a,char b)
{
    if(a=='{' && b=='}')
        return true;
    else if(a=='[' && b==']')
        return true;
    else if(a=='(' && b==')')
        return true;
    else if(a=='<' && b=='>')
        return true;
    else
        return false;
}
int main()
{
    int t,ks=1;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        int len=s.length();
        stack<char>st;
        stack<int>ct;
        int cnt=0;
        int ans[100007];
        memset(ans,0,sizeof(ans));
        for(int i=len-1;i>=0;i--) {
            if(right(s[i])) {
                st.push(s[i]);
                ct.push(cnt);
                cnt=0;
            }
            else {
                if(st.empty()) {
                    cnt=0;
                    continue;
                }
                else if(!check(s[i],st.top())) {
                    while(!st.empty())
                        st.pop();
                    while(!ct.empty())
                        ct.pop();
                    cnt=0;
                    continue;
                }
                else {
                    st.pop();
                    cnt += ct.top();
                    ct.pop();
                    cnt += 2;
                    ans[i] = cnt;
                }
            }
        }
        printf("Case %d:\n",ks++);
        for(int i=0;i<s.length();i++) {
            cout<<ans[i]<<endl;
        }
    }
    return 0;
}
