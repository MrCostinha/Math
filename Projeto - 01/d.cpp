/*Uma função intersecção que irá ser chamada para realizar a intersecção dos 
seguintes conjuntos A e B.*/
#include <iostream>
#include <vector> // Biblioteca padrão de vetores em C++
#include <algorithm> // Biblioteca com funções úteis para vetores em C++

using namespace std;

vector<int> interseccao(vector<int> A, vector<int> B) { // Função intersecção
    vector<int> AiB; // Cria um conjunto/vetor inteiro vazio da intersecçãoo de A com B
    int a = 0, b = 0; // Índices para percorrerem os vetores A e B simultâneamente

    while (a < A.size() && b < B.size()) {
        if (A[a] < B[b]) { // Verifica se o elemento do vetor A é menor que o elemento do vetor B
            a++; // Incrementa o índice do vetor A
        } else if (A[a] > B[b]) { // Verifica se o elemento do vetor B é menor que o elemento do vetor A
            b++; // Incrementa o índice do vetor B
        } else { // Se não, os elementos são iguais
            AiB.push_back(A[a]); // Adiciona o elemento ao final do vetor AiB
            a++; // Incrementa o índice do vetor A
            b++; // Incrementa o índice do vetor B
        }
    }

    sort(AiB.begin(), AiB.end()); // Ordena o vetor AiB
    AiB.erase(unique(AiB.begin(), AiB.end()), AiB.end()); // Remove elementos duplicados

    return AiB; // Retorna o vetor AiB
}

int main() {
    vector<int> A; // Cria um conjunto/vetor inteiro vazio A
    vector<int> B; // Cria um conjunto/vetor inteiro vazio B

    cout << "Digite os elementos do conjunto A (-1 para parar):" << endl;
    while (true) { // Loop infinito
        int numero; // Variável para armazenar um número/elemento para o conjunto A
        cin >> numero; // Recebe e armazena o valor digitado pelo usuário
        if (numero == -1) { // Verifica se o número digitado é -1
            break; // Se sim, sai do loop
        }
        A.push_back(numero); // Adiciona o número digitado ao final do vetor A
    }
    cout << "Digite os elementos do conjunto B (-1 para parar):" << endl;
    while (true) { // Loop infinito
        int numero; // Variável para armazenar um número/elemento para o conjunto B
        cin >> numero; // Recebe e armazena o valor digitado pelo usuário
        if (numero == -1) { // Verifica se o número digitado é -1
            break; // Se sim, sai do loop
        }
        B.push_back(numero); // Adiciona o número digitado ao final do vetor B
    }

    sort(A.begin(), A.end()); // Ordena o vetor A
    A.erase(unique(A.begin(), A.end()), A.end()); // Remove elementos repetidos do vetor A
    sort(B.begin(), B.end()); // Ordena o vetor B
    B.erase(unique(B.begin(), B.end()), B.end()); // Remove elementos repetidos do vetor B

    cout << "\nConjunto A = {";
    for (int i = 0; i < A.size(); i++) { // Estrutura de repetição para percorrer o conjunto A
        cout << A[i]; // Mostra o número que está na atual posição do vetor A
        if (i < A.size() - 1) { // Verifica se o elemento não é o último
            cout << ", "; // Mostra uma vírgula caso não esteja no último elemento
        }
    }
    cout << "}" << endl;
    cout << "Conjunto B = {";
    for (int i = 0; i < B.size(); i++) { // Estrutura de repetição para percorrer o conjunto B
        cout << B[i]; // Mostra o número que está na atual posição do vetor B
        if (i < B.size() - 1) { // Verifica se o elemento não é o último
            cout << ", "; // Mostra uma vírgula caso não esteja no último elemento
        }
    }
    cout << "}\n" << endl;

    cout << "Conjunto A ∩ B = {";
    for (int i = 0; i < interseccao(A, B).size(); i++) { // Estrutura de repetição para percorrer o conjunto intersecão de A com B
        cout << interseccao(A, B)[i]; // Mostra o número que está na atual posição do vetor intersecção
        if (i < interseccao(A, B).size() - 1) { // Verifica se o elemento não é o último
            cout << ", "; // Mostra uma vírgula caso não esteja no último elemento
        }
    }
    cout << "}" << endl;

    return 0;
}