// funções auxiliares para os testes
	// imprimir comparação
		void imprimi(int res) {
			switch(res){
				case 0:
					cout << "São iguais!\n";
					break;
				case 1:
					cout << "O primeiro é maior!\n";
					break;
				case -1:
					cout << "O segundo é maior!\n";
					break;
			}
		}