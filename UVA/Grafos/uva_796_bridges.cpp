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

const int N = 10005; // Who knows...
int n;
vi g[N];
vi dfs_low(N), dfs_num(N), dfs_parent(N);
int dfs_cnt;
vpi ans;

void dfs(int v) {
    dfs_num[v] = dfs_low[v] = dfs_cnt++;
    for(int k : g[v]) {
        if(dfs_num[k] == -1) {
            dfs_parent[k] = v;
            dfs(k);

            if(dfs_low[k] > dfs_num[v]) v > k ? ans.emplace_back(k, v) : ans.emplace_back(v, k);

            dfs_low[v] = min(dfs_low[v], dfs_low[k]);
        } else if(k != dfs_parent[v]) {
            dfs_low[v] = min(dfs_low[v], dfs_num[k]);
        }
    }
}

int main() {
    while(scanf("%d", &n) != EOF) {
        if(n == 0) {
            puts("0 critical links");
            puts("");
            continue;
        }
        
        for(int i = 0; i < n; i++)
        {
            g[i].clear();
        }
        int a, b, c;
        for(int i = 0; i < n; i++)
        {
            scanf("%d (%d)", &a, &c);
            while(c--) {
                scanf("%d", &b);
                g[a].push_back(b);
                g[b].push_back(a);
            }
        }
        dfs_num.assign(n+5, -1); dfs_low.assign(n+5, -1);
        dfs_parent.assign(n+5, -1);
        dfs_cnt = 0;
        ans.clear();
        
        for(int i = 0; i < n; i++)
        {
            if(dfs_num[i] == -1) {
                dfs(i);
            }
        }
        printf("%d critical links\n", (int)ans.size());
        sort(ans.begin(), ans.end());
        
        for(ii k : ans) {
            printf("%d - %d\n", k.ff, k.ss);
        }
        puts("");
    }
}
