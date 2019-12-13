#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auditorias.h"

Auditoria novaAuditoria(int id)
{
    int opcao, auditorias, nColaboradores, codigo;

    Auditoria auditoria;
    Colaborador colaborador;

    auditoria.id = id + 1;
    printf("Digite o codigo da auditoria: ");
    scanf("%d", &auditoria.codigo);

    printf("Digite a duracao em minutos da auditoria: ");
    scanf("%d", &auditoria.duracaoMinutos);

    printf("Insira a data da auditoria (dd/mm/aa)\n");
    printf("Insira o dia: ");
    scanf("%d", &auditoria.data.dia);
    printf("Insira o mes: ");
    scanf("%d", &auditoria.data.mes);
    printf("Insira o ano: ");
    scanf("%d", &auditoria.data.ano);

    printf("Digite o codigo do colaborador: ");
    scanf("%d", &auditoria.colaborador.codigo);

    



    /*printf("|| CRIAR COLABORADOR -> 1|| ASSOCIAR UM COLABORADOR PREVIAMENTE CRIADO -> 2\n");
    printf("OPCAO: ");
    scanf("%d", &opcao);

    if (opcao == 1)
    {
    
        printf("Digite o codigo do colaborador: ");
        scanf("%d", &auditoria.colaborador.codigo);

        printf("Digite o nome do colaborador: ");
        scanf("%s", auditoria.colaborador.nome);
    }
    if (opcao == 2)
    {
        
        printf("Digite o codigo do colaborador: ");
        scanf("%d", &codigo);
        auditoria.colaborador.codigo = codigo;
    }

    printf("|| CRIAR VULNERABILIDADE -> 1 || ASSOCIAR UMA VULNERABILIDADE PREVIAMENTE CRIADA ->2\n");
    printf("OPCAO: ");
    scanf("%d", &opcao);

    if (opcao == 1)

    {
        
        printf("Digite o codigo da vulnerabilidade: ");
        scanf("%d", &auditoria.vulnerabilidade.codigo);

        printf("Digite a descricao da vulnerabilidade: ");
        scanf("%s", auditoria.vulnerabilidade.descricao);

        printf("Digite o nivel de impacto\n");
        printf("|| baixo -> 0|| moderado -> 1 || elevado -> 2 ||\n");
        printf("OPCAO: ");
        scanf("%d", &auditoria.vulnerabilidade.nivelImpacto);

    }
    else if (opcao == 2)
    {
        
        printf("codigo da vulnerabilidade: ");
        scanf("%d", &codigo);

        auditoria.vulnerabilidade.codigo = codigo;
    }
    */

    auditoria.ativo = true;

    return auditoria;
}

int inserirAuditoria(Auditoria *auditorias, int nAuditorias)
{
    if (nAuditorias > TAM_AUDITORIAS)
    {
        return -1;
    }

    auditorias[nAuditorias] = novaAuditoria(nAuditorias);
    nAuditorias++;

    return nAuditorias;
}

int pesquisaAuditoriaCodigo(Auditoria *auditorias, int nAuditorias, int codigo)
{
    int i = 0;

    while (codigo != auditorias[i].codigo && i < nAuditorias)
    {
        i++;
    }

    if (i >= nAuditorias)
    {
        return -1;
    }
    return i;
}

int lerAuditorias(Auditoria *auditorias)
{
    FILE *ficheiro;

    int quantidade;

    ficheiro = fopen(FICHEIRO_AUDITORIAS, "rb");

    if (ficheiro == NULL)
    {
        return -1;
    }

    quantidade = fread(auditorias, sizeof(Auditoria), TAM_AUDITORIAS, ficheiro);
    fclose(ficheiro);
    return quantidade;
}

void guardarAuditorias(Auditoria *auditorias, int qt)
{

    FILE *ficheiro;
    int i;

    ficheiro = fopen(FICHEIRO_AUDITORIAS, "wb");
    rewind(ficheiro);
    fwrite(auditorias, sizeof(Auditoria), qt, ficheiro);
    fclose(ficheiro);
}
void mostraAud(Auditoria *auditorias, int nAuditorias)
{
    int i;
    for (i = 0; i < nAuditorias; i++)
    {
        printf("|CODIGO AUDITORIA: %d | DURACAO MIN: %d | DIA: %d | MES: %d | ANO: %d | NOME DO COLABORADOR: %s | DESCRICAO DA VULNERABILIDADE %s | NIVEL DE IMPACTO %d |",
               auditorias[i].codigo, auditorias[i].duracaoMinutos,
               auditorias[i].data.dia, auditorias[i].data.mes, auditorias[i].data.ano,
               auditorias[i].colaborador.nome, auditorias[i].vulnerabilidade.descricao,
               auditorias[i].vulnerabilidade.nivelImpacto);
    }
}
