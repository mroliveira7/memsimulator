#include <stdio.h>
#include <string.h>
//#include <pthread.h>

int main(){
	
	//variaveis
	FILE *arq_open;
	int numero_paginas, numero_threads, paginas;
	int i, j, cont;
	int vetor[50];

	//leitura do arquivo texto
	arq_open = fopen("teste.txt", "r");

	cont = 1;
	i = 0;

	//extraindo todo o conteudo do arquivo
	while(!feof(arq_open)){
		if (cont == 1){ //armazenar numero de paginas
			fscanf(arq_open, "%d", &numero_paginas);

			//criacao do vetor de paginas
			int vetor_paginas[numero_paginas];
			cont++;
			//i = 0;
		}
		if (cont == 2){ //armazenar numero de threads
			fscanf(arq_open, "%d", &numero_threads);
			cont++;
			//i = 0;
		}
		if(cont == 3){
			fscanf(arq_open, "%d", &paginas);
			vetor[i] = paginas;
			i++;
		}
		
	}
	printf("%d\n", numero_paginas);
	printf("%d\n", numero_threads);
	for(j=0; j<=i; j++){
		printf("%d ", vetor[j]);
	}
	printf("\n");

	//fim da leitura do arquivo texto
	fclose(arq_open);
	return 0;
}