#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool verificar_palavra(int estado_inicial, int estados_finais[], int qtd_estados_finais, int qtd_simbolos, char alfabeto[], int tabela_transicao[][10], char palavra[]) {
    int estado_atual = estado_inicial;

    for (int i = 0; palavra[i] != '\0'; i++) {
        int indice_simbolo = -1;
        for (int j = 0; j < qtd_simbolos; j++) {
            if (palavra[i] == alfabeto[j]) {
                indice_simbolo = j;
                break;
            }
        }
        if (indice_simbolo == -1) {
            printf("Palavra contém símbolo inválido.\n");
            return false;
        }

        estado_atual = tabela_transicao[estado_atual - 1][indice_simbolo];
    }

    for (int i = 0; i < qtd_estados_finais; i++) {
        if (estado_atual == estados_finais[i]) {
            return true;
        }
    }

    return false;
}
 
int main() {
    int estado_inicial, qtd_estados, qtd_estados_finais, qtd_simbolos;
    char alfabeto[10];
    int estados_finais[100], tabela_transicao[100][10];

    // Pedir informações ao usuário
    printf("Digite o estado inicial (q1): ");
    scanf("%d", &estado_inicial);

    printf("Digite a quantidade de estados: ");
    scanf("%d", &qtd_estados);

    printf("Digite a quantidade de estados finais: ");
    scanf("%d", &qtd_estados_finais);

    printf("Digite os estados finais:\n");
    for (int i = 0; i < qtd_estados_finais; i++) {
        scanf("%d", &estados_finais[i]);
    }

    printf("Digite a quantidade de símbolos do alfabeto: ");
    scanf("%d", &qtd_simbolos);

    printf("Digite os símbolos do alfabeto (sem espaços): ");
    for (int i = 0; i < qtd_simbolos; i++) {
        scanf(" %c", &alfabeto[i]); 
    }

    // Preencher a tabela de transição
    printf("Preencha a tabela de transição (estado x símbolo):\n");
    for (int i = 0; i < qtd_estados; i++) {
        for (int j = 0; j < qtd_simbolos; j++) {
            printf("Delta(q%d, %c): ", i + 1, alfabeto[j]);
            scanf("%d", &tabela_transicao[i][j]);
        }
    }

    // Imprimir a tabela de transição
    printf("\nTabela de Transição:\n");
    printf("Estado   ");
    for (int i = 0; i < qtd_simbolos; i++) {
        printf("| %c ", alfabeto[i]);
    }
    printf("\n");
    for (int i = 0; i < qtd_estados; i++) {
        printf("q%d        ", i + 1);
        for (int j = 0; j < qtd_simbolos; j++) {
            printf("| q%d ", tabela_transicao[i][j]);
        }
        printf("\n");
    }

    // Verificar palavra
    char palavra[100];
    printf("\nDigite a palavra a ser verificada: ");
    scanf("%s", palavra);

    if (verificar_palavra(estado_inicial, estados_finais, qtd_estados_finais, qtd_simbolos, alfabeto, tabela_transicao, palavra)) {
        printf("A palavra \"%s\" é aceita pelo AFD.\n", palavra);
    } else {
        printf("A palavra \"%s\" não é aceita pelo AFD.\n", palavra);
    }

    return 0;
}


---------------------------->  ------------------------------------------- > b ------------------------------------------------> c 
