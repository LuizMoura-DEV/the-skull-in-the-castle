#include <iostream>
#include <clocale>
#include <stdlib.h>
#include "bibItens.h"
#include "bibNPC.h"
#include "bibDado.h"
#include "bibGame.h"
#include <time.h>


using namespace std;


void barra(int x, int y){
    int aux=1;
    for(int i=1; i<=x;i++){
    cout << "▮";                //desenha barra cheia para quantidade
    aux++;
    }
    for(int j=aux; j<=y; j++){
    cout << "▯";                //completa com barra vazia
    }
}

//Desenhas os personagens na tela do terminal
void desenho(int character){
    switch (character){
    case 1:
        cout << "    ☤             " << endl;
        cout << "   ↙█↘☄           " << endl;
        cout << "    █             " << endl;
    break;
    case 2:
        cout << "    ☫             " << endl;
        cout << "   ╽█◍            " << endl;
        cout << "    █             " << endl;
    break;
    case 3:
        cout << "    ☬           " << endl;
        cout << "   ↙█⟫          " << endl;
        cout << "    █           " << endl;
    break;
    default:
        cout << "    ☺           " << endl;
        cout << "    █           " << endl;
        cout << "    █           " << endl;
    break;
    }
}

//Escreve o nome do porsonagem
void classe(int classe){
    switch(classe){
    case 1:
        cout << " - MAGO - ";
    break;
    case 2:
        cout << " - GUERREIRO - ";
    break;
    case 3:
        cout << " - ARQUEIRO - ";
    break;
    default:
        cout << " - ERRO - ";
    break;
    }
}

//contem od dados de cada tipo de classe de personagem
void caracteristicas(TPersonagem &player){
    switch (player.character){
    case 1:
        player.f    = 1;        //Força do Personagem 1
        player.h    = 2;        //Habilidade do Personagem 1
        player.a    = 3;        //Armadura do personagem 1
        player.r    = 1;        //Resistencia do Personagem 1
        player.pdf  = 5;        //Poder de fogo do Personagem 1

    break;
    case 2:
        player.f    = 3;        //Força do Personagem 2
        player.h    = 2;        //Habilidade do Pesonagem 2
        player.a    = 2;        //Armadura do Personagem 2
        player.r    = 2;        //Resistencia do Personagem 2
        player.pdf  = 5;        //Poder de Fogo do Pesonagem 2
    break;
    case 3:
        player.f    = 2;        //Força do Personagem 3
        player.h    = 2;        //Habilidade do Personagem 3
        player.a    = 2;        //Armadura do Personagem 3
        player.r    = 1;        //Resistencia do Personagem 3
        player.pdf  = 4;        //Poder de Fogo do Personagem 3
    break;
    }
    player.nivel = 0;           //Nivel inicial dos personagens
    player.id = 0;              //ID dos players
    player.exp = 0;             //zera a experiencia
    player.vida = 50;           //Vida inicial dos jogadores
    player.magia = player.vida; //Quantidade de Magia
}

//limpa o terminal, deixando menos poluido
void limpar(){
    cout << "\033[2J"; //limpa
    cout << "\033[u";  //reseta cursor
}

//Desenha os tipos de personagens o usuario pode escolher
void tela1(TPersonagem player){
    limpar();
    cout << "===============================================================" << endl;
    cout << ">> " << player.nomePersonagem << endl;
    cout << "Personagens\n" << endl;
    cout << " 1-MAGO             " << endl;
    cout << "    ☤         FORÇA        : 1 | ARMADURA      : 1" << endl;
    cout << "   ↙█↘☄       HABILIDADE   : 2 | PODER DE FOGO : 5" << endl;
    cout << "    █         ARMADURA     : 3\n" << endl;
    cout << " 2-GUERREIRO        " << endl;
    cout << "    ☫         FORÇA        : 3 | ARMADURA      : 2" << endl;
    cout << "   ╽█◍        HABILIDADE   : 2 | PODER DE FOGO : 7" << endl;
    cout << "    █         ARMADURA     : 2\n" << endl;
    cout << " 3-ARQUEIRO         " << endl;
    cout << "    ☬         FORÇA        : 2 | ARMADURA      : 1" << endl;
    cout << "   ↙█⟫        HABILIDADE   : 2 | PODER DE FOGO : 4" << endl;
    cout << "    █         ARMADURA     : 2\n" << endl;
    cout << "\n\n";
    cout << "===============================================================" << endl;
}


