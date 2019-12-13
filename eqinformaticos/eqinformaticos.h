#ifndef EQINFORMATICOS_H_
#define EQINFORMATICOS_H_
#define TAM_EQINFORMATICOS 100


//#define Ficheiro_eqinformaticos//
#define FICHEIRO_EQINFORMATICOS "eqinformaticos/eqinformaticos.dat"

typedef struct
{
    int id;
    int codigo;
    char marca[30];
    char modelo[30];
    char tipo[30];
    Data data;
    bool ativo;

} Eqinformatico;

Eqinformatico novoEqinformatico(int id);
int inserirEqinformatico(Eqinformatico *eqinformatico, int n);

#endif

