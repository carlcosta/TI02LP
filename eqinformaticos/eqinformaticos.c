#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "eqinformaticos.h"

Eqinformatico novoEqinformatico(int id)
{
    Eqinformatico eqinformatico;

    eqinformatico.id = id + 1;
    printf("Digite o codigo do equipamento: ");
    scanf("%d", &eqinformatico.codigo);

    printf("Digite o tipo do equipamento: ");
    scanf("%s", eqinformatico.tipo);

    printf("Digite a marca do equipamento: ");
    scanf("%s", eqinformatico.marca);

    printf("Digite o modelo do equipamento: ");
    scanf("%s", eqinformatico.modelo);

    printf("Insira a data do equipamento (dd/mm/aa)\n");
    printf("Insira o dia: ");
    scanf("%d", &eqinformatico.data.dia);
    printf("Insira o mes: ");
    scanf("%d", &eqinformatico.data.mes);
    printf("Insira o ano: ");
    scanf("%d", &eqinformatico.data.ano);

    eqinformatico.ativo = true;

    return eqinformatico;
}

int inserirEqinformatico(Eqinformatico *eqinformaticos, int nEqinformaticos)
{
    if (nEqinformaticos > TAM_EQINFORMATICOS)
    {
        return -1;
    }

    eqinformaticos[nEqinformaticos] = novoEqinformatico(nEqinformaticos);
    nEqinformaticos++;

    return nEqinformaticos;
}

int pesquisaEqInformaticoCodigo(Eqinformatico *eqinformaticos, int nEqinformaticos, int codigo)
{
    int i = 0;

    while (codigo != eqinformaticos[i].codigo && i < nEqinformaticos)
    {
        i++;
    }

    if (i >= nEqinformaticos)
    {
        return -1;
    }
    return i;
}
int lerEqinformaticos(Eqinformatico *eqinformaticos)
{
    FILE *ficheiro;

    int quantidade;

    ficheiro = fopen(FICHEIRO_EQINFORMATICOS, "rb");

    if (ficheiro == NULL)
    {
        return -1;
    }

    quantidade = fread(eqinformaticos, sizeof(Eqinformatico), TAM_EQINFORMATICOS, ficheiro);
    fclose(ficheiro);
    return quantidade;
}

void guardarEqinformaticos(Eqinformatico *eqinformaticos, int qt)
{
    FILE *ficheiro;
    int i;

    ficheiro = fopen(FICHEIRO_EQINFORMATICOS, "wb");
    rewind(ficheiro);
    fwrite(eqinformaticos, sizeof(Eqinformatico), qt, ficheiro);
    fclose(ficheiro);
}

