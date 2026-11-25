#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

// Na minha lógica o usuário terá que preencher todos os dados da opção 1 para poder seguir para as demais opções.

const int max_contas = 100; // Limite máximo de 100 contas

int numeroConta[max_contas];
int tipoConta[max_contas];
string nomeCliente[max_contas];
string cpf[max_contas];
double saldo[max_contas];
bool contaAtiva[max_contas];

int quantidadeContas = 0;

const int max_movimentacoes = 500;

// Variáveis utilizadas no case 4
int contaMovimentacao[max_movimentacoes];
char tipoMovimentacao[max_movimentacoes];
double valorMovimentacao[max_movimentacoes];

int quantidadeMovimentacoes = 0;

// Lê o arquivo contas.txt e preenche os arrays
void carregarContas()
{
    ifstream arquivo("contas.txt");

    // Se o arquivo não existe (primeira execução), não faz nada
    if (!arquivo.is_open())
    {
        return;
    }

    string campo;

    while (quantidadeContas < max_contas && getline(arquivo, campo, ';'))
    {
        numeroConta[quantidadeContas] = stoi(campo);

        getline(arquivo, nomeCliente[quantidadeContas], ';');
        getline(arquivo, cpf[quantidadeContas], ';');

        getline(arquivo, campo, ';');
        tipoConta[quantidadeContas] = stoi(campo);

        getline(arquivo, campo, ';');
        saldo[quantidadeContas] = stod(campo);

        getline(arquivo, campo);
        contaAtiva[quantidadeContas] = (campo[0] == '1');

        quantidadeContas++;
    }

    arquivo.close();
}

// Grava todos os dados dos arrays de contas no arquivo contas.txt
void salvarContas()
{
    ofstream arquivo("contas.txt");

    if (arquivo.is_open())
    {
        arquivo << fixed << setprecision(2);

        for (int i = 0; i < quantidadeContas; i++)
        {
            arquivo << numeroConta[i] << ";"
                    << nomeCliente[i] << ";"
                    << cpf[i] << ";"
                    << tipoConta[i] << ";"
                    << saldo[i] << ";"
                    << contaAtiva[i] << endl;
        }

        arquivo.close();
    }
    else
    {
        cout << "Erro ao salvar o arquivo contas.txt" << endl;
    }
}

// Lê o arquivo movimentacoes.txt e preenche os arrays
void carregarMovimentacoes()
{
    ifstream arquivo("movimentacoes.txt");

    // Se o arquivo não existe (primeira execução), não faz nada
    if (!arquivo.is_open())
    {
        return;
    }

    string campo;

    while (quantidadeMovimentacoes < max_movimentacoes && getline(arquivo, campo, ';'))
    {
        contaMovimentacao[quantidadeMovimentacoes] = stoi(campo);

        getline(arquivo, campo, ';');
        tipoMovimentacao[quantidadeMovimentacoes] = campo[0];

        getline(arquivo, campo);
        valorMovimentacao[quantidadeMovimentacoes] = stod(campo);

        quantidadeMovimentacoes++;
    }

    arquivo.close();
}

// Grava todo o histórico de movimentações no arquivo movimentacoes.txt
void salvarMovimentacoes()
{
    ofstream arquivo("movimentacoes.txt");

    if (arquivo.is_open())
    {
        arquivo << fixed << setprecision(2);

        for (int i = 0; i < quantidadeMovimentacoes; i++)
        {
            arquivo << contaMovimentacao[i] << ";"
                    << tipoMovimentacao[i] << ";"
                    << valorMovimentacao[i] << endl;
        }

        arquivo.close();
    }
    else
    {
        cout << "Erro ao salvar o arquivo movimentacoes.txt" << endl;
    }
}

