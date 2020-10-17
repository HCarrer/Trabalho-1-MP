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

    bool teste_create();
    bool teste_destroy();
    bool teste_push();
    bool teste_top();
    bool teste_pop();
    bool teste_size();
    bool teste_setSize();
    bool teste_IsFull();
    bool teste_IsEmpty();
};

class TestePilhaSTC : PilhaSTC {
private:
    PilhaSTC pilha;
public:
    bool estado;

    bool teste_create();
    bool teste_destroy();
    bool teste_push();
    bool teste_top();
    bool teste_pop();
    bool teste_size();
    bool teste_setSize();
    bool teste_IsFull();
    bool teste_IsEmpty();
};

#endif //TESTE_PILHA_HPP