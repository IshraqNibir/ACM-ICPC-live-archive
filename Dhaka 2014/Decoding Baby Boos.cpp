#include <bits/stdc++.h>
#define mx 10004
using namespace std;
vector <int> g[mx];
vector <int> cost[mx];
int bfs (int s)
{
    queue <int> q;
    q.push(s);
    int prvs_cost = 0;
    int ans;
    while (!q.empty()) {
        int u = q.front();
        ans = u;
        q.pop();
        for (int i=0; i<g[u].size(); i++) {
            int v = g[u][i];
            if (cost[u][i] > prvs_cost) {
                prvs_cost = cost[u][i];
                q.push(v);
                break;
            }
        }
    }
    return ans;
}
int main()
{
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n;
        cin >> n;
        int cnt = 1;
        char ch,ch1;
        for (int i=1; i<=n; i++) {
            cin >> ch;
            cin >> ch1;
            int u = ch;
            int v = ch1;
            g[v].push_back(u);
            cost[v].push_back(cnt++);
        }
        map <int,int> my;
        for (int i=65; i<=90; i++) {
            int tmp = bfs(i);
            my[i] = tmp;
        }
        for (int i=0; i<s.length(); i++) {
            if (s[i] == '_') {
                cout << s[i];
                continue;
            }
            char fn = my[s[i]];
            cout << fn;
        }
        cout << endl;
        for (int i=0; i<mx; i++) {
            g[i].clear();
            cost[i].clear();
        }
    }
    return 0;
}