void personagem(TPersonagem &player){
    limpar(); //Limpa o terminal
    cout << "\n===============================================================" << endl;
    cout << ">> " << player.nomePersonagem;
    classe(player.character);
    cout << "NIVEL = " << player.nivel << endl;
    desenho(player.character);
    cout << " FORÇA:          " << player.f << endl;        //Exibe a força
    cout << " HABILIDADE:     " << player.h<< endl;         //Exibe a habilidade
    cout << " ARMADURA:       " << player.a<< endl;         //Exibe a armadura
    cout << " RESISTENCIA:    " << player.r<< endl;         //Exibe a resistencia
    cout << " PODER DE FOGO:  " << player.pdf<< endl;       //Exibe o Poder de Fogo
    cout << " XP:    ";
    barra(player.exp, 20);  //Mostra quantidade de experiencia
    cout << "\n VIDA:  ";
    barra(player.vida, 50); //Mostra quantidade de vida
    cout << endl;
    cout << " MAGIA: ";
    barra(player.magia, 50); //mostra quantidade de magia
    cout << "\n\n\n\n\n\n\n\n\n\n";
    cout << "===============================================================" << endl;
}

//Utilizada na animação de combate
void personagemCob(TPersonagem player){
    cout << "\n===============================================================" << endl;
    cout << ">> " << player.nomePersonagem;
    classe(player.character);
    cout << "NIVEL = " << player.nivel << endl;
    desenho(player.character);
    cout << " FORÇA:          " << player.f << endl;
    cout << " HABILIDADE:     " << player.h<< endl;
    cout << " ARMADURA:       " << player.a<< endl;
    cout << " RESISTENCIA:    " << player.r<< endl;
    cout << " PODER DE FOGO:  " << player.pdf<< endl;
    cout << " XP:    ";
    barra(player.exp, 20);
    cout << "\n VIDA:  ";
    barra(player.vida, 50);
    cout << endl;
    cout << " MAGIA: ";
    barra(player.magia, 50);
    cout << "\n===============================================================" << endl;
}

//Inicia a criação do personagem pelo jogador
void criarPersonagem(TPersonagem &player){;
    tela1(player);
    cout << "Digite um nome para seu personagem" << endl;
    cout << "=> ";
    cin >> player.nomePersonagem;       //Recebe o nome do personagem criado
	int confirmar=0;
	while(confirmar!=1){                //Permanece dentro do while enquando o Usuario nao digitar 1
        tela1(player);
        cout << "Selecione um personagem(Digite o numero correspoondente): ";
        cin >> player.character;
        switch (player.character){
        case 1:                                 //Caso 1 exibe o Mago
            caracteristicas(player);
            personagem(player);
        break;
        case 2:                                 //Caso 2 exibe o Guerreiro
            caracteristicas(player);
            personagem(player);
        break;
        case 3:                                 //Caso 3 exibe o Arqueiro
            caracteristicas(player);
            personagem(player);
        break;
        default:
            caracteristicas(player);
            personagem(player);
        break;
            }
        if(player.character==1 ||player.character==2||player.character==3){
        cout << "Digite 1  para confirmar e 0 para cancelar: ";
        cin >> confirmar;
        }else{
        confirmar = 0;
        }
    }
    personagem(player);
    cout << "Personagem criado com sucesso!!!" << endl;
}


