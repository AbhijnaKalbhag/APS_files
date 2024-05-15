#include <iostream>

using namespace std;

bool colorGraph(int **G, int color[], int pos, int c, int V) {
    if(color[pos] != -1 && color[pos] !=c)
        return false;

    color[pos] = c;
    bool ans = true;
    for(int i = 0; i < V; i++) {
        if(G[pos][i]) {
            if(color[i] == -1)
                ans &= colorGraph(G, color, i, 1 - c, V);

            if(color[i] !=-1 && color[i] != 1 - c)
                return false;
        }
        if (!ans)
            return false;
    }

    return true;
}

bool isBipartite(int **G, int V) {
    int color[V];
    for(int i = 0; i < V; i++)
        color[i] = -1;
        int pos = 0;
    return colorGraph(G, color, pos, 1, V);
}

int main() {
    int q;
    cin >> q;

    while(q--) {
        int r, c;
        cin >> r >> c;
        int **G = new int*[r];
        for(int i = 0; i < r; i++) {
            G[i] = new int[c];
            for(int j = 0; j < c; j++) {
                cin >> G[i][j];
            }
        }
        isBipartite(G, r) ? cout << "1\n" : cout << "0\n";
        for(int i = 0; i < r; i++) {
            delete[] G[i];
        }
        delete[] G;
    }
    return 0;
}
