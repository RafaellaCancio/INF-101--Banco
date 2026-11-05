#include <iostream>
#include <string>
using namespace std;

// Na minha lógica o usuário terá que preencher todos os dados da opção 1 para poder seguir para as demais opções.

int main()
{
    const int max_contas = 100; // Limite máximo de 100 contas

    int numeroConta[max_contas];
    int tipoConta[max_contas];
    string nomeCliente[max_contas];
    string cpf[max_contas];
    double saldo[max_contas];
    bool contaAtiva[max_contas];
    bool contaCadastrada;
    char resposta, resposta2, resposta3;
    int opcao;

    int quantidadeContas = 0;

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
            if (quantidadeContas >= max_contas)
            {
                cout << "Limite máximo de contas atingido." << endl;
                break;
            }
            cout << "1- Cadastrar Conta" << endl;

            // Número da conta
            cout << "Número da conta: " << endl;
            cin >> numeroConta[quantidadeContas];

            // Validação: número da conta positivo
            while (numeroConta[quantidadeContas] <= 0)
            {
                cout << "Número de conta inválido." << endl;
                cout << "Digite novamente o número da conta: " << endl;
                cin >> numeroConta[quantidadeContas];
            }

            cin.ignore();

            // Nome do titular
            cout << "Nome do titular: " << endl;
            getline(cin, nomeCliente[quantidadeContas]);

            // Número do CPF
            cout << "Número do CPF: " << endl;
            cin >> cpf[quantidadeContas];

            // Tipo da conta
            cout << "Tipo da conta: " << endl;
            cin >> tipoConta[quantidadeContas];

            while (tipoConta[quantidadeContas] != 1 && tipoConta[quantidadeContas] != 2)
            {
                cout << "Tipo de conta não existente" << endl;
                cout << "1- Conta Corrente" << endl;
                cout << "2- Conta Poupança" << endl;
                cout << "Escolha o tipo da conta: ";
                cin >> tipoConta[quantidadeContas];
            }

            if (tipoConta[quantidadeContas] == 1)
            {
                cout << "1- Conta Corrente" << endl;
            }

            else if (tipoConta[quantidadeContas] == 2)
            {
                cout << "2- Conta Poupança" << endl;
            }

            // Saldo inicial
            cout << "Saldo inicial: " << endl;
            cin >> saldo[quantidadeContas];

            // Validação: saldo positivo
            while (saldo[quantidadeContas] < 0)
            {
                cout << "O saldo inicial não pode ser negativo." << endl;
                cout << "Digite novamente o saldo inicial: " << endl;
                cin >> saldo[quantidadeContas];
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
                contaAtiva[quantidadeContas] = true;
                cout << "Sua conta foi ativada." << endl;
            }
            else if (resposta == 'N' || resposta == 'n')
            {
                contaAtiva[quantidadeContas] = false;
                cout << "Sua conta NÃO foi ativada." << endl;
            }

            contaCadastrada = true;

            quantidadeContas++;
            break;

        case 2:
        {   
            if (quantidadeContas == 0)
            {
                cout << "É necessário cadastrar uma conta primeiro." << endl;
                break;
            }

            int contaBusca;
            cout << "Digite o número da conta: ";
            cin >> contaBusca;

            for (int i = 0; i < quantidadeContas; i++)
            {
                if (numeroConta[i] == contaBusca)
                {
                    cout << "Nome: " << nomeCliente[i] << endl;
                    cout << "CPF: " << cpf[i] << endl;

                    if (tipoConta[i] == 1)
                    {
                        cout << "Tipo: Conta Corrente" << endl;
                    }
                    else
                    {
                        cout << "Tipo: Conta Poupança" << endl;
                    }

                    cout << "Saldo: R$ " << saldo[i] << endl;

                    cout << "Situação: ";
                    if (contaAtiva[i] == true)
                    {
                        cout << "Ativa" << endl;
                    }
                    else
                    {
                        cout << "Desativada" << endl;
                    }

                    break;
                }

                if (i == quantidadeContas - 1)
                {
                    cout << "Conta não encontrada." << endl;
                }
            }

            break;
            }
            
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
            if (tipoConta[max_contas] == 1)
            {
                cout << "1- Conta Corrente" << endl;
            }
            else if (tipoConta[max_contas] == 2)
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

            if ((resposta2 == 'S' || resposta2 == 's') && tipoConta[max_contas] == 1)
            {
                tipoConta[max_contas] = 2;
                cout << "Tipo de conta alterado para: Conta Poupança";
            }
            else if ((resposta2 == 'S' || resposta2 == 's') && tipoConta[max_contas] == 2)
            {
                tipoConta[max_contas] = 1;
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
            cout << "teste";

            // Ativar/ Desativar conta
            if (contaAtiva[max_contas] == true)
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
                    contaAtiva[max_contas] = false;
                    cout << "Sua conta foi DESATIVADA" << endl;
                }
                else
                {
                    cout << "Nenhuma alteração foi feita" << endl;
                }
            }

            else if (contaAtiva[max_contas] == false)
            {
                cout << "Sua conta está DESATIVADA. Deseja ativá-la? (S/N)" << endl;
                cin >> resposta3;
                if (resposta3 == 'S' || resposta3 == 's')
                {
                    contaAtiva[max_contas] = true;
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