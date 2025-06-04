#include <stdio.h>

void menu() {
    int opcao;
    do {
        printf("\n--- Sistema de Cadastro ---\n");
        printf("1. Cadastrar Cliente\n");
        printf("2. Listar Clientes\n");
        printf("3. Agendar Consulta\n");
        printf("4. Listar Consultas\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                cadastrarCliente();
                break;
            case 2:
                listarClientes();
                break;
            case 3:
                agendarConsulta();
                break;
            case 4:
                listarConsultas();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while(opcao != 0);
}

int main() {
    menu();
    return 0;
}
