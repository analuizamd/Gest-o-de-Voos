#ifndef GESTAO_HPP
#define GESTAO_HPP

#include <iostream>
#include <list>
#include "voo.hpp"
#include "astronauta.hpp"

using namespace std;

class gestao{
private:
    list<astronauta> todosAstronautas;
    list<voo> todosVoos;

public:
    void cadastrarAstronauta();
    void cadastrarVoo();
    void addAstronautaVoo(); //Ajeitar
    void removerAstronauta();
    void lancarVoo();
    void explodirVoo();//Ajeitar
    void finalizarVoo();
    void listarTodosVoos();
};


#endif // GESTAO_HPP
