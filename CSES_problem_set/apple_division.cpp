#include<iostream>
#include<vector>
using namespace std;


long long int min_sum(int i,vector<int>a,long long int sum1,long long int sum2,int n){
    if(i==n){
        return abs(sum1-sum2);
    }
    long long int choose=min_sum(i+1,a,sum1+a[i],sum2,n);

    long long int not_choose=min_sum(i+1,a,sum1,sum2+a[i],n);

    return min(choose,not_choose);
    
}

int main(){
 int n,k;
 cin>>n;
 vector<int>a;
 for ( int i = 0; i < n; i++)
 {
    cin>>k;
    a.push_back(k);
 }
 long long int sum1=0,sum2=0;
 cout<<min_sum(0,a,sum1,sum2,n);
 
}
