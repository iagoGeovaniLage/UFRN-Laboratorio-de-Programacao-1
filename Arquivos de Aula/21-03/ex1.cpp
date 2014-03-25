/* 
 * ler 20 numeros que estão entre 10 - 100
 * a medida que cada numero for lido imprimao, somente se não for duplicata de um número já lido
 * utilize o menor array possível
 */
#include <iostream>
#include <cstdlib>
#define qtd 5

using std::cout;
using std::cin;

int main() {
	int *vet; // vetor principal
	int *vet_aux; // vetor de cópia
	int i, tam, controle;
	int num;
	bool teste;

	tam = 0;
	vet_aux = new int[tam+1]; // aloca um espaço de memória para o vetor de cópia
	
	for(i = 0; i <= qtd; i++) {
		// Inicializa o vetor principal com o tamanho necessário
			vet = new int[tam];
		/*
		 * Se já tiver lido todos os números irá preencher o vetor com o tamanho final
		 * e liberar a memória do vetor de cópia, caso contrário vai ler mais um número e fazer os testes
		 */
			if(i == qtd){
				for(int k = 0; k < tam; k++)
					vet[k] = vet_aux[k];
				delete vet_aux;
			} else {
				// Recebe da entrada padrão um número
					cout << "Digite um número inteiro: ";
						cin >> num;
				/*
				 * Se o for a primeira interação coloca o número lido no vetor principal
				 * e aumenta o tamanho de vetor, senão faz todo o processo de comparação do numero lido
				 * com os guardados atualmente no vetor principal
				 */
					if(i == 0){
						cout << "Número válido: " << num << "\n";
						vet[tam] = num;
						tam++;
					} else {
						// pega os dados do vetor de copia e coloca no vetor principal
							for(int k = 0; k < tam; k++)
								vet[k] = vet_aux[k];
						// libera a memória usada atualmente pelo vetor de cópia
							delete vet_aux;

						// aloca uma nova memória para o vetor de cópia
							vet_aux = new int[tam+1];

						// inicialização da váriavel controle e teste
							controle = 0;
							teste    = 1; // true
						while(controle < tam){
							if(vet[controle] == num){
								teste = 0; // false
								break; // quebra o laço, pois encontrou um número igual ao lido
							}
							controle++; // incrementa a variável de controle
						}
						// se teste true guarda o número no vetor, imprime na tela e aumenta o tamanho
							if (teste == 1) {
								cout << "Número válido: " << num << "\n";
								vet[tam] = num;
								tam++;
							}
					}
					// faz um cópia do vetor principal para o vetor auxiliar
						for(int k = 0; k <= tam; k++)
							vet_aux[k] = vet[k];
					// libera a memória atualmente usada pelo vetor principal
						delete vet;
			}
	}
	cout << "Tamanho do vetor: "<< tam << ".\n";
	cout << "Vetor: ";
	for(int k = 0; k < tam; k++)
		cout << vet[k] << " ";
	cout << "\n";

	delete vet;

}