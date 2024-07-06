#include <iostream>
#include <string>
#include "gestao.hpp"

using namespace std;
using std::string;

void imprimeMenu(){
    cout << "Bem vindo! Selecione uma das opções.\n";
    cout << "(1)Cadastrar astronauta\n";
    cout << "(2)Cadastrar voo\n";
    cout << "(3)Adicionar astronauta em voo\n";
    cout << "(4)Remover astronauta de um voo\n";
    cout << "(5)Lançar um voo\n";
    cout << "(6)Explodir voo\n";
    cout << "(7)Finalizar um voo\n";
    cout << "(8)Listar todos os voos\n";
    cout << "(9)Listar todos os astronautas mortos\n";
    cout << "(10)Concluir operação\n";
    }

int main(){

    gestao sistema;
    int operacao;
    do{
        imprimeMenu();
        cin >> operacao;
        cin.ignore(); //Limpar buffer de entrada

        switch(operacao){
            case 1:
                sistema.cadastrarAstronauta();
                break;
            case 2:
                sistema.cadastrarVoo();
                break;
            case 3:
                sistema.addAstronautaVoo();
                break;
            case 4:
                sistema.removerAstronauta();
                break;
            case 5:
                sistema.lancarVoo();
                break;
            case 6:
                sistema.explodirVoo();
                break;
            case 7:
                //função para finalizar um voo
                break;
            case 8:
                //função para listar todos os voos
                //a lista do astronauta é atualizada
                break;
            case 9:
                //função para listar todos os astronautas mortos
                break;
            case 10:
                cout << "Operação concluída!\n";
                break;
            default:
                cout << "Opção inválida. Tente novamente.\n";
        }
    }while(operacao!=10);

}
