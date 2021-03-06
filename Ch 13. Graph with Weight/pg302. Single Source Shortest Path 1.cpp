#include <iostream>

static const int MAX = 100;
static const int INF = (1<<21); 
static const int WHITE = 0; 
static const int GRAY = 1;
static const int BLACK = 2; 

using namespace std;

int n;
int matrix[MAX][MAX];

void dijkstra() {
    int minv;
    int d[MAX], color[MAX];

    for (int i = 0; i < n; i++) {
        d[i] = INF;
        color[i] = WHITE;
    }

    d[0] = 0;
    color[0] = GRAY;

    while (1) {
        minv = INF;
        int u = -1;

        for (int i = 0; i < n; i++) {
            if ((minv > d[i]) && (color[i] != BLACK)) { 
                u = i;
                minv = d[i];
            }
        }

        if (u == -1) break;

        color[u] = BLACK;

        for(int v = 0; v < n; v++) {
            if ((color[v] != BLACK) && (matrix[u][v] != INF)) {
                if (d[v] > d[u] + matrix[u][v]) {
                    d[v] = d[u] + matrix[u][v];
                    color[v] = GRAY;
                }
            }
        }
    }
    
    for(int i = 0; i < n; i++) {
        cout << i << " " << (d[i] == INF ? -1 : d[i]) << endl;
    }
}

int main () {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = INF;
        }
    }

    int k, c, u, v;
    for (int i = 0; i < n; i++) {
        cin >> u >> k;
        for (int j = 0; j < k; j++) {
            cin >> v >> c;
            matrix[u][v] = c;
        }
    }

    dijkstra();

    return 0;
}
