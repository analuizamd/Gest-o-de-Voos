#include <iostream>
#include "gestao.hpp"
#include "astronauta.hpp"
#include <algorithm>

using namespace std;

void gestao::cadastrarAstronauta() {
    string nome;
    string cpf;
    int idade;

    cout << "Operação cadastrar astronauta." << endl;

    cout << "Digite o nome do astronauta: ";
    getline(cin, nome);

    do{
        cout << "Digite o CPF do astronauta com apenas números e com 11 dígitos: ";
        getline(cin, cpf);

        //Verificar se tem 11 dígitos
        if (cpf.length() != 11) {
            cout << "CPF inválido! Deve conter exatamente 11 dígitos." << endl;
        }
    } while(cpf.length() != 11);
    
    // Verificar se o astronauta já está cadastrado
    bool cadastrado = false;
    for (const auto& astro : todosAstronautas) {
        if (astro.getCPF() == cpf) { // Usar o getter para acessar CPF
            cadastrado = true;
            break;
        }
    }
    if (cadastrado) {
        cout << "Astronauta já cadastrado com este CPF." << endl;
        return;
    }

    cout << "Digite a idade do astronauta: ";
    cin >> idade;
    cin.ignore();

    //Guardar dados
    astronauta novoAstronauta(nome, cpf, idade);

    todosAstronautas.push_back(novoAstronauta);

    cout << "Astronauta cadastrado com sucesso!" << endl;

}

void gestao::cadastrarVoo(){
    int codigo;

    cout << "Operação cadastrar voo." << endl;

    cout << "Digite o código do voo: ";
    cin >> codigo;

    // Verificar se o voo já está cadastrado
    bool cadastrado = false;
    for (const auto& vooExistente : todosVoos) {
        if (vooExistente.getCodigo() == codigo) {
            cadastrado = true;
            break;
        }
    }

    if (cadastrado) {
        cout << "Erro: Voo já está cadastrado." << endl;
        return;
    }

    // Criar e adicionar o novo voo à lista de voos
    voo novoVoo(codigo, estadoVoo::PLANEJADO);
    todosVoos.push_back(novoVoo);

    cout << "Voo cadastrado com sucesso!" <<endl;
}

void gestao::addAstronautaVoo(){
    string cpf;
    int codigoVoo;

    if(todosAstronautas.empty()){
        cout << "** Nenhum astronauta foi cadastrado até o momento."<< endl;
        return;
    }

    if(todosVoos.empty()){
        cout << "** Nenhum voo foi cadastrado até o momento."<< endl;
        return;
    }

    cout << "Operação adicionar astronauta em voo." << endl;

    cout << "Digite o CPF do astronauta: ";
    cin >> cpf;

    // Procurar o astronauta na lista de astronautas cadastrados
    astronauta* encontrado = nullptr;
    for (auto& astro : todosAstronautas) {
        if (astro.getCPF() == cpf) {
            encontrado = &astro;
            break;
        }
    }
    if (!encontrado) {
        cout << "Erro: Astronauta não encontrado." << endl;
        return;
    }

    // Verificar disponibilidade e vida do astronauta encontrado
    if (!encontrado->getDisponibilidade()) {
        cout << "Erro: Astronauta não disponível." << endl;
        return;
    }

    if (!encontrado->getVida()) {
        cout << "Erro: O astronauta não está vivo." << endl;
        return;
    }

    cout << "Digite o código do voo: ";
    cin >> codigoVoo;

    // Procurar o voo na lista de voos cadastrados
    voo* vooEncontrado = nullptr;
    for (auto& v : todosVoos) {
        if (v.getCodigo() == codigoVoo) {
            vooEncontrado = &v;
            break;
        }
    }

    if (!vooEncontrado) {
        cout << "Erro: Voo não encontrado." << endl;
        return;
    }

    // Verificar se o estado do voo é planejado
    if (vooEncontrado->getEstado() != PLANEJADO) {
        cout << "Erro: A opção não está disponível para esse voo." << endl;
        return;
    }

    // Verificar se o astronauta já está cadastrado no voo
    if (vooEncontrado->isAstronautaCadastrado(cpf)) {
        cout << "Erro: Astronauta já está cadastrado neste voo." << endl;
        return;
    }


    // Adicionar o astronauta ao voo
    vooEncontrado->adicionarAstronauta(*encontrado);

    // Definir disponibilidade como false após verificação
    encontrado->setDisponibilidade(false);

    cout << "Astronauta adicionado ao voo com sucesso!" << endl;
}

void gestao::removerAstronauta(){
    string cpf;
    int codigoVoo;

    if(todosAstronautas.empty()){
        cout << "** Nenhum astronauta foi cadastrado até o momento."<< endl;
        return;
    }

    if(todosVoos.empty()){
        cout << "Nenhum voo foi cadastrado até o momento."<< endl;
        return;
    }

    cout << "Operação remover astronauta de voo." << endl;

    cout << "Digite o CPF do astronauta: ";
    cin >> cpf;

    // Procurar o astronauta na lista de astronautas cadastrados
    astronauta* encontrado = nullptr;
    for (auto& astro : todosAstronautas) {
        if (astro.getCPF() == cpf) {
            encontrado = &astro;
            break;
        }
    }
    if (!encontrado) {
        cout << "Erro: Astronauta não encontrado." << endl;
        return;
    }

    cout << "Digite o código do voo: ";
    cin >> codigoVoo;

    // Procurar o voo na lista de voos cadastrados
    voo* vooEncontrado = nullptr;
    for (auto& v : todosVoos) {
        if (v.getCodigo() == codigoVoo) {
            vooEncontrado = &v;
            break;
        }
    }

    if (!vooEncontrado) {
        cout << "Erro: Voo não encontrado." << endl;
        return;
    }

    // Verificar se o estado do voo é planejado
    if (vooEncontrado->getEstado() != PLANEJADO) {
        cout << "Erro: A opção não está disponível para esse voo." << endl;
        return;
    }

    // Verificar se o astronauta está no voo
    if (!vooEncontrado->astronautaEstaNoVoo(cpf)) {
        cout << "Erro: O astronauta não está cadastrado neste voo." << endl;
        return;
    }

    // Remover o astronauta do voo
    vooEncontrado->removerAstronauta(cpf);

    // Atualizar a disponibilidade do astronauta para verdadeiro
    encontrado->setDisponibilidade(true);

    cout << "Astronauta removido do voo com sucesso!" << endl;

}