int main()
{
    char resposta;
    int opcao;

    // Carrega os dados salvos nas execuções anteriores
    carregarContas();
    carregarMovimentacoes();

    opcao = 1;

    while (opcao != 8)
    {
        // Menu
        cout << "*******************" << endl;
        cout << "*** BANCO SWIFT ***" << endl;
        cout << "*******************" << endl;
        cout << "1- Cadastrar Conta" << endl;
        cout << "2- Listar Contas" << endl;
        cout << "3- Consultar Conta" << endl;
        cout << "4- Realizar Depósitos" << endl;
        cout << "5- Realizar Saques" << endl;
        cout << "6- Realizar Transferências" << endl;
        cout << "7- Exibir Extrato" << endl;
        cout << "8- Sair" << endl;

        // Cliente escolhe uma opção do Menu
        cout << "Escolha uma opção: " << endl;
        cin >> opcao;

        switch (opcao)
        {
        case 1:
        {
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
            bool numeroExistente = false;

            for (int i = 0; i < quantidadeContas; i++)
            {
                if (numeroConta[i] == numeroConta[quantidadeContas])
                {
                    numeroExistente = true;
                    break;
                }
            }

            if (numeroExistente == true)
            {
                cout << "Este número de conta já está cadastrado." << endl;
                break;
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

            quantidadeContas++;

            // Salva a nova conta no arquivo
            salvarContas();

            break;
        }
        case 2:
        {
            cout << "2- Listar Contas Cadastradas" << endl;

            if (quantidadeContas == 0)
            {
                cout << "Nenhuma conta cadastrada." << endl;
                break;
            }

            for (int i = 0; i < quantidadeContas; i++)
            {
                cout << "\n--------------------------------" << endl;
                cout << "Conta: " << numeroConta[i] << endl;
                cout << "Nome do cliente: " << nomeCliente[i] << endl;
                cout << "CPF: " << cpf[i] << endl;
                cout << "Tipo da conta: " << tipoConta[i] << endl;
                cout << "Saldo: R$ " << saldo[i] << endl;

                if (contaAtiva[i] == true)
                {
                    cout << "Status: Ativa" << endl;
                }
                else
                {
                    cout << "Status: Desativada" << endl;
                }
            }

            cout << "--------------------------------" << endl;

            break;
        }

        case 3:
        {
            if (quantidadeContas == 0)
            {
                cout << "É necessário cadastrar uma conta primeiro." << endl;
                break;
            }

            int contaBusca;
            cout << "Digite o número da conta que deseja consultar: ";
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
        case 4:
        {
            if (quantidadeContas == 0)
            {
                cout << "É necessário cadastrar uma conta primeiro." << endl;
                break;
            }

            cout << "4- Realizar Depósito" << endl;

            int contaBusca;
            double valor;

            cout << "Digite o número da conta: ";
            cin >> contaBusca;

            for (int i = 0; i < quantidadeContas; i++)
            {
                if (numeroConta[i] == contaBusca)
                {
                    if (contaAtiva[i] == false)
                    {
                        cout << "Esta conta está desativada. Não é possível realizar depósitos." << endl;
                        break;
                    }
                    if (quantidadeMovimentacoes >= max_movimentacoes)
                    {
                        cout << "Limite de movimentações atingido." << endl;
                        break;
                    }
                    cout << "Digite o valor do depósito: R$ ";
                    cin >> valor;

                    while (valor <= 0)
                    {
                        cout << "Valor inválido. Digite um valor positivo: R$ ";
                        cin >> valor;
                    }

                    saldo[i] = saldo[i] + valor;

                    cout << "Depósito realizado com sucesso!" << endl;
                    cout << "Novo saldo: R$ " << saldo[i] << endl;

                    contaMovimentacao[quantidadeMovimentacoes] = numeroConta[i];
                    tipoMovimentacao[quantidadeMovimentacoes] = 'D';
                    valorMovimentacao[quantidadeMovimentacoes] = valor;

                    quantidadeMovimentacoes++;

                    // Salva o novo saldo e a movimentação nos arquivos
                    salvarContas();
                    salvarMovimentacoes();

                    break;
                }

                if (i == quantidadeContas - 1)
                {
                    cout << "Conta não encontrada." << endl;
                }
            }

            break;
        }
        case 5:
        {
            if (quantidadeContas == 0)
            {
                cout << "É necessário cadastrar uma conta primeiro." << endl;
                break;
            }

            cout << "5- Realizar Saque" << endl;

            int contaBusca;
            double valor;

            cout << "Digite o número da conta: ";
            cin >> contaBusca;

            for (int i = 0; i < quantidadeContas; i++)
            {
                if (numeroConta[i] == contaBusca)
                {
                    if (contaAtiva[i] == false)
                    {
                        cout << "Esta conta está desativada." << endl;
                        break;
                    }

                    cout << "Digite o valor do saque: R$ ";
                    cin >> valor;

                    while (valor <= 0)
                    {
                        cout << "Valor inválido. Digite um valor positivo: R$ ";
                        cin >> valor;
                    }

                    if (valor > saldo[i])
                    {
                        cout << "Saldo insuficiente para realizar o saque." << endl;
                        break;
                    }

                    if (quantidadeMovimentacoes >= max_movimentacoes)
                    {
                        cout << "Limite de movimentações atingido." << endl;
                        break;
                    }

                    saldo[i] = saldo[i] - valor;

                    cout << "Saque realizado com sucesso!" << endl;
                    cout << "Novo saldo: R$ " << saldo[i] << endl;

                    // Registro da movimentação
                    contaMovimentacao[quantidadeMovimentacoes] = numeroConta[i];
                    tipoMovimentacao[quantidadeMovimentacoes] = 'S';
                    valorMovimentacao[quantidadeMovimentacoes] = valor;

                    quantidadeMovimentacoes++;

                    // Salva o novo saldo e a movimentação nos arquivos
                    salvarContas();
                    salvarMovimentacoes();

                    break;
                }

                if (i == quantidadeContas - 1)
                {
                    cout << "Conta não encontrada." << endl;
                }
            }

            break;
        }

        case 6:
        {
            if (quantidadeContas < 2)
            {
                cout << "É necessário ter pelo menos duas contas cadastradas." << endl;
                break;
            }

            cout << "6- Realizar Transferência" << endl;

            int contaOrigem, contaDestino;
            int indiceOrigem = -1;
            int indiceDestino = -1;
            double valor;

            cout << "Digite o número da conta de origem: ";
            cin >> contaOrigem;

            cout << "Digite o número da conta de destino: ";
            cin >> contaDestino;

            // Procurar as duas contas
            for (int i = 0; i < quantidadeContas; i++)
            {
                if (numeroConta[i] == contaOrigem)
                {
                    indiceOrigem = i;
                }

                if (numeroConta[i] == contaDestino)
                {
                    indiceDestino = i;
                }
            }

            // Verificar se as contas existem
            if (indiceOrigem == -1 || indiceDestino == -1)
            {
                cout << "Uma ou ambas as contas não foram encontradas." << endl;
                break;
            }

            // Verificar se são contas diferentes
            if (indiceOrigem == indiceDestino)
            {
                cout << "Não é possível transferir para a mesma conta." << endl;
                break;
            }

            // Verificar se as contas estão ativas
            if (contaAtiva[indiceOrigem] == false || contaAtiva[indiceDestino] == false)
            {
                cout << "As duas contas precisam estar ativas para realizar a transferência." << endl;
                break;
            }

            cout << "Digite o valor da transferência: R$ ";
            cin >> valor;

            while (valor <= 0)
            {
                cout << "Valor inválido. Digite um valor positivo: R$ ";
                cin >> valor;
            }

            // Verificar saldo da conta de origem
            if (valor > saldo[indiceOrigem])
            {
                cout << "Saldo insuficiente para realizar a transferência." << endl;
                break;
            }

            // A transferência gera duas movimentações
            if (quantidadeMovimentacoes + 2 > max_movimentacoes)
            {
                cout << "Limite de movimentações atingido." << endl;
                break;
            }

            // Atualizar os saldos
            saldo[indiceOrigem] = saldo[indiceOrigem] - valor;
            saldo[indiceDestino] = saldo[indiceDestino] + valor;

            // Registrar saída na conta de origem
            contaMovimentacao[quantidadeMovimentacoes] = numeroConta[indiceOrigem];
            tipoMovimentacao[quantidadeMovimentacoes] = 'S';
            valorMovimentacao[quantidadeMovimentacoes] = valor;
            quantidadeMovimentacoes++;

            // Registrar entrada na conta de destino
            contaMovimentacao[quantidadeMovimentacoes] = numeroConta[indiceDestino];
            tipoMovimentacao[quantidadeMovimentacoes] = 'D';
            valorMovimentacao[quantidadeMovimentacoes] = valor;
            quantidadeMovimentacoes++;

            cout << "Transferência realizada com sucesso!" << endl;
            cout << "Novo saldo da conta de origem: R$ " << saldo[indiceOrigem] << endl;
            cout << "Novo saldo da conta de destino: R$ " << saldo[indiceDestino] << endl;

            // Salva os novos saldos e as duas movimentações nos arquivos
            salvarContas();
            salvarMovimentacoes();

            break;
        }
        case 7:
        {
            if (quantidadeContas == 0)
            {
                cout << "É necessário cadastrar uma conta primeiro." << endl;
                break;
            }

            cout << "7- Consultar Extrato" << endl;

            int contaBusca;
            bool encontrouConta = false;
            bool encontrouMovimentacao = false;

            cout << "Digite o número da conta: ";
            cin >> contaBusca;

            // Verificar se a conta existe
            for (int i = 0; i < quantidadeContas; i++)
            {
                if (numeroConta[i] == contaBusca)
                {
                    encontrouConta = true;
                    break;
                }
            }

            if (encontrouConta == false)
            {
                cout << "Conta não encontrada." << endl;
                break;
            }

            cout << "\nExtrato da conta " << contaBusca << endl;
            cout << "--------------------------------" << endl;

            // Percorrer o histórico de movimentações
            for (int i = 0; i < quantidadeMovimentacoes; i++)
            {
                if (contaMovimentacao[i] == contaBusca)
                {
                    encontrouMovimentacao = true;

                    if (tipoMovimentacao[i] == 'D')
                    {
                        cout << "Depósito: + R$ " << valorMovimentacao[i] << endl;
                    }
                    else if (tipoMovimentacao[i] == 'S')
                    {
                        cout << "Saque/Transferência: - R$ " << valorMovimentacao[i] << endl;
                    }
                }
            }

            if (encontrouMovimentacao == false)
            {
                cout << "Nenhuma movimentação encontrada para esta conta." << endl;
            }

            cout << "--------------------------------" << endl;

            // Mostrar saldo atual
            for (int i = 0; i < quantidadeContas; i++)
            {
                if (numeroConta[i] == contaBusca)
                {
                    cout << "Saldo atual: R$ " << saldo[i] << endl;
                    break;
                }
            }

            break;
        }
        case 8:
        {
            cout << "Encerrando o sistema BANCO SWIFT..." << endl;
            cout << "Obrigado por utilizar nossos serviços!" << endl;
            break;
        }
        default:
        {
            cout << "Opção inválida. Escolha uma opção entre 1 e 8." << endl;
            break;
        }
        }
    }
    return 0;
}