#ifndef COLABORADORES_H_
#define COLABORADORES_H_
#define TAM_COLABORADORES 100


//#define Ficheiro_colaboradores//
#define FICHEIRO_COLABORADORES "colaboradores/colaboradores.dat"

typedef struct
{
    int id;
    int codigo;
    char nome[30];
    bool ativo;

} Colaborador;

Colaborador novoColaborador(int id);
int inserirColaborador(Colaborador *colaborador, int n);

#endif

