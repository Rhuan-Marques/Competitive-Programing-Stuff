#include<bits/stdc++.h>
using namespace std;

long int p[1000005];

int main(){

    int n, k, l, r, x;
    scanf("%d %d", &n, &k);
    for(int i=0; i<k; i++){
        scanf("%d %d %d", &l, &r, &x);
        p[l-1]+=x;
        p[r]-=x;
    }

    long int mxm, sum=0, keep=0;
    for(int i=0; i<n; i++){
        keep += p[i];
        sum += keep;
        if(sum > mxm || i==0){
            mxm=sum;
        }
        if(sum<0){
            sum=0;
        }
    }
    printf("%ld\n", mxm);
    return 0;
}
