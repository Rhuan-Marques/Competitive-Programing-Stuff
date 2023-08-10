#include<bits/stdc++.h>
using namespace std;

int main(){
    unsigned long long int n, k, som=0, low=0, resp=0, counter=0;
    unsigned long long int* before, *after;
    cin >> n >> k;
    vector<unsigned long long int> v(n), truezero(n);
    vector<unsigned long long int*> zero(n);

    for(unsigned long int i=0; i<n; i++){
        cin >> v[i];
        som+=v[i];
        zero[i] = NULL;
        if(som>k){
            for(low; low<=i && som > k; low++)
                som-=v[low];
        }
        if(som==k && !(som==0 && v[i] != 0)){
            resp++;
            if(zero[low] != NULL) resp+=(*zero[low]);
        }


        if(v[i] == 0){
            zero[i] = &truezero[counter];
            (*zero[i])++;
            //cout << "debug " << *zero[i] << endl;
        }
        else{
            zero[i] = NULL;
            //before = &truezero[counter];
            counter++;
            //after = &truezero[counter-1];
            
        }

    }
    /*
    for(int i=0; i<zero.size(); i++){
        if(zero[i] != NULL) cout << (*zero[i]) << " ";
        else cout << "NULL" << " ";
    }
    */
    cout << resp << endl;
}
