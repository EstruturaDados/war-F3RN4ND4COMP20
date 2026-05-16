#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TERRITORIOS 10
#define MAX_ATAQUES 50
#define TAM_STRING 50


struct Territorio {
    char nome[TAM_STRING];
    char cor[TAM_STRING];
    int tropa;
};

struct Ataque {
    int indiceAtacante;
    char nomeAtacante[TAM_STRING];
    int indiceDefensor;
    char nomeDefensor[TAM_STRING];
};

void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    struct Territorio *mapa;
    struct Ataque *ataques;

    int totalTerritorios = 0;
    int totalAtaques = 0;
    int opcao;

    srand(time(NULL));
    

    mapa = (struct Territorio *) calloc(MAX_TERRITORIOS, sizeof(struct Territorio));

    ataques = (struct Ataque *) malloc(MAX_ATAQUES *  sizeof(struct Ataque));

    if (mapa == NULL || ataques == NULL) {
        printf("Erro: Falha ao alocar memória\n");
        return 1;
    }

    do {
        printf("=====================\n");
        printf("JOGO WAR\n");
        printf("=====================\n");
        printf("1-cadastrar novo território\n");
        printf("2-listar todos os territórios\n");
        printf("3-realizar ataque\n");
        printf("4-listar todos os ataques\n");
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

                printf("Território cadastrado com sucesso\n");
            } else {
                    printf("Mapa cheio!Não foi possível cadastrar mais territórios\n");
            }

            break;

             case 2:
            printf("--- Lista de territórios cadastrados ---\n\n");

            if (totalTerritorios == 0) {
                printf("Nenhum território cadastrado ainda\n");
            } else {
                for (int i = 0; i < totalTerritorios; i++) {
                    printf("==================\n");
                    printf("TERRITÓRIO %d\n", i + 1);
                    printf("Nome: %s\n", mapa[i].nome);
                    printf("Cor: %s\n", mapa[i].cor);
                    printf("Tropa: %d\n", mapa[i].tropa);
                    printf("====================\n");
                }
                
            }

            break;
            
            case 3: {
            if(totalTerritorios < 2) {
                printf("É necessário pelo menos 2 territórios\n");
                break;
            }

            int atacante, defensor;

            printf("--- Fase de Ataque ---\n");
            for(int i = 0; i < totalTerritorios; i++) {
                printf("%d - %s(%d tropas)\n",
                    i,
                    mapa[i].nome,
                    mapa[i].tropa);
            }

            printf("Escolha o território atacante: \n");
            scanf("%d", &atacante);

            printf("Escolha o Território defensor: \n");
            scanf("%d", &defensor);

            limparBufferEntrada();

            if(atacante == defensor ||
               atacante < 0 || atacante >= totalTerritorios ||
               defensor < 0 || defensor >= totalTerritorios) {
               printf("Ataque inválido\n");
               break;
            }

            int dadoAtacante = rand() % 6 + 1;
            int dadoDefensor = rand() % 6 + 1;

            printf("Dado atacante: %d\n", dadoAtacante);
            printf("Dado defensor: %d\n", dadoDefensor);

            if(dadoAtacante > dadoDefensor) {
                mapa[defensor].tropa--;
                printf("Vitória do atacante!\n");
                printf("%s perdeu 1 tropa\n", mapa[defensor].nome);
            } else {
                mapa[atacante].tropa--;
                printf("Vitória do defensor!\n");
                printf("%s perdeu 1 tropa\n", mapa[atacante].nome);
            }

            strcpy(ataques[totalAtaques].nomeAtacante, mapa[atacante].nome);
            strcpy(ataques[totalAtaques].nomeDefensor, mapa[defensor].nome);

            ataques[totalAtaques].indiceAtacante = atacante;
            ataques[totalAtaques].indiceDefensor = defensor;

            totalAtaques++;

            break;
        }

        case 4:
        if(totalAtaques == 0) {
            printf("Nenhum ataque registrado\n");
        } else {
            printf("--- Lista de Ataques ---\n");

            for(int i = 0; i < totalAtaques; i++) {
                printf("Ataque %d\n", i + 1);
                printf("Atacante: %s\n", ataques[i].nomeAtacante);
                printf("Defensor: %s\n", ataques[i].nomeDefensor);
            }
        }
        
        break;

            case 0:
            printf("Saindo do sistema...\n");
            break;

            default:
            printf("Opção inválida.Tente novamente\n");
            }
            
        } while(opcao != 0);
        
    free(mapa);
    free(ataques);

    printf("Memória liberada com sucesso!\n");

    return 0;
     
}
