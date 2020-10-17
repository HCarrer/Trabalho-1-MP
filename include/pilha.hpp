#ifndef PILHA_HPP
#define PILHA_HPP
#define CAPACIDADE_INICIAL 10

#include <iostream>

class ItemType {

public:
    int valor; 
    ItemType * seguinte;

};

class Pilha {

private:
    ItemType * topo;
    int tamanho;

public:
    Pilha* createStack();
    void destroyStack(Pilha* pilha);
    void push(Pilha *pilha, ItemType dado);
    ItemType* pop(Pilha* pilha) ;
    ItemType* top(Pilha* pilha);
    int size(Pilha* pilha);
    bool setSize(Pilha* pilha, int tamanho);
    bool isFull(Pilha* pilha);
    bool isEmpty(Pilha* pilha);
};


class PilhaSTC {

private:
    int tamanho, topo, capacidade;
    ItemType vetor[CAPACIDADE_INICIAL];

public:
    PilhaSTC* createStack();
    void destroyStack(PilhaSTC* pilha);
    void push(PilhaSTC *pilha, ItemType dado);
    ItemType pop(PilhaSTC* pilha);
    ItemType top(PilhaSTC* pilha);
    int size(PilhaSTC* pilha);
    bool setSize(PilhaSTC* pilha, int tamanho);
    bool isFull(PilhaSTC* pilha);
    bool isEmpty(PilhaSTC* pilha);
    
    void show(PilhaSTC* pilha, int elemento);
};

#endif // PILHA_HPP