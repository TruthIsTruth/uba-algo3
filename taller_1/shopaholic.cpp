#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int calcularMaximoDescuento(vector<int>& precios){
    int r = 0;
    int prod_gratis = precios.size()-3;
    while (prod_gratis >= 0)
    {
        r += precios[prod_gratis];
        prod_gratis -= 3;
    }
    return r;
}

int main () {
    int t; cin >> t;
    
    while (t--) {
        vector<int> precios;
        int n; cin >> n;
        while (n--)
        {
            int precio_i; cin >> precio_i;
            precios.push_back(precio_i);
        }
        sort(precios.begin(), precios.end());
        int maxDescuento = calcularMaximoDescuento(precios);
        cout << maxDescuento << endl;
    }

    return 0;
}