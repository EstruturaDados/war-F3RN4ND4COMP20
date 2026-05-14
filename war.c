#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TERRITORIOS 5
#define TAM_STRING 50


struct Territorio {
    char nome[TAM_STRING];
    char cor[TAM_STRING];
    int tropa;
};

void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    struct Territorio mapa[MAX_TERRITORIOS];
    int totalTerritorios = 0;
    int opcao;

    do {
        printf("=====================\n");
        printf("JOGO WAR\n");
        printf("=====================\n");
        printf("1-cadastrar novo território\n");
        printf("2-listar todos os territórios\n");
        printf("0-sair\n");
        printf("=====================\n");
        printf("Escolha uma opção:");
        
        scanf("%d", &opcao);
        limparBufferEntrada();

        switch (opcao) {
            case 1:
            printf("--- Cadastro de novo território ---\n\n");

            if(totalTerritorios < MAX_TERRITORIOS) {
                printf("Digite o nome do território: ");
                fgets(mapa[totalTerritorios].nome, TAM_STRING, stdin);

                printf("Digite a cor do exército: ");
                fgets(mapa[totalTerritorios].cor, TAM_STRING, stdin);

                mapa[totalTerritorios].nome[strcspn(mapa[totalTerritorios].nome, "\n")] = '\0';
                mapa[totalTerritorios].cor[strcspn(mapa[totalTerritorios].cor, "\n")] = '\0';

                printf("Digite o número de tropas: ");
                scanf("%d", &mapa[totalTerritorios].tropa);
                limparBufferEntrada();
                
                totalTerritorios++;

                printf("\nTerritório cadastrado com sucesso\n");
            }else {
                    printf("Mapa cheio!Não foi possível cadastrar mais territórios\n");
            }

            printf("\nPressione Enter para continuar");
            getchar();
            break;

            case 2:
            printf("--- Lista de territórios cadastrados ---\n\n");

            if (totalTerritorios == 0) {
                printf("Nenhum território cadastrado ainda\n");
            } else {
                for (int i = 0; i < totalTerritorios; i++) {
                    printf("==================\n");
                    printf("TERRITÒRIO %d\n", i + 1);
                    printf("Nome: %s\n", mapa[i].nome);
                    printf("Cor: %s\n", mapa[i].cor);
                    printf("Tropa: %d\n", mapa[i].tropa);
                }
                printf("====================\n");
            }

            printf("\nPressione Enter para continuar");
            getchar();
            break;

            case 0:
            printf("\nSaindo do sistema...\n");
            break;

            default:
            printf("\nOpção inválida.Tente novamente\n");
            printf("\nPressione Enter para continuar\n");
            getchar();
            break;
        }

    } while (opcao != 0);

    return 0;
}
            
        
    


