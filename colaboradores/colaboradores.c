#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "colaboradores.h"

Colaborador novoColaborador(int id)
{
    Colaborador colaborador;

    colaborador.id = id + 1;
    printf("Digite o codigo do colaborador: ");
    scanf("%d", &colaborador.codigo);

    printf("Digite o nome do colaborador: ");
    scanf("%s", colaborador.nome);

    colaborador.ativo = true;

    return colaborador;
}

int inserirColaborador(Colaborador *colaboradores, int nColaboradores)
{
    if (nColaboradores > TAM_COLABORADORES)
    {
        return -1;
    }

    colaboradores[nColaboradores] = novoColaborador(nColaboradores);
    nColaboradores++;

    return nColaboradores;
}

int pesquisaColaboradorCodigo(Colaborador *colaboradores, int nColaboradores, int codigo)
{
    int i = 0;

    while (codigo != colaboradores[i].codigo && i < nColaboradores)
    {
        i++;
    }

    if (i >= nColaboradores)
    {
        return -1;
    }
    return i;
}

int editarColaborador(Colaborador *colaboradores, int nColaboradores, int codigo)
{

    int i;

    i = pesquisaColaboradorCodigo(colaboradores, nColaboradores, codigo);

    printf("Inserir o nome do colaborador: ");
    scanf("%s", colaboradores[i].nome);
    printf("\n");
    printf("DADOS DO COLABORADOR ALTERADOS: codigo -> %d | nome -> %s \n", colaboradores[i].codigo, colaboradores[i].nome);
}

bool removerColaborador(Colaborador *colaboradores, int nColaboradores, int id)
{
    int indice;
    indice = pesquisaColaboradorCodigo(colaboradores, nColaboradores, id);

    if (indice >= 0)
    {
        colaboradores[indice].ativo = false;
        return true;
    }
    return false;
}

int lerColaboradores(Colaborador *colaboradores)
{
    FILE *ficheiro;

    int quantidade;

    ficheiro = fopen(FICHEIRO_COLABORADORES, "rb");

    if (ficheiro == NULL)
    {
        return -1;
    }

    quantidade = fread(colaboradores, sizeof(Colaborador), TAM_COLABORADORES, ficheiro);
    fclose(ficheiro);
    return quantidade;
}

void guardarColaboradores(Colaborador *colaboradores, int qt)
{
    FILE *ficheiro;
    int i;

    ficheiro = fopen(FICHEIRO_COLABORADORES, "wb");
    rewind(ficheiro);
    fwrite(colaboradores, sizeof(Colaborador), qt, ficheiro);
    fclose(ficheiro);
}

void mostraColabs(Colaborador *colaboradores, int nColaboradores)
{

    int i;

    for (i = 0; i < nColaboradores; i++)
    {
        printf("CODIGO: %d | NOME: %s | ATIVO: %d |", colaboradores[i].codigo, colaboradores[i].nome, colaboradores[i].ativo);
        printf("\n");
    }
}
