#include <iostream>
#include <string>
using namespace std;

int main()
{
    int numeroConta, tipoConta, opcao;
    string nomeCliente, cpf;
    double saldo;
    bool contaAtiva;

    opcao = 1;
    while (opcao != 6)
    {
        // Menu
        cout << "*******************" << endl;
        cout << "*** BANCO SWIFT ***" << endl;
        cout << "*******************" << endl;
        cout << "1- Cadastrar Conta" << endl;
        cout << "2- Consultar Conta" << endl;
        cout << "3- Verificar Saldo" << endl;
        cout << "4- Alterar tipo de Conta" << endl;
        cout << "5- Ativar/Desativar Conta" << endl;
        cout << "6- Sair" << endl;

        // Cliente escolhe uma opção do Menu
        cout << "Escolha uma opção: " << endl;
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            cout << "1- Cadastrar Conta" << endl;
            cout << "Número da conta: " << endl;
            cin >> numeroConta;
            // Validação: número da conta positivo
            if (numeroConta < 0)
            {
                cout << "Número de conta inválido." << endl;
            }
            cin.ignore();
            cout << "Nome do titular: " << endl;
            getline(cin, nomeCliente);

            cout << "Número do CPF: " << endl;
            cin >> cpf;

            cout << "Tipo da conta: " << endl;
            cin >> tipoConta;
            if (tipoConta = 1)
            {
                cout << "1- Conta Corrente" << endl;
            }
            else if (tipoConta = 2)
            {
                cout << "2- Conta Poupança" << endl;
            }
            else
            {
                cout << "Tipo de conta não existente" << endl;
            }

            cout << "Saldo inicial: " << endl;
            cin >> saldo;
            // Validação: saldo positivo
            if (saldo < 0)
            {
                cout << "O saldo inicial não pode ser negativo." << endl;
            } else {
                cout << "Saldo válido" << endl;
            }

            break;

        case 2:
            cout << "2- Consultar Conta" << endl;
            break;

        case 3:
            cout << "3- Verificar Saldo" << endl;
            break;

        case 4:
            cout << "4- Alterar tipo de Conta" << endl;
            break;

        case 5:
            cout << "5- Ativar/Desativar Conta" << endl;
            break;

        default:
            cout << "6- Sair" << endl;
        }
    }
    return 0;
}
