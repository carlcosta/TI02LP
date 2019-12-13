int menuListar(int escolha)
{

    /*!Menu listar */
    printf("\n");
    printf("==========================================================\n");
    printf("======================= MENU LISTAR ======================\n");
    printf("==========================================================\n");
    printf("\n");
    printf("MOSTRAR AUDITORIAS ->1\n");
    printf("Listar auditorias por numero de vulnerabilidades por ordem descendente -> 1\n");
    printf("Listar auditorias efetuadas por colaborador -> 2\n");
    printf("Listar vulnerabilidades de uma auditoria -> 3\n");
    printf("Listar vulnerabilidades identificadas num determinado equipamento -> 4\n");
    printf("Sair => 0\n");
    printf("\n");
    printf("Digite a sua opcao: ");
    scanf("%d", &escolha);

    return escolha;
}

int menuEditar()
{

    int escolha;

    /*!Menu editar/remover */
    printf("\n");
    printf("==========================================================\n");
    printf("================== MENU EDITAR/REMOVER ===================\n");
    printf("==========================================================\n");
    printf("\n");
    printf("Editar colaboradores -> 1\n");
    printf("Editar vulnerabilidades -> 2\n");
    printf("Remover colaboradores -> 3\n");
    printf("\n");
    printf("Digite a sua opcao: ");
    scanf("%d", &escolha);

    return escolha;
}

int menuAdicionar()
{

    int escolha;

    /*!Menu adicionar */
    printf("\n");
    printf("==========================================================\n");
    printf("===================== MENU ADICIONAR =====================\n");
    printf("==========================================================\n");
    printf("\n");
    printf("Inserir colaboradores -> 1\n");
    printf("Inserir vulnerabilidades -> 2\n");
    printf("Inserir um equipamento Informatico -> 3\n");
    printf("Criar uma auditoria -> 4\n");
    printf("\n");
    printf("Digite a sua opcao: ");
    scanf("%d", &escolha);

    return escolha;
}