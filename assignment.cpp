#include<iostream>
#include<math.h>
#include <algorithm>
using namespace std;

int N=3;
int cost[3][3]={{3,2,7},
                {5,1,3},
                {2,7,2}};
int count_set_bits(int N){
    int count=0;
    while(N>0){
        if(N&1>0){
            count++;
        }
        N>>=1;
    }
    return count;
}

int main(){
    int n=pow(2,N);
    int dp[n];
    for(int i=0;i<n;i++){
        dp[i]=INT_MAX;
    }
    dp[0]=0;
    int k;
    for(int mask=0;mask<n;mask++){
        int x=count_set_bits(mask);
         k=mask;
         k<<=1;
        for(int j=0;j<N;j++){
            if(!(k&1<<j)){
            dp[mask | 1<<j]=min(dp[mask | 1<<j],dp[mask]+cost[x][j]);
            }
            k<<=1;
    
        }
       
    }

    cout<<"Cost : "<<dp[n-1];
}