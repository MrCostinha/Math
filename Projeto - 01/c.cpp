/* Uma função união que irá ser chamada para unir os seguintes conjuntos dados A
e B e mostrar na tela o resultado. */
#include <iostream>
#include <vector> // Biblioteca padrão de vetores em C++
#include <algorithm> // Biblioteca com funções úteis para vetores em C++

using namespace std;

vector<int> uniao(vector<int> A, vector<int> B) { // Função união
    vector<int> AuB; // Cria um conjunto/vetor inteiro vazio da união de A com B

    for (int i = 0; i < A.size(); i++) { // Percorre o vetor A
        AuB.push_back(A[i]); // Adiciona o elemento do vetor A ao final do vetor AuB
    }
    for (int i = 0; i < B.size(); i++) { // Percorre o vetor B
        AuB.push_back(B[i]); // Adiciona o elemento do vetor B ao final do vetor AuB
    }

    sort(AuB.begin(), AuB.end()); // Ordena o vetor AuB
    AuB.erase(unique(AuB.begin(), AuB.end()), AuB.end()); // Remove elementos duplicados (Intersecção de A com B)

    return AuB; // Retorna o vetor AuB
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

    cout << "Conjunto A ∪ B = {";
    for (int i = 0; i < uniao(A, B).size(); i++) { // Estrutura de repetição para percorrer o conjunto união de A com B
        cout << uniao(A, B)[i]; // Mostra o número que está na atual posição do vetor união
        if (i < uniao(A, B).size() - 1) { // Verifica se o elemento não é o último
            cout << ", "; // Mostra uma vírgula caso não esteja no último elemento
        }
    }
    cout << "}" << endl;

    return 0;
}