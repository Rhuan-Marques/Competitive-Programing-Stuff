#include<bits/stdc++.h>
using namespace std;

class Pont{
    public:
    long int p=0;
    int id= 0;
};

class Jogador{
    public:
    vector<Pont*> coloc;

    long int ptotal(int k){
        long int soma=0;
        for(int i=0; i<coloc.size(); i++){
            if(coloc[i]->id <= k)
                soma += (coloc[i]->p);
        }
        return soma;
    }
};

vector<long int> checkbest(vector<Jogador> v, int k){
    vector<long int> winners;
    long int best=0;
    for(int i=1; i<v.size(); i++){
        long int aux = v[i].ptotal(k);
        if(aux >= best){
            if(aux>best){
                winners.clear();
                best=aux;
            }
            winners.push_back(i);
        }
    }
    return winners;

}

int main(){
    long int g, p, s, k, aux;
    while(cin >> g >> p && (g!=0 && p!=0)){
        vector<Pont> placar(p+1);
        vector<Jogador> player(p+1);
        vector<long int> result;
        for(int i=0; i<g; i++){
            for(int ii=1; ii<=p; ii++){
                placar[ii].id = ii;
                cin >> aux;
                player[ii].coloc.push_back(&placar[aux]);
            }
        }
       
        cin >> s;
        while(s--){
            cin >> k;
            for(int i=1; i<=k; i++){
                cin >> aux;
                placar[i].p = aux;
            }
            result.clear();
            result = checkbest(player, k);
            for(int i=0; i<result.size(); i++){
                if(i>0) cout << " ";
                cout << result[i];
            }
            cout << endl;
        }
    }
}
