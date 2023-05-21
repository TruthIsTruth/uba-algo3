#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int n, m;
vector<vector<bool>> M;
vector<vector<int>> G;

int main() {
    while (true) {
        cin >> n >> m;
        if (n+m==0) break;

        M.assign(n, vector<bool>(m, false));
        map<pair<int, int>,int> coord_to_index;

        int pozos = 0;
        for (int i=0; i<n; i++) {
            for (int j = 0; j < m; j++) {
                char pos; cin >> pos;
                if (pos == '@'){
                    M[i][j] = true;
                    coord_to_index[make_pair(i,j)] = pozos;
                    pozos++;
                }
            }
        }

        G.assign(pozos, vector<int>(0));
        vector<bool> visitado(pozos, false);
        for (int i=0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (M[i][j] && !visitado[coord_to_index[make_pair(i,j)]]) {
                    visitado[coord_to_index[make_pair(i,j)]] = true;
                    if (i-1 >= 0 && M[i-1][j] && !visitado[coord_to_index[make_pair(i-1,j)]]) {
                        G[coord_to_index[make_pair(i,j)]].push_back(coord_to_index[make_pair(i-1,j)]);
                        G[coord_to_index[make_pair(i-1,j)]].push_back(coord_to_index[make_pair(i,j)]);
                    }
                    if (j-1 >= 0 && M[i][j-1] && !visitado[coord_to_index[make_pair(i,j-1)]]) {
                        
                    }
                    if (i+1 < n && M[i+1][j] && !visitado[coord_to_index[make_pair(i+1,j)]]) {
                        
                    }
                    if (j+1 < m && M[i][j+1] && !visitado[coord_to_index[make_pair(i,j+1)]]) {
                        
                    }
                }
            }
        }
        


    }

    return 0;
}