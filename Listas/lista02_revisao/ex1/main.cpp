/*
 * 
 * Os motoristas estão preocupados com a quilometragem obtida por seus automóveis. 
 * Um motorista fez um controle de vários tanques de gasolina gastos, anotando os quilômetros de rodagem
 * obtidos pelo tanque.
 * 
 * Desenvolva um programa em C++ que recebe como entrada os quilômetros rodados e os litros para cada tanque.
 * O programa deve calcular e exibir os quilômetros por litro obtidos para cada tanque.
 * Depois de processar todas as informações fornecidas, o programa deve calcular e
 * imprimir os quilômetros por litro obtidos por todos os tanques combinados. 
 * 
 * Você deve utilizar uma classe para representar as informações sobre cada automóvel.
 * 
 */

#include <iostream>

// Classe que representa cada automóvel
	#include "Automovel.h"

// Classe que representa a Lista de Automóveis
	#include "ListaAutomoveis.h"

// metodo de menu
	#include "menu.h"	

// Programa principal
	int main(){

		ListaAutomoveis *automoveis = new ListaAutomoveis;
		menu(0,automoveis);

		return 0;
	}