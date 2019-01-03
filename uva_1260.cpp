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
 
int tc, n;
vi v;
int soma;
 
void merge(int l, int m, int r) {
    queue<int> e, d;
   
    for(int i = l; i <= m; i++)
    {
        e.push(v[i]);
    }
   
    for(int i = m+1; i <= r; i++)
    {
        d.push(v[i]);
    }
   
    int i = l;
    while(!e.empty() and !d.empty()) {
        if(e.front() <= d.front()) {
            v[i++] = e.front();
            e.pop();
            soma += (int)d.size();
        } else {
            v[i++] = d.front();
            d.pop();
        }
    }
    while(!e.empty()) v[i++] = e.front(), e.pop();
    while(!d.empty()) v[i++] = d.front(), d.pop();
   
}
 
void mergesort(int l, int r) {
    if(l == r) return;
    int m = (l + r)/2;
    mergesort(l, m);
    mergesort(m+1, r);
    merge(l, m, r);
}
 
int main() {
    cin >> tc;
    while(tc--) {
        scanf("%d", &n);
        v.resize(n+5, 0);
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &v[i]);
        }
        soma = 0;
        mergesort(0, n-1);
        printf("%d\n", soma);
    }
 
   
    return 0;
}
