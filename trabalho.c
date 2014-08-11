#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

typedef struct 
{
	int id;
	int *tabela;
}thread_infos, *pthread_infos;

void * acessa_pagina(void *arg);

int main(){
	

	FILE *arq_open;
	int tamanho_tabela, numero_threads;
	int cont = 1;

	arq_open = fopen("teste.txt", "r");

	while(!feof(arq_open)){
			fscanf(arq_open, "%d", &tamanho_tabela);
			fscanf(arq_open, "%d", &numero_threads);
	}

	//Definindo tamanho da tabela e de threads
	int tabela[tamanho_tabela], i;
	pthread_t threads[numero_threads];
	thread_infos infos[numero_threads];

	//Criação das threads
	for (i = 0; i < numero_threads; i++){
		infos[i].id = i;
		infos[i].tabela = tabela;
		pthread_create(&(threads[i]), NULL, acessa_pagina, &infos[i]);
	}

	for (i = 0; i < numero_threads; i++)
		pthread_join(threads[i],NULL);
	

	fclose(arq_open);
	return 0;
}

void * acessa_pagina(void *arg){
	pthread_infos thread_atual = (pthread_infos) arg;
//	printf("Thread numero %d e referencia %d \n", thread_atual->id, thread_atual->tabela[0]);
}