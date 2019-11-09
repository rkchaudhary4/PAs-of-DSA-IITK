#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int merge_count_inv(long long a[],int p,int q,int r){
    vector<long long> L;
    vector<long long> R;
    for(int i=p;i<=q;i++){
        L.push_back(a[i]);
    }
    L.push_back(pow(10.0,15));
    for(int i=q+1;i<=r;i++){
        R.push_back(a[i]);
    }
    R.push_back(pow(10.0,15));
    int l=0,r1=0,count=0;
    for(int i=p;i<=r;i++){
        if(L[l]<=R[r1]){
            a[i]=L[l];
            l++;
        }else{
            a[i]=R[r1];
            count+=q-p+1-l;
            r1++;
        }
    }
    return count;
}

int merge_sort_count_inv(long long a[], int p,int r){
    int lcount_inv=0, rcount_inv=0, cross_inv=0;
    if(p<r){
        int q=(p+r)/2;
        lcount_inv=merge_sort_count_inv(a,p,q);
        rcount_inv=merge_sort_count_inv(a,q+1,r);
        cross_inv=merge_count_inv(a,p,q,r);
    }
    return lcount_inv+rcount_inv+cross_inv;
}

int main(){
    int t;
    cin>>t;
    for(;t;t--){
        int n;
        cin>>n;
        long long a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        cout<<merge_sort_count_inv(a,0,n-1)<<endl;
    }
    return 0;
}

/*theta(nlogn) */