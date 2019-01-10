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

int tc;
int sum;
int c;
vi v(105);
ii tb[10005][105];

ii dp(int a, int i) {
    if(a >= sum) return make_pair(0, 0);
    if(i == c) return make_pair(oo, oo);
    if(tb[a][i].ff != -1) return tb[a][i];

    ii ans = dp(a+v[i], i+1);
    ans.ff += v[i];
    ans.ss++;
    ans = min(ans, dp(a, i+1));


    tb[a][i] = ans;
    return ans;
}

int main() {
    cin >> tc;
    while(tc--) {
        scanf("%d %d", &sum, &c);
        v.resize(c+5);
        
        for(int i = 0; i < c; i++)
        {
            scanf("%d", &v[i]);
        }
        memset(tb, -1, sizeof tb);
        ii res = dp(0, 0);
        printf("%d %d\n", res.ff, res.ss);
    }    

}
