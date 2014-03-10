#include <iostream>

/*
 * Funções necessárias para desenvolver os metodos de simplificação e soma subtração de frações
 * Não eram obrigatórias na prova bastava dizer que existiam
 */
 	// Função recursiva para encontrar o MDC entre dois inteiros (algortimo de euclides)
		int mdc(int a, int b) {
			if (b == 0)
				return a;
			return mdc(b, a % b);
		}

	// Função de MMC utilizando o MDC para encontrar o MMC entre dois inteiros
		int mmc(int a,int b) {
			return ( a * b ) / ( mdc(a,b) );
		}
// Classe Fração como pedido
	class Fracao {
		// definição dos atributos da classe por padrão PRIVATE
			int num;
			int den;
		// definição dos metódos da classe todos públicos
			public:
				// metódos de contrução e desconstrução
					Fracao () { } // método contrutor padrão
					Fracao (int n, int d); // método contrutor recebendo parametros
					virtual ~Fracao() { } // destrutor virtual -- chamada da função feita em tempo de execução e não em tempo de compilação como é o padrão

				// metódos estáticos - de uso da classe e não do objeto
					// soma entre duas frações
						static Fracao soma(Fracao f1, Fracao f2, Fracao *res) {
							res->den = mmc(f1.den, f2.den);
							res->num = ( (res->den / f1.den) * f1.num ) + ( (res->den / f2.den) * f2.num );
						}
					// subtração entre duas frações
						static void sub(Fracao f1, Fracao f2, Fracao *res) {
							res->den = mmc(f1.den, f2.den);
							res->num = ( (res->den / f1.den) * f1.num ) - ( (res->den / f2.den) * f2.num );
						}
					// multiplicação entre duas frações
						static void mult(Fracao f1, Fracao f2, Fracao *res) {
							res->num = f1.num * f2.num;
							res->den = f1.den * f2.den;
						}
					// divisão entre duas frações
						static void div(Fracao f1, Fracao f2, Fracao *res) {
							res->num = f1.num * f2.den;
							res->den = f1.den * f2.num;
						}
				// metodos get
					int getNum() const; // retorna o numerador do objeto fração 
					int getDen() const; // retorna o denominador do objeto fração

				// metodos set
					void setNum(int n); // recebe um inteiro n e faz a alteração do numerador do objeto fração
					void setDen(int d); // recebe um inteiro d e faz a alteração do denominador do objeto fração

				// comparação entre duas frações
					bool compare(Fracao f) const;
				// simplifica a fração usando o mdc entre o numerador e o denominador
					void simplifica();
	};
	// metódo contrutor
		Fracao::Fracao (int n, int d){
			if(d > 0) { // proíbe que o denominador seja menor ou igual a 0
				num = n;
				den = d;
			} else { // se ele for menor que 0 ele cria o a fração como se fosse um número inteiro com denominador 
				num = n;
				den = 1;
			}
		}
	// metodos get
		int Fracao::getNum() const { return num; } // retorna o numerador
		int Fracao::getDen() const { return den; } // retorna o denominador
	// metodos set
		void Fracao::setNum(int n) { num = n; } // recebe um inteiro n e faz a alteração do numerador do objeto fração
		void Fracao::setDen(int d) { den = d; } // recebe um inteiro n e faz a alteração do denominador do objeto fração
	// comparação entre duas frações
		bool Fracao::compare(Fracao f) const {
			if( (num == f.num) && (den == f.den) ) // se for igual retorna verdadeiro
				return true;
			else  // senão retorna falso
				return false;
		}
	// simplifica a fração usando o mdc entre o numerador e o denominador
		void Fracao::simplifica() {
			// alocação dinamica de x
				int *x = new int;

			*x = mdc(num, den); // váriavel x recebe o mdc entre o numerador e o denominador

			num /= *x; // divide o numerador pelo MDC entre o numerador e o denominador
			den /= *x; // divide o denominador pelo MDC entre o numerador e o denominador

			// desalocação da váriavel x
				delete x;
		}

int main(){
	// alocação das frações na memória
		Fracao *f1  = new Fracao(10,12);
		Fracao *f2  = new Fracao(16,26);
		// Fração que receberá os resultados das operações, instanciada pelo construtor padrão
			Fracao *res = new Fracao();

	std::cout << "\n--- Operações aritméticas entre frações (com simplificação) ---\n\n"; // pula linha

	// Operando uma soma entre as duas frações
			Fracao::soma(*f1, *f2, res);
			std::cout << "A soma entre " << f1->getNum() << "/" << f1->getDen();
			std::cout << " e " << f2->getNum() << "/" << f2->getDen() << " = ";
			std::cout << res->getNum() << "/" << res->getDen();
			res->simplifica();
			std::cout << " ou " << res->getNum() << "/" << res->getDen() << " simplicado.\n";

	// Operando uma subtração entre as duas frações
			Fracao::sub(*f1, *f2, res);
			std::cout << "A subtração entre " << f1->getNum() << "/" << f1->getDen();
			std::cout << " e " << f2->getNum() << "/" << f2->getDen() << " = ";
			std::cout << res->getNum() << "/" << res->getDen();
			res->simplifica();
			std::cout << " ou " << res->getNum() << "/" << res->getDen() << " simplicado.\n";

	// Operando uma multiplicação entre as duas frações
			Fracao::mult(*f1, *f2, res);
			std::cout << "A multiplicação entre " << f1->getNum() << "/" << f1->getDen();
			std::cout << " e " << f2->getNum() << "/" << f2->getDen() << " = ";
			std::cout << res->getNum() << "/" << res->getDen();
			res->simplifica();
			std::cout << " ou " << res->getNum() << "/" << res->getDen() << " simplicado.\n";

	// Operando uma divisão entre as duas frações
			Fracao::div(*f1, *f2, res);
			std::cout << "A divisão entre " << f1->getNum() << "/" << f1->getDen();
			std::cout << " e " << f2->getNum() << "/" << f2->getDen() << " = ";
			std::cout << res->getNum() << "/" << res->getDen();
			res->simplifica();
			std::cout << " ou " << res->getNum() << "/" << res->getDen() << " simplicado.\n";

	std::cout << "\n--- Comparação entre frações ---\n\n"; // pula linha

	// Teste do metódo SET, alterando frações para teste de comparação
		// alterando f1
			f1->setNum(2);
			f1->setDen(15);
		// alterando f2
			f2->setNum(2);
			f2->setDen(15);
			
	// teste da função compare - esperando iguais
		if(f1->compare(*f2))
			std::cout << "As frações " << f1->getNum() << "/" << f1->getDen() << " e " << f2->getNum() << "/" << f2->getDen() << " são iguais\n";
		else
			std::cout << "As frações " << f1->getNum() << "/" << f1->getDen() << " e " << f2->getNum() << "/" << f2->getDen() << " são diferentes\n";

	// teste da função compare - esperando diferentes
		if(f1->compare(*res))
			std::cout << "As frações " << f1->getNum() << "/" << f1->getDen() << " e " << res->getNum() << "/" << res->getDen() << " são iguais\n";
		else
			std::cout << "As frações " << f1->getNum() << "/" << f1->getDen() << " e " << res->getNum() << "/" << res->getDen() << " são diferentes\n";

	std::cout << "\n"; // pula linha

	return 0;
}