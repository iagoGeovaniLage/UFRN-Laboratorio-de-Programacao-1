/*
 * 
 * Desenvolva um programa em C++ que determinará se um cliente de uma loja de departamentos
 * excedeu o limite de crédito em conta-corrente. Para cada cliente, os seguintes fatos estão
 * disponíveis:
 *
 * 		a) Número da conta (um inteiro)
 * 		b) Saldo no princípio do mês
 * 		c) Total de todos os itens comprados a crédito por este cliente neste mês
 * 		d) Total de todos créditos do cliente nesta conta neste mês 
 * 		e) Limite de crédito permitido
 *
 * Seu programa deve utilizar uma classe para representar esses dados. O programa deve receber como
 * entrada cada um destes fatos, calcular o novo saldo ( = saldo inicial + debitos – crédito ) e
 * determinar se o novo valor excede o limite de crédito do cliente. Para aqueles clientes cujo o limite
 * de crédito for excedido, o programa deve exibir o número da conta do cliente, o limite de crédito, o
 * novo saldo e a mensagem “O limite de crédito foi excedido”.
 * 
 */

#include <iostream>

// classe de lista de clientes
	#include "Clientes.h"
// metodo de menu
	#include "menu.h"

// Programa principal
	int main(){

		// alocando a lista de clientes
			Clientes * clientes = new Clientes;

		// execução do menu de opções
			menu(0, clientes);

		// desalocando a lista de clientes
			delete clientes;

		return 0;
	}