#include "astronauta.hpp"

using namespace std;

astronauta::astronauta(string nome, string cpf, int idade) {
    Nome = nome;
    CPF = cpf;
    Idade = idade;
    Disponibilidade = true;
    Vida = true;
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

bool astronauta::getVida() const{
    return Vida;
}

void astronauta::setDisponibilidade(bool disponibilidade) {
    Disponibilidade = disponibilidade;
}

