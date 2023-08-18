#include<bits/stdc++.h>
using namespace std;

class Point{
    public:
    Point* p = this;

    Point* last(){
        if(p == this) return p;
        else return p->last();
    }
};


int main(){
    long int n, k;
    cin >> n >> k;
    vector<long int> z(n+2);

    vector<Point> v(n+2);
    for(int i=1; i<=n; i++){
        z[i] = i;
        v[i].p = &v[i];

    }
    int a, b;
    char c;
    while(k--){
        cin >> c >> a >> b;
        if(c == 'F'){
            Point *aux = v[b].last();
            v[b].last()->p = (v[a]).last();
        }
        else if(v[a].last() == v[b].last()) cout << "S" << endl;
        else cout << "N" << endl;
    }
}
