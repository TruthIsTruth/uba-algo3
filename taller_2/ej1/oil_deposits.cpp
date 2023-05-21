#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <stack>

using namespace std;

enum {BLANCO, GRIS, NEGRO};
int n, m;
vector<vector<bool>> M; //Mapa de Petroleo
vector<vector<int>> color; //Matriz de visitados

int dfs(pair<int,int> u){
    color[u.first][u.second] = GRIS;
    if (!M[u.first][u.second]){
        color[u.first][u.second] = NEGRO;
        return 0;
    }

    for (int y = -1; y <= 1; y++) {
        for (int x = -1; x <= 1; x++) {
            if (y == 0 && x == 0) 
                continue;
            if (u.first + y < 0 || u.first + y >= n || u.second + x < 0 || u.second + x >= m)
                continue;
            pair<int,int> coord;
        }
    }
    

    dfs(make_pair(u.first-1, u.second-1));  //Top-Left
    dfs(make_pair(u.first-1, u.second));    //Top
    dfs(make_pair(u.first-1, u.second+1));  //Top-Right
    dfs(make_pair(u.first, u.second-1));    //Left
    dfs(make_pair(u.first, u.second+1));    //Right
    dfs(make_pair(u.first+1, u.second-1));  //Bottom-Left
    dfs(make_pair(u.first+1, u.second));    //Bottom
    dfs(make_pair(u.first+1, u.second+1));  //Bottom-Right

    color[u] = NEGRO;
    
}

int main() {
    while (true) {
        cin >> n >> m;
        if (n+m==0) break;

        M.assign(n, vector<bool>(m, false));
        C.assign(n, vector<int>(m, BLANCO));
        
        //map<pair<int, int>,int> coord_to_index;

        int pozos = 0;
        for (int i=0; i<n; i++) {
            for (int j = 0; j < m; j++) {
                char pos; cin >> pos;
                if (pos == '@'){
                    M[i][j] = true;
                    //coord_to_index[make_pair(i,j)] = pozos;
                    pozos++;
                }
            }
        }

        int cc = 0;
        for (int i=0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cc += dfs(make_pair(i,j));
            }
        }
        


    }

    return 0;
}
