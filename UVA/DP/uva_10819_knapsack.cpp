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
 
int tb[10205][105];
int m, n;
int tmp;
vi p, f;
 
int dp(int money, int i) {
    if(money > tmp and money <= 2000 and i == n) return -oo;
    if(i == n or money == m) return 0;
    if(tb[money][i] != -1) return tb[money][i];
 
    int ans = dp(money, i+1);
    if(money + p[i] <= m) ans = max(ans, dp(money + p[i], i+1) + f[i]);
 
    tb[money][i] = ans;
    return ans;
}
 
int main() {
    while(scanf("%d %d", &m, &n) != EOF) {
        p.assign(n+5, 0);
        f.assign(n+5, 0);
       
        for(int i = 0; i < n; i++)
        {
            scanf("%d %d", &p[i], &f[i]);
        }
        memset(tb, -1, sizeof tb);
        tmp = m;
        if(m + 200 > 2000) m += 200;
        printf("%d\n", dp(0, 0));
    }
}
