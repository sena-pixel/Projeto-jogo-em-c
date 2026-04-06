#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void limparBuffer() {
    while (getchar() != '\n');
}

void esperarEnter() {
    printf("\nPressione ENTER...");
    getchar();
}

int menu() {
    int op;
    printf("\n=== HUB DE JOGOS ===\n");
    printf("1. Perguntas\n");
    printf("2. Cobra na Caixa\n");
    printf("3. Gousmas War\n");
    printf("4. Sair\n");
    printf("Escolha: ");

    if (scanf("%d", &op) != 1) {
        limparBuffer();
        return 0;
    }
    limparBuffer();
    return op;
}

void perguntas() {
    int i, resp, jogar;

    char *perguntas[5] = {
        "7x8?",
        "Capital da Franca?",
        "2+2?",
        "Cor do ceu?",
        "Maior planeta?"
    };

    char *alt[5][4] = {
        {"54","56","60","64"},
        {"Berlim","Madrid","Paris","Roma"},
        {"3","4","5","6"},
        {"Azul","Verde","Vermelho","Amarelo"},
        {"Terra","Marte","Jupiter","Lua"}
    };

    int corretas[5] = {2,3,2,1,3};

    do {
        for(i=0;i<5;i++) {
            printf("\n%s\n", perguntas[i]);
            printf("1)%s 2)%s 3)%s 4)%s\n",
                alt[i][0], alt[i][1], alt[i][2], alt[i][3]);

            while(1) {
                if(scanf("%d",&resp)!=1){
                    printf("Invalido!\n");
                    limparBuffer();
                    continue;
                }
                if(resp<1 || resp>4){
                    printf("Digite 1 a 4\n");
                    continue;
                }
                break;
            }

            if(resp == corretas[i])
                printf("Correto!\n");
            else
                printf("Incorreto! Resposta: %d\n", corretas[i]);

            limparBuffer();
        }

        printf("\n1-Jogar novamente | 0-Menu: ");
        scanf("%d",&jogar);
        limparBuffer();

    } while(jogar==1);
}

void cobraNaCaixa() {
    char nomes[7][20]={"Ramses","Cleopatra","Anubis","Horus","Osiris","Isis","Tut"};
    int j1,j2,turno,botao,cobra,caixas[5],op,i;

    do {
        for(i=0;i<5;i++) caixas[i]=0;

        printf("\nJogador 1 (1-7): ");
        scanf("%d",&j1);

        printf("Jogador 2 (1-7 diferente): ");
        scanf("%d",&j2);
        limparBuffer();

        turno = rand()%2;
        botao = rand()%5;

        do { cobra=rand()%5; } while(cobra==botao);

        while(1){
            int esc;

            printf("\nVez de %s\n",
                turno==0?nomes[j1-1]:nomes[j2-1]);

            printf("Escolha caixa (1-5): ");

            if(scanf("%d",&esc)!=1){
                printf("Invalido!\n");
                limparBuffer();
                continue;
            }

            if(esc<1 || esc>5 || caixas[esc-1]){
                printf("Invalido!\n");
                continue;
            }

            esc--;

            if(esc==botao){
                printf("VENCEU!\n");
                break;
            }
            else if(esc==cobra){
                printf("PERDEU!\n");
                break;
            }
            else{
                printf("Vazio...\n");
                caixas[esc]=1;
                turno=1-turno;
            }
        }

        printf("\n1-Jogar novamente | 0-Menu: ");
        scanf("%d",&op);
        limparBuffer();

    } while(op==1);
}

#define MAX 5

typedef struct {
    int furia;
    int ativa;
} Gousma;

int tem(Gousma g[2]){
    return g[0].ativa || g[1].ativa;
}

void verificar(Gousma g[2]){
    int i;
    for(i=0;i<2;i++){
        if(g[i].ativa && g[i].furia>MAX){
            g[i].ativa=0;
            printf("Explodiu!\n");
        }
    }
}

void gousmasWar(){
    Gousma p1[2]={{1,1},{1,1}};
    Gousma p2[2]={{1,1},{1,1}};
    int turno=1, op;

    do{
        while(tem(p1)&&tem(p2)){
            int a,t;

            printf("\nJ1[%d,%d] J2[%d,%d]\n",
                p1[0].furia,p1[1].furia,
                p2[0].furia,p2[1].furia);

            printf("Jogador %d\n1-Atacar\n2-Dividir\nEscolha: ",turno);

            if(scanf("%d",&op)!=1){
                printf("Invalido!\n");
                limparBuffer();
                continue;
            }

            printf("Origem (1-2) e Alvo (1-2): ");

            if(scanf("%d %d",&a,&t)!=2){
                printf("Invalido!\n");
                limparBuffer();
                continue;
            }

            limparBuffer();

            if(a<1 || a>2 || t<1 || t>2){
                printf("Invalido!\n");
                continue;
            }

            a--; t--;

            Gousma *meu = (turno==1)?p1:p2;
            Gousma *inimigo = (turno==1)?p2:p1;

            if(op==1){
                inimigo[t].furia += meu[a].furia;
                verificar(inimigo);
            }
            else if(op==2){
                if(meu[a].furia>1){
                    meu[a].furia--;
                    meu[1-a].furia++;
                    meu[1-a].ativa=1;
                    verificar(meu);
                }
            }

            turno = (turno==1)?2:1;
        }

        if(tem(p1)) printf("J1 venceu!\n");
        else printf("J2 venceu!\n");

        printf("\n1-Reiniciar | 0-Menu: ");
        scanf("%d",&op);
        limparBuffer();

    }while(op==1);
}

int main(){
    srand(time(NULL));
    int op;

    do{
        op = menu();

        if(op==1) perguntas();
        else if(op==2) cobraNaCaixa();
        else if(op==3) gousmasWar();

    }while(op!=4);

    return 0;
}