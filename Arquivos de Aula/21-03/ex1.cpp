/* 
 * ler 20 numeros que estão entre 10 - 100
 * a medida que cada numero for lido imprimao, somente se não for duplicata de um número já lido
 * utilize o menor array possível
 */

#include <iostream>
#include <cstdlib>
#define qtd 20 // qtd de números a serem digitados

using std::cout;
using std::cin;

// função para fazer copia de vetor, (vetor que receberá a cópia, vetor que será copiado, tamanho dos vetores)
	void copia(int *vet, int *vet_aux, int tam){
		for(int k = 0; k < tam; k++)
			vet[k] = vet_aux[k];
	}

// programa principal
	int main() {
		int *vet; // vetor principal
		int *vet_aux; // vetor de cópia
		int i, tam, controle; // variaveis de controle e tamanho
		int num; // variável de leitura padrão que receberá o número digitado
		bool teste; // teste bolleano

		tam = 1; // inicialização do tamanho
		vet_aux = new int[tam]; // aloca um espaço de memória para o vetor de cópia
		
		for(i = 0; i < qtd; i++) {
			// Recebe da entrada padrão um número
				cout << "Digite um número entre 10 e 100: ";
					cin >> num;
			if(num < 10 || num > 100) {
				cout << "Número inválido!\n";
				i--;
			} else {
				/*
				 * Se o for a primeira interação coloca o número lido no vetor principal
				 * e aumenta o tamanho de vetor, senão faz todo o processo de comparação do numero lido
				 * com os guardados atualmente no vetor principal
				 */
					if(i == 0) {
						cout << "Número válido: " << num << "\n";
						vet_aux[0] = num;
					} else {
						// inicialização da váriavel controle e teste
							controle = 0;
							teste    = 1; // true
						while(controle < tam) {
							if(vet_aux[controle] == num) {
								teste = 0; // false
								break; // quebra o laço, pois já foi encontrado um número igual ao lido
							}
							controle++; // incrementa a variável de controle
						}
						// se teste = true, então guarda o número no vetor, imprime na tela e aumenta o tamanho
							if (teste) {
								tam++; // aumenta o tamanho atual do vetor
								// Inicializa o vetor principal com o tamanho necessário
									vet = new int[tam];
								// pega os dados do vetor de copia e coloca no vetor principal
									copia(vet, vet_aux, tam);
								// libera a memória usada atualmente pelo vetor de cópia
									delete vet_aux;

								// coloca o numero lido na última posição do vetor principal e mostra na tela
									vet[tam-1] = num;
									cout << "Número válido: " << vet[tam-1] << "\n";
								// se não for o último número lido, então faz a cópia do vetor principal
									if(i < (qtd - 1)) {
										// aloca uma nova memória para o vetor de cópia
											vet_aux = new int[tam];
										// faz uma cópia do vetor principal para o vetor auxiliar
											copia(vet_aux, vet, tam);
										// libera a memória atualmente usada pelo vetor principal
											delete vet;
									}
							} else {
								cout << "Número repetido!\n"; // mensagem de número repetido
							}
					}
			}
		}

		// mostra o tamanho usado no vetor e como ficou o vetor depois de todo o processo
			cout << "Tamanho do vetor: "<< tam << ".\n";
			cout << "Vetor: ";
			for(int k = 0; k < tam; k++)
				cout << vet[k] << " ";
			cout << "\n";

		// libera a memória usa pelo vetor principal
			delete vet;
	}