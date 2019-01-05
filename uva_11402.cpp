#include <bits/stdc++.h>
 
using namespace std;
 
#define LEFT(i) (i<<1)+1
#define RIGHT(i) (i<<1)+2
 
const int size = 1024000;
struct Node{
    int v;
    int l,r;
    char op = ' ';
};
Node st[size*4+1];
int pirates[size+1];
 
char inline change(char child, char state){
    switch(state){
        case 'F': return 'F';
        case 'E': return 'E';
        case 'I':
                switch(child){
                    case 'F': return 'E';
                    case 'E': return 'F';
                    case 'I': return ' ';
                    case ' ': return 'I';
                }
        case ' ':
                return child;
    }
}
 
void propagate(int id){
    Node &n = st[id];
    switch(n.op){
        case 'F':   n.v = (n.r - n.l + 1);
                    break;
        case 'E':   n.v = 0;
                    break;
        case 'I':   n.v = (n.r - n.l + 1) - n.v;
                    break;
    }
    st[LEFT(id)].op = change(st[LEFT(id)].op, n.op);
    st[RIGHT(id)].op = change(st[RIGHT(id)].op, n.op);
    n.op = ' ';
}
 
int query(int id, int l, int r){
    Node &n = st[id];
    propagate(id);
 
    if(l > n.r  || r < n.l)
        return 0;
   
    if(l <= n.l && r >= n.r)
        return n.v;
 
    return query(LEFT(id), l, r) +
           query(RIGHT(id), l, r);
}
 
void update_range(int id, int l, int r, char op){
    Node &n = st[id];
    propagate(id);
   
    if(l > n.r || r < n.l)
        return;
   
    if(l <= n.l && r >= n.r){
        //cout << op << endl;
        n.op = op;
        propagate(id);
        return;
    }
   
    update_range(LEFT(id), l, r, op);
    update_range(RIGHT(id), l, r, op);
   
    n.v = st[LEFT(id)].v + st[RIGHT(id)].v;
}
 
void build(int id, int lo, int hi){
    Node &n = st[id];
   
    n.l = lo;
    n.r = hi;
    n.op = ' ';
       
    if(n.l == n.r){
        n.v = pirates[n.l];
        n.op = ' ';
        return;
    }
   
    build(LEFT(id), lo, (lo+hi)>>1);
    build(RIGHT(id), ((lo+hi)>>1)+1, hi);
   
    n.v = st[LEFT(id)].v + st[RIGHT(id)].v;
}
 
int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
   
    int t;
    scanf("%d", &t);
    char repeat[80];
   
    int it = 1;
    while(t--){
        int m;
        scanf("%d", &m);
       
        int j = 0;
        while(m--){
            int n;
            scanf("%d", &n);
            scanf("%s", repeat);
           
            for(int i = 0; i < n; ++i){
                for(int k = 0; k < strlen(repeat); ++k){
                    switch(repeat[k]){
                        case '0': pirates[j] = 0;
                                    break;
                        case '1': pirates[j] = 1;
                                    break;
                    }
                    j++;
                }
            }
        }
       
        build(0,0,j);
       
        int q;
        scanf("%d", &q);
        int qr = 1;
        printf("Case %d:\n", it++);
        for(int i = 0; i < q; ++i){
            char v;
            int x,y;
            getchar();
            scanf("%c %d %d", &v, &x, &y);
           
            // for(int i = 0; i < j; ++i)
                // cout << query(0,i,i) << " ";cout << endl;
           
            switch(v){
                case 'S': printf("Q%d: %d\n", qr++, query(0,x,y));
                            break;
                default: update_range(0,x,y,v);
                            break;
            }
        }
    }
   
    return 0;
}
