#include <stdio.h>
#include <stdlib.h>
#include "headers.h"



void lerArquivo(char *nomeArquivo, RegistroTemperatura temperaturas[], int *numRegistros) {
	FILE *arquivo = fopen(nomeArquivo, "r");
	if (arquivo == NULL) {
		perror("Erro ao abrir o arquivo");
		exit(EXIT_FAILURE);
	}

	*numRegistros = 0;
	while (fscanf(arquivo, "%d, %d, %f, %f", &temperaturas[*numRegistros].mes,
				  &temperaturas[*numRegistros].dia,
				  &temperaturas[*numRegistros].temp_max,
				  &temperaturas[*numRegistros].temp_min) == 4) {
		(*numRegistros)++;
	}

	fclose(arquivo);
}

void gerarRelatorio(const char *nomeArquivo, RegistroTemperatura temperaturas[], int numRegistros) {
	FILE *relatorio = fopen(nomeArquivo, "w");
	if (relatorio == NULL) {
		perror("Erro ao criar o relatório");
		exit(EXIT_FAILURE);
	}

	float tempMediaMes = 0;
	float maiorTemp = temperaturas[0].temp_max;
	float menorTemp = temperaturas[0].temp_min;

	for (int i = 0; i < numRegistros; i++) {
		float tempMediaDia = (temperaturas[i].temp_max + temperaturas[i].temp_min) / 2.0;
		tempMediaMes += tempMediaDia;

		if (temperaturas[i].temp_max > maiorTemp) {
			maiorTemp = temperaturas[i].temp_max;
		}

		if (temperaturas[i].temp_min < menorTemp) {
			menorTemp = temperaturas[i].temp_min;
		}
	}

	tempMediaMes /= numRegistros;

	char *mes = switchMes(temperaturas[0].mes);

	fprintf(relatorio, "\nPrezada comunidade,\n\n");
	fprintf(relatorio, "Informamos que no mês %d (%s) tivemos as seguintes temperaturas médias:\n\n", temperaturas[0].mes, mes);

	for (int i = 0; i < numRegistros; i++) {
		fprintf(relatorio, "Dia %d:  %.2f\n", temperaturas[i].dia, (temperaturas[i].temp_max + temperaturas[i].temp_min) / 2.0);
	}

	fprintf(relatorio, "\n\nSendo que a temperatura média do mês ficou em %.2f.\n", tempMediaMes);
	fprintf(relatorio, "\nA maior temperatura registrada foi de %.2f e a menor temperatura foi de %.2f.\n", maiorTemp, menorTemp);
	fprintf(relatorio, "\nAtenciosamente,\n\nCentro de Metrologia Metrologic\n");

	fclose(relatorio);
}

char * switchMes(int numeroMes){
		switch (numeroMes) {
		case 1:
			return "janeiro";
		case 2:
			return "fevereiro";
		case 3:
			return "março";
		case 4:
			return "abril";
		case 5:
			return "maio";
		case 6:
			return "junho";
		case 7:
			return "julho";
		case 8:
			return "agosto";
		case 9:
			return "setembro";
		case 10:
			return "outubro";
		case 11:
			return "novembro";
		case 12:
			return "dezembro";
		default:
			return "mes_invalido";
	}
}

int tratarMesInput(int *mes){

	printf("Digite o número do mês desejado (1 a 12): ");
	scanf("%d", mes);

	if (*mes < 1 || *mes > 12) {
		printf("Mês inválido. Encerrando o programa.\n");
		return 1;
	}

	int diasNoMes;
	switch (*mes) {
		case 4:
		case 6:
		case 9:
		case 11:
			return 30;
		case 2:
			return 28; 
		default:
			return 31;
	}
}