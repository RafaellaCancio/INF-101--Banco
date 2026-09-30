#include <iostream>
#include <string>
using namespace std;

// Na minha lógica o usuário terá que preencher todos os dados da opção 1 para poder seguir para as demais opções.

int main()
{

    int numeroConta, tipoConta, opcao;
    string nomeCliente, cpf;
    double saldo;
    bool contaAtiva, contaCadastrada;
    char resposta, resposta2, resposta3;

    numeroConta = 0;
    tipoConta = 0;
    saldo = 0;
    contaAtiva = false;
    contaCadastrada = false;
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

            // Número da conta
            cout << "Número da conta: " << endl;
            cin >> numeroConta;

            // Validação: número da conta positivo
            while (numeroConta <= 0)
            {
                cout << "Número de conta inválido." << endl;
                cout << "Digite novamente o número da conta: " << endl;
                cin >> numeroConta;
            }

            cin.ignore();

            // Nome do titular
            cout << "Nome do titular: " << endl;
            getline(cin, nomeCliente);

            // Número do CPF
            cout << "Número do CPF: " << endl;
            cin >> cpf;

            // Tipo da conta
            cout << "Tipo da conta: " << endl;
            cin >> tipoConta;

            while (tipoConta != 1 && tipoConta != 2)
            {
                cout << "Tipo de conta não existente" << endl;
                cout << "Digite novamente o tipo da conta: " << endl;
                cin >> tipoConta;
            }

            if (tipoConta == 1)
            {
                cout << "1- Conta Corrente" << endl;
            }

            else if (tipoConta == 2)
            {
                cout << "2- Conta Poupança" << endl;
            }

            // Saldo inicial
            cout << "Saldo inicial: " << endl;
            cin >> saldo;

            // Validação: saldo positivo
            while (saldo < 0)
            {
                cout << "O saldo inicial não pode ser negativo." << endl;
                cout << "Digite novamente o saldo inicial: " << endl;
                cin >> saldo;
            }

            // Conta ativa
            cout << "Deseja ativar a conta? (S/N)" << endl;
            cin >> resposta;
            while (resposta != 'S' && resposta != 's' &&
                   resposta != 'N' && resposta != 'n')
            {
                cout << "Resposta inválida. Digite S ou N: ";
                cin >> resposta;
            }
            if (resposta == 'S' || resposta == 's')
            {
                contaAtiva = true;
                cout << "Sua conta foi ativada." << endl;
            }
            else if (resposta == 'N' || resposta == 'n')
            {
                contaAtiva = false;
                cout << "Sua conta NÃO foi ativada." << endl;
            }

            contaCadastrada = true;
            break;

        case 2:
            if (contaCadastrada == false)
            {
                cout << "É necessário cadastrar uma conta primeiro." << endl;
                break;
            }
            cout << "2- Consultar Conta" << endl;

            // Tipo da conta
            if (tipoConta == 1)
            {
                cout << "Sua conta é do tipo: Conta Corrente" << endl;
            }
            else if (tipoConta == 2)
            {
                cout << "Sua conta é do tipo: Conta Poupança" << endl;
            }
            break;

        case 3:
            if (contaCadastrada == false)
            {
                cout << "É necessário cadastrar uma conta primeiro." << endl;
                break;
            }
            cout << "3- Verificar Saldo" << endl;

            // Verificação do saldo:
            cout << "Seu saldo é de: R$" << saldo << endl;
            break;

        case 4:
            if (contaCadastrada == false)
            {
                cout << "É necessário cadastrar uma conta primeiro." << endl;
                break;
            }
            cout << "4- Alterar tipo de Conta" << endl;

            // Alterar tipo de conta
            cout << "A sua conta atualmente é do tipo: ";
            if (tipoConta == 1)
            {
                cout << "1- Conta Corrente" << endl;
            }
            else if (tipoConta == 2)
            {
                cout << "2- Conta Poupança" << endl;
            }

            cout << "Deseja alterar o tipo da sua conta? (S/N)" << endl;
            cin >> resposta2;
            while (resposta2 != 'S' && resposta2 != 's' &&
                   resposta2 != 'N' && resposta2 != 'n')
            {
                cout << "Resposta inválida. Digite S ou N: ";
                cin >> resposta2;
            }

            if ((resposta2 == 'S' || resposta2 == 's') && tipoConta == 1)
            {
                tipoConta = 2;
                cout << "Tipo de conta alterado para: Conta Poupança";
            }
            else if ((resposta2 == 'S' || resposta2 == 's') && tipoConta == 2)
            {
                tipoConta = 1;
                cout << "Tipo de conta alterado para: Conta Corrente";
            }
            else if (resposta2 == 'N' || resposta2 == 'n')
            {
                cout << "Tipo de conta NÃO alterado.";
            }
            break;

        case 5:
            if (contaCadastrada == false)
            {
                cout << "É necessário cadastrar uma conta primeiro." << endl;
                break;
            }
            cout << "5- Ativar/Desativar Conta" << endl;

            // Ativar/ Desativar conta
            if (contaAtiva == true)
            {
                cout << "Sua conta está ATIVA. Deseja desativá-la? (S/N)" << endl;
                cin >> resposta3;
                while (resposta3 != 'S' && resposta3 != 's' &&
                       resposta3 != 'N' && resposta3 != 'n')
                {
                    cout << "Resposta inválida. Digite S ou N: ";
                    cin >> resposta3;
                }
                if (resposta3 == 'S' || resposta3 == 's')
                {
                    contaAtiva = false;
                    cout << "Sua conta foi DESATIVADA" << endl;
                }
                else
                {
                    cout << "Nenhuma alteração foi feita" << endl;
                }
            }

            else if (contaAtiva == false)
            {
                cout << "Sua conta está DESATIVADA. Deseja ativá-la? (S/N)" << endl;
                cin >> resposta3;
                if (resposta3 == 'S' || resposta3 == 's')
                {
                    contaAtiva = true;
                    cout << "Sua conta foi ATIVADA" << endl;
                }
                else
                {

                    cout << "Nenhuma alteração foi feita" << endl;
                }
            }
            break;

        case 6:
            cout << "6- Sair" << endl;
            break;

        default:
            cout << "Opção inválida" << endl;
        }
    }

    return 0;
}