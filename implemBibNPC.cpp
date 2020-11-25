#include <iostream>
#include <clocale>
#include <stdlib.h>
#include "bibItens.h"
#include "bibNPC.h"
#include "bibDado.h"
#include "bibGame.h"
#include <time.h>
#include "stdafx.h"
#include <fcntl.h>
#include <io.h>

#include <windows.h>
#include <io.h> // <- need to add this include for _setmode
#include <fcntl.h> // <- need to add this include for _O_TEXT
#include <cstdio> // <- need to add this include for wprintf


using namespace std;

//cria uma arvore para armazenar os oponentes
void iniciarBancoNpc(TBancoNpc &banco){
    banco.raiz = NULL;
    banco.nome = "NPC";
    banco.contador=0;
}

bool verificaBanco(TBancoNpc banco){
    return banco.raiz == NULL; //Retorna valor NULL caso nao tenha NPC's cadastrados.
}

//NPCs são inserido utilizando o ID como metodo de ordenação, facilitando a busca.
void inserirNPC(TPersonagem i, TNpc *&n, TBancoNpc &banco){
     if (n == NULL){
        n = new TNpc;
        n->npc = i;
        n->esq = NULL;
        n->dir = NULL;
        if (banco.raiz == NULL){
            banco.raiz = n;
        };
        banco.contador++;
    }
    else{
        if (i.id < n->npc.id){
            inserirNPC(i,n->esq,banco);
        }else{
            if (i.id > n->npc.id){
                inserirNPC(i,n->dir,banco);
            }else{
                cout << "Erro ao inserir NPC!" << endl;
            }
        }
    }
}

//Função que crias os NPS
void cadastrarNPC(TBancoNpc &banco){
    TPersonagem n; //Cria uma variavel auxiliar do tipo TPersonagem
    n.nomePersonagem = "Esqueleto"; //Nome do Pesonagem
    n.f         =1; //Força
    n.h         =0; //Habilidade
    n.a         =1; //Armadura
    n.r         =1; //Resistencia
    n.pdf       =0; //Poder de fogo
    n.vida      =1; //Vida
    n.magia     =0; //Magia
    n.exp       =2; //Experiencia gerada
    n.id        =banco.contador; //ID gerado altomaticamente
    inserirNPC(n,banco.raiz,banco);
    n.nomePersonagem = "Zumbi";
    n.f         =1;
    n.h         =0;
    n.a         =1;
    n.r         =1;
    n.pdf       =0;
    n.vida      =1;
    n.magia     =1;
    n.exp       =2;
    n.id        =banco.contador;
    inserirNPC(n,banco.raiz,banco);
    n.nomePersonagem = "Anão";
    n.f         =1;
    n.h         =0;
    n.a         =1;
    n.r         =1;
    n.pdf       =0;
    n.vida      =3;
    n.magia     =0;
    n.exp       =3;
    n.id        =banco.contador;
    inserirNPC(n,banco.raiz,banco);
    n.nomePersonagem = "Druida";
    n.f         =3;
    n.h         =2;
    n.a         =2;
    n.r         =3;
    n.pdf       =0;
    n.vida      =3;
    n.magia     =0;
    n.exp       =4;
    n.id        =banco.contador;
    inserirNPC(n,banco.raiz,banco);
    n.nomePersonagem = "Goblin";
    n.f         =3;
    n.h         =2;
    n.a         =2;
    n.r         =3;
    n.pdf       =0;
    n.vida      =3;
    n.magia     =0;
    n.exp       =4;
    n.id        =banco.contador;
    inserirNPC(n,banco.raiz,banco);
    n.nomePersonagem = "Ranger";
    n.f         =1;
    n.h         =3;
    n.a         =2;
    n.r         =1;
    n.pdf       =0;
    n.vida      =3;
    n.magia     =0;
    n.exp       =3;
    n.id        =banco.contador;
    inserirNPC(n,banco.raiz,banco);
    n.nomePersonagem = "Golem";
    n.f         =4;
    n.h         =1;
    n.a         =1;
    n.r         =3;
    n.pdf       =0;
    n.vida      =11;
    n.magia     =0;
    n.exp       =5;
    n.id        =banco.contador;
    inserirNPC(n,banco.raiz,banco);
}

void pesquisarNPC(TPersonagem &aux, TNpc *n, TBancoNpc banco){
    if (n == NULL){
        cout << "Registro não localizado!!" << endl;
    }
    //Busca os NPC atraves do ID dentro da Arvore
    else {
        //Se menor busca pela esquerda
        if (aux.id < n->npc.id){
            pesquisarNPC(aux, n->esq, banco);
        }
        else {
            //se maior busca pela direita
            if (aux.id > n->npc.id){
                pesquisarNPC(aux, n->dir, banco);
            }
            else{
                aux = n->npc;
            }
        }
    }
}
