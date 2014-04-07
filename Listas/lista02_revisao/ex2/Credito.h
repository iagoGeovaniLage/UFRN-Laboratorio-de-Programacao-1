#ifndef _CREDITO_H_
	#define _CREDITO_H_
		class Credito{
			float valor;
			Credito * next;
			public:
				// Construstor Padrão
					Credito();
				// Construto 
					Credito(float v);
				// Metódos SET
					void setNext(Credito * novo);
				// Metódos GET
					Credito * getNext() const;
		};
#endif