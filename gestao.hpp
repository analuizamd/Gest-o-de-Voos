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
    void addAstronautaVoo();
    void removerAstronauta();
    void lancarVoo();
    void explodirVoo();
    void finalizarVoo();
    void listarTodosVoos();
    void listarMortos();
};


#endif // GESTAO_HPP
