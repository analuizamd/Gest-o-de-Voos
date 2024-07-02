#include <iostream>
#include <string>
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

    int operacao;
    do{
        imprimeMenu();
        cin >> operacao;
        switch(operacao){
            case 1:
                //função cadastrar astronauta
                break;
            case 2:
                //função cadastrar voo
                break;
            case 3:
                //função para adicionar astronauta em voo
                break;
            case 4:
                //função para remover astronauta de um voo
                break;
            case 5:
                //função para lançar um voo
                break;
            case 6:
                //função para explodir um voo
                break;
            case 7:
                //função para finalizar um voo
                break;
            case 8:
                //função para listar todos os voos
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
