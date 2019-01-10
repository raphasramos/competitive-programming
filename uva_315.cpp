#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define ll long long
#define pq priority_queue
#define mii map<int,int>

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef set<int> si;
typedef vector<vi> vii;
typedef vector<ii> vpi;
typedef vector<ll> vll;
int oo = (1e9) + 7;

vi g[105];
int dfs_cnt;
vi dfs_num(105, -1), dfs_low(105, 0), dfs_parent(105, -1);
vector<bool> articulation;
int root, children;

void dfs(int u) {
    dfs_low[u] = dfs_num[u] = dfs_cnt++;
    for(int k : g[u]) {
        if(dfs_num[k] == -1) { // Checa se não foi visitado
            dfs_parent[k] = u;
            if(u == root) children++;

            dfs(k);
            if(dfs_low[k] >= dfs_num[u]) { // remover u desconecta o grafo
            // Não consegue chegar nos ancestrais de u, visto que um vértice w com dfs_num(w) 
            // menor que dfs_num(u) implica que w é ancestral de u na DFS spanning tree
            // (Bridge: dfs_low(k) > dfs_num[u]: u -- k)
                articulation[u] = true;
            }
            dfs_low[u] = min(dfs_low[u], dfs_low[k]);
        } else if (k != dfs_parent[u]) { // Se não for outra direção da aresta bidirecional
            dfs_low[u] = min(dfs_low[u], dfs_num[k]); 
        } // Não vamos atualizar o dfs_low do pai de u, pois pai de u pode atingir dfs_num menores.
    }
}
 
int main() {
    int n = 1;
    while(1) {
        scanf("%d", &n);
        if(n == 0) break;

        int m;
        int d;
        while(scanf("%d", &m), m) {
            while(cin.peek() != '\n'){
                scanf("%d", &d);
                
                g[m].push_back(d);
                g[d].push_back(m);
            }
        }
        dfs_cnt = 0; dfs_num.assign(n+5, -1); dfs_low.assign(n+5, 0);
        dfs_parent.assign(n+5, 0); articulation.assign(n+5, false);
        for(int i = 1; i <= n; i++) // Vértices
        {
            if(dfs_num[i] == -1) {
                root = i; children = 0;
                dfs(i);
                articulation[i] = (children > 1);
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++)
        {
            if(articulation[i]) ans++;
        }
        printf("%d\n", ans);
        for(int i = 0; i <= 100; i++)
        {
            g[i].clear();
        }
    }
}
