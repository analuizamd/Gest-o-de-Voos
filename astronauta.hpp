#ifndef ASTRONAUTA_HPP
#define ASTRONAUTA_HPP

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
    astronauta(string nome, string cpf, int idade);

    string getNome() const;
    string getCPF() const;
    int getIdade() const;
    bool getDisponibilidade() const;
    bool getVida() const;

    void setDisponibilidade(bool disponibilidade);
};

#endif // ASTRONAUTA_HPP
