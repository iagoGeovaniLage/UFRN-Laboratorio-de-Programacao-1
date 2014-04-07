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
		system("clear");
		while(op != 6){
			cout << "Menu de opções:\n";
			cout << "\tNovo Cliente......................1\n";
			cout << "\tListar Clientes...................2\n";
			cout << "\tNova Compra.......................3\n";
			cout << "\tNovo Crédito......................4\n";
			cout << "\tConsultar saldo...................5\n";
			cout << "\tSair do programa..................6\n";
			cout << "Digite a opção: ";
				cin >> op;
			system("clear");
			switch(op){
				case 1:
					float saldo;
					cout << "Digite o Saldo Inicial do Cliente: ";
						cin >> saldo;
					float limite;
					cout << "Digite o Limite do Cliente: ";
						cin >> limite;
					clientes->inserir(saldo, limite);
					break;
				case 2:
					clientes->listarClientes();
					break;
				case 3:
					break;
				case 4:
					break;
				case 5:
					break;
				case 6:
					cout<< "\nAté a próxima!\n\n";
					break;
				default:
					cout << "\nOpção inválida!\n\n";
					break;
			}
		}
	}
