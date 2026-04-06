#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void limparBuffer() {
    while (getchar() != '\n');
}

void esperarEnter() {
    printf("\nPressione ENTER para continuar...");
    getchar();
}

void menu() {
    printf("\n=== HUB DE JOGOS ===\n");
    printf("1. Perguntas\n");
    printf("2. Cobra na Caixa\n");
    printf("3. Gousmas War\n");
    printf("4. Sair\n");
    printf("Escolha: ");
}

// JOGO 1
void perguntas() {
    int resposta;
    char jogar;

    do {
        printf("7x8?\n1)54  2)56  3)64\n: ");

        while (1) {
            if (scanf("%d", &resposta) != 1) {
                printf("Invalido!\n");
                limparBuffer();
                continue;
            }
            if (resposta < 1 || resposta > 3) {
                printf("Digite 1, 2 ou 3!\n");
                continue;
            }
            break;
        }

        if (resposta == 2) printf("Correta!\n");
        else printf("Errada!\n");

        esperarEnter();

        printf("Capital da Franca?\n1)Berlim 2)Madrid 3)Paris\n: ");

        while (1) {
            if (scanf("%d", &resposta) != 1) {
                printf("Invalido!\n");
                limparBuffer();
                continue;
            }
            if (resposta < 1 || resposta > 3) {
                printf("Digite 1, 2 ou 3!\n");
                continue;
            }
            break;
        }

        if (resposta == 3) printf("Correta!\n");
        else printf("Errada!\n");

        esperarEnter();

        printf("Jogar dnv? (s/n): ");
        scanf(" %c", &jogar);
        limparBuffer();

    } while (jogar == 's' || jogar == 'S');
}

// JOGO 2
void cobraNaCaixa() {
    int caixas[5] = {0};
    int botao = rand() % 5;
    int cobra;

    do { cobra = rand() % 5; } while (cobra == botao);

    while (1) {
        int escolha;

        printf("Escolha caixa (1-5): ");

        if (scanf("%d", &escolha) != 1) {
            printf("Invalido!\n");
            limparBuffer();
            continue;
        }

        limparBuffer();

        if (escolha < 1 || escolha > 5 || caixas[escolha-1]) {
            printf("Invalido!\n");
            continue;
        }

        escolha--;
        caixas[escolha] = 1;

        if (escolha == botao) {
            printf("GANHOU!\n");
            break;
        } else if (escolha == cobra) {
            printf("PERDEU!\n");
            break;
        } else {
            printf("Vazio...\n");
        }
    }

    esperarEnter();
}

// JOGO 3
#define MAX 5

typedef struct {
    int furia;
    int ativa;
} Gousma;

int tem(Gousma g[2]) {
    return g[0].ativa || g[1].ativa;
}

void verificar(Gousma g[2]) {
    int i;
    for (i = 0; i < 2; i++) {
        if (g[i].furia > MAX) {
            g[i].ativa = 0;
            printf("Explodiu!\n");
        }
    }
}

void gousmasWar() {
    Gousma p1[2] = {{1,1},{1,1}};
    Gousma p2[2] = {{1,1},{1,1}};
    int turno = 1;

    while (tem(p1) && tem(p2)) {
        int op, a, t;

        printf("\nJ1[%d,%d] J2[%d,%d]\n",
        p1[0].furia, p1[1].furia,
        p2[0].furia, p2[1].furia);

        printf("Jogador %d (1 atacar / 2 passar): ", turno);

        if (scanf("%d", &op) != 1) {
            printf("Invalido!\n");
            limparBuffer();
            continue;
        }

        printf("Origem e alvo (1-2): ");

        if (scanf("%d %d", &a, &t) != 2) {
            printf("Invalido!\n");
            limparBuffer();
            continue;
        }

        limparBuffer();

        if (a < 1 || a > 2 || t < 1 || t > 2) {
            printf("Invalido!\n");
            continue;
        }

        a--; t--;

        if (turno == 1) {
            if (op == 1) p2[t].furia += 2;
            verificar(p2);
            turno = 2;
        } else {
            if (op == 1) p1[t].furia += 2;
            verificar(p1);
            turno = 1;
        }
    }

    if (tem(p1)) printf("J1 venceu!\n");
    else printf("J2 venceu!\n");

    esperarEnter();
}

// MAIN
int main() {
    srand(time(NULL));
    int op;

    do {
        menu();

        if (scanf("%d", &op) != 1) {
            printf("Invalido!\n");
            limparBuffer();
            continue;
        }

        limparBuffer();

        if (op == 1) perguntas();
        else if (op == 2) cobraNaCaixa();
        else if (op == 3) gousmasWar();
        else if (op == 4) printf("Saindo...\n");
        else printf("Invalido!\n");

    } while (op != 4);

    return 0;
}