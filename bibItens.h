#ifndef BIBITENS_H_INCLUDED
#define BIBITENS_H_INCLUDED

using namespace std;

struct TPocao{
    string nomeItem;
    int id, bonus;
};

struct TItem{
    TPocao item;
    TItem *proximo;
};

struct TListaItens{
    TItem *primeiro;
    TItem *ultimo;
};

void criaListaItens(TListaItens &itens);

bool eVazia(TListaItens &itens);

void inserirItens(TPocao n, TListaItens &itens);

void mostrarListaItens(TListaItens itens);

TItem *pegaAnteriorDoItem(int id, TListaItens itens);

void retirarItem(TItem *antItemRet, TListaItens &itens);

void listaItens(TListaItens &itens);

#endif // BIBITENS_H_INCLUDED
