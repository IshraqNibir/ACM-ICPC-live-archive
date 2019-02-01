#include <bits/stdc++.h>
using namespace std;
int visited[1005],node[1005];
vector<int>adj[1005],jacky[1005];
int k;
void dfs(int at)
{
    if(visited[at])
        return;

    visited[at]=1;

    for(int i=0;i<adj[at].size();i++) {
        int v=adj[at][i];
        dfs(v);
        if(node[v]!=0)
            jacky[at].push_back(node[v]);
    }

    sort(jacky[at].begin(),jacky[at].end());

    reverse(jacky[at].begin(),jacky[at].end());

    if(jacky[at].size()==0 || jacky[at].size()<k)
        node[at]=1;

    else if(jacky[at].size()>=k)
    {
        for(int j=0;j<k;j++)
            node[at]+=jacky[at][j];
        node[at]++;
    }
}

int main()
{

    int t,ks=1;
    cin>>t;
    while(t--)
    {
        int n,u,v;
        cin>>n>>k;
        for(int i=1;i<1005;i++)
            node[i]=0;
        memset(visited,0,sizeof(visited));
        for(int i=1;i<n;i++) {
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(1);
        //cout<<node[4]<<endl;
       // if(node[1]==0)
            //node[1]=1;
        printf("Case %d: %d\n",ks++,node[1]);
        for(int i=0;i<1005;i++) {
            adj[i].clear();
            jacky[i].clear();
        }
    }
    return 0;
}
/*
9 3
1 2
1 3
1 4
2 5
5 9
3 6
3 7
3 8
*/


