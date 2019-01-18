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
    int tc;
    cin >> tc;
    while(tc--) {
        int n, m;
        scanf("%d %d", &n, &m);
        int a, b, c;
        vector<pair<int, ii>> g;
        while(m--) {
            scanf("%d %d %d", &a, &b, &c);
            a--, b--;
            g.emplace_back(c, ii(a,b));
        }
        sort(g.begin(), g.end());
        
        UnionFind uf(n);
        ii p;
        int w;
        int mst = 0;
        vector<pair<int, ii>> ms;
        for(int i = 0; i < (int)g.size(); i++)
        {
            tie(w, p) = g[i];
            if(!uf.isSameSet(p.ff, p.ss)) {
                mst += w;
                ms.emplace_back(w, ii(p.ff, p.ss));
                uf.unionSet(p.ff, p.ss);
            }
        }
        int ans = oo;
        for(int i = 0; i < (int)ms.size(); i++)
        {
            UnionFind uf2(n);
            int mst2 = 0;
            for(int j = 0; j < (int)g.size(); j++)
            {
                tie(w, p) = g[j];
                if(!uf2.isSameSet(p.ff, p.ss) and g[j] != ms[i]) {
                    mst2 += w;
                    uf2.unionSet(p.ff, p.ss);
                }
            }
            if(uf2.getNum() != 1) continue;
            ans = min(ans, mst2);
        }
        printf("%d %d\n", mst, ans);

    }


    return 0;
}
