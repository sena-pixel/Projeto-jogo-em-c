#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#ifdef _WIN32
    #include <windows.h>
    #define SLEEP(ms) Sleep(ms)
#else
    #include <unistd.h>
    #define SLEEP(ms) usleep(ms * 1000)
#endif

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void limparTela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void menu() {
    printf("\n=== HUB DE JOGOS ===\n");
    printf("1. Perguntas e Respostas\n");
    printf("2. Cobra na Caixa\n");
    printf("3. Gousmas War\n");
    printf("4. Sair\n");
    printf("Escolha: ");
}

// ================= JOGO 1 =================
void perguntas() {
    int resposta;
    char jogarNovamente;

    do {
        limparTela();
        printf("Quanto e 7x8?\n1. 54\n2. 56\n3. 64\nOpcao: ");
        while (scanf("%d", &resposta) != 1 || resposta < 1 || resposta > 3) {
            printf("Invalido! Digite 1, 2 ou 3: ");
            limparBuffer();
        }
        printf(resposta == 2 ? "Correta!\n" : "Errada!\n");
        SLEEP(1000);

        limparTela();
        printf("Capital da Franca?\n1. Berlim\n2. Madrid\n3. Paris\nOpcao: ");
        while (scanf("%d", &resposta) != 1 || resposta < 1 || resposta > 3) {
            printf("Invalido! Digite 1, 2 ou 3: ");
            limparBuffer();
        }
        printf(resposta == 3 ? "Correta!\n" : "Errada!\n");
        SLEEP(1000);

        printf("\nJogar novamente? (s/n): ");
        scanf(" %c", &jogarNovamente);
        limparBuffer();
    } while (jogarNovamente == 's' || jogarNovamente == 'S');
}

// ================= JOGO 2 =================
void cobraNaCaixa() {
    char nomes[7][20] = {"Ramses", "Cleopatra", "Anubis", "Horus", "Osiris", "Isis", "Tutankhamon"};
    int escolha1, escolha2, opcaoJogo, i;

    do {
        limparTela();
        printf("=== COBRA NA CAIXA ===\n");

        for(i = 0; i < 7; i++) {
            printf("%d - %s\n", i+1, nomes[i]);
        }

        printf("Jogador 1 (1-7): ");
        while (scanf("%d", &escolha1) != 1 || escolha1 < 1 || escolha1 > 7) {
            printf("Escolha de 1 a 7: ");
            limparBuffer();
        }

        printf("Jogador 2 (1-7, diferente de %d): ", escolha1);
        while (scanf("%d", &escolha2) != 1 || escolha2 < 1 || escolha2 > 7 || escolha2 == escolha1) {
            printf("Escolha valida para o J2: ");
            limparBuffer();
        }

        int turno = rand() % 2;
        int botao = rand() % 5;
        int cobra;

        do { cobra = rand() % 5; } while(cobra == botao);

        int caixas[5] = {0,0,0,0,0};

        while(1) {
            int escolha;

            printf("\nVez de: %s. Escolha caixa (1-5): ",
                (turno == 0) ? nomes[escolha1-1] : nomes[escolha2-1]);

            if (scanf("%d", &escolha) != 1 || escolha < 1 || escolha > 5 || caixas[escolha-1]) {
                printf("Caixa invalida ou ja aberta!\n");
                limparBuffer();
                continue;
            }

            escolha--;
            caixas[escolha] = 1;

            if(escolha == botao) {
                printf("BOTAO! Vitoria!\n");
                break;
            } else if(escolha == cobra) {
                printf("COBRA! Perdeu!\n");
                break;
            } else {
                printf("Nada aqui...\n");
                turno = 1 - turno;
            }
        }

        printf("\n1-Jogar denovo | 0-Menu: ");
        scanf("%d", &opcaoJogo);
        limparBuffer();

    } while(opcaoJogo == 1);
}

// ================= JOGO 3 =================
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
    for(i = 0; i < 2; i++) {
        if(g[i].ativa && g[i].furia > MAX) {
            g[i].ativa = 0;
            printf("Gousma %d explodiu!\n", i+1);
        }
    }
}

void gousmasWar() {
    Gousma p1[2] = {{1,1},{1,1}};
    Gousma p2[2] = {{1,1},{1,1}};
    int turno = 1;

    while(tem(p1) && tem(p2)) {
        limparTela();

        printf("J1: [%d, %d] | J2: [%d, %d]\n",
            p1[0].furia*p1[0].ativa, p1[1].furia*p1[1].ativa,
            p2[0].furia*p2[0].ativa, p2[1].furia*p2[1].ativa);

        int op, a, t;

        printf("\nJogador %d: 1-Atacar | 2-Passar: ", turno);
        if(scanf("%d", &op) != 1) { limparBuffer(); continue; }

        printf("Origem (1-2) e Alvo (1-2): ");
        if(scanf("%d %d", &a, &t) != 2 || a < 1 || a > 2 || t < 1 || t > 2) {
            printf("Entrada invalida!\n");
            limparBuffer();
            continue;
        }

        a--; t--;

        Gousma *atacante;
        Gousma *defensor;

        if(turno == 1) {
            atacante = p1;
            defensor = p2;
        } else {
            atacante = p2;
            defensor = p1;
        }

        if(op == 1) {
            if(atacante[a].ativa && defensor[t].ativa) {
                defensor[t].furia += 2;
                printf("Ataque! Furia: %d\n", defensor[t].furia);
            } else {
                printf("Gousma invalida!\n");
                continue;
            }
        } else {
            printf("Passada!\n");
        }

        verificar(defensor);

        turno = (turno == 1) ? 2 : 1;
        SLEEP(1000);
    }

    if(tem(p1))
        printf("\nJogador 1 venceu!\n");
    else
        printf("\nJogador 2 venceu!\n");

    SLEEP(2000);
}

// ================= MAIN =================
int main() {
    srand(time(NULL));
    int opcao;

    do {
        limparTela();
        menu();

        if(scanf("%d", &opcao) != 1) {
            limparBuffer();
            continue;
        }

        limparBuffer();

        switch(opcao) {
            case 1: perguntas(); break;
            case 2: cobraNaCaixa(); break;
            case 3: gousmasWar(); break;
            case 4: printf("Saindo...\n"); break;
            default: printf("Opcao invalida!\n"); SLEEP(1000);
        }

    } while(opcao != 4);

    return 0;
}