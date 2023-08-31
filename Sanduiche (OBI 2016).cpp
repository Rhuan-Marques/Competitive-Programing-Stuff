#include<bits/stdc++.h>
using namespace std;

int main(){
    long int n, d, i=0, j=0, som=0, cont=0;
    cin >> n >> d;
    vector<int> v(n+1);
    for(int it=0;it<n; it++){
        cin >> v[it];
    }

    while(i<n){
        som+=v[j];
        while(som>d && i!=j && i<n){
            som-=v[i];
            i++;
        }
        if(som==d && i<n){
            cont++;
        }
        if(j+1 >= n)
            j=0;
        else
            j++;
        if(j==i){
            som-=v[i];
            i++;
        }
    }
    cout << cont << endl;
}



