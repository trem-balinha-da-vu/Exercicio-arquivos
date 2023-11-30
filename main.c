#include<stdio.h>
#include "headers.h"

#define MAX_DIAS_MES 31

int main() {
    int mes;
    int diasNoMes = tratarMesInput(&mes);
    RegistroTemperatura temperaturas[MAX_DIAS_MES];
    int numRegistros;

    lerArquivo("temperaturas.dat", temperaturas, &numRegistros);

    if (numRegistros > diasNoMes) {
        printf("A quantidade de dias no arquivo é maior do que o esperado para o mês %d. Encerrando o programa.\n", mes);
        return 1;
    }

    gerarRelatorio("relatorio.txt", temperaturas, numRegistros);

    return 0;
}
