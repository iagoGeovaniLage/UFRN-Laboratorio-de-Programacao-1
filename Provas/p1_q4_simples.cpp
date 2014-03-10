#include <iostream>

/*
 * Funções necessárias para desenvolver os metodos de simplificação e soma subtração de frações
 * Não eram obrigatórias na prova bastava dizer que existiam
 */
	int mdc(int a, int b) {
		if (b == 0)
			return a;
		return mdc(b, a % b);
	}
	int mmc(int a,int b) { return ( a * b ) / ( mdc(a,b) ); }

class Fracao {
	int num;
	int den;
	public:
		Fracao () { } // construtor padrão
		Fracao (int n, int d){
			if(d > 0) {
				num = n;
				den = d;
			} else {
				num = n;
				den = 1;
			}
		}
		~Fracao() { }
		static Fracao soma(Fracao f1, Fracao f2, Fracao *res) {
			res->den = mmc(f1.den, f2.den);
			res->num = ( (res->den / f1.den) * f1.num ) + ( (res->den / f2.den) * f2.num );
		}
		static void sub(Fracao f1, Fracao f2, Fracao *res) {
			res->den = mmc(f1.den, f2.den);
			res->num = ( (res->den / f1.den) * f1.num ) - ( (res->den / f2.den) * f2.num );
		}
		static void mult(Fracao f1, Fracao f2, Fracao *res) {
			res->num = f1.num * f2.num;
			res->den = f1.den * f2.den;
		}
		static void div(Fracao f1, Fracao f2, Fracao *res) {
			res->num = f1.num * f2.den;
			res->den = f1.den * f2.num;
		}
		int getNum() const { return num; }
		int getDen() const { return den; }
		void setNum(int n) { num = n; }
		void setDen(int d) { den = d; }
		bool compare(Fracao f) const {
			if( (num == f.num) && (den == f.den) )
				return true;
			else
				return false;
		}
		void simplifica() {
			int *x = new int;
			*x = mdc(num, den);
			num /= *x;
			den /= *x;
			delete x;
		}
};

int main(){
	Fracao *f1  = new Fracao(10,12);
	Fracao *f2  = new Fracao(16,26);
	Fracao *res = new Fracao();
	Fracao::soma(*f1, *f2, res);
	std::cout << f1->getNum() << "/" << f1->getDen() << " + " << f2->getNum() << "/" << f2->getDen() << " = " << res->getNum() << "/" << res->getDen();
	res->simplifica();
	std::cout << " ou " << res->getNum() << "/" << res->getDen() << " simplicado.\n";

	Fracao::sub(*f1, *f2, res);
	std::cout << f1->getNum() << "/" << f1->getDen() << " - " << f2->getNum() << "/" << f2->getDen() << " = " << res->getNum() << "/" << res->getDen();
	res->simplifica();
	std::cout << " ou " << res->getNum() << "/" << res->getDen() << " simplicado.\n";

	Fracao::mult(*f1, *f2, res);
	std::cout << f1->getNum() << "/" << f1->getDen() << " * " << f2->getNum() << "/" << f2->getDen() << " = " << res->getNum() << "/" << res->getDen();
	res->simplifica();
	std::cout << " ou " << res->getNum() << "/" << res->getDen() << " simplicado.\n";

	Fracao::div(*f1, *f2, res);
	std::cout << f1->getNum() << "/" << f1->getDen() << " / " << f2->getNum() << "/" << f2->getDen() << " = " << res->getNum() << "/" << res->getDen();
	res->simplifica();
	std::cout << " ou " << res->getNum() << "/" << res->getDen() << " simplicado.\n";

	f1->setNum(2);
	f1->setDen(15);
	f2->setNum(2);
	f2->setDen(15);
	if(f1->compare(*f2))
		std::cout << "As frações " << f1->getNum() << "/" << f1->getDen() << " e " << f2->getNum() << "/" << f2->getDen() << " são iguais\n";
	else
		std::cout << "As frações " << f1->getNum() << "/" << f1->getDen() << " e " << f2->getNum() << "/" << f2->getDen() << " são diferentes\n";
	if(f1->compare(*res))
		std::cout << "As frações " << f1->getNum() << "/" << f1->getDen() << " e " << res->getNum() << "/" << res->getDen() << " são iguais\n";
	else
		std::cout << "As frações " << f1->getNum() << "/" << f1->getDen() << " e " << res->getNum() << "/" << res->getDen() << " são diferentes\n";
	return 0;
}