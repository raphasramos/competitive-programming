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
 
int n;
double dist[15][15];
double tb[10][1<<10];
int calc[10][1<<10];
int aux[10][1<<10];
vector<ii> d;
 
double dp(int v, int mask) {
    if(mask == (1 << n)-1) return 0; // Todos visitados, retornou pra origem
    if(calc[v][mask]) return tb[v][mask];
 
    double ans = 1e9;
   
    for(int i = 0; i < n; i++)
    {
        if(mask & (1 << i)) continue;
        double tmp = dist[v][i] + dp(i, mask | (1 << i));
        if(tmp < ans) {
           ans = tmp;
           aux[v][mask] = i;
        }
    }
 
    calc[v][mask] = 1;
    tb[v][mask] = ans;
    return ans;
}
 
void build(int v, int mask) {
    if(mask == (1 << n)-1) return;
 
    printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n",
                d[v].ff, d[v].ss, d[aux[v][mask]].ff, d[aux[v][mask]].ss, dist[v][aux[v][mask]]);
    build(aux[v][mask], mask | (1<<aux[v][mask]));
}
 
int main() {
    int cnt = 0;
    while(scanf("%d", &n)) {
        if(n == 0) break;
        cnt++;
        int a, b;
        d.resize(n+5);
        for(int i = 0; i < n; i++)
        {
            scanf("%d %d", &a, &b);
            ii p = make_pair(a, b);
            d[i] = p;
        }
       
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                dist[i][j] = sqrt((d[i].ff- d[j].ff)*(d[i].ff - d[j].ff)+
                                          (d[i].ss-d[j].ss)*(d[i].ss-d[j].ss)) + 16.0;
            }
            dist[i][i] -= 16.0;  
        }
        // for(int i = 0; i < n; i++)
        // {
        //     for(int j = 0; j < n; j++)
        //     {
        //         printf("dist[%d,%d][%d,%d]=%f\n", v[i].ff, v[i].ss, v[j].ff, v[j].ss,
        //                             dist[i][j]);
        //     }  
        // }
        double ans = 2e9;
       
        int mn = 0;
        memset(calc, 0, sizeof calc);
        for(int i = 0; i < n; i++)
        {
            double tmp = dp(i, 1<<i);
            if(ans > tmp) {
                mn = i;
                ans = tmp;
            }
        }
        puts("**********************************************************");
        printf("Network #%d\n", cnt);
        build(mn, 1 << mn);
        printf("Number of feet of cable required is %.2lf.\n", ans);
    }
 
}
