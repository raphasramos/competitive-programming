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

int main() {
    int n;
    cin >> n;
    
    for(int c = 0; c < n; c++)
    {
        string s;
        cin >> s;
        
        vi cnt(30, 0);
        stack<int> pilha;
        pilha.push(s[0]-'A');
        for(size_t i = 1; i < s.size(); i++)
        {
            if(s[i]-'A' == pilha.top()) {
                cnt[s[i]-'A']++;
                pilha.pop();
                if((int)pilha.size()) cnt[pilha.top()]++;
            } else {
                pilha.push(s[i]-'A');
            }
        }
        printf("Case %d\n", c+1);
        cnt[s[0]-'A']--;
        for(int j = 0; j <= 26; j++)
        {
            if(cnt[j]) printf("%c = %d\n", j+'A', cnt[j]);
        }   
    }
    
    

    return 0;
}
