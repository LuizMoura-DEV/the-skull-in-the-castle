#ifndef BIBNPC_H_INCLUDED
#define BIBNPC_H_INCLUDED

using namespace std;

struct TPersonagem{
    string nomePersonagem="", itens[9];
    int id ,character, nivel, f, h, a, r, pdf, vida, magia, exp;
};

struct TNpc{
    TPersonagem npc;
    TNpc *esq,*dir;
};

struct TBancoNpc{
    TNpc *raiz;
    string nome;
    int contador;
};

void iniciarBancoNpc(TBancoNpc &banco);

bool verificaBanco(TBancoNpc banco);

void inserirNPC(TPersonagem i, TNpc *&n, TBancoNpc &banco);

void cadastrarNPC(TBancoNpc &banco);

void percorrerNPC(TNpc *&n);

void mostrarNPCs(TBancoNpc banco);

void pesquisarNPC(TPersonagem &aux, TNpc *n, TBancoNpc banco);

#endif // BIBNPC_H_INCLUDED
