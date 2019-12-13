#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vulnerabilidades.h"
//código, descricao e nivel de impacto

Vulnerabilidade novaVulnerabilidade(int id)
{
    Vulnerabilidade vulnerabilidade;
    int opcao, codigo;

    vulnerabilidade.id = id + 1;
    printf("Digite o codigo da vulnerabilidade: ");
    scanf("%d", &vulnerabilidade.codigo);

    getchar();
    printf("Digite a descricao da vulnerabilidade: ");
    fgets(vulnerabilidade.descricao, 30, stdin);

    printf("Digite o nivel de impacto \n");
    printf("|| baixo -> 0 || moderado -> 1 || elevado -> 2 ||\n");
    printf("opcao: ");
    scanf("%d", &vulnerabilidade.nivelImpacto);

    vulnerabilidade.ativo = true;

    /*printf(" ASSOCIAR VULNERABILIDADE A UM EQUIPAMENTO -> 1|| ASSOCIAR VULNERABILIDADE A UMA AUDITORIA -> 2\n");
    printf("opcao: ");
    scanf("%d", &opcao);
    
    if (opcao == 1)
    {
        
        printf("digite o codigo do equipamento: ");
        scanf("%d", &codigo);

        vulnerabilidade.eqinformatico.codigo = codigo;
    }
    
    else if (opcao == 2)
    {
        printf("digite o codigo da auditoria: ");
        scanf("%d", &codigo);

        vulnerabilidade.eqinformatico.codigo = codigo;
    }
    */

    return vulnerabilidade;
}

int inserirVulnerabilidade(Vulnerabilidade *vulnerabilidades, int nVulnerabilidades)
{
    if (nVulnerabilidades > TAM_VULNERABILIDADES)
    {
        return -1;
    }

    vulnerabilidades[nVulnerabilidades] = novaVulnerabilidade(nVulnerabilidades);
    nVulnerabilidades++;

    return nVulnerabilidades;
}

int pesquisaVulnerabilidadeCodigo(Vulnerabilidade *vulnerabilidades, int nVulnerabilidades, int codigo)
{
    int i = 0;

    while (codigo != vulnerabilidades[i].codigo && i < nVulnerabilidades)
    {
        i++;
    }

    if (i >= nVulnerabilidades)
    {
        return -1;
    }
    return i;
}

int editarVulnerabilidade(Vulnerabilidade *vulnerabilidades, int nVulnerabilidades, int codigo)
{

    int i;

    i = pesquisaVulnerabilidadeCodigo(vulnerabilidades, nVulnerabilidades, codigo);

    printf("Inserir uma nova descricao da vulnerabilidade: ");
    scanf("%s", vulnerabilidades[i].descricao);
    printf("\n");
    printf("DADOS DA VULNERABILIDADE ALTERADAS: codigo -> %d | descricao -> %s \n",
           vulnerabilidades[i].codigo, vulnerabilidades[i].descricao);
}

int lerVulnerabilidades(Vulnerabilidade *vulnerabilidades)
{
    FILE *ficheiro;

    int quantidade;

    ficheiro = fopen(FICHEIRO_VULNERABILIDADES, "rb");

    if (ficheiro == NULL)
    {
        return -1;
    }

    quantidade = fread(vulnerabilidades, sizeof(Vulnerabilidade), TAM_VULNERABILIDADES, ficheiro);
    fclose(ficheiro);
    return quantidade;
}

void guardarVulnerabilidades(Vulnerabilidade *vulnerabilidades, int qt)
{
    FILE *ficheiro;
    int i;

    ficheiro = fopen(FICHEIRO_VULNERABILIDADES, "wb");
    rewind(ficheiro);
    fwrite(vulnerabilidades, sizeof(Vulnerabilidade), qt, ficheiro);
    fclose(ficheiro);
}

void mostraVulns(Vulnerabilidade *vulnerabilidades, int nVulnerabilidades)
{

    int i;

    for (i = 0; i < nVulnerabilidades; i++)
    {
        printf("| CODIGO: %d | DESCRICAO: %s | IMPACTO: %d | ATIVO: %d |",
               vulnerabilidades[i].codigo, vulnerabilidades[i].descricao, vulnerabilidades[i].nivelImpacto, vulnerabilidades[i].eqinformatico.codigo,
               vulnerabilidades[i].eqinformatico.data.dia, vulnerabilidades[i].eqinformatico.data.mes,
               vulnerabilidades[i].eqinformatico.data.ano, vulnerabilidades[i].eqinformatico.marca,
               vulnerabilidades[i].eqinformatico.modelo, vulnerabilidades[i].eqinformatico.tipo, vulnerabilidades[i].ativo);
        printf("\n");
    }
}