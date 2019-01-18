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
    int numSets;
    vi p, rank, setSize;

    public:
    UnionFind(int n) {
        rank.assign(n, 0);
        numSets = n;
        setSize.assign(n, 1);
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
                setSize[findSet(x)] += setSize[findSet(y)];
                p[y] = x;
            } else {
                setSize[findSet(y)] += setSize[findSet(x)];
                p[x] = y;
                if(rank[x] == rank[y]) rank[y]++;
            }
            numSets--;
        }
    }
    int getSize(int i) {
        return setSize[findSet(i)];
    }
    int getSets() {
        return numSets;
    }
};


int main() {
    int n, m;
    int cnt = 0;
    while(scanf("%d %d", &n, &m), m) {
        cnt++;
        UnionFind UF(n);
        while(m--) {
            int a, b;
            scanf("%d %d", &a, &b);
            a--, b--;
            if(!UF.isSameSet(a, b)) UF.unionSet(a, b);
        }
        printf("Case %d: %d\n", cnt, UF.getSets());
    }    

    return 0;
}
