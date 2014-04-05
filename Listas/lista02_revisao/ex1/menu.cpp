#include <iostream>
#include <cstdlib> // para uso da função system()
#include "ListaAutomoveis.h"
#include "menu.h"

// alguns metódos do namespace std
	using std::cout;
	using std::cin;

// menu do programa
	void menu(int op, ListaAutomoveis * autos){
		system("clear");
		while(op != 3){
			cout << "Menu de opções:\n";
			cout << "\tNovo tanque......................1\n";
			cout << "\tListar os tanques................2\n";
			cout << "\tSair do programa.................3\n";
			cout << "Digite a opção: ";
				cin >> op;
			system("clear");
			switch(op){
				case 1:
					float k, l;
					cout << "Digite a quantidade de quilometros: ";
						cin >> k;
					cout << "Digite a quantidade de litros: ";
						cin >> l;
					autos->inserir(k,l);
					break;
				case 2:
					autos->imprimir();
					break;
				case 3:
					cout << "\nAté a próxima!\n\n";
					break;
				default:
					cout << "\nOpção inválida!\n\n";
					break;
			}
		}
	}
