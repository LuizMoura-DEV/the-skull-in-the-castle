#include <iostream>
#include <clocale>
#include <stdlib.h>
#include "bibItens.h"
#include "bibNPC.h"
#include "bibDado.h"
#include "bibGame.h"
#include <time.h>


//http://www.codenet.ru/progr/video/ansi.php
using namespace std;

int main(){
	setlocale(LC_ALL, "Portuguese");
    TPersonagem player, npc;
    TPocao n;
    TBancoNpc listaNpc;
    TListaItens itens;
    criaListaItens(itens);
    listaItens(itens);
    iniciarBancoNpc(listaNpc);
    cadastrarNPC(listaNpc);
    criarPersonagem(player);
    telaCombate(player, listaNpc, itens);
	return 0;
}
