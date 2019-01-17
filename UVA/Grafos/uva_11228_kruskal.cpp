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
    int tc = 0;
    cin >> tc;
    for(int c = 1; c <= tc; c++) {
        int n, r;
        scanf("%d %d", &n, &r);
        UnionFind uf(n), st(n);
        vpi v;
        while(n--) {
            int x, y;
            scanf("%d %d", &x, &y);
            v.emplace_back(x, y);
        }
        vector<pair<double, ii>> g;
        for(int i = 0; i < (int)v.size()-1; i++)
        {
            
            for(int j = i+1; j < (int)v.size(); j++)
            {
                double dist = sqrt((v[i].ff-v[j].ff)*(v[i].ff-v[j].ff)+
                                    (v[i].ss-v[j].ss)*(v[i].ss-v[j].ss));
                if(dist <= r) {
                    st.unionSet(i, j);
                }
                g.emplace_back(dist, ii(i, j));
            }
        }
        sort(g.begin(), g.end());
        double dt;
        ii p;
        double roads = 0;
        double rails = 0;
        for(int i = 0; i < (int)g.size(); i++)
        {
            tie(dt, p) = g[i];
            if(!uf.isSameSet(p.ff, p.ss)) {
                st.isSameSet(p.ff, p.ss) ? roads+=dt : rails+=dt;
                uf.unionSet(p.ff, p.ss);
            }
        }
        printf("Case #%d: %d %d %d\n", c, st.getNum(), (int)round(roads), (int)round(rails));
    }


    return 0;
}
