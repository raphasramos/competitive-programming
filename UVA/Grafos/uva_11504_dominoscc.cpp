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

const int N = 100005;
vi g[N];
int n, m;
vi dfs_num(N), dfs_low(N);
vector<bool> visited(N);
vi stk;
int dfs_cnt;
int cnt;
int scc[N];
struct Aresta {
    int x;
    int y;
};

void dfs(int u) {
    dfs_num[u] = dfs_low[u] = dfs_cnt++;
    visited[u] = true;
    stk.push_back(u);
    for(int k : g[u]) {
        if(dfs_num[k] == -1) dfs(k);
        if(visited[k]) dfs_low[u] = min(dfs_low[u], dfs_low[k]);
    }

    if(dfs_low[u] == dfs_num[u]) {
        cnt++;
        while(stk.back() != u) {
            visited[stk.back()] = false;
            scc[stk.back()] = cnt;
            stk.pop_back();
        }
        scc[u] = cnt;
        visited[u] = false;
        stk.pop_back();
    }
}

int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        scanf("%d %d", &n, &m);
        int a, b;
        
        for(int j = 1; j <= n; j++)
        {
            g[j].clear();
        }
        vector<Aresta> edges;
        while(m--) {
            scanf("%d %d", &a, &b);
            g[a].push_back(b);
            edges.push_back({a, b});
        }
        dfs_low.assign(n+5, -1); dfs_num.assign(n+5, -1);
        visited.assign(n+5, false);
        dfs_cnt = cnt = 0;
        int ans = 0;
        
        for(int v = 1; v <= n; v++)
        {
            if(dfs_num[v] == -1) dfs(v);
        }
        vi in(n+5, 0);
        for(auto w : edges) {
            if(scc[w.x] != scc[w.y]) {
                in[scc[w.y]]++;
            }
        }
        
        for(int cc = 1; cc <= cnt; cc++)
        {
            if(in[cc] == 0) ans++;
        }
        printf("%d\n", ans);
    }
    

    return 0;
}
