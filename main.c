#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "menus.c"
#include "header.h"
#include "colaboradores/colaboradores.c"
#include "colaboradores/colaboradores.h"
#include "vulnerabilidades/vulnerabilidades.c"
#include "vulnerabilidades/vulnerabilidades.h"
#include "eqinformaticos/eqinformaticos.c"
#include "eqinformaticos/eqinformaticos.h"
#include "auditorias/auditorias.c"
#include "auditorias/auditorias.h"

/*!
Autor: Carlos Costa
Data: 22/12/2019
Função: Aplicação de auditorias
*/

int main(int argc, char const *argv[])
{

    int i, escolha, nColaboradores = 0, nVulnerabilidades = 0, nEqInformaticos = 0, nAuditorias = 0;
    Colaborador colaboradores[TAM_COLABORADORES];
    Vulnerabilidade vulnerabilidades[TAM_VULNERABILIDADES];
    Eqinformatico eqinformaticos[TAM_EQINFORMATICOS];
    Auditoria auditorias[TAM_AUDITORIAS];

    nVulnerabilidades = lerVulnerabilidades(vulnerabilidades);
    if (nVulnerabilidades == -1)
    {
        nVulnerabilidades = 0;
    }

    nColaboradores = lerColaboradores(colaboradores);
    if (nColaboradores == -1)
    {
        nColaboradores = 0;
    }

    nAuditorias = lerAuditorias(auditorias);
    if (nAuditorias == -1)
    {
        nAuditorias = 0;
    }

    int opcao, codigo;

    do
    {
        int escolha, opcao;

        /*!Menu principal */
        printf("\n");
        printf("==========================================================\n");
        printf("====================== MENU PRINCIPAL ====================\n");
        printf("==========================================================\n");
        printf("\n");
        printf("MENU ADICIONAR -> 1\n");      // incicializa o menu adicionar
        printf("MENU EDITAR/REMOVER -> 2\n"); // inicializa o menu editar/remover
        printf("MENU LISTAR -> 3\n");         // inicializa o menu listar
        printf("Sair -> 0\n");                // caso seja selecionado "0" a aplicação fecha
        printf("\n");
        printf("Digite a sua opcao: "); // espaço dedicado para a seleção da opção
        scanf("%d", &escolha);
        fflush(stdin);

        switch (escolha)
        {

        case 1:
        {
            opcao = menuAdicionar(opcao);

            switch (opcao)
            {
            case 1:

                nColaboradores = inserirColaborador(colaboradores, nColaboradores);
                guardarColaboradores(colaboradores, nColaboradores);

                break;

            case 2:

                nVulnerabilidades = inserirVulnerabilidade(vulnerabilidades, nVulnerabilidades);
                guardarVulnerabilidades(vulnerabilidades, nVulnerabilidades);
                break;

            case 3:

                nEqInformaticos = inserirEqinformatico(eqinformaticos, nEqInformaticos);

                break;

            case 4:

                nAuditorias = inserirAuditoria(auditorias, nAuditorias);
                guardarAuditorias(auditorias, nAuditorias);

                break;

            default:
                break;
            }

            break;
        }
        case 2:

            opcao = menuEditar(opcao);

            switch (opcao)
            {
            case 1:

                /* code */
                printf("Inserir codigo do colaborador: ");
                scanf("%d", &codigo);

                editarColaborador(colaboradores, nColaboradores, codigo);

                break;

            case 2:

                printf("Inserir o codigo da vulnerabilidade: ");
                scanf("%d", &codigo);

                editarVulnerabilidade(vulnerabilidades, nVulnerabilidades, codigo);

                break;

            case 3:

                printf("Insira o codigo do colaborador: ");
                scanf("%d", &codigo);

                removerColaborador(colaboradores, nColaboradores, codigo);

                break;
            }

            break;

        case 3:

            opcao = menuListar(opcao);

            switch ((opcao))
            {
            case 1:

                mostraAud(auditorias, nAuditorias);

                break;

            case 2:

                mostraVulns(vulnerabilidades, nVulnerabilidades);

                break;

            case 3:

                mostraColabs(colaboradores, nColaboradores);

                break;

            case 4:

                break;

            default:
                break;
            }
        }
        fflush(stdin);
        

    } while (escolha != 0);

    return 0;
}
