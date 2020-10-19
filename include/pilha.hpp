// Copyright Henrique de Miranda Carrer 2020

/**
 * @file pilha.hpp
 * @author Henrique Carrer
 * @brief Biblioteca simples de Pilha
 * @version 0.1
 *
 * @copyright Copyright (c) 2020
 *
 */

#ifndef INCLUDE_PILHA_HPP_
#define INCLUDE_PILHA_HPP_
#define CAPACIDADE_INICIAL 10

#include <iostream>

/**
* \mainpage
* Estrutura da classe ItemType, contendo um inteiro
* responsável por ser o valor das variáveis presentes
* em ambas as pilhas. Possui um ponteiro do tipo
* ItemType para apontar para o elemento seguinte no
* caso da pilha dinâmica.
*/
class ItemType {
 public:
    int valor;
    ItemType * seguinte;
};

/**
* Estrutura da classe Pilha, responsável por representar
* uma pilha dinâmica. Contém um ponteiro ItemType respon-
* sável pelo conteúdo e ponteiro do próximo item da pilha.
* Contém um inteiro chamado tamanho para se indicar o atual
* tamanho da pilha. Seus métodos serão melhor explicados no
* arquivo pilhaD.cpp.
*/
class Pilha {
 private:
    ItemType * topo;
    int tamanho;

 public:
    Pilha* createStack();
    void destroyStack(Pilha* pilha);
    void push(Pilha *pilha, ItemType dado);
    ItemType* pop(Pilha* pilha);
    ItemType* top(Pilha* pilha);
    int size(Pilha* pilha);
    bool setSize(Pilha* pilha, int tamanho);
    bool isFull(Pilha* pilha);
    bool isEmpty(Pilha* pilha);
};

/**
* \mainpage 
* Estrutura da classe PilhaSTC, responsável por representar
* uma pilha estática. Contém um  vetor do tipo ItemType,
* onde somente o atributo "valor" é utilizado. Possui três
* inteiros, "tamanho", responsável por dizer o tamanho atual
* da pilha, "topo", responsável por dizer qual a posição do
* elemento do topo no vetor, e "dapacidade", responsável por
* dizer qual o tamanho máximo que a pilha suporta.
* Sua capacidade inicial é 10, podendo ser mudada no futuro.
* Seus métodos serão melhor explicados no
* arquivo pilhaD.cpp.
*/
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
};

#endif  // INCLUDE_PILHA_HPP_
