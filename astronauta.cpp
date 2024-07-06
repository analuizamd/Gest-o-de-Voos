#include "astronauta.hpp"

using namespace std;

astronauta::astronauta(string nome, string cpf, int idade, estadoVida vida) {
    Nome = nome;
    CPF = cpf;
    Idade = idade;
    Disponibilidade = true;
    Vida = vida;

    // Vida = true;
}

string astronauta::getNome() const {
    return Nome;
}

string astronauta::getCPF() const {
    return CPF;
}

int astronauta::getIdade() const {
    return Idade;
}

bool astronauta::getDisponibilidade() const{
    return Disponibilidade;
}

estadoVida astronauta::getVida() {
    return Vida;
}

// bool astronauta::getVida() const{
//     return Vida;
// }

void astronauta::setDisponibilidade(bool disponibilidade) {
    Disponibilidade = disponibilidade;
}

// void astronauta::setVida(bool vida) {
//     Vida = vida;
// }

void astronauta::adicionarVoo(int codigo) {
    Voos.push_back(codigo);
}

void astronauta::setVida(estadoVida novoEstadoVida) {
    Vida = novoEstadoVida;
}
