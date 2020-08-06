#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>

void gotoxy(int x, int y){
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x-1,y-1});
}
int salvando = 0, q = 0, carregando = 0;
FILE* arquivo, *arquivo2;
int main(){
    int x = 25, y = 10,z = 4, y1, x1, t, posicao[3100][2], p = 0, g = 4, i = 0, enter = 0, parede = 0, x3 = 0, b = 0, velocidade = 0, rbug = 0, r, o, v;
    short x2 = 1, y2 = 0, dificuldade = 25, pausa, jogosalvo = 0, limiteParede = 0;
    unsigned long rand;
    char tecla, escolha;
    void salvar(int dificuldade, int parede, int velocidade, int pontuacao , int x1, int y1, int g, int posicao);
    void pontuacoes();
    void placar(int pontuacao);
    void zerarPlacar();
    int carregar();

    y2 = 16;

    while(i != 1){ //Menu
        system("cls");
        gotoxy(52, 14);
        printf("Jogo da cobra!!!");
        gotoxy(55, 16);
        printf("Jogar!");
        gotoxy(55, 17);
        printf("Carregar");
        gotoxy(55, 18);
        printf("Configura%c%ces", 135, 228);
        gotoxy(55, 19);
        printf("Placares");
        gotoxy(55, 20);
        printf("Sair");

        if(kbhit() != 0){
            tecla = getch();
            switch (tecla){
                case 72:
                    y2--;
                    break;
                case 80:
                    y2++;
                    break;
                case 13:
                    enter = 1;
            }
            if(y2 < 16){
                y2 = 20;
            } else if(y2 > 20){
                y2 = 16;
            }
        }

        gotoxy(53, y2);
        printf(">");
        if(y2 == 16 && enter == 1){
            enter = 0;
            goto comeco;

        } else if(y2 == 18 && enter == 1){ //Configuracoes
            enter = 0;
            y2 = 16;
            while(enter != 1){
            system("cls");
            gotoxy(52, 14);
            printf("Jogo da cobra!!");
            gotoxy(55, 16);
            printf("Dificuldade:");
            if(x2 == 0){
                printf(" Facil");
            } else if(x2 == 1){
                printf(" Medio");
            } else if(x2 == 2){
                printf(" Dificil");
            } else if(x2 == 3){
                printf(" Crescente");
            } else if(x2 == 4){
                printf(" Sem fim");
            }
            gotoxy(55, 17);
            printf("Parede: ");
            if(parede == 0){
                printf("Normal");
            } else if(parede == 1){
                printf("Desvia");
            } else if(parede == 2){
                printf("Sem paredes");
            }
            gotoxy(55, 18);
            printf("Resetar o placar");
            gotoxy(55, 19);
            printf("Voltar");

            if(kbhit() != 0){
            tecla = getch();
            switch (tecla){
                case 72:
                    y2--;
                    break;
                case 80:
                    y2++;
                    break;
                case 13:
                    enter = 2;
            }
            if(y2 < 16){
                    y2 = 19;
                } else if(y2 > 19){
                    y2 = 16;
                }
            }

            gotoxy(53, y2);
            printf(">");

                if(y2 == 16){
                    enter = 0;
                    gotoxy(67, 16);
                    if(x2 == 0){
                    printf(" Facil");
                    } else if(x2 == 1){
                    printf(" Medio");
                    } else if(x2 == 2){
                        printf(" Dificil");
                    } else if(x2 == 3){
                        printf(" Crescente");
                    } else if(x2 == 4){
                        printf(" Sem fim");
                    }

                    if(kbhit() != 0){
                        tecla = getch();
                        switch (tecla){
                            case 72:
                                y2--;
                                break;
                            case 80:
                                y2++;
                                break;
                            case 75:
                                x2--;
                                break;
                            case 77:
                                x2++;
                                break;
                            case 13:
                                enter = 2;
                        }
                        if(x2 < 0){
                            x2 = 4;
                        } else if(x2 > 4){
                            x2 = 0;
                        }
                        if(y2 < 16){
                            y2 = 19;
                        } else if(y2 > 19){
                            y2 = 16;
                        }
                    }
                    if(x2 == 0){//Facil
                        dificuldade = 50;
                        limiteParede = 0;
                    } else if(x2 == 1){//Medio
                        dificuldade = 25;
                        limiteParede = 0;
                    } else if(x2 == 2){//Dificil
                        dificuldade = 5;
                        limiteParede = 0;
                    } else if(x2 == 3){//Crescente
                        dificuldade = 0;
                        velocidade = 50;
                        limiteParede = 0;
                    }  else if(x2 == 4){//Sem fim
                        dificuldade = 10;
                        if(parede == 0){
                            parede = 1;
                            x3 = 1;
                        }
                        limiteParede = 1;
                    }
                } else if(y2 == 17){
                    enter = 0;
                    gotoxy(63, 17);
                    if(parede == 0){
                        printf("Normal");
                    } else if(parede == 1){
                        printf("Desvia");
                    } else if(parede == 2){
                        printf("Sem paredes");
                    }
                    if(kbhit() != 0){
                        tecla = getch();
                        switch (tecla){
                            case 72:
                                y2--;
                                break;
                            case 80:
                                y2++;
                                break;
                            case 75:
                                x3--;
                                break;
                            case 77:
                                x3++;
                                break;
                            case 13:
                                enter = 2;
                        }
                        if(x3 < limiteParede){
                            x3 = 2;
                        } else if(x3 > 2){
                            x3 = limiteParede;
                        }
                        if(y2 < 16){
                            y2 = 18;
                        } else if(y2 > 18){
                            y2 = 16;
                        }
                        if(x3 == 0){
                            parede = 0;
                        } else if(x3 == 1) {
                            parede = 1;
                        } else if(x3 == 2){
                            parede = 2;
                        }
                    }

                } else if(y2 == 18 && enter == 2) { // Resetar os Placares
                    printf(" Voce tem certeza de que deseja resetar os placares?");
                    escolha = getch();
                    if(escolha == 13){
                        zerarPlacar();
                        gotoxy(80, 29);
                        printf("O placar foi resetado com sucesso!");
                        getch();
                    }
                    enter = 0;
                } else if(y2 == 19 && enter == 2){
                    y2 = 18;
                    break;
                }
            }

        } else if(y2 == 17 && enter == 1){ // carregar jogo salvo
            dificuldade = carregar();
            parede = carregar();
            velocidade = carregar();
            p = carregar();
            x1 = carregar();
            y1 = carregar();
            g = carregar();
            for(t = 0; t <= p; t++){
                for(v = 0; v < 2; v++){
                    posicao[t][v] = carregar();
                }
            }
            fclose(arquivo);
            x = posicao[0][0];
            y = posicao[0][1];
            y2 = 15;
            goto pausa;

        } else if(y2 == 19 && enter == 1){  //Placares
            pontuacoes();
            enter = 0;
        } else if(y2 == 20 && enter == 1){ //Sair
            exit(0);
        }
    }
    comeco:
    if(dificuldade == 0){
        velocidade = 50;
    }
    x = 25;
    y = 10;
    z = 4;
    p = 1;
    g = 4;

    rand = time(NULL);
    x1 = (rand * rand) %119+1;
    y1 = (rand * 3) %23+1;

    loop:

    if(posicao[0][0] == x1 && posicao[0][1] == y1){ //Marcar pontuacao
        rand = time(NULL);
        x1 = (rand * rand)%119+1;
        y1 = (rand * 3)%23+1;
        verificar:
        for(t = 0; t < p; t++){
            if(x1 == posicao[t][0] && y1 == posicao[t][1]){
                x1 = (y1 * rand)%119 +1;
                y1 = (x1 * rand)%23 + 1;
                goto verificar;
            }
        }
        p++;
        if(p%3 == 1){
            velocidade -= 1;
        }
        rbug = 1;
    }

    gotoxy(x1, y1);
    printf("@");

    do{
        if(kbhit()){ //Comandos durante o jogo
            Resprobtec:
            tecla = getch();
            if(tecla == 'w' || tecla == 'W' || tecla == 72){
                if(g == 2 && p > 1){
                        z = 2;
                    } else {
                        z = 1;
                    }
            } else if(tecla == 's' || tecla == 'S' || tecla == 80){
                if (g == 1 && p > 1){
                        z = 1;
                    } else {
                        z = 2;
                    }
            } else if(tecla == 'a' || tecla == 'A' || tecla == 75){
                if (g == 4 && p > 1){
                        z = 4;
                    } else {
                        z = 3;
                    }
            } else if(tecla == 'd' || tecla =='D' || tecla == 77){
                if (g == 3 && p > 1){
                        z = 3;
                    } else {
                        z = 4;
                    }
            } else if(tecla == 'p' || tecla == 'P' || tecla == 27){
                z = 0;
            } else if(tecla == -32){
                goto Resprobtec;
            }
        } else {
            goto aliEmbaixo;
        }

    }while(tecla != '0');
    aliEmbaixo:
    loop1:
    if (dificuldade == 0){//Velocidade
        if(velocidade < 5){
            velocidade = 5;
        }
    } else if(dificuldade == 10){
        velocidade = 25;
    } else {
        velocidade = dificuldade;
    }
    Sleep(velocidade);
        if(z == 1){
            w:
            y--;
            g = 1;
        } else if(z == 2){
            s:
            y++;
            g = 2;
        } else if(z == 3){
            a:
            x--;
            g = 3;
        } else if(z == 4){
            d:
            x++;
            g = 4;
        } else if(z == 0){ // pausa
            y2 = 15;
            while(pausa != 1){
                pausa:
                enter = 0;
                system("cls");
                gotoxy(54, 13);
                printf("Jogo pausado");
                gotoxy(55, 15);
                printf("Continuar");
                gotoxy(55, 16);
                printf("Menu");
                gotoxy(55, 17);
                printf("Salvar");
                gotoxy(55, 18);
                printf("Sair");
                if(jogosalvo == 1){
                    gotoxy(105, 29);
                    printf("Jogo salvo");
                }
                if(kbhit() != 0){
                    tecla = getch();
                    switch (tecla){
                        case 72:
                            y2--;
                            break;
                        case 80:
                            y2++;
                            break;
                        case 13:
                            enter = 1;
                        case 27:
                            pausa = 1;
                            break;
                        case 'p':
                            pausa = 1;
                            break;
                    }
                    if(y2 < 15){
                        y2 = 18;
                    } else if(y2 > 18){
                        y2 = 15;
                    }
                }

                gotoxy(53, y2);
                printf(">");
                if(y2 == 15 && enter == 1){
                    pausa = 1;
                } else if(y2 == 16 && enter == 1){
                    main();
                } else if(y2 == 17 && enter == 1){
                    for(r = 0; r <= p; r++){
                        for(o = 0; o < 2; o++){
                            salvar(dificuldade, parede, velocidade, p, x1 , y1, g , posicao[r][o]); // Salvar partida
                            jogosalvo = 1;
                            pausa = 0;
                        }
                    }
                    fclose(arquivo);
                    salvando = 0;
                } else if( y2 == 18 && enter == 1){
                    exit(0);
                }
            }
            jogosalvo = 0;
            pausa = 0;
            enter = 0;
            z = g;
            if(g == 1){
                goto w;
            } else if(g == 2){
                goto s;
            } else if(g == 3){
                goto a;
            } else if (g == 4){
                goto d;
            }
        }
    if(parede == 0){ //Parede: Modo NORMAL
        if(x < 1){
            goto fimdojogo;
        } else if(x > 120){
            goto fimdojogo;
        }
        if(y < 1){
            goto fimdojogo;
        } else if(y > 27){
            goto fimdojogo;
        }
    } else if(parede == 1){ //Parede: Modo DESVIA
        if(x < 1){
            x = 1;
            if(y > 13){
                if(b == 2){
                    z = 2;
                } else {
                    z = 1;
                }
                goto loop;
            } else {
               if(b == 1){
                    z = 1;
                } else {
                    z = 2;
                }
                goto loop;
            }
        } else if(x > 120){
            x = 120;
            if(y > 13){
                if(b == 2){
                    z = 2;
                } else {
                    z = 1;
                }
                goto loop;
            } else {
                if(b == 1){
                    z = 1;
                } else {
                    z = 2;
                }
                goto loop;
            }
        }
        if(y < 1){
            y = 1;
            if(x > 60){
                if(b == 4){
                    z = 4;
                } else {
                    z = 3;
                }
                goto loop;
            } else {
                if(b == 3){
                    z = 3;
                } else {
                    z = 4;
                }
                goto loop;
            }
        } else if(y > 27){
            y = 27;
        if(x > 60){
                if(b == 4){
                    z = 4;
                } else {
                    z = 3;
                }
                goto loop;
            } else {
                if(b == 3){
                    z = 3;
                } else {
                    z = 4;
                }
                goto loop;
            }
        }
    } else if(parede == 2){
        if(x < 1){
            x = 120;
        } else if(x > 120){
            x = 1;
        }
        if(y < 1){
            y = 27;
        } else if(y > 27){
            y = 1;
        }

    }
    if(x == 1 || x == 120 || y == 1 || y == 27){ //Resolucao do problema com o modo desvia
        b = z;
    } else {
        b = 0;
    }
    if(carregando == 1){
        for(t = p; t > 0; t--){
            gotoxy(posicao[t][0], posicao[t][1]);
            printf("o");
        }
        carregando = 0;
    }
    system("cls");
    gotoxy(x, y);
    printf("O");
    posicao[0][0] = x;
    posicao[0][1] = y;
    for(t = 3; t <= p; t++){ //Condicao para perder
        if(posicao[0][0] == posicao[t][0] && posicao[0][1] == posicao[t][1]){
            if (dificuldade == 10){
                p = t;
            } else {
                goto fimdojogo;
            }
        }
    }
    for(t = p; t > 0; t--){ //Movimento do corpo
        gotoxy(posicao[t][0], posicao[t][1]);
        if(rbug == 0){
            if (t == p) {
                if (posicao[t][0] < posicao[t - 1][0]){
                    printf("<");
                } else if(posicao[t][0] > posicao[t - 1][0]){
                    printf(">");
                } else if(posicao[t][1] < posicao[t - 1][1]){
                    printf("^");
                } else if(posicao[t][1] > posicao[t - 1][1]){
                    printf("v");
                }
            } else {
                printf("o");
            }
        }
        rbug = 0;
        posicao[t][0] = posicao[t - 1] [0];
        posicao[t][1] = posicao[t - 1] [1];
    }

    gotoxy(1, 28);
    printf("-----------------------------------------------------------------------------------------------------------------------\n");
    printf("                                                       Pontua%c%co: %d", 135, 198 ,p - 1);

    goto loop;

    fimdojogo:
    Sleep(500);
    gotoxy(54, 15);
    printf("Fim do jogo.");
    gotoxy(52, 16);
    printf("Sua pontua%c%co: %d", 135, 198, p - 1);
    placar(p);
    getch();
    enter = 0;
    y2 = 15;
    while(enter == 0){
        system("cls");
        gotoxy(54, 13);
        printf("Fim do jogo.");
        gotoxy(55, 15);
        printf("Jogar novamente");
        gotoxy(55, 16);
        printf("Menu");
        gotoxy(55, 17);
        printf("Sair");
        if(kbhit() != 0){
            tecla = getch();
            switch (tecla){
                case 72:
                    y2--;
                    break;
                case 80:
                    y2++;
                    break;
                case 13:
                    enter = 1;
            }
            if(y2 < 15){
                y2 = 17;
            } else if(y2 > 17){
                y2 = 15;
            }
        }

        gotoxy(53, y2);
        printf(">");
        if(y2 == 15 && enter == 1){
            enter = 0;
            goto comeco;
        } else if(y2 == 16 && enter == 1){
            enter = 0;
            main();
        } else if(y2 == 17 && enter == 1){
            exit(0);
        }
    }
}

