#ifndef BIBGAME_H_INCLUDED
#define BIBGAME_H_INCLUDED


void barra(int x, int y);

void desenho(int character);

void classe(int classe);

void caracteristicas(TPersonagem &player);

void limpar();

void tela1(TPersonagem player);

void personagem(TPersonagem &player);

void personagemCob(TPersonagem player);

void criarPersonagem(TPersonagem &player);

void ataque(TPersonagem &player, TPersonagem &oponente);

void morte(TPersonagem &player);

void fimDeJogo(TPersonagem &player);

void acaoAtiva(int acao, TPersonagem &player, TPersonagem &oponente, TBancoNpc banco, TListaItens itens);

void telaCombate(TPersonagem &player ,TBancoNpc banco, TListaItens lista);
#endif // BIBGAME_H_INCLUDED
