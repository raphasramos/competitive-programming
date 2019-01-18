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
};


int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        int s, p;
        scanf("%d %d", &s, &p);
        
        vpi v;
        int a, b;
        for(int i = 0; i < p; i++)
        {
            scanf("%d %d", &a, &b);
            v.emplace_back(a, b);
        }
        
        vector<pair<double, ii>> edges;
        for(int i = 0; i < (int)v.size()-1; i++)
        {
            
            for(int j = i+1; j < (int)v.size(); j++)
            {
                double dist = sqrt( (v[i].ff-v[j].ff)*(v[i].ff-v[j].ff) + 
                                    (v[i].ss-v[j].ss)*(v[i].ss-v[j].ss));
                edges.emplace_back(dist, ii(i,j));
            }
        }
        sort(edges.begin(), edges.end());
        UnionFind uf(p);
        ii pr;
        double ans = 0;
        double dt;
        deque<double> dq;
        for(int i = 0; i < (int)edges.size(); i++)
        {
            tie(dt, pr) = edges[i];
            if(!uf.isSameSet(pr.ff, pr.ss)) {
                uf.unionSet(pr.ff, pr.ss);
                dq.push_back(dt);
            }
        }
        for(int i = 0; i < s-1; i++)
        {
            dq.pop_back();
        }
        
        printf("%.2lf\n", dq.back());
    }


    return 0;
}
