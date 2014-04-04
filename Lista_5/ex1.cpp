/*
 * 
 * Os motoristas estão preocupados com a quilometragem obtida por seus automóveis. 
 * Um motorista fez um controle de vários tanques de gasolina gastos, anotando os quilômetros de rodagem
 * obtidos pelo tanque.
 * 
 * Desenvolva um programa em C++ que recebe como entrada os quilômetros rodados e os litros para cada tanque.
 * O programa deve calcular e exibir os quilômetros por litro obtidos para cada tanque.
 * Depois de processar todas as informações fornecidas, o programa deve calcular e
 * imprimir os quilômetros por litro obtidos por todos os tanques combinados. 
 * 
 * Você deve utilizar uma classe para representar as informações sobre cada automóvel.
 * 
 */

#include <iostream>
#include <cstdlib>

// alguns metódos do namespace std
	using std::cout;
	using std::cin;

// Classe que representa cada automóvel
	class Automovel {
		// atributos públicos
			float km;
			float litros;
			float consumo;
			Automovel * next;
			public:
				Automovel()	{ next = NULL; } // construtor padrão
				Automovel(float k, float l){
					km      = k;
					litros  = l;
					consumo = km / litros;
					next = NULL;
				}
				// metodos set
					void setNext(Automovel *novo){ next = novo; }
				// metodos get
					float getConsumo() const { return consumo; }
					Automovel * getNext() const { return next; }
	};
	class ListaAutomoveis {
		Automovel * head; // aponta para o primeiro tanque listado
		public:	
			ListaAutomoveis(){
				head = NULL;
			}
			// Método para adicionar um elemento novo ao final da lista.
				void inserir (float k, float l) { 
		            Automovel *novoAutomovel = new Automovel(k,l);
		            if (head == NULL)
		                head = novoAutomovel;
		            else {
		                Automovel *onde = head;
		                while (onde->getNext())
		                    onde = onde->getNext();
		                onde->setNext(novoAutomovel);
		            }
					// mensagem falando do consumo cadastrado
						cout << "\nO consumo desse tanque foi de " << novoAutomovel->getConsumo() << "km/l.\n\n";
		        }
			// Método para imprimir, na saída padrão, todos os elementos na tela;
		        void imprimir(){
		            Automovel* temp = head;
		            int cont = 0;
		            cout << "Consumo dos tanques:\n";
		            while (temp) {
		                cout << "\tTanque " << ++cont << ": " << temp->getConsumo() << "km/l.\n";
		                temp = temp->getNext();
		            }
		            cout << "\n";
		        }
 	};

	// menu do programa
		void menu(int op, ListaAutomoveis *autos){
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


// Programa principal
	int main(){

		ListaAutomoveis *automoveis = new ListaAutomoveis;
		menu(0,automoveis);

		return 0;
	}