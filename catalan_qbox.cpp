#include <iostream>
#include <vector>
using namespace std;

unsigned long int catalanDP(unsigned int n) {
    unsigned long int catalan[n + 1];
    catalan[0] = catalan[1] = 1;
    for (int i = 2; i <= n; i++) {
        catalan[i] = 0;
        for (int j = 0; j < i; j++)
            catalan[i] += catalan[j] * catalan[i - j - 1];
    }
    return catalan[n];
}

void countCatalanNumbers(unsigned long int l, unsigned long int r) {
    unsigned long int count = 0;
    for (unsigned long int i = 0; ; ++i) {
        unsigned long int currentCatalan = catalanDP(i);
        if (currentCatalan > r) break;
        if (currentCatalan >= l && currentCatalan <= r) {
            count++;
        }
    }
    cout << count << endl;
}

int main() {
    unsigned long int l, r;
    cin >> l >> r;
    countCatalanNumbers(l, r);
    return 0;
}
