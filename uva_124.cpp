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

int N;
char a, b, c;
string line;
vector<char> elements;
vector<char> g[55];
map<char, bool> vis;
string cts;

 
bool valid(char e) {
    
    for(int i = 0; i < (int)g[e-'a'].size(); i++)
    {
        if(vis[g[e-'a'][i]]) return false;
    }
    return true;
}

bool dfs(string path) {
    if(path.size() == elements.size()) {
        cout << path << endl;
        return true;
    }
    bool ans = false;
    
    for(int i = 0; i < (int)elements.size(); i++)
    {
        if(!vis[elements[i]] and valid(elements[i])) {
            vis[elements[i]] = true;
            ans |= dfs(path + elements[i]);
            vis[elements[i]] = false;
        }
    }
    return ans;
}
 
int main() {
    int cnt = 0;
    while(getline(cin, line)) {
        if(cnt) puts("");
        elements.clear();
        
        for(int i = 0; i < 55; i++)
        {
            g[i].clear();
        }
        
        for(size_t i = 0; i < line.size(); i+=2)
        {
            elements.push_back(line[i]);
        }
        sort(elements.begin(), elements.end());
        getline(cin, cts);
        
        for(size_t i = 0; i < cts.size(); i+=4)
        {
            g[cts[i]-'a'].push_back(cts[i+2]);
        }
        if(!dfs("")) puts("NO");
        cnt++;
    }
}
