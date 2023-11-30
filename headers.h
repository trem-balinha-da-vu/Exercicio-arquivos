#ifndef ARQUIVOS_INCLUDED
#define ARQUIVOS_INCLUDED

typedef struct {
    int mes;
    int dia;
    float temp_max;
    float temp_min;
} RegistroTemperatura;

void lerArquivo(char *nomeArquivo, RegistroTemperatura temperaturas[], int *numRegistros);

void gerarRelatorio(const char *nomeArquivo, RegistroTemperatura temperaturas[], int numRegistros);

char * switchMes(int numeroMes);

int tratarMesInput(int *mes);

#endif // ARQUIVOS_INCLUDED

