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
    void UnionSet(int i, int j) {
        if(!isSameSet(i, j)) {
            int x = findSet(i), y = findSet(j);
            if(rank[x] > rank[y]) {
                p[y] = x;
            } else {
                p[x] = y;
                if(rank[x] == rank[y]) rank[y]++;
            }
        }
    }

};

int main() {
    int tc;
    cin >> tc;
    
    for(int t = 0; t < tc; t++)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        int a, b, w;
        vector<pair<int, ii>> g;
        while(m--) {
            scanf("%d %d %d", &a, &b, &w);
            g.emplace_back(w, ii(a,b));
        }
        sort(g.rbegin(), g.rend());
        UnionFind uf(n);
        ii p;
        int ans = oo;
        for(int i = 0; i < (int)g.size(); i++)
        {
            tie(w, p) = g[i];
            if(!uf.isSameSet(p.ff, p.ss)) {
                ans = min(ans, w);
                uf.UnionSet(p.ff, p.ss);
            }
        }
        printf("Case #%d: %d\n", t+1, ans);
    }
        


    return 0;
}
