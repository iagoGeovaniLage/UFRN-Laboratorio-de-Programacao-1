#ifndef _AUTOMOVEL_H_
	#define _AUTOMOVEL_H_
	class Automovel {
		float km, litros, consumo;
		Automovel * next;
		// atributos públicos
			public:
				Automovel(); // construtor padrão
				Automovel(float k, float l);
				// metodos set
					void setNext(Automovel * novo);
				// metodos get
					float getConsumo() const;
					Automovel * getNext() const;
	};
#endif	