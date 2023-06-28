/*Uma função que mostre na tela a cardinalidade do conjunto.*/
#include <iostream>
#include <vector> // Biblioteca padrão de vetores em C++
#include <algorithm> // Biblioteca com funções úteis para vetores em C++

using namespace std;

int cardinalidade(vector<int> conjunto) { // Função cardinalidade
    return conjunto.size(); // Retorna o tamanho do vetor
}

int main() {
    vector<int> conjunto; // Cria um conjunto/vetor inteiro vazio conjunto

    cout << "Digite os elementos do conjunto (-1 para parar):" << endl;
    while (true) { // Loop infinito
        int numero; // Variável para armazenar um número/elemento para o conjunto
        cin >> numero; // Recebe e armazena o valor digitado pelo usuário
        if (numero == -1) { // Verifica se o número digitado é -1
            break; // Se sim, sai do loop
        }
        conjunto.push_back(numero); // Adiciona o número digitado ao final do vetor conjunto
    }

    sort(conjunto.begin(), conjunto.end()); // Ordena o vetor conjunto
    conjunto.erase(unique(conjunto.begin(), conjunto.end()), conjunto.end()); // Remove elementos repetidos do vetor conjunto

    cout << "\nConjunto = {";
    for (int i = 0; i < conjunto.size(); i++) { // Estrutura de repetição para percorrer o conjunto
        cout << conjunto[i]; // Mostra o número que está na atual posição do vetor conjunto
        if (i < conjunto.size() - 1) { // Verifica se o elemento não é o último
            cout << ", "; // Mostra uma vírgula caso não esteja no último elemento
        }
    }
    cout << "}" << endl;

    cout << "Cardinalidade do conjunto = " << cardinalidade(conjunto) << endl; // Mostra a cardinalidade do conjunto
}