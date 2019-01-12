#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define ll long long
#define mii map<int,int>

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef set<int> si;
typedef vector<vi> vii;
typedef vector<ii> vpi;
typedef vector<ll> vll;
int oo = (1e9) + 7;
ll oo2 = 1ll*oo*oo;

int dfs_cnt;
vector<bool> visited;
vi stk, dfs_low, dfs_num;
vi g[2000*2000];
int num;

void tarjan(int u) {
    dfs_low[u] = dfs_num[u] = dfs_cnt++;
    visited[u] = true;
    stk.push_back(u);
    for(int k : g[u]) {
        if(dfs_num[k] == -1) tarjan(k);
        if(visited[k]) dfs_low[u] = min(dfs_low[u], dfs_low[k]);
    }
    if(dfs_low[u] == dfs_num[u]) {
        num++;
        while(stk.back() != u) {
            visited[stk.back()] = false;
            stk.pop_back();
        }
        visited[stk.back()] = false;
        stk.pop_back();
    }
}


int main() {
    int n, m;
    while(scanf("%d %d", &n, &m), n) {
        
        for(int i = 1; i <= n; i++)
        {
            g[i].clear();
        }
        int a, b, p;
        while(m--) {
            scanf("%d %d %d", &a, &b, &p);
            g[a].push_back(b);
            if(p == 2) g[b].push_back(a);
        }
        dfs_cnt = num = 0;
        dfs_num.assign(n+5, -1); dfs_low.assign(n+5, -1);
        visited.assign(n+5, false);
        stk.clear();
        for(int i = 1; i <= n; i++)
        {
            if(dfs_num[i] == -1) tarjan(i);
        }
        printf("%d\n", num == 1);
    }
    
    return 0;
}
