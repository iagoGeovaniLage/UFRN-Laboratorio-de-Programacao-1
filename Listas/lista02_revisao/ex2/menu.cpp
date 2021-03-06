#include <iostream>
#include <cstdlib> // para uso da função system()

#include "Clientes.h"
#include "Cliente.h"

#include "menu.h"

// alguns metódos do namespace std
	using std::cout;
	using std::cin;

// menu do programa
	void menu(int op, Clientes * clientes){
		Cliente * cliente = new Cliente;
		int conta;
		float valor, saldo, limite;
		system("clear");
		while(op != 6){
			cout << "Menu de opções:\n";
			cout << "\tNovo Cliente................................1\n";
			cout << "\tListar Informações dos Clientes.............2\n";
			cout << "\tNova Compra.................................3\n";
			cout << "\tNovo Crédito................................4\n";
			cout << "\tConsultar saldo.............................5\n";
			cout << "\tSair do programa............................6\n";
			cout << "Digite a opção: ";
				cin >> op;
			system("clear");
			switch(op){
				case 1:
					saldo  = 1;
					limite = 0;
					while(saldo > limite){
						cout << "Digite o Saldo Inicial do Cliente: ";
							cin >> saldo;
						cout << "Digite o Limite do Cliente: ";
							cin >> limite;
						if(saldo > limite)
							cout << "O limite deve ser maior ou igual ao saldo!\n";
					}
					clientes->inserir(saldo, limite);
					break;
				case 2:
					if(Cliente::qtd != 0) {
						clientes->listarClientes();
					} else {
						system("clear");
						cout << "Não existem clientes!\n";
					}
					break;
				case 3:
					if(Cliente::qtd != 0) {
						conta = Cliente::qtd + 1;
						while(conta > Cliente::qtd){
							cout << "Digite a conta do cliente: ";
								cin >> conta;
							if(conta > Cliente::qtd){
								system("clear");
								cout << "Conta inválida!\n";
							}
						}
						cliente =  clientes->buscarCliente(conta);
						cout << "Digite o valor da compra: ";
							cin >> valor;
						cliente->inserirCompra(valor);
					} else{
						system("clear");
						cout << "Não existem clientes!\n";
					}
					break;
				case 4:
					if(Cliente::qtd != 0) {
						conta = Cliente::qtd + 1;
						while(conta > Cliente::qtd){
							cout << "Digite a conta do cliente: ";
								cin >> conta;
							if(conta > Cliente::qtd){
								system("clear");
								cout << "Conta inválida!\n";
							}
						}
						cliente = clientes->buscarCliente(conta);
						cout << "Digite o valor do crédito: ";
							cin >> valor;
						cliente->inserirCredito(valor);
					} else{
						system("clear");
						cout << "Não existem clientes!\n";
					}
					break;
				case 5:
					if(Cliente::qtd != 0) {
						conta = Cliente::qtd + 1;
						while(conta > Cliente::qtd){
							cout << "Digite a conta do cliente: ";
								cin >> conta;
							if(conta > Cliente::qtd){
								system("clear");
								cout << "Conta inválida!\n";
							}
						}
						cliente = clientes->buscarCliente(conta);
						cout << "O saldo atual do cliente é R$ " << cliente->getSaldoAtual() << "\n\n";
					} else{
						system("clear");
						cout << "Não existem clientes!\n";
					}
					break;
				case 6:
					cout<< "\nAté a próxima!\n\n";
					break;
				default:
					cout << "\nOpção inválida!\n\n";
					break;
			}
		}
		delete cliente;
	}