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


int n, k, m;
ll tb[55][55][55];


ll dp(int i, int num, int w) {
    if(num > k or w > m) return 0;
    if(i == n and num == k) return 1;
    if(i == n) return 0;
    if(tb[i][num][w] != -1) return tb[i][num][w];

    ll ans = dp(i+1, num, w+1) + dp(i+1, num+1, 1);

    tb[i][num][w] = ans;
    return ans;
}

int main() {
    while(scanf("%d %d %d", &n, &k, &m) != EOF) {
        memset(tb, -1, sizeof tb);
        printf("%lld\n", dp(1, 1, 1));
    }   
}
