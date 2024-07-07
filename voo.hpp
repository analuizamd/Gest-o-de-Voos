#ifndef VOO_HPP
#define VOO_HPP

#include <string>
#include <list>
#include "astronauta.hpp"

using namespace std;

enum estadoVoo{
    PLANEJADO,
    LANCADO,
    EXPLODIDO,
    FINALIZADO
};

class voo{
private:
    int Codigo;
    list<astronauta> Tripulantes; 
    estadoVoo Estado;   
public:
    voo(int codigo, estadoVoo estado);

    int getCodigo() const;
    estadoVoo getEstado();
    list<astronauta> getTripulantes();
    
    void adicionarAstronauta(const astronauta& astro);
    void removerAstronauta(const string& cpf);
    bool isAstronautaCadastrado(const string& cpf);
    bool astronautaEstaNoVoo(const string& cpf);
    void setEstado(estadoVoo novoEstado);
};

#endif // VOO_HPP