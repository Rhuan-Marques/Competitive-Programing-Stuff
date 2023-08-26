#include<bits/stdc++.h>
using namespace std;

class Player{
    public:
        long int point;
        long int tree_rank = 0;
        long int rafa = 0;
        Player* parent = this;
        Player* last_save = this;
        Player* root(){
            if(parent == this)
                return this;
            else if(last_save == this){
                last_save = parent->root();
                return last_save;
            }
            else
                return last_save->root();
        }
};

void fuse(Player* a, Player* b){
    if(a->tree_rank > b->tree_rank){
        swap(a, b);
    }
    else if(a->tree_rank == b->tree_rank){
        b->tree_rank++;
    }
    a->parent = b;
    b->rafa += a->rafa;
    b->point += a->point;
    return;
}


int main(){
    long int n, m;
    while(scanf("%ld %ld", &n, &m) && (n!=0 && m!=0)){
        long int rafa_w=0;
        vector<Player> v(n+1);
        for(long int i=1; i<=n; i++){
            scanf("%d", &v[i].point);
        }
        v[1].rafa=1;
        int q, a, b;
        for(long int i=0; i<m; i++){
           scanf("%d %d %d", &q, &a, &b);
           Player *pa = v[a].root(), *pb = v[b].root();
            if(q==1){
                fuse(pa, pb);
            }
            else{
                if(pa->point > pb->point && pa->rafa)
                    rafa_w++;
                else if(pa->point < pb->point && pb->rafa)
                    rafa_w++;
                
            }
        }
        cout << rafa_w << endl;
    }
    
}
