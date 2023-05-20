#include <iostream>
#include <vector>
#include <utility>

using namespace std;
/*
void sortRelacionPrecioPeso(vector<pair<int, int>> &objetos){
    for (int i = 0; i < objetos.size()-1; i++)
    {
        float minRel = ((float) objetos[i].first) / ((float) objetos[i].second);
        int indexMin = i;
        for (int j = i+1; j < objetos.size(); j++)
        {
            float rel = ((float) objetos[j].first) / ((float) objetos[j].second);
            if (rel < minRel){
                minRel = rel;
                indexMin = j;
            }
        }
        //swap
        if (indexMin != i) {
            pair<int, int> temp = objetos[i];
            objetos[i] = objetos[indexMin];
            objetos[indexMin] = temp;
        }
    }
}*/

int calcularMaximoMonto(vector<int>& precios, vector<int>& pesos, vector<int>& capacidades) {
    int maxMonto = 0;
    for (int i = 0; i < capacidades.size(); i++)
    {
        maxMonto += maxMontoPersona(precios, pesos, capacidades);
    }
    
    return 0;
}

int main () {
    int t; cin >> t;
    
    while (t--) {
        vector<int> precios, pesos, capacidades;
        int n, g; 
        cin >> n;
        while (n--)
        {
            int precio, peso;
            cin >> precio >> peso;
            precios.push_back(precio);
            pesos.push_back(peso);
        }
        cin >> g;
        while (g--)
        {
            int capacidad_amigo; cin >> capacidad_amigo;
            capacidades.push_back(capacidad_amigo);
        }
        
        int maxMonto = calcularMaximoMonto(precios, pesos, capacidades);
        cout << maxMonto << endl;
    }

    return 0;
}