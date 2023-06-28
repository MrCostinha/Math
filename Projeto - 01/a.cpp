/* Um programa em linguagem de programação que crie seguintes dois conjuntos M e N e mostre na tela 
FALSO ou VERDADEIRO para a pertinência dos elementos. */
#include <iostream>
#include <vector> // Biblioteca padrão de vetores em C++

using namespace std;

int main() {
    vector<int> M = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // Cria um conjunto/vetor inteiro M
    vector<int> N = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29}; // Cria um conjunto/vetor inteiro N
    int numero; // Variável para armazenar um número/elemento para o teste de pertinência
    bool pertence_a_M = false, pertence_a_N = false; // Variáveis que armazenam se o elemento pertence ou não aos conjuntos

    cout << "Conjunto M = {";
    for (int i = 0; i < M.size(); i++) { // Estrutura de repetição para percorrer o conjunto M
        cout << M[i]; // Mostra o número que está na atual posição do vetor M
        if (i < M.size() - 1) { // Verifica se o elemento não é o último
            cout << ", "; // Mostra uma vírgula caso não esteja no último elemento
        }
    }
    cout << "}" << endl;

    cout << "Conjunto N = {";
    for (int i = 0; i < N.size(); i++) { // Estrutura de repetição para percorrer o conjunto N
        cout << N[i]; // Mostra o número que está na atual posição do vetor N
        if (i < N.size() - 1) { // Verifica se o elemento não é o último
            cout << ", "; // Mostra uma vírgula caso não esteja no último elemento
        }
    }
    cout << "}" << endl;

    cout << "\nDigite um inteiro: "; // Pede para o usuário digitar um número inteiro
    cin >> numero; // Recebe e armazena o valor digitado pelo usuário
    cout << endl;

    for (int i = 0; i < M.size(); i++) { // Percorre o vetor M
        if (numero == M[i]) { // Verifica se o número digitado é igual ao valor armazenado na atual posição do vetor M
            pertence_a_M = true; // Se sim, o elemento pertence a M
            break;
        }
    }
    for (int i = 0; i < N.size(); i++) { // Percorre o vetor N
        if (numero == N[i]) { // Verifica se o número digitado é igual ao valor armazenado na atual posição do vetor N
            pertence_a_N = true; // Se sim, o elemento pertence a N
            break;
        }
    }

    if (pertence_a_M && pertence_a_N) { // Se o número pertence a M e N...
        cout << "O número " << numero << " pertence aos conjuntos M e N." << endl;
    } else if (pertence_a_M == false && pertence_a_N == false) { // Se o número não pertence a M nem a N...
        cout << "O número " << numero << " não pertence a nenhum dos conjuntos." << endl;
    } else if (pertence_a_M) { // Se o número só pertence a M...
        cout << "O número " << numero << " pertence ao conjunto M." << endl;
    } else { // Se o número só pertence a N...
        cout << "O número " << numero << " pertence ao conjunto N." << endl;
    }

    return 0;
}