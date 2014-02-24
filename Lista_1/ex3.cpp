/*
 * Escreva um programa que monte uma lista de números inteiros positivos. 
 * Para cada novo número inteiro digitado pelo usuário no teclado,
 * o programa deve alocar uma nova variável no heap
 * e inserí-la no final da lista composta pelos números já digitados. 
 *  
 * Quando o usuário digitar um número menor ou igual a 0 (zero), o programa deve imprimir todos os números
 * digitados, na ordem em que eles foram alimentados pelo usuário.
 * Utilizar o tipo de dados struct Item definido abaixo:
 * 		Struct Item {
 * 			int valor;
 * 			struct Item *proximo;
 *	 	};
 */

#include <iostream>

// Estrutura da lista
	struct Item {
		int valor;
		struct Item *proximo;
	};

// Função que cria uma nova lista
	Item * cria_lista(){
		// Alocação das variáveis do tipo Item
		    struct Item *novo = new struct Item;
		    struct Item *aux = new struct Item; 
	 
	    novo->proximo = NULL;
	    aux = novo;
	    
	    return aux;
	}

// Função para inserir um número no fim da lista
	void inserir(struct Item * lista, int n){
	    // Alocação do novo item
	    	struct Item *novo = new struct Item;

	    novo->valor = n;
	    novo->proximo = NULL;

		if(lista == NULL) { // caso não exista uma lista
			lista = novo;
		} else {
			// Alocação das variáveis do tipo lista
		    	struct Item *aux = new struct Item;

	        aux = lista;

	        while(aux->proximo != NULL){
	            aux = aux->proximo;
	        }

	        aux->proximo = novo;
	        lista = aux;
	    }
	}

// Função para imprimir na ordem digitada
	void imprimir(struct Item * lista){
		// Alocação das variáveis do tipo lista
			struct Item *aux = new struct Item;
		
		aux = lista->proximo;
		
		while(aux){
			std::cout << aux->valor << " ";
			aux = aux->proximo;
		}
		// desalocação da variável aux
			delete aux;
	}

int main (){
	// Alocação das variáveis
		int *n = new int;
		struct Item *lista = new struct Item;

	// Criação da lista para inserção dos números
		lista = cria_lista();

	do {
		// leitura do número que será inserido
			std::cin >> *n;

		if(*n > 0) // verifica se o número não é negativo ou zero, pois zero encerra o processo de inserção e negativo não é permitido pelo enunciado
			inserir(lista,*n); // inserção
	} while(*n > 0);

	// chamada da função de impressão
		imprimir(lista);

	std::cout << "\n"; // pula linha

	// Desalocando todas as variáveis do programa
		delete n;
		delete lista;

	return 0;
 }
