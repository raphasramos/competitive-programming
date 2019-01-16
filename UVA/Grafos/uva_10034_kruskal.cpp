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

    void unionSet(int i, int j) {
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
    int tc = 0;
    cin >> tc;
    int cnt = 0;
    while(tc--) {
        int n;
        if(cnt) puts("");
        cnt++;
        scanf("%d", &n);
        double a, b;
        vector<pair<double, ii>> g;
        vector<pair<double, double>> v;
        for(int i = 0; i < n; i++) {
            scanf("%lf %lf", &a, &b);
            v.emplace_back(a, b);
        }
        
        for(int i = 0; i < (int)v.size()-1; i++)
        {
            for(int j = i+1; j < (int)v.size(); j++)
            {
                double dist = sqrt( (v[i].ff-v[j].ff)*(v[i].ff-v[j].ff) + 
                                    (v[i].ss-v[j].ss)*(v[i].ss-v[j].ss));
                g.emplace_back(dist, make_pair(i, j));
            }
        }
        UnionFind UF(n);
        sort(g.begin(), g.end());
        double cost = 0;
        double w;
        ii p;
        for(int i = 0; i < (int)g.size(); i++)
        {
            tie(w, p) = g[i];
            if(!UF.isSameSet(p.ff, p.ss)) {
                cost += w;
                UF.unionSet(p.ff, p.ss);
            }
        }
        printf("%.2lf\n", cost);
    }


    return 0;
}
