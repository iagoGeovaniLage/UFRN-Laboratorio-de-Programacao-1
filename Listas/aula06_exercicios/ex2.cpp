/*
 * Crie uma classe chamada Ponto utilizando as seguintes informações: 
 * 		- Seus atributos são duas coordenadas x e y;
 * 		- Defina um construtor que recebe estes dois parâmetros;
 * 		- Defina os métodos get inline e os set normalmente;
 * 		- Escreva um método chamado equals que recebe um outro ponto como argumento 
 *		retornando true se as coordenadas de ambos forem iguais e false caso contrário;  
 * 		- Implemente um método chamado distancia que recebe um outro ponto como 
 * 		argumento e calcula a distância entre os dois. 
 */

#include <iostream>
#include <cmath> // biblioteca para uso das funções pow e sqtr
// inclusão de alguns metodos do namespace std
	using std::cout;
	using std::cin;

/*
 * Definição da classe ponto
 */
	class Ponto{
		// definição dos atributos da classe por padrão PRIVATE
			double x;
			double y;
			static int total;
		// definição dos metódos da classe todos públicos
			public:
				Ponto(double a, double b); // construtor
				virtual ~Ponto(){} // destrutor virtual -- chamada da função feita em tempo de execução e não em tempo de compilação como é o padrão

				// metodos get da classe
					double getPonto_x() const; // retorna a coordenada de x
					double getPonto_y() const; // retorna a coordenada de y
					static int getTotal() { return total; }

				// metodos set da classe
					void setPonto_x(double a); // retorna a coordenada de x
					void setPonto_y(double a); // retorna a coordenada de y

				// metodo para verificar se dois pontos são iguais
					bool equals (Ponto p) const;
				// metodo para verificar a distância entre dois pontos
					double dist(Ponto p) const;
	};
	// inicialização do dado membro estático
		int Ponto::total = 0;

	// metodo construtor da classe
		Ponto::Ponto(double a, double b){
			// inicialização dos atributos
				x = a;
				y = b;
				++total;
		}
	// metodos get da classe
		inline double Ponto::getPonto_x() const { return x; }
		inline double Ponto::getPonto_y() const { return y; }

	// metodos set da classe
		void Ponto::setPonto_x(double a) { x = a; }
		void Ponto::setPonto_y(double a) { y = a; }

	// metodo para verificar se dois pontos são iguais
		bool Ponto::equals (Ponto p) const { 
			if( (x == p.x) && (y == p.y) )
				return true;
			else
				return false;
		}
	// metodo para verificar a distância entre dois pontos
		double Ponto::dist(Ponto p) const {
			return sqrt(pow(x - p.x, 2.0) + pow(y - p.y, 2.0));
		}


int main(){

	// alocação dos pontos na memória
		Ponto* p1 = new Ponto( 1.0, 2.0 );
		Ponto* p2 = new Ponto( 1.0, 2.0 );

		cout << "O total de pontos é " << Ponto::getTotal() << ".\n";

	// chamadas do metodo getPonto para mostrar os pontos
		cout << "As coordenadas de P1 são (" << (*p1).getPonto_x() << "," << (*p1).getPonto_y() << ")\n";
		cout << "As coordenadas de P2 são (" << (*p2).getPonto_x() << "," << (*p2).getPonto_y() << ")\n";

	// metodo equals entre P1 e P2 - espera que sejam iguais
			if( (*p1).equals(*p2) )
				cout << "Os pontos P1 e P2 são iguais!\n";
			else
				cout << "Os pontos P1 e P2 são diferentes!\n";
	// metodo dist entre P1 e P2 - result = 0
			cout << "A distância entre os pontos P1 e P2 é " << (*p1).dist(*p2) << ".\n";

	// chamadas do metodo setPonto para atualizar o ponto P2
		(*p2).setPonto_x(1.0);
		(*p2).setPonto_y(3.0);

	// chamadas do metodo getPonto para mostrando os pontos atualizados
		cout << "As coordenadas de P1 são (" << (*p1).getPonto_x() << "," << (*p1).getPonto_y() << ")\n";
		cout << "As coordenadas de P2 são (" << (*p2).getPonto_x() << "," << (*p2).getPonto_y() << ")\n";

	// metodo equals entre P1 e P2 - espera que sejam diferentes
			if( (*p1).equals(*p2) )
				cout << "Os pontos P1 e P2 são iguais!\n";
			else
				cout << "Os pontos P1 e P2 são diferentes!\n";
	// metodo dist entre P1 e P2 - result = 1
			cout << "A distância entre os pontos P1 e P2 é " << (*p1).dist(*p2) << ".\n";


	// desalocação da memória dos pontos
		delete p1;
		delete p2;

	return 0;
}