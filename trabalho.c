/*				Universidade Federal da Bahia
		   Trabalho de Sistemas Operacionais - MATA58
		   		   Professor Ricardo Rios
		   	   Marcos Ricardo e Pedro Marcelino			*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

//Estrutura para identificar a thread e apontar para a tabela de memória
typedef struct 
{
	int id;
	int *tabela;
	int tamanho_da_tabela;
	int paginas_acessadas[50];
}thread_infos, *pthread_infos;

int fim_fila = 0;

void * acessa_pagina(void *arg);

int main(){
	
	int tamanho_tabela, numero_threads;
	char string[50];
	char *token;



	//extraindo as informações do arquivo
	scanf("%d", &tamanho_tabela);
	scanf("%d", &numero_threads);

	printf("%d\n", tamanho_tabela);
	printf("%d\n", numero_threads);


	//Definindo tamanho da tabela e número de threads threads
	int tabela[tamanho_tabela], i;
	pthread_t threads[numero_threads];
	thread_infos infos[numero_threads];

	int j = 0;
	//Criação das threads
	for (i = 0; i < numero_threads; i++){
		infos[i].id = i;
		infos[i].tabela = tabela;
		infos[i].tamanho_da_tabela = tamanho_tabela;
		scanf("\n\r%[^\n]", string);
		token = strtok(string," ");
		while(token != NULL){
			infos[i].paginas_acessadas[j] = atoi(token);
			j++;
			token = strtok(NULL," ");
		}
		infos[i].paginas_acessadas[j] = -1;
		j = 0;
	}
		//scanf("\n\r%[^\n]", infos[i].paginas_acessadas);	
		//pthread_create(&(threads[i]), NULL, acessa_pagina, &infos[i]);

	for(i = 0; i < numero_threads; i++){
		for(j = 0;; j++){
			if(infos[i].paginas_acessadas[j] == -1)
				break;
			printf("%d ", infos[i].paginas_acessadas[j]);
		}
		printf("\n");
	}


	//for (i = 0; i < numero_threads; i++)
	//	pthread_join(threads[i],NULL);
	
	return 0;
}


/*
void * acessa_pagina(void *arg){
	
	FILE *arq_thread;
	char nome_arq[20];

	pthread_infos thread_atual = (pthread_infos) arg;
	
	sprintf(nome_arq, "thread-%d.txt",thread_atual->id);
	arq_open = fopen(nome_arq, "a");

	int acessos[] = {7,4,9,2,9,0,1,3,4}, i,j, tamanho_vetor;
	int tamanho_tabela = thread_atual->tamanho_da_tabela;

	tamanho_vetor = sizeof(acessos)/sizeof(int);
	
	//Loops para verificação dos acessos e da tabela
	for (int j = 0; j <tamanho_vetor ; j++){
		for (i = 0; i < tamanho_tabela; i++){
			if (thread_atual->tabela[i] != acessos[j] &&  i == (tamanho_tabela-1))  //Condição para encontrar ou não um acesso
			{
				
				//Aqui vai dar pagefault e vai inserir uma pagina
				
				fprintf(nome_arq, "%d-fault\n", acessos[j]);

				
				//Iteração para manipulação da tabela com FCFS
				
				if (fim_fila == 0)
				{
					thread_atual->tabela[fim_fila] = acessos[j];
					fim_fila++;
					continue;
				}
				else
				{
					if (fim_fila == tamanho_tabela-1)
					{
						int h;
						for(h = 0; h < tamanho_tabela-1;h++)
						{
							thread_atual->tabela[h] = thread_atual->tabela[h+1];
						}
						thread_atual->tabela[tamanho_tabela-1] = acessos[j];
						continue;
					}
					else
					{
						thread_atual->tabela[fim_fila] = acessos[j];
						fim_fila++;
					}
				}

			}
			else
			{
				//Página encontrada, escreve no arquivo
				fprintf(nome_arq, "%d-mem\n", acessos[j]);
			}
		}
	}
	fclose(nome_arq);
//	printf("Thread numero %d e referencia %d \n", thread_atual->id, thread_atual->tabela[0]);
}*/