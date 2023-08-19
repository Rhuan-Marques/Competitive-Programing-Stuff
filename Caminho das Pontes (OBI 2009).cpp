#include<bits/stdc++.h>
using namespace std;

class Pilar{
    public:
    int n=-1;
    class Ponte{
        public:
        Pilar* p;
        int bur=0;
    };
    vector<Ponte> con;
    int consize = 0;

    void add_ponte(Pilar* x, int n){
        Ponte aux;
        aux.p = x;
        aux.bur = n;
        consize++;
        con.push_back(aux);
    }

    void spread(){
        for(int i=0; i<consize; i++){
            if(n + con[i].bur < con[i].p->n || con[i].p->n  == -1){
                con[i].p->n = n + con[i].bur;
                con[i].p->spread();
            }
        }
    }
};

int main(){
    int n, k;
    cin >> n >> k;
    vector<Pilar> map(n+2);
    int a, b, c;
    while(k--){
        cin >> a >> b >> c;
        map[a].add_ponte(&map[b], c);
        map[b].add_ponte(&map[a], c);
    }
    map[0].n = 0;
    map[0].spread();
    cout << map[n+1].n << endl;
}
