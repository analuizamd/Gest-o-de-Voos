#include <string>
#include <list>
using namespace std;

class astronauta {
private:
    string Nome;
    string CPF;
    int Idade;
    bool Disponibilidade;
    bool Vida;
    list<int> Voos;
 
public:
    astronauta(string nome, string cpf, int idade){
        Nome = nome;
        CPF = cpf;
        Idade = idade;
        Disponibilidade = true;
        Vida = true;
    }

};

// bool getVida() {
//         return Vida;
//     }

//     void setVida(bool vivo) {
//         Vida = vivo;
//     }
// astro.setVida(false);