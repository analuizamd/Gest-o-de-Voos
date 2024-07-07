#ifndef ASTRONAUTA_HPP
#define ASTRONAUTA_HPP

#include <string>
#include <list>

using namespace std;

enum estadoVida{
    VIVO,
    MORTO
};

class astronauta {
private:
    string Nome;
    string CPF;
    int Idade;
    bool Disponibilidade;
    estadoVida Vida;
    list<int> Voos;
 
public:
    astronauta(string nome, string cpf, int idade, estadoVida vida);

    string getNome() const;
    string getCPF() const;
    int getIdade() const;
    bool getDisponibilidade() const;
    estadoVida getVida() ;

    void setDisponibilidade(bool disponibilidade);
    void adicionarVoo(int codigo);
    void setVida(estadoVida novoEstadoVida);
    const list<int>& getVoos() const; 
 
};

#endif // ASTRONAUTA_HPP
