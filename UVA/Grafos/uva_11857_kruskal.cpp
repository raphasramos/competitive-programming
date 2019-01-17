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
    vi p, rank;
    int numSets;

    public:
    UnionFind(int n) {
        rank.assign(n, 0);
        p.resize(n);
        numSets = n;
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
                p[y] = x;
            } else {
                p[x] = y;
                if(rank[x] == rank[y]) rank[y]++;
            }
            numSets--;
        }
    }
    int getNum() {
        return numSets;
    }
};


int main() {
    int n, m;
    while(scanf("%d %d", &n, &m), n) {
        if(m == 0) {
            puts("IMPOSSIBLE");
            continue;
        }
        int a, b, w;
        vector<pair<int, ii>> g;
        while(m--) {
            scanf("%d %d %d", &a, &b, &w);
            g.emplace_back(w, ii(a,b));
        }
        UnionFind uf(n);
        sort(g.begin(), g.end());
        ii p;
        int ans = 1;
        for(int i = 0; i < (int)g.size(); i++)
        {
            tie(w, p) = g[i];
            if(!uf.isSameSet(p.ff, p.ss)) {
                ans = max(ans, w);
                uf.unionSet(p.ff, p.ss);
            }
        }
        uf.getNum() != 1 ? puts("IMPOSSIBLE") : printf("%d\n", ans);
    }


    return 0;
}
