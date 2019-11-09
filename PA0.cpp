#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int n;
    cin>>n;
    long f1=0,f2=1,f,sum=0;
    if(n>=2)sum+=1;
    for(int i=3;i<=n;i++){
        f=f1+f2;
        sum+=f;
        f1=f2;
        f2=f;
    }
    cout<<sum;
    return 0;
}