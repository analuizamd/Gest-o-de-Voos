#include "voo.hpp"

using namespace std;

voo::voo(int codigo, estadoVoo estado){
    Codigo = codigo;
    Estado = estado;
}

int voo::getCodigo() const {
    return Codigo;
}

estadoVoo voo::getEstado() {
    return Estado;
}

list<astronauta> voo::getTripulantes() {
    return Tripulantes;
}

void voo::adicionarAstronauta(const astronauta& astro) {
    Tripulantes.push_back(astro);
}

bool voo::isAstronautaCadastrado(const std::string& cpf) {
    for (const auto& astro : Tripulantes) {
        if (astro.getCPF() == cpf) {
            return true;
        }
    }
    return false;
}

void voo::removerAstronauta(const string& cpf) {
    for (auto it = Tripulantes.begin(); it != Tripulantes.end(); ++it) {
        if (it->getCPF() == cpf) {
            Tripulantes.erase(it);
            return;
        }
    }
}

bool voo::astronautaEstaNoVoo(const string& cpf) {
    for (const auto& astro : Tripulantes) {
        if (astro.getCPF() == cpf) {
            return true;
        }
    }
    return false;
}

void voo::setEstado(estadoVoo novoEstado) {
    Estado = novoEstado;
}