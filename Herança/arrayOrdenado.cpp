#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

template <typename T>
class ArrayOrdenado {
    vector<T> dados;
public:
    void inserir(const T& valor) {
        // 1. Encontra a posição correta para inserção
        int pos = 0;
        while (pos < dados.size() && dados[pos] < valor) {
            pos++;
        }

        // 2. Adiciona um elemento no final para "abrir espaço"
        dados.push_back(valor);

        // 3. Desloca os elementos para a direita a partir da posição encontrada        
        for (int i = dados.size() - 1; i > pos; --i) {
            dados[i] = dados[i - 1];
        }
        // 4. Insere o valor na posição correta
        dados[pos] = valor;
    }

    // remove a primeira ocorrencia do valor
    bool removerPorValor(const T& valor) {
        int pos = -1;
        // 1. Encontra a posição do elemento a ser removido
        for(int i = 0; i < dados.size(); ++i) {
            if(dados[i] == valor) {
                pos = i;
                break;
            }
        }

        // se o valor não for encontrado retorna false
        if(pos == -1) {
            return false;
        }

        // criar um vetor auxiliar 
        vector<T> temp;
        for(int i = 0; i < dados.size(); ++i) {
            if (i != pos) {
                temp.push_back(dados[i]);
            }
        }
        
        // limpamos o vetor original e repopula com os dados do vetor auxiliar
        dados.clear();
        for(int i = 0; i < temp.size(); ++i) {
            dados.push_back(temp[i]);
        }

        return true;
    }
 /**
     * Operador[] para acesso de leitura.
     * A versão 'const' garante que o usuário não possa alterar os valores e quebrar a ordenação.
     **/
    const T& operator[](int index) const {
        if(index < 0 || index >= dados.size()) {
            throw out_of_range("Indice fora do limite de array");
        }
        return dados[index];
    }

    // Retorna o numero de elementos do array
    int tamanho() const {
        return dados.size();
    }

    void imprimir() const { 
        cout << "[ ";
        for(int i = 0; i < dados.size(); ++i) {
            cout << dados[i] << " ";
        }
        cout << "]" << endl;
    }
};

template <typename T>
class VetorComInsercaoNoMeio {
private:
    vector<T> dados;
public:
    // insere elemento na posição meio do vetor
    void inserirNoMeio(const T& valor) {
        int n = dados.size();
        int meio = n / 2;

        // Adiciona um valor temporário no final para aumentar o tamanho do vetor
        dados.push_back(valor);

        // Desloca os elementos da antiga última posição até 'meio' uma casa para a direita
        for(int i = n; i > meio; --i) {
            dados[i] = dados[i - 1];
        }
        // Coloca o valor desejado na posição do meio
        dados[meio] = valor;
    }

    void adicionarFinal(const T& valor) {
        dados.push_back(valor);
    }

    int tamanho() const {
        return dados.size();
    }

    const T& operator[](int index) const {
        return dados[index];
    }

    void imprimir() const {
        cout << "[ ";
        for(int i = 0; i < dados.size(); ++i) {
            cout << dados[i] << " ";
        }
        cout << "]" << endl;
    }
};

int main() {
    cout << "---Testes da questao 1: ArrayOrdenado---" << endl;
    ArrayOrdenado<int> array;

    cout << "inserindo 10, 5, 20, 8" << endl;
    array.inserir(10);
    array.inserir(5);
    array.inserir(20);
    array.inserir(8);

    cout << "Estado atual: ";
    array.imprimir();
    cout << "Tamanho: " << array.tamanho() << endl;

    cout << "\nRemovendo o valor 8..." << endl;
    array.removerPorValor(8);
    cout << "Estado após remocao: ";
    array.imprimir();

    cout << "\nRemovendo um valor inexistente(99)..." << endl;
    bool sucesso = array.removerPorValor(99);
    cout << "Sucesso na remocao: " << (sucesso ? "sim" : "nao") << endl;
    cout << "Estado final: ";
    array.imprimir();

    cout << "\nAcessando o elemento no indice 1: " << array[1] << endl;

    cout << "\n\n----Teste da Questao 2: InserirComInsercaoMeio-----" << endl;
    VetorComInsercaoNoMeio<char> vet;

    cout << "Adicionando no final: 'a', 'b', 'd', 'e' " << endl;
    vet.adicionarFinal('a');
    vet.adicionarFinal('b');
    vet.adicionarFinal('d');
    vet.adicionarFinal('e');

    cout << "vetor antes da insercao no meio: ";
    vet.imprimir();
    cout << "Tamanho: " << vet.tamanho() << endl;

    cout << "\nInserindo 'c' no meio...." << endl;
    vet.inserirNoMeio('c');

    cout << "Vetor apos insercao no meio: " << endl;
    vet.imprimir();
    cout << "Novo tamanho: " << vet.tamanho() << endl;

    return 0;
}