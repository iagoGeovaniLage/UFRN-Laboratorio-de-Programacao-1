#include <iostream>

int mdc(int a, int b) {
	if (b == 0)
		return a;
	return mdc(b, a%b);
}
int mmc(int a,int b){
	return ( a * b ) / ( mdc(a,b) );
}

class Fracao {
	int num;
	int den;
	public:
		Fracao (int n, int d){
			if(d > 0){
				num = n;
				den = d;
			} else {
				num = n;
				den = 1;
			}
		}
		static void soma(Fracao f1, Fracao f2, Fracao *res){
			res->den = mmc(f1.den, f2.den);
			res->num = ( (res->den / f1.den) * f1.num ) + ( (res->den / f2.den) * f2.num );
		}
		static void sub(Fracao f1, Fracao f2, Fracao *res){
			res->den = mmc(f1.den, f2.den);
			res->num = ( (res->den / f1.den) * f1.num ) - ( (res->den / f2.den) * f2.num );
		}
		static void mult(Fracao f1, Fracao f2, Fracao *res){
			res->num = f1.num * f2.num;
			res->den = f1.den * f2.den;
		}
		static void div(Fracao f1, Fracao f2, Fracao *res){
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
};
int main(){
	Fracao *f1  = new Fracao(1,1);
	Fracao *f2  = new Fracao(1,1);
	Fracao *res = new Fracao(1,1);

	Fracao::soma(*f1, *f2, res);
	std::cout << (*res).getNum() << "/" << (*res).getDen() << "\n";

	Fracao::sub(*f1, *f2, res);
	std::cout << (*res).getNum() << "/" << (*res).getDen() << "\n";

	Fracao::mult(*f1, *f2, res);
	std::cout << (*res).getNum() << "/" << (*res).getDen() << "\n";

	Fracao::div(*f1, *f2, res);
	std::cout << (*res).getNum() << "/" << (*res).getDen() << "\n";
	
	std::cout << (*f1).compare(*f2) << "\n";
	std::cout << (*f1).compare(*res) << "\n";


	return 0;
}