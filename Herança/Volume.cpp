//Crie um aplicativo, em C++, para a representação de sólidos em R3 e 
//calculo de área de superfície e volume destes sólidos. 
//Na hierarquia de classes, obrigatoriamente deverá existir uma classe responsável 
//pelo armazenamento do conjunto de objetos, que representam os sólidos, 
//e calculo, de áreae volume, total desse conjunto de objetos.
//Seu aplicativo deve admitir que o usuário realize a inserção de esferas e cilindros, 
//requisitar o calculo da área e volume total dos sólidos inseridos. 
//Além disso deve prever a ampliação do conjunto de sólidos, implementados inicialmente, 
//sem a necessidade de alteração das classes criadas inicialmente

#include <iostream>
#include <cmath>
#include <memory>
#include <limits>
#include <vector>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

using namespace std;

class Solido {
public:
    virtual ~Solido() = default;

    virtual double volume() const = 0;
    virtual double areaSuperficie() const = 0;
};

class Esfera : public Solido {
    double raio;
public:
    explicit Esfera(double r) : raio(r) {};

    double volume() const override {
        return (4.0 / 3.0) * M_PI * pow(raio, 3);
    }

    double areaSuperficie() const override {
        return 4.0 * M_PI * pow(raio, 2);
    }
};

class Cilindro : public Solido {
    double raio;
    double altura;
public:
    Cilindro(double r, double h) : raio(r), altura(h){};

    double volume() const override {
        return M_PI * pow(raio, 2) * altura;
    }

    double areaSuperficie() const override {
        return (2.0 * M_PI * pow(raio, 2)) + (2.0 * M_PI * raio * altura);
    }
};

class ConjuntoDeSolidos {
private:
    vector<unique_ptr<Solido>> solidos;
public:
    void adicionarSolido(unique_ptr<Solido> solido) {
        solidos.push_back(move(solido));
    }

    double volumeTotal() const { 
        double total = 0.0;

        for(const auto& solidoPtr : solidos) {
            total += solidoPtr->volume();
        }
        return total;
    }

    
    double areaTotal() const {
        double total = 0.0;
        for(const auto& solidoPtr : solidos) {
            total += solidoPtr->areaSuperficie();
        }
        return total;
    }

    size_t quantidade() const {
        return solidos.size();
    }
};

void exibirMenu() {
    cout << "\n--- Menu de Opcoes ---\n";
    cout << "1. Adicionar uma Esfera\n";
    cout << "2. Adicionar um Cilindro\n";
    cout << "3. Calcular Area e Volume Totais\n";
    cout << "4. Sair\n";
    cout << "Escolha uma opcao: ";
}

double obterEntradaPositiva(const string& prompt) {
    double valor;
    while (true) {
        cout << prompt;
        cin >> valor;
        if (cin.good() && valor > 0) {
            return valor;
        } else {
            cout << "Entrada invalida. Por favor, insira um numero positivo.\n";
            cin.clear(); // Limpa o estado de erro
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descarta a linha inválida
            continue;
        }
    }
}



int main()
{
    ConjuntoDeSolidos colecao;
    int escolha;

    while(true) {
        exibirMenu();
        cin >> escolha;

        if(cin.fail()) {
            cout << "opção inválida. Tente novamente\n";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        switch (escolha) {
            case 1: {
                std::cout << "\n-- Adicionando Esfera --\n";
                double raio = obterEntradaPositiva("Digite o raio: ");
                // Cria um ponteiro único para uma nova Esfera e o adiciona à coleção.
                // std::make_unique é a forma segura e recomendada de fazer isso.
                colecao.adicionarSolido(std::make_unique<Esfera>(raio));
                std::cout << "Esfera adicionada com sucesso!\n";
                break;
            }
            case 2: {
                std::cout << "\n-- Adicionando Cilindro --\n";
                double raio = obterEntradaPositiva("Digite o raio da base: ");
                double altura = obterEntradaPositiva("Digite a altura: ");
                colecao.adicionarSolido(std::make_unique<Cilindro>(raio, altura));
                std::cout << "Cilindro adicionado com sucesso!\n";
                break;
            }
            case 3: {
                std::cout << "\n-- Calculo Total --\n";
                if (colecao.quantidade() == 0) {
                    std::cout << "Nenhum solido foi inserido ainda.\n";
                } else {
                    std::cout.precision(2); // Define a precisão para 2 casas decimais
                    std::cout << std::fixed; // Garante que a notação não seja científica
                    std::cout << "Quantidade de solidos: " << colecao.quantidade() << std::endl;
                    std::cout << "Area de Superficie Total: " << colecao.areaTotal() << std::endl;
                    std::cout << "Volume Total: " << colecao.volumeTotal() << std::endl;
                }
                break;
            }
            case 4: {
                std::cout << "Saindo do programa. Ate mais!\n";
                return 0; // Termina o programa
            }
            default: {
                std::cout << "Opcao invalida. Por favor, escolha um numero de 1 a 4.\n";
                break;
            }
    }

}

    return 0;
}
