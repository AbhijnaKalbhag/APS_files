#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n=4,max_cost=10;
    vector<int>costs={4,8,5,3};
    vector<int>pages={5,12,8,1};
    vector<int>dp(max_cost+1,-1);
    dp[0]=0;
    int j;
    for(int i=0;i<n;i++){
        j=max_cost-costs[i];
        for(int k=j;k>=0;k--){
            if(dp[k]>-1){
                dp[k+costs[i]]=max(dp[k+costs[i]],dp[k]+pages[i]);
            }
        }
    }
    for(int i=1;i<=max_cost;i++){
       dp[i]=max(dp[i],dp[i-1]);
    }
    for(int i=0;i<max_cost+1;i++){
        cout<<dp[i]<<" ";
    }
}