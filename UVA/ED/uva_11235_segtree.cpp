#include <bits/stdc++.h>
 
using namespace std;
 
class SegTree{
    vector<pair<int,int>> st;
    vector<pair<int,int>> lazy;
    vector<bool> has;
    int size;
 
    pair<int,int> el_neutro = {0, 0};
 
    pair<int,int> f(pair<int,int> a, pair<int,int> b){
        return max(a,b);
    }
 
     void propagate(int sti, int stl, int str){
        if(has[sti]){
            st[sti] = lazy[sti];
            if(stl != str){
                lazy[sti*2 + 1] = lazy[sti];
                lazy[sti*2 + 2] = lazy[sti];
 
                has[sti*2 + 1] = true;
                has[sti*2 + 2] = true;
            }
            has[sti] = false;
        }
    }
 
    pair<int,int> query(int sti, int stl, int str, int l, int r){
        propagate(sti, stl, str);
 
        if(str < l || r < stl)
            return el_neutro;
 
        if(stl >= l and str <= r)
            return st[sti];
 
        int mid = (str+stl)/2;
 
        return f(query(sti*2+1,stl,mid,l,r),query(sti*2+2,mid+1,str,l,r));
    }
 
    void update_range(int sti, int stl, int str, int l,int r, pair<int,int> amm){
        propagate(sti, stl, str);
       
        if(stl >= l and str <= r){
            lazy[sti] = amm;
            has[sti] = true;
            propagate(sti, stl, str);
            return;
        }
 
        if(stl > r  or str < l)
            return;
       
        int mid = (stl + str)/2;
       
        update_range(sti*2+1,stl,mid,l,r,amm);
        update_range(sti*2+2,mid+1,str,l,r,amm);
       
        st[sti] = f(st[sti*2+1],st[sti*2+2]);
    }
 
    public:
        SegTree(int n):  st(4*n, el_neutro), lazy(4*n, el_neutro),has(4*n, false),size(n){}
       
        int query(int l, int  r){
            return query(0,0,size-1,l,r).first;
        }
       
        void update_range(int l, int r, pair<int,int> amm){
            update_range(0,0,size-1,l,r,amm);
        }
};
 
SegTree st(100001);
vector<int> in(100001);
 
int main(){
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
   
    int n,q;
    while(cin >> n, n){
        cin >> q;
        vector<pair<int,int>> freq(2);
       
        cin >> freq[1].second;
        freq[1].first++;
        in[1] = freq[1].second;
        for(int i = 2; i <= n; ++i){
            int x;
            cin >> x;
            in[i] = x;
            if(x != freq.back().second){
                freq.push_back({1,x});
            }else{
                freq.back().first++;
            }
        }
       
        int index = 1;
        st.update_range(1,1,freq[index]);
        for(int i = 2; i < in.size(); ++i){
            if(in[i-1] != in[i]) index++;
            st.update_range(i,i,freq[index]);  
        }
       
        for(int i = 0; i < q; ++i){
            int x,y;
            cin >> x >> y;
           
            if(in[x] == in[y]) cout << y-x+1 << endl;
            else{
                int total = 0;
                int lo_index = upper_bound(in.begin()+x, in.begin()+y, in[x]) - in.begin();
                int hi_index = lower_bound(in.begin()+x, in.begin()+y, in[y]) - in.begin();
                hi_index--;
               
                total = max(lo_index - x, y - hi_index);
                x = lo_index;
                y = hi_index;
               
                if(x >= y) cout <<total << endl;
                else cout << max(total, st.query(x,y)) << endl;
            }
        }
    }
   
    return 0;
}
