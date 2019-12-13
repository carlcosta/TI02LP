#ifndef VULNERABILIDADES_H_
#define VULNERABILIDADES_H_
#define TAM_VULNERABILIDADES 100
#include "../eqinformaticos/eqinformaticos.h"

//#define Vulnerabilidades//
#define FICHEIRO_VULNERABILIDADES "vulnerabilidades/vulnerabilidades.dat"

typedef struct
{
    int id;
    int codigo;
    char descricao[150];
    NivelImpacto nivelImpacto;
    Eqinformatico eqinformatico;
    bool ativo;

} Vulnerabilidade;

Vulnerabilidade novaVulnerabilidade(int id);
int inserirVulnerabilidade(Vulnerabilidade *vulnerabilidade, int n);

#endif
