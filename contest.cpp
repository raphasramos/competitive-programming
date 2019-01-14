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

const int N = 10005;
vi g[N];
int n, m;
vector<bool> visited;
int ans;

void bfs(int u) {
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        int cur = 0;
        for(int k : g[v]) {
            if(!visited[k]) {
                cur = 1;
                visited[k] = true;
                q.push(k);
            } 
        }
        ans += cur;
    }
}

int main() {
    int tc;
    cin >> tc;
    for(int i = 1; i <= tc; i++) {
        scanf("%d %d", &n, &m);
        int a, b;
        
        for(int j = 1; j <= n; j++)
        {
            g[j].clear();
        }
        
        while(m--) {
            scanf("%d %d", &a, &b);
            g[a].push_back(b);
            g[b].push_back(a);
        }
        visited.assign(n+5, false);
        ans = 0;
        
        for(int k = 1; k <= n; k++)
        {
            if(!visited[k]) bfs(k);
        }
        
        printf("Case %d: %d\n", i, ans);
    }   
    

    return 0;
}