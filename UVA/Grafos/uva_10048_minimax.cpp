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

class UnionFind {
    private:
    vi p, rank, maxEl;
    int numSets;

    public:
    UnionFind(int n) {
        rank.assign(n, 0);
        p.resize(n);
        for(int i = 0; i < n; i++) p[i] = i;
    }
    int findSet(int i) {
        return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    }
    bool isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }

    void unionSet(int i, int j) {
        if(!isSameSet(i, j)) {
            int x = findSet(i), y = findSet(j);
            if(rank[x] > rank[y]) {
                // maxEl[findSet(x)] = max(maxEl[findSet(x)], maxEl[findSet(y)]);
                p[y] = x;
            } else {
                p[x] = y;
                if(rank[x] == rank[y]) rank[y]++;
            }
            numSets--;
        }
    }
};


int main() {
    int c, s, q;
    int cnt = 0;
    while(scanf("%d %d %d", &c, &s, &q), q) {
        if(cnt) puts("");
        cnt++;
        vector<pair<int, ii>> g;
        int a, b, w;
        while(s--) {
            scanf("%d %d %d", &a, &b, &w);
            a--, b--;
            g.emplace_back(w, ii(a,b));
        }
        sort(g.begin(), g.end());
        
        ii p;
        UnionFind uf(c);
        vpi g2[105];
        for(int i = 0; i < (int)g.size(); i++)
        {
            tie(w, p) = g[i];
            if(!uf.isSameSet(p.ff, p.ss)) {
                uf.unionSet(p.ff, p.ss);
                g2[p.ff].emplace_back(w, p.ss);
                g2[p.ss].emplace_back(w, p.ff);
            }
        }
        printf("Case #%d\n", cnt);
        while(q--) {
            scanf("%d %d", &a, &b);
            a--, b--;
            if(!uf.isSameSet(a, b)) {
                puts("no path");
            } else {
                queue<int> fila;
                vi d(c+5, -oo);            
                d[a] = 0;
                fila.push(a);
                while(!fila.empty()) {
                    int u = fila.front();
                    fila.pop();
                    for(auto edge : g2[u]) {
                        if(d[edge.ss] == -oo) {
                            d[edge.ss] = max(d[u], edge.ff);
                            fila.push(edge.ss);
                        }
                    }
                }
                printf("%d\n", d[b]);
            }
        }
    }


    return 0;
}
