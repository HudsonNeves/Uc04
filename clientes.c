#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CLIENTES 100
#define TAM_NOME 50

typedef struct {
    int id;
    char nome[TAM_NOME];
    char email[100];
} Cliente;

void salvarCliente(Cliente c) {
    FILE *fp = fopen("clientes.txt", "a");
    if (fp == NULL) {
        printf("Erro ao abrir arquivo.\n");
        return;
    }
    fprintf(fp, "%d,%s,%s\n", c.id, c.nome, c.email);
    fclose(fp);
}

void listarClientes() {
    FILE *fp = fopen("clientes.txt", "r");
    if (fp == NULL) {
        printf("Nenhum cliente cadastrado.\n");
        return;
    }

    char linha[200];
    printf("\nLista de clientes:\n");
    while (fgets(linha, sizeof(linha), fp)) {
        printf("%s", linha);
    }

    fclose(fp);
}

int main() {
    int opcao;
    Cliente cliente;

    do {
        printf("\n=== MENU ===\n");
        printf("1. Cadastrar cliente\n");
        printf("2. Listar clientes\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        getchar(); // limpar buffer

        switch (opcao) {
            case 1:
                printf("ID: ");
                scanf("%d", &cliente.id);
                getchar();

                printf("Nome: ");
                fgets(cliente.nome, TAM_NOME, stdin);
                cliente.nome[strcspn(cliente.nome, "\n")] = '\0';

                printf("Email: ");
                fgets(cliente.email, 100, stdin);
                cliente.email[strcspn(cliente.email, "\n")] = '\0';

                salvarCliente(cliente);
                printf("Cliente salvo com sucesso!\n");
                break;
            case 2:
                listarClientes();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}
