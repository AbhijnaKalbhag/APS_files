#include <iostream>
#include <vector>
#include <limits.h>
#include <bitset>
using namespace std;

int assignment(int cost[3][3], int n) {
    vector<int> dp(1 << n, INT_MAX);
    dp[0] = 0;
    int x, y;
    string mask;
    int intmask;

    for (int i = 0; i < (1 << n); i++) {
        x = __builtin_popcount(i);
        mask = bitset<10>(i).to_string().substr(10 - n); 
        intmask = stoi(mask, 0, 2);

        for (int j = 0; j < n; j++) {
            if (mask[n - j - 1] != '1') {
                y = (intmask | (1 << j));
                dp[y] = min(dp[y], dp[intmask] + cost[x][j]);
            }
        }
    }

    return dp[(1 << n) - 1];
}

int main() {
    int n = 3;
    int cost[3][3] = {{3, 2, 7}, {5, 1, 3}, {2, 7, 2}};
    cout << assignment(cost, n);
    return 0;
}
