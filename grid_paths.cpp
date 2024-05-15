#include<iostream>
using namespace std;

int main(){
    int r,c;
    cin>>r;
    cin>>c;
    char input[r][c];
    int dp[r][c];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>input[i][j];
            dp[i][j]=0;
        }
    }
    if(input[0][0]!='*'){
                dp[1][1]=1;
            }
    for(int i=1;i<r;i++){
        for(int j=1;j<c;j++){
            
            if(input[i][j]!='*'){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
    }
      for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
           cout<<dp[i][j]<<" ";
        }
        cout<<endl;

    }
    cout<<dp[r-1][c-1];
}

/*sample input:
4
4
. . . .
. * . .
. . . *
* . . .

output:
0 0 0 0
0 1 1 1
0 1 2 0
0 1 3 3
3
*/