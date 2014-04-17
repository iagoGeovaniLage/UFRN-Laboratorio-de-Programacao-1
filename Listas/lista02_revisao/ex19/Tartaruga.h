#ifndef _TARTARUGA_H_
	#define _TARTARUGA_H_
		class Tartaruga {
			int posicao;
			public:
				Tartaruga(); // construtor padrão
				// Função que faz o movimento de uma caminhada rapida
					void CaminhadaRapida();
				// Função que faz o movimento de uma escorregada
					void Escorregada();
				// Função que faz o movimento de uma caminhada lenta
					void CaminhadaLenta();
				// Função responsável por determinar qual movimento será executado
					void Movimento(int valor);
				// metodos set
					int getPosicao() const;
		};
#endif