//Reponsavel pelo combate, calculo de dano e tipo de dano
void ataque(TPersonagem &player, TPersonagem &oponente){

    int playerDano, oponenteDano, aux, criticoPl = 0, criticoOp = 0, tipoAtk, atk, cm;
    if(player.magia>0){
        switch(player.character){
        case 1:     //Tipos de ataque do personagem tipo 1
            cout << "===============================================================" << endl;
            cout << "                    1 - Atacar || 2 - Magia                     " << endl;
            cout << "=> ";
            cin >> tipoAtk;
            cm=3;
        break;
        case 2:     //Tipos de ataque do personagem tipo 2
            cout << "===============================================================" << endl;
            cout << "                    1 - Atacar || 2 - Adaga                     " << endl;
            cout << "=> ";
            cin >> tipoAtk;
            cm=15;
        break;
        case 3:     //Tipos de ataque do personagem tipo 3
            cout << "===============================================================" << endl;
            cout << "                    1 - Atacar || 2 - Flecha                    " << endl;
            cout << "=> ";
            cin >> tipoAtk;
            cm=5;
        break;
        }
    }else{
        cout << "===============================================================" << endl;
        cout << "                    1 - Atacar || Mana Inssuficiente           " << endl;
        tipoAtk=1;
    }

    //define se sera utilidado ataque 1 ou 2
    if(tipoAtk == 1){
        atk = player.f;
    }else{
        atk = player.pdf;
        player.magia = player.magia - cm;  //remove magia, ja que eh um ataque com base nesse atributoŔ
    }

    aux = dado(0,10);
    if (aux == 10){
        criticoPl = 1;
    }

    //dano é calculado com o ataque/pdf do personagem + dado tanto para o personagem quanto para o NPC
    playerDano = (atk +  player.h + aux) - (oponente.f + oponente.h + dado(0,5));
    aux = dado(0,5);
    if (aux == 5){
        criticoOp = 1;
    }
    oponenteDano = (player.f + player.h + aux) - (oponente.a + oponente.h + dado(0,3));


    if(oponenteDano<=0){
        oponenteDano = 0;       //caso nao tenha sofrido dano exibe
        cout << ">> Você Esquivou! << ";
    }else{
        cout << "Dano Sofrido: "<< oponenteDano;
        if (criticoPl == 1){        //caso tenha recebido dano maximo
            cout << " >> Dano Critico! << ";
    }
    }

    if(playerDano <=0){
        playerDano = 0; //caso nao tenha sofrido dano exibe
        cout << "\n>> Oponente Esquivou! << ";
    } else {
        cout << "\nDano Causado: "<< playerDano;
        if (criticoOp == 1){        //caso tenha recebido dano maximo
            cout << " >> Dano Critico! << ";
    }

    }
    player.vida = player.vida - oponenteDano;       //atribui o dano no personagem retirando equivalente de sua vida
    oponente.vida = oponente.vida - playerDano;     //Atribui o dano no NPC
}


//Exibe animação de derrota
void morte(TPersonagem &player){
    int acao;
    limpar();
    cout << "===============================================================" << endl;cout << "            88                               88       " << endl;
    cout << "            88                         ,d    88           " << endl;
    cout << "            88                         88    88           " << endl;
    cout << "    ,adPPYb,88  ,adPPYba, ,adPPYYba, MM88MMM 88,dPPYba,   " << endl;
    cout << "   a8*    `Y88 a8P_____88 ""       `Y8   88    88P'    *8a  " << endl;
    cout << "   8b       88 8PP******* ,adPPPPP88   88    88       88  " << endl;
    cout << "   *8a,   ,d88 *8b,   ,aa 88,    ,88   88,   88       88  " << endl;
    cout << "    `*8bbdP*Y8  `*Ybbd8*' `*8bbdP*Y8   *Y888 88       88  " << endl;
    cout << "===============================================================" << endl;
    cout << endl;
    cout <<"                       :::!~!!!!!:.               " << endl;
    cout <<"                  .xUHWH!! !!?M88WHX:. " << endl;
    cout <<"                .X*#M@$!!  !X!M$$$$$$WWx:. " << endl;
    cout <<"               :!!!!!!?H! :!$!$$$$$$$$$$8X: " << endl;
    cout <<"              !!~  ~:~!! :~!$!#$$$$$$$$$$8X: " << endl;
    cout <<"             :!~::!H!<   ~.U$X!?R$$$$$$$$MM! " << endl;
    cout <<"             ~!~!!!!~~ .:XW$$$U!!?$$$$$$RMM! " << endl;
    cout <<"               !:~~~ .:!M%T#$$$$WX??#MRRMMM! " << endl;
    cout <<"               ~?WuxiW*`   `*#$$$$8!!!!??!!! " << endl;
    cout <<"             :X- M$$$$       `*T#$T~!8$WUXU~ " << endl;
    cout <<"            :%`  ~#$$$m:        ~!~ ?$$$$$$ " << endl;
    cout <<"          :!`.-   ~T$$$$8xx.  .xWW- ~**##** " << endl;
    cout <<".....   -~~:<` !    ~?T#$$@@W@*?$$      /` " << endl;
    cout <<"W$@@M!!! .!~~ !!     .:XUW$W!~ `*~:    : " << endl;
    cout <<"#* `.:x%`!!  !H:    WM$$$$Ti.: .!WUn+!` " << endl;
    cout <<":::~:!!`:X~ .: ?H.!u *$$$B$$$!W:U!TM~ " << endl;
    cout <<".~~   :X@!.-~   ?@WTWo(**$$$W$TH$! ` " << endl;
    cout <<"Wi.~!X$?!-~    : ?$$$B$Wu(***$RM! " << endl;
    cout <<"$R@i.~~ !     :   ~$$$$$B$$en:`` " << endl;
    cout <<"?MXT@Wx.~    :     ~*##*$$$$M~ " << endl;
    cout << endl;
    cout << "===============================================================" << endl;
    cout << "                   1- Reiniciar | 2 - Sair                " << endl;
    cout << "=> ";
    cin >> acao;
    if(acao==2){
        limpar();
        exit(0);
    }else{
        criarPersonagem(player);
        limpar();
    }
}