void salvar(int dificuldade, int parede, int velocidade, int pontuacao, int x1, int y1, int g ,int posicao)
{
    int x = 0, y = 0, z = 0, ya = 0;
    char nome[100], nomeArquivo[120], local[16] = "Jogos Salvos//", tipo[5] = ".txt";
    if(salvando == 0){
        printf(" Nome do arquivo:");
        scanf("%s", nome);
        while(local[x] != '\0'){
            nomeArquivo[x] = local[x];
            x++;
        }
        while(nome[y] != '\0'){
            nomeArquivo[y + 14] = nome[y];
            y++;
        }
        while(tipo[z] != '\0'){
            nomeArquivo[y + 14 + z] = tipo[z];
            z++;
        }
        nomeArquivo[y + 14 + z] = '\0';
        arquivo = fopen(nomeArquivo, "w");
    }
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo");
    } else {
        if(salvando == 0){
            fprintf(arquivo, "%d %d %d %d %d %d %d " , dificuldade, parede, velocidade, pontuacao, x1, y1, g);
            fclose(arquivo);
        }
        salvando = 1;
        arquivo = fopen(nomeArquivo, "a");
        fprintf(arquivo, "%d ", posicao);
    }
}

int carregar()
{
    int re;
    if(carregando == 0){
        arquivo = fopen("Jogos Salvos//salvando.txt", "r");
    }
    carregando = 1;
    if(arquivo == NULL){
        printf("Erro ao abrir arquivo");
    } else {
        fscanf(arquivo, "%d ", &re);
        return re;
    }

}
void pontuacoes()
{
    short y, x, a = 0;
    int pont[10];
    char tecla;
    arquivo = fopen("Dados do Jogo//Placar.txt", "r");

    if(arquivo == NULL){
        printf("Erro ao visualizar o placar!");
    } else {
        system("cls");
        while((fscanf(arquivo,"%d ",&pont[a]))!= EOF){
            a++;
        }

    }
    fclose(arquivo);
    loop:
    y = 23;
    x = 10;
    gotoxy(57, 11);
    printf("Placar");
    for(a = 0; a < 10; a++){
        gotoxy(53, y);
        printf("Posicao %d:",x);
        gotoxy(65, y);
        if(pont[a] == 0){
            printf("-");
        } else {
            printf("%d", pont[a]);
        }
        y--;
        x--;

    }
    tecla = getch();
    if(tecla != 13 && tecla != 8 && tecla != 27){
        Sleep(150);
        system("cls");
        goto loop;
    }

}

