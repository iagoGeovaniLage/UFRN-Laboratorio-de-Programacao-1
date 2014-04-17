#ifndef _LEBRE_H_
	#define _LEBRE_H_
		class Lebre {
			int posicao;
			public:
				// Contrutor Padrão
					Lebre();
				// Função que faz o movimento de um grande pulo
					void GrandePulo();
				// Função que faz o movimento de uma grande escorregada
					void GrandeEscorregada();
				// Função que faz o movimento de um pulo pequeno
					void PuloPequeno();
				// Função que faz o movimento de uma escorregada pequena
					void EscorregadaPequena();
				// Função responsável por determinar qual movimento será executado
					void Movimento(int valor);
				// metodos set
					int getPosicao() const;
		};
#endif