#include <bits/stdc++.h>
 
using namespace std;
 
bool g[1001][1001];
int dfs_num[1001];
int dfs_low[1001];
int parent[1001];
int n,m;
 
void dfs(int v, int count){
    dfs_low[v] = dfs_num[v] = count++;
    for(int i = 1; i <= n; ++i){
        if(g[v][i]){
            if(!dfs_num[i]){
                parent[i] = v;
                dfs(i, count);
               
                if(dfs_low[i] <= dfs_num[v])
                    g[i][v] = false;
               
                dfs_low[v] = min(dfs_low[v], dfs_low[i]);
            }else if(i != parent[v]){
                dfs_low[v] = min(dfs_low[v], dfs_num[i]);
                if(dfs_num[i] < dfs_num[v])
                    g[i][v] = false;
            }
        }
    }
}
 
int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
   
    int it = 1;
    while(cin >> n >> m, n){
        memset(g, false, sizeof(g));
        memset(dfs_num, 0, sizeof(dfs_num));
        memset(dfs_low, 0, sizeof(dfs_low));
        memset(parent, -1, sizeof(parent));
       
        for(int i = 0; i < m; ++i){
            int x,y;
            cin >> x >> y;
            g[x][y] = g[y][x] = true;
        }
       
        dfs(1, 1);
       
        cout << it++ << endl << endl;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                if(g[i][j])
                    cout << i << " " << j << endl;
            }
        }
        cout << "#" << endl;
    }
   
    return 0;
}
