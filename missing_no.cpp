#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    long long n;
    cin>>n;
    vector<long long>a;
    long long k;
    for(int i=0;i<n-1;i++){
        cin>>k;
        a.push_back(k);
    }
    sort(a.begin(),a.end());
    for(long long i=0;i<n;i++){
        if(a[i]!=i+1){
            cout<<i+1;
            break;
        }
    }


}