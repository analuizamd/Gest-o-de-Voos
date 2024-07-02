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
    int codigo;
    list<astronauta> tripulantes; 
    estadoVoo estado;   

};