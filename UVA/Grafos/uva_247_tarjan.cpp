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
 
vector<string> g[25*25];
map<string, int> mp;
vector<bool> visited;
vi dfs_num, dfs_low;
vector<string> ans;
int dfs_cnt;
 
 
void tarjan(string s) {
    int vrt = mp[s];
    dfs_num[vrt] = dfs_low[vrt] = dfs_cnt++;
 
    ans.push_back(s);
    visited[vrt] = true;
    for(string k : g[vrt]) {
        int v = mp[k];
        if(dfs_num[v] == -1) { 
            tarjan(k);
        }
        if(visited[v]) dfs_low[vrt] = min(dfs_low[vrt], dfs_low[v]);
    }
    if(dfs_low[vrt] == dfs_num[vrt]) { // Raiz da SCC
        while(ans.back() != s) {
            string aux = ans.back();
            ans.pop_back();
            visited[ mp[aux] ] = false;
            cout << aux << ", ";
        }
        cout << ans.back() << "\n";
        visited[vrt] = false;
        ans.pop_back();
    }
}
 
int main() {
    int n, m;
    int cnt = 0;
    while(scanf("%d %d", &n, &m) == 2) {
        if(n == 0 and m == 0) break;
        cnt++;
        if(cnt > 1) puts("");
        printf("Calling circles for data set %d:\n", cnt);
        mp.clear();
 
        for(int i = 0; i <= n; i++)
        {
            g[i].clear();
        }
 
        string s1, s2;
        while(m--) {
            cin >> s1 >> s2;
            if(!mp.count(s1)) mp[s1] = (int)mp.size();
            if(!mp.count(s2)) mp[s2] = (int)mp.size();
            g[mp[s1]].push_back(s2);
        }
        dfs_cnt = 0;
        dfs_num.assign(n+5, -1); dfs_low.assign(n+5, -1);
        visited.assign(n+5, false);
        ans.clear();
 
        for(auto &k : mp) {
            if(dfs_num[k.ss] == -1) tarjan(k.ff);
        }
    }
}
