#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
int main()
{
    while(1) {
        int n, q, a, b, r;
        scanf ("%d %d", &n, &q);
        if (n==0 && q==0)
            break;
        vector< pair<int,int> >v;
        for (int i=1; i<=n; i++) {
            scanf ("%d %d", &a, &b);
            v.pb (make_pair(a,b));
        }
        vector <int> v1[3005];
        for (int i=0; i<n; i++) {
            int st = v[i].first;
            int ed = v[i].second;
            for (int j=0; j<n; j++) {
                int st1 = v[j].first;
                int ed1 = v[j].second;
                int dis = ((st-st1)*(st-st1)) + ((ed-ed1)*(ed-ed1));
                int dis1 = sqrt(dis);
                if (dis1*dis1<dis)
                    dis1++;
                v1[i].pb(dis1);
            }
        }
        for (int i=0; i<n; i++)
            sort (v1[i].begin(), v1[i].end());
        for (int i=1; i<=q; i++) {
            scanf ("%d", &r);
            double sum = 0;
            for (int j=0; j<n; j++) {
                int up = upper_bound(v1[j].begin(),v1[j].end(),r)-v1[j].begin();
                sum += up;
            }
            //cout << sum << endl;
            sum = (sum*1.0/n);
            printf ("%0.2lf\n",sum);
        }
        printf("\n");
    }
    return 0;
}
