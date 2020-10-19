// Copyright Henrique de Miranda Carrer 2020

/**
 * @file teste_pilha.hpp
 * @author Henrique Carrer
 * @brief Biblioteca simples de testes de Pilha
 * @version 0.1
 *
 * @copyright Copyright (c) 2020
 *
 */

#ifndef INCLUDE_TESTE_PILHA_HPP_
#define INCLUDE_TESTE_PILHA_HPP_

#define SUCESSO 1
#define FALHA 0

#include <iostream>
#include "pilha.hpp"

/**
* \mainpage
* Classe referente aos testes de métodos
* da classe "Pilha", responsável por uma
* pilha dinâmica.
*/
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

/**
* \mainpage
* Classe referente aos testes de métodos
* da classe "PilhaSTC", responsável por uma
* pilha estática.
*/
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

#endif  // INCLUDE_TESTE_PILHA_HPP_
