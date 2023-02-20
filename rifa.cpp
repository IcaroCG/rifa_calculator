// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

double produtorio (int produtado, int indice){
    //max = quantidade de numeros
    //n = qrd de sorteios
    //t = qtd de tickets possuidos
    //cout << "---- produtado: " << produtado << endl;
    //cout << "---- indice: " << indice << endl;
    double total=1;
    for(int i = 0; i < indice; i++){
        double atual;
        atual = produtado-i;
        //cout << "--- atual " << i << ": " << produtado << endl;
        total = total*atual;
    }
    
    return total;
}

unsigned long long
choose(unsigned long long n, unsigned long long k) {
    if (k > n) {
        return 0;
    }
    unsigned long long r = 1;
    for (unsigned long long d = 1; d <= k; ++d) {
        r *= n--;
        r /= d;
    }
    return r;
}

double outros (int max, double n, int t, int x = 1){
    //max = quantidade de numeros
    //n = qrd de sorteios
    //t = qtd de tickets possuidos
    //x = qtd de premios que quer ganhar
    int y=x-1;
    double total = 0;
    if(y >= 0 ){
        unsigned long long comb = choose(n, y);
        //cout << "comb: " << comb << endl;
        
        double prod_ganhos = produtorio(t,y);
        //cout << "ganhos: " << prod_ganhos << endl;
        
        double prod_perdas = produtorio(max-n,t-y);
        //cout << "perdas: " << prod_perdas << endl;
        
        double prod_denominador = produtorio(max,t);
        //cout << "denominador: " << prod_denominador << endl;
        
        total = comb*prod_ganhos*prod_perdas/prod_denominador;
        //cout << "teste 3 outros: " << total << "\n";
        total += outros(max, n, t, x-1);
        //return total;
    }
    return total;
}

int max (vector<double> vetor){
    int max = 0.0;
    for (int i = 0; i<vetor.size(); i++){
        if(vetor[i] > max) max = i;
    }
    return max;
}

int main() {
    
    //cout << 2000*1999*1998 <<endl;
    int max = 200;
    int n = 2;
    int x = 1;
    int t = 3;
    vector<pair<int,double>> valores;
    //cout << "teste 1\n";
    //vector<double> eficiencia;
    
    if (t != 0) {
        double chance = 1-outros(max, n, t, x);
        cout << setprecision(4) << fixed << t << ": " << chance*100 << "%\n\n";
    }
    
    for(int i = 0; i < max; i++) {
        //cout << "teste 2:" << i << "\n";
        double chance = 1-outros(max, n, i, x);
        //cout << chance << endl;
        //cout << "teste 4\n\n";
        //if (chance >= 0.99999) break;
        //valores.push_back(make_pair(i,chance));
        //eficiencia.push_back(chance/i);
        cout << setprecision(4) << fixed << i << ": " << chance*100 << "%\n\n";
    }
    //cout << max(eficiencia) << endl;
    
    //cout << *max_element(eficiencia.begin(), eficiencia.end()) << endl;
    
    for(int i = 0; i < valores.size(); i++)
    cout << valores[i].first << ": " << valores[i].second *100 << "%\n";
    cout << "foi";

    return 0;
}
