/* Uma função chamada subconjunto ao ser mostrada na tela retorna 
FALSO ou VERDADEIRO quando entra com os dois conjuntos criados anteriormente. */
#include <iostream>
#include <vector> // Biblioteca padrão de vetores em C++
#include <algorithm> // Biblioteca com funções úteis para vetores em C++

using namespace std;

bool subconjunto(vector<int> A, vector<int> B) { // Função subconjunto
    int count_A_em_B = 0; // Contador para a quantidade de elementos de A que estão em B

    for (int i = 0; i < B.size(); i++) { // Percorre o vetor B
        for (int j = 0; j < A.size(); j++) { // Percorre o vetor A para cada elemento do vetor B
            if (A[j] == B[i]) { // Verifica se o elemento do vetor A é igual ao elemento do vetor B
                count_A_em_B++; // Se sim, incrementa o contador
            }
        }
    }

    if (count_A_em_B == A.size()) { // Verifica se a quantidade de elementos de A que estão em B é igual ao tamanho do vetor A
        return true; // Se sim, todos os elementos de A estão em B, então o vetor A é subconjunto do vetor B
    } else {
        return false; // Se não, o vetor A não é subconjunto do vetor B
    }
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
    A.erase(unique(A.begin(), A.end()), A.end()); // Remove os elementos repetidos do vetor A
    sort(B.begin(), B.end()); // Ordena o vetor B
    B.erase(unique(B.begin(), B.end()), B.end()); // Remove os elementos repetidos do vetor B

    cout << "\nConjunto A = {";
    for (int i = 0; i < A.size(); i++) { // Estrutura de repetição para percorrer o conjunto A
        cout << A[i]; // Mostra o número que está na atual posição do vetor A
        if (i < A.size() - 1) { // Verifica se o elemento não é o último
            cout << ", "; // Mostra uma vírgula caso não esteja no último elemento
        }
    }
    cout << "}\n" << endl;
    cout << "Conjunto B = {";
    for (int i = 0; i < B.size(); i++) { // Estrutura de repetição para percorrer o conjunto B
        cout << B[i]; // Mostra o número que está na atual posição do vetor B
        if (i < B.size() - 1) { // Verifica se o elemento não é o último
            cout << ", "; // Mostra uma vírgula caso não esteja no último elemento
        }
    }
    cout << "}\n" << endl;

    if (subconjunto(A, B) && subconjunto(B, A)) { // Se A for subconjunto de B e vice-versa...
        cout << "A e B são iguais!" << endl;
    } else if (subconjunto(A, B)) { // Se A for subconjunto de B...
        cout << "A é subconjunto de B!" << endl;
    } else if (subconjunto(B, A)) { // Se B for subconjunto de A...
        cout << "B é subconjunto de A!" << endl;
    } else { // Se nenhum for subconjunto do outro...
        cout << "A e B não são subconjuntos um do outro!" << endl;
    }

    return 0;
}