//Exibe animação de Vitoria
void fimDeJogo(TPersonagem &player){
    int acao;
    limpar();
    cout << "                          _    __    __    __    __    _      " << endl;
    cout << "                         | |__|__|__|__|__|__|__|__|__|_|" << endl;
    cout << "   __    __    __       |_|___|___|___|___|___|___|___||       __    __    __" << endl;
    cout << "   |__|  |__|  |__|      |___|___|___|___|___|___|___|__|      |__|  |__|  |__|" << endl;
    cout << "   |__|__|__|__|__|       |____________________________|       |__|__|__|__|__|" << endl;
    cout << "   |_|___|___|___||        |_|___|___|___|___|___|___||        |_|___|___|___||" << endl;
    cout << "   |___|___|___|__|        |___|___|___|___|___|___|__|        |___|___|___|__|" << endl;
    cout << "    |_|__|__|___ |          |________________________|          |_|__|__|__|_|" << endl;
    cout << "     |__|____|__|           |___|___|___|___|___|__|              |_|__|__|_|" << endl;
    cout << "      |||_|_|_||             |_|___|___|___|___|__|_|             |_|_|_|_||" << endl;
    cout << "      ||_|_|||_|__    __    _| _  __ |_ __  _ __  _ |_    __    __||_|_|_|_|" << endl;
    cout << "      |_|_|_|_||__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|_|_|_|_||" << endl;
    cout << "      ||_|||_|||___|___|___|___|___|___|___|___|___|___|___|___|__||_|_|_|_|" << endl;
    cout << "      |_|_|_|_||_|___|___|___|___|___|___|___|___|___|___|___|___||_|_|_|_||" << endl;
    cout << "      ||_|_|_|_|___|___|___|___|___|___|___|___|___|___|___|___|__||_|_|_|_|" << endl;
    cout << "      |_|||_|_||_|___|___|___|___|___|___|___|___|___|___|___|___||_|_|_|_||" << endl;
    cout << "      ||_|_|_|_|___|___|___|___|___|_/| | | |__|___|___|___|___|__||_|_|_|_|" << endl;
    cout << "      |_|_|_|_||_|___|___|___|___|__/ | | | ||___|___|___|___|___||_|_|_|_||" << endl;
    cout << "      ||_|_|_|||___|___|___|___|___|| | | | | |____|___|___|___|__||_|_|_|_|" << endl;
    cout << "      |_|_|_|_||_|___|___|___|___|_|| | | | | |__|___|___|___|___||_|_|_|_||" << endl;
    cout << "     /___|___|__|__|___|___|___|___|| | | | | |____|___|___|___|_/_|___|__|_|  " << endl;
    cout << "    |_|_|_|_|_|_||___|___|___|___|_|| | | | | |__|___|___|___|__|_|__|__|__|_|" << endl;
    cout << "    ||_|_|_|_|_|_|_|___|___|___|___||_|_|_|_|_|____|___|___|____|___|__|__|__|" << endl;
    cout << " ===============================================================================" << endl;
    cout << "                                     LEVEL MAXIMO                                 " << endl;
    cout << " ===============================================================================" << endl;
    cout << "                               1 - Reiniciar | 2 - Sair                          " << endl;
    cin >> acao;
    if(acao==2){
        limpar();
        exit(0);
    }else{
        criarPersonagem(player);
        limpar();
    }
}

void acaoAtiva(int acao, TPersonagem &player, TPersonagem &oponente, TBancoNpc banco, TListaItens itens){
    switch (acao){
    case 1:
        ataque(player,oponente);
    break;
    case 2:
        int item,bonus;
        TItem *pegaAnterior;
        mostrarListaItens(itens);
        cout << "\n===============================================================" << endl;
        cout << "         1 - Poção de Vida | 2 - Poção de Mana" << endl;
        cin >> item;
        pegaAnterior = pegaAnteriorDoItem(item,itens);
        if(pegaAnterior->proximo != NULL){
            if(pegaAnterior->proximo->item.id == 1){
                bonus = pegaAnterior->proximo->item.bonus;
                player.vida = player.vida + bonus;
                if(player.vida > 50){
                    player.vida =50;
                }
            }
            if(pegaAnterior->proximo->item.id == 2){
                bonus = pegaAnterior->proximo->item.bonus;
                player.magia = player.magia + bonus;
                if(player.magia > 50){
                    player.magia =50;
                }
            }
        }else{
            cout << "Você nao possui o item!!" << endl;
        }
        retirarItem(pegaAnterior,itens);
    break;
    case 3:
        oponente.id = dado(0,6);
        pesquisarNPC(oponente, banco.raiz,banco);
    break;
    default:
    break;
    }
}

void telaCombate(TPersonagem &player ,TBancoNpc banco, TListaItens lista){
    limpar();
    while(player.vida >0){
        TPersonagem oponente;
        int acao, aux = 0, bonusVida, bonusXP;
        oponente.id = dado(0,6);
        pesquisarNPC(oponente, banco.raiz,banco);
        oponente.vida = oponente.vida * oponente.h + dado(5,15);
        while(oponente.vida > 0){
            personagemCob(player);
            cout << "OPONENTE: " << oponente.nomePersonagem << endl;
            cout << "FORÇA:         " << oponente.f << " || ARMADURA:      " << oponente.a << endl;
            cout << "HABILIDADE:    " << oponente.h << " || RESISTENCIA:   " << oponente.r << endl;
            cout << "VIDA: ";
            barra(oponente.vida, 50);
            cout << endl;
            cout << "===============================================================" << endl;
            cout << "              1- Combate  | 2 - Item | 3 - Fugir                " << endl;
            cout << "=> ";
            cin >> acao;
            acaoAtiva(acao, player,oponente,banco,lista);
            cout << "\n===============================================================" << endl;
            cout << "                           1-Continuar                    " << endl;
            cout << "=> ";
            cin >> acao;
            if(player.vida <= 0){
                morte(player);
            }
            limpar();
        }
    if(player.vida>0){
        bonusVida = oponente.exp * dado(2,5);
        player.vida = player.vida + bonusVida;          //recebe um bonus de vida aleatorio a cada vitoria
        bonusXP = oponente.exp * dado(1,4);             //gera experiencia com base aleatorio*experiencia monstro
        player.exp = player.exp + bonusXP;
        cout << "===============================================================" << endl;
        cout << ">> Você Matou " << oponente.nomePersonagem << " || Bônus vida + " << bonusVida << " || Bônus XP + " << bonusXP;
        //Verifica se o personagem possui experiencia suficiente para subir de nivel
        if(player.exp >=20){                //caso tenha experiencia suficente sobe de nivel
            cout << "\n>> Level UP \n>> FORÇA +1 | HABILIDADE +1 | ARMADURA +1 | RESISTENCIA | PdF +1";
            player.nivel++;                 //incrementa o nivel
            player.exp = 0;                 //reseta a quantidade de exp
            player.vida = player.vida + 5;  //recebe 5 de vida
            if (player.vida >= 50){         //elimina estouro na variavel
                player.vida=50;
            }
            player.f++;             //incrementa força
            player.h++;             //incrementa habilidade
            player.a++;             //incrementa armadura
            player.r++;             //incrementa resistencia
            player.pdf++;           //incrementa poder de fogo
        }
        }
        if(player.nivel >=20){      //verifica se o jogador possui vida, caso nao chama a função morte
            fimDeJogo(player);
        }
    }
}
