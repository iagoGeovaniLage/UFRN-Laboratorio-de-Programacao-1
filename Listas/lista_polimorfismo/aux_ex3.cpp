// funções auxiliares para os testes
	// função para imprimir vetor
		template <typename Tipo>
		void imprimiVet(Tipo v[], int tam, int tipo){
			if(tipo == 1)
				cout << "Vetor antes da ordenação: ";
			else
				cout << "Vetor depois da ordenação: ";
			for (int i = 0; i < tam; ++i){
				cout << v[i];
				if(i != tam-1)
					cout << ", ";
			}
			cout << "\n";
		}