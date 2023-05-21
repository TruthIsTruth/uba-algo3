#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int n, m;
vector<vector<bool>> M; //Mapa de Petroleo
vector<vector<bool>> visitado; //Matriz de visitados

void dfs(pair<int,int> u){
    visitado[u.first][u.second] = true;

    for (int y = -1; y <= 1; y++) {
        for (int x = -1; x <= 1; x++) {
            if (y == 0 && x == 0) 
                continue;
            if (u.first + y < 0 || u.first + y >= n || u.second + x < 0 || u.second + x >= m)
                continue;
            pair<int,int> adj(u.first + y, u.second + x);
            if (M[adj.first][adj.second] && !visitado[adj.first][adj.second])
                dfs(adj);
        }
    }
    /* Idea */
    // dfs(make_pair(u.first-1, u.second-1));  //Top-Left
    // dfs(make_pair(u.first-1, u.second));    //Top
    // dfs(make_pair(u.first-1, u.second+1));  //Top-Right
    // dfs(make_pair(u.first, u.second-1));    //Left
    // dfs(make_pair(u.first, u.second+1));    //Right
    // dfs(make_pair(u.first+1, u.second-1));  //Bottom-Left
    // dfs(make_pair(u.first+1, u.second));    //Bottom
    // dfs(make_pair(u.first+1, u.second+1));  //Bottom-Right
}

int main() {
    while (true) {
        cin >> n >> m;
        if (n+m==0) break;

        M.assign(n, vector<bool>(m, false));
        visitado.assign(n, vector<bool>(m, false));

        int pozos = 0;
        for (int i=0; i<n; i++) {
            for (int j = 0; j < m; j++) {
                char pos; cin >> pos;
                if (pos == '@'){
                    M[i][j] = true;
                    pozos++;
                }
            }
        }

        int cc = 0;
        for (int i=0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (M[i][j] && !visitado[i][j]){
                    cc++;
                    dfs(make_pair(i,j));
                }
            }
        }
        cout << cc << endl;
    }

    return 0;
}
