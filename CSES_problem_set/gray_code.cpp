#include<iostream>
#include<cmath>
#include<bitset>
using namespace std;

// Function to convert binary to Gray code
int binaryToGray(int binary) {
    return binary ^ (binary >> 1);
}

int main() {
    int n, i = 0;
    cin >> n;
    string mask;

    while (i < pow(2, n)) {
        int grayCode = binaryToGray(i);

    
        bitset<32> binaryRepresentation(grayCode);
        mask = binaryRepresentation.to_string().substr(32 - n);

        cout << mask << endl;
        i++;
    }

    return 0;
}
