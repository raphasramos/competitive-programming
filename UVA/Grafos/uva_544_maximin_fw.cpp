#include <bits/stdc++.h>
using namespace std;
 
#define ff first
#define ss second
#define ll long long
 
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef set<int> si;
typedef vector<vi> vii;
typedef vector<ii> vpi;
typedef vector<ll> vll;
int oo = (1e9) + 7;
ll oo2 = 1ll*oo*oo;

int dist[205][205];
int main() {
    int n, r;
    int cnt = 0;
    while(scanf("%d %d", &n, &r), r) {
        if(cnt) puts("");
        cnt++;
        map<string, int> mp;
        string a, b;
        int w;
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                dist[i][j] = -oo;
            }
            
        }
        while(r--) {
            cin >> a >> b >> w;
            if(!mp.count(a)) mp[a] = (int)mp.size();
            if(!mp.count(b)) mp[b] = (int)mp.size();
            dist[mp[a]][mp[b]] = dist[mp[b]][mp[a]] = w;
        }
        
        for(int i = 0; i < n; i++)
        {
            dist[i][i] = 0;
        }
        
        for(int k = 0; k < n; k++)
        {
            
            for(int i = 0; i < n; i++)
            {
                
                for(int j = 0; j < n; j++)
                {
                    dist[i][j] = max(dist[i][j], min(dist[i][k], dist[k][j]));
                }
                
            }
            
        }
        cin >> a >> b;
        printf("Scenario #%d\n%d tons\n", cnt, dist[mp[a]][mp[b]]);
        
    }


    return 0;
}
