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
    astronauta novoAstronauta(nome, cpf, idade, estadoVida::VIVO);

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
        cout << "Nenhum astronauta foi cadastrado."<< endl;
        return;
    }

    if(todosVoos.empty()){
        cout << "Nenhum voo foi cadastrado."<< endl;
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

    // if (!encontrado->getVida()) {
    //     cout << "Erro: O astronauta não está vivo." << endl;
    //     return;
    // }

    //Código acima não funciona

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
    // encontrado->setDisponibilidade(false);

    cout << "Astronauta adicionado ao voo com sucesso!" << endl;
}

void gestao::removerAstronauta(){
    string cpf;
    int codigoVoo;

    if(todosAstronautas.empty()){
        cout << "Nenhum astronauta foi cadastrado."<< endl;
        return;
    }

    if(todosVoos.empty()){
        cout << "Nenhum voo foi cadastrado."<< endl;
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

void gestao::lancarVoo(){
    int codigoVoo;

    if(todosVoos.empty()){
        cout << "Nenhum voo foi cadastrado."<< endl;
        return;
    }

    cout << "Operação lançar voo." << endl;

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
        cout << "Erro: O voo já foi lançado ou não está planejado." << endl;
        return;
    }

    //Verifica se há pelo menos um astronauta no voo
    if (vooEncontrado->getTripulantes().empty()) {
        cout << "Erro: Não há astronautas cadastrados no voo." << endl;
        return;
    }

    //Verificar se todos os astronautas do voo estão disponíveis
    for (const auto& astro : vooEncontrado->getTripulantes()) {
        if (!astro.getDisponibilidade()) {
            cout << "Erro: O astronauta " << astro.getNome() << " não está disponível." << endl;
            return;
        }
    }

    // Lançar o voo alterando seu estado para LANCADO
    vooEncontrado->setEstado(LANCADO);
    cout << "Voo lançado com sucesso!" << endl;

    // Definir disponibilidade de todos os astronautas do voo como false após verificação
    for (auto& astro : vooEncontrado->getTripulantes()) {
        astro.setDisponibilidade(false);
    }

    // Atualizar a lista de voos de todos os astronautas
    for (auto& astro : vooEncontrado->getTripulantes()) {
        astro.adicionarVoo(codigoVoo);
    }

}

void gestao::explodirVoo(){
    int codigoVoo;

    if(todosVoos.empty()){
        cout << "Nenhum voo foi cadastrado."<< endl;
        return;
    }

    cout << "Operação explodir voo." << endl;

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

    // Verificar se o estado do voo foi lançado
    if (vooEncontrado->getEstado() != LANCADO) {
        cout << "Erro: O voo não foi lançado." << endl;
        return;
    }

    // Explodir o voo alterando seu estado para EXPLODIDO
    vooEncontrado->setEstado(EXPLODIDO);
    cout << "Voo explodido com sucesso! Todos os astronautas do voo faleceram." << endl;

    // Modificar o estado de vida dos astronautas do voo para MORTO
    for (auto& astro : vooEncontrado->getTripulantes()) {
        astro.setVida(MORTO);
    }

    // Mostrar o estado atual dos astronautas após a explosão do voo
    cout << "Estado dos astronautas após a explosão do voo:" << endl;
    for (auto& astro : vooEncontrado->getTripulantes()) {
        cout << "Astronauta: " << astro.getNome();
        if (astro.getVida() == VIVO) {
            cout << " - Vivo" << endl;
        } else {
            cout << " - Morto" << endl;
        }
    }
    // Modificar o estado de vida dos astronautas do voo para false
    // for (auto& astro : vooEncontrado->getTripulantes()) {
    //     astro.setVida(false);
    // }

    // cout << "Estado dos astronautas após a explosão do voo:" << endl;
    // for (const auto& astro : vooEncontrado->getTripulantes()) {
    //     cout << "Astronauta: " << astro.getNome();
    //     if (astro.getVida() == false) {
    //         cout << " - Morto" << endl;
    //     } else if (astro.getVida() == true) {
    //         cout << " - Vivo" << endl;
    //     }
    // }


}

void gestao::finalizarVoo(){
    int codigoVoo;

    if(todosVoos.empty()){
        cout << "Nenhum voo foi cadastrado."<< endl;
        return;
    }

    cout << "Operação finalizar voo." << endl;

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

    // Verificar se o estado do voo foi lançado
    if (vooEncontrado->getEstado() != LANCADO) {
        cout << "Erro: O voo não foi lançado." << endl;
        return;
    }

    // Finalizar o voo alterando seu estado para FINALIZADO
    vooEncontrado->setEstado(FINALIZADO);
    cout << "Voo finalizado com sucesso!" << endl;

    //Deixar astronautas disponíveis (não funciona)
    for (auto& astro : vooEncontrado->getTripulantes()) {
        astro.setDisponibilidade(true);
    }


}

void gestao::listarTodosVoos(){

    if(todosVoos.empty()){
        cout << "Nenhum voo foi cadastrado."<< endl;
        return;
    }

    cout << "Operação listar todos os voos." << endl;

    //Listar voos
    auto listarVoosPorEstado = [&](estadoVoo estado, const string& estadoNome) {
        cout << estadoNome << ":" << endl;
        bool encontrou = false;
        for (auto& v : todosVoos) {
            if (v.getEstado() == estado) {
                encontrou = true;
                cout << "  Código do voo: " << v.getCodigo() << endl;
                cout << "  Tripulantes:" << endl;
                for (auto& astro : v.getTripulantes()) {
                    cout << "    - " << astro.getNome() << endl; // Uso de . para valor
                }
            }
        }
        if (!encontrou) {
            cout << "  Nenhum voo encontrado." << endl;
        }
        cout << endl;
    };
    // Listar voos por estado
    listarVoosPorEstado(PLANEJADO, "Planejados");
    listarVoosPorEstado(LANCADO, "Lançados");
    listarVoosPorEstado(EXPLODIDO, "Finalizados sem sucesso(explodidos)");
    listarVoosPorEstado(FINALIZADO, "Finalizados com sucesso");
}

void gestao::listarMortos(){
    cout << "Lista de astronautas mortos:" << endl;

    bool encontrou = false;
    for (auto& astro : todosAstronautas) {
        if (astro.getVida() == MORTO) {
            encontrou = true;
            cout << "Nome: " << astro.getNome() << endl;
            cout << "CPF: " << astro.getCPF() << endl;
            cout << "Voos em que participou: ";
            for (const auto& v : todosVoos) {
                for (const auto& tripulante : v.getTripulantes()) {
                    if (tripulante.getCPF() == astro.getCPF()) {
                        cout << v.getCodigo() << " ";
                        break;
                    }
                }
            }
            cout << endl << "--------------------------" << endl;
        }
    }

    if (!encontrou) {
        cout << "Nenhum astronauta morto encontrado." << endl;
    }
}