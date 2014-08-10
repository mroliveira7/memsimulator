#include <stdio.h>
#include <string.h>
//#include <pthread.h>

int main(){
	
	//variaveis
	FILE *arq_open;
	int tamanho_tabela, numero_threads;
	int cont = 1;

	//leitura do arquivo texto
	arq_open = fopen("teste.txt", "r");

	//extraindo todo o conteudo do arquivo
	while(!feof(arq_open)){
			fscanf(arq_open, "%d", &tamanho_tabela);
			fscanf(arq_open, "%d", &numero_threads);
		
	}
	printf("%d\n", tamanho_tabela);
	printf("%d\n", numero_threads);

	//fim da leitura do arquivo texto
	fclose(arq_open);
	return 0;
}