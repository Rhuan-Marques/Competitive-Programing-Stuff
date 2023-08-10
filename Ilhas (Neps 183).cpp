#include<bits/stdc++.h>
using namespace std;

#define lint long long int
class Ilha{
    public:
        class Conexao{
            public:
                Ilha* isle;
                int ping;
        };


        vector<Conexao> lig;
        lint dist = -1;

        void connect(Ilha* i, int p){
            Conexao aux;
            aux.isle = i;
            aux.ping = p;
            lig.push_back(aux);
            //x->connect(this, p);
        }

        long int propag(lint d){
            dist = d;
            for(int i=0; i<lig.size(); i++){
                unsigned long long int next = (lig[i].isle)->dist;
                if(next == -1 || (dist + lig[i].ping < next)) (lig[i].isle)->propag(dist + lig[i].ping);
            }
            return 0;
        }
};


int main(){
    long int n, m, a, b, p, r;
    cin >> n >> m;
    vector<Ilha> v(n+1);
    for(int i=0; i<m; i++){
        cin >> a >> b >> p;
        v[a].connect(&v[b], p);
        v[b].connect(&v[a], p);
    }
    cin >> r;
    v[r].propag(0);
    lint top=-1, bot=9999999999999;
    for(int i=1; i<=n; i++){
        //cout << i << " - " << v[i].dist << endl;
        top=max(v[i].dist, top);
        if(v[i].dist>0) bot=min(v[i].dist, bot);
    }
    //cout << top << " " << bot;
    cout << top-bot << endl;
}
