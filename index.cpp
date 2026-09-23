#include <iostream>
using namespace std;

int main() {
    int numeroConta, tipoConta, opcao;
    string nomeCliente, cpf;
    double saldo;
    bool contaAtiva;
    
    opcao = 1;
    while (opcao != 6) {
    cout<< "*******************"<< endl;
    cout<< "*** BANCO SWFIT ***"<< endl;
    cout<< "*******************"<< endl;
    cout<< "1- Cadastrar Conta"<< endl;
    cout<< "2- Consultar Conta"<< endl;
    cout<< "3- Verificar Saldo" << endl;
    cout<< "4- Alterar tipo de Conta"<< endl;
    cout<< "5- Ativar/Desativar Conta"<< endl;
    cout<< "6- Sair"<< endl;
    
    cout<< "Escolha uma opção: "<< endl;
    cin>> opcao;
    
        switch(opcao) {
            case 1:
                cout<< "1- Cadastrar Conta"<< endl;
                cout<< "Nome do cliente: "<< endl;
                cin>> nomeCliente;
                cout<< "Número do CPF (apenas os números): "<< endl;
                cin>> cpf;
            break;
            case 2:
                cout<< "2- Consultar Conta"<< endl;
                cout<< "Nome do cliente: "<< endl;
                cin>> nomeCliente;
                cout<< "Número da conta: "<< endl;
                cin>> numeroConta;
            break;
            case 3:
                cout<< "3- Verificar Saldo"<< endl;
                cout<< "Nome do cliente: "<< endl;
                cin>> nomeCliente;
                cout<< "Número da conta: "<< endl;
                cin>> numeroConta;
            break;
            case 4:
                cout<< "4- Alterar tipo de Conta"<< endl;
                cout<< "Nome do cliente: "<< endl;
                cin>> nomeCliente;
                cout<< "Número da conta: "<< endl;
                cin>> numeroConta;
            break;
            case 5:
                cout<< "5- Ativar/Desativar Conta"<< endl;
                cout<< "Nome do cliente: "<< endl;
                cin>> nomeCliente;
                cout<< "Número da conta: "<< endl;
                cin>> numeroConta;
            break;
            case 6:
                cout<< "6- Sair"<< endl;
            break;
        } 
    }
    return 0;
}
