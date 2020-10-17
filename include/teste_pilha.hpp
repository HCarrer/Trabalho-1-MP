#ifndef TESTE_PILHA_HPP
#define TESTE_PILHA_HPP

#define SUCESSO 1
#define FALHA 0

#include <iostream>
#include "pilha.hpp"

class TestePilhaD : Pilha {
private:
    Pilha* pilha;
public:
    bool estado;

    void teste_create();
    void teste_push();
    void teste_top();
    void teste_pop();
    void teste_size();
    void teste_setSize();
};

#endif //TESTE_PILHA_HPP