void placar(int pontuacao)
{
    int ponto[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, x = 0, temporario, u = 0, y, z;
    arquivo = fopen("Dados do Jogo//Placar.txt", "r");
    pontuacao -= 1;
    if(arquivo == NULL){
        printf("Erro ao atualizar o placar");
    } else {
       for(x = 0; x < 10; x++){
            fscanf(arquivo,"%d ", &ponto[x]);
        }

    }
    fclose(arquivo);
    z = 0;
    arquivo = fopen("Dados do Jogo//Placar.txt", "w");
    if(arquivo == NULL){
        printf("Erro ao atualizar o placar");
    } else {
        for(x = 0; x < 10; x++){
            if(pontuacao < ponto[x] && pontuacao >= ponto[x - 1]){
                temporario = ponto[x - 1];
                ponto[x - 1] = pontuacao;
                u = 1;
                break;
            } else if(x == 9 && pontuacao >= ponto[x]){
                temporario = ponto[x];
                ponto[x] = pontuacao;
                u = 1;
                z = 1;
                break;
            }
        }
    }
    if(u == 1){
        for(x -= 1; x >= 0; x--){
            y = ponto[x];
            if(z == 1){
                ponto[x] = temporario;
                temporario = y;
            }
            z = 1;
        }
    }
    for(x = 0; x < 10; x++){
        fprintf(arquivo, "%d ", ponto[x]);
    }

    fclose(arquivo);
}

void zerarPlacar()
{
    arquivo = fopen("Dados do Jogo//Placar.txt", "w");
    if(arquivo == NULL){
        printf("Erro ao tentar resetar o placar.");
    } else {
        fprintf(arquivo,"0 0 0 0 0 0 0 0 0 0");
        fclose(arquivo);
    }
}
