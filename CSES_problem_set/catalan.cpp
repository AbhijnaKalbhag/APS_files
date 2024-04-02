#include<iostream>
using namespace std;
unsigned long int catalan(unsigned int n){
    if(n<=1){
        return 1;
    }
    unsigned long int res =0;
    for(int i=0;i<n;i++){
        res+=catalan(i)*catalan(n-i-1);
    }
    return res;
}
main(){
    for(int i=0;i<50;i++){
        cout<<catalan(i)<<" ";
    }
}
//challanges:
//1. as the size of sequence increases computation time increases
//2. using recusrsion puts computational overhead (stack)
//3.recomputation of numbers( extra loop) (solution -using)