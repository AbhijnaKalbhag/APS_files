#include<iostream>
using namespace std;
unsigned long int dp[101];


main(){
    dp[0]=1;
    dp[1]=1;
    cout<<dp[0]<<" ";
    cout<<dp[1]<<" ";
    for(int i=2;i<=100;i++){
        for(int j=0;j<i;j++){
            dp[i]+=dp[j]*dp[i-j-1];
            
        }
       // cout<<dp[i]<<" ";
    }
    cout<<dp[99];
}
