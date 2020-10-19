// Copyright Henrique de Miranda Carrer 2020

/**
 * @file teste_pilha.cpp
 * @author Henrique Carrer
 * @brief Arquivo de implementação de testes de Pilha
 * @version 0.1
 *
 * @copyright Copyright (c) 2020
 *
 */

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "pilha.hpp"
#include "teste_pilha.hpp"



////////////////////////// Testes Pilha Dinâmica ///////////////////////

/**
* \mainpage Index
* Método responsável por se testar a implementação
* do método "createStack" de uma pilha dinâmica.
* Não recebe parâmetros e retorna 1 caso tenha
* funcionado como esperado e 0 caso contrário.
*/
bool TestePilhaD::teste_create() {
    Pilha* temp = NULL;
    temp = temp->createStack();
    estado = SUCESSO;
    return estado;
}

/**
* \mainpage Index
* Método responsável por se testar a implementação
* do método "destroyStack" de uma pilha dinâmica.
* Não recebe parâmetros e retorna 1 caso tenha
* funcionado como esperado e 0 caso contrário.
*/
bool TestePilhaD::teste_destroy() {
    try {
        estado = FALHA;
        Pilha* temp = NULL;
        temp = temp->createStack();
        temp->destroyStack(temp);
        if (temp->size(temp) == 0) {
            estado = SUCESSO;
        }
    }
    catch(std::invalid_argument& ia) {
        std::cout << ia.what() << std::endl;
    }
    return estado;
}

/**
* \mainpage Index
* Método responsável por se testar a implementação
* do método "push" de uma pilha dinâmica.
* Não recebe parâmetros e retorna 1 caso tenha
* funcionado como esperado e 0 caso contrário.
*/
bool TestePilhaD::teste_push() {
    try {
        estado = FALHA;
        ItemType valido;
        valido.valor = 10;
        Pilha* temp = NULL;
        temp = temp->createStack();
        temp->push(temp, valido);
        if (temp->top(temp)->valor == valido.valor) {
            estado = SUCESSO;
        }
    }
    catch(std::invalid_argument& ia) {
        std::cout << ia.what() << std::endl;
    }
    return estado;
}

/**
* \mainpage Index
* Método responsável por se testar a implementação
* do método "top" de uma pilha dinâmica.
* Não recebe parâmetros e retorna 1 caso tenha
* funcionado como esperado e 0 caso contrário.
*/
bool TestePilhaD::teste_top() {
    try {
        estado = FALHA;
        ItemType valido1;
        valido1.valor = 99;
        Pilha* temp = NULL;
        temp = temp->createStack();
        temp->push(temp, valido1);
        if (temp->top(temp)->valor == valido1.valor) {
            estado = SUCESSO;
        }
    }
    catch(std::invalid_argument& ia) {
        std::cout << ia.what() << std::endl;
    }
    return estado;
}

/**
* \mainpage Index
* Método responsável por se testar a implementação
* do método "pop" de uma pilha dinâmica.
* Não recebe parâmetros e retorna 1 caso tenha
* funcionado como esperado e 0 caso contrário.
*/
bool TestePilhaD::teste_pop() {
    try {
        estado = FALHA;
        Pilha* temp = NULL;
        temp = temp->createStack();
        ItemType dado1, dado2;
        dado1.valor = 123;
        dado2.valor = 765;
        temp->push(temp, dado1);
        temp->push(temp, dado2);
        if (temp->top(temp)->valor == dado2.valor) {
            temp->pop(temp);
            if (temp->top(temp)->valor == dado1.valor) {
                estado = SUCESSO;
            }
        }
    }
    catch(std::invalid_argument& ia) {
        std::cout << ia.what() << std::endl;
    }
    return estado;
}

/**
* \mainpage Index
* Método responsável por se testar a implementação
* do método "size" de uma pilha dinâmica.
* Não recebe parâmetros e retorna 1 caso tenha
* funcionado como esperado e 0 caso contrário.
*/
bool TestePilhaD::teste_size() {
    try {
        estado = FALHA;
        Pilha* temp = NULL;
        temp = temp->createStack();
        int tamanhoComparador = 1;
        ItemType dado;
        dado.valor = 20;
        temp->push(temp, dado);
       if (temp->size(temp) == tamanhoComparador) {
           estado = SUCESSO;
       }
    }
    catch(std::invalid_argument& ia) {
        std::cout << ia.what() << std::endl;
    }
    return estado;
}

/**
* \mainpage Index
* Método responsável por se testar a implementação
* do método "setSize" de uma pilha dinâmica.
* Não recebe parâmetros e retorna 1 caso tenha
* funcionado como esperado e 0 caso contrário.
*/
bool TestePilhaD::teste_setSize() {
    try {
        estado = FALHA;
        int TAMANHO_TESTE = 2;
        // Caso TAMANHO_TESTE seja um valor maior que o atual, cairá no catch
        Pilha* temp = NULL;
        temp = temp->createStack();
        ItemType dado;
        dado.valor = 123;
        for (int i = 0; i < 10; i++) {
            temp->push(temp, dado);  // Adicionando 10 itens a pilha
        }
        if (temp->setSize(temp, 30) == 0) {  // Deve retornar 0 pois
        // a pilha implementada não permite mudar seu tamanho para um
        // maior ou igual ao atual
            temp->setSize(temp, TAMANHO_TESTE);
            if (temp->size(temp) == TAMANHO_TESTE) {
                estado = SUCESSO;
            }
        }
    }
    catch(std::invalid_argument& ia) {
        std::cout << ia.what() << std::endl;
    }
    return estado;
}

/**
* \mainpage Index
* Método responsável por se testar a implementação
* do método "isFull" de uma pilha dinâmica.
* Não recebe parâmetros e retorna 1 caso tenha
* funcionado como esperado e 0 caso contrário.
*/
bool TestePilhaD::teste_IsFull() {
    try {
        estado = FALHA;
        Pilha* temp = NULL;
        temp = temp->createStack();
        if (temp->isFull(temp) == 0) {
            estado = SUCESSO;
        }
    }
    catch(std::invalid_argument& ia) {
        std::cout << ia.what() << std::endl;
    }
    return estado;
}

/**
* \mainpage Index
* Método responsável por se testar a implementação
* do método "isEmpty" de uma pilha dinâmica.
* Não recebe parâmetros e retorna 1 caso tenha
* funcionado como esperado e 0 caso contrário.
*/
bool TestePilhaD::teste_IsEmpty() {
    try {
        estado = FALHA;
        Pilha* temp = NULL;
        temp = temp->createStack();
        if (temp->isEmpty(temp) == 1) {
            estado = SUCESSO;
        }
    }
    catch(std::invalid_argument& ia) {
        std::cout << ia.what() << std::endl;
    }
    return estado;
}




////////////////////////// Testes Pilha Estática ///////////////////////

/**
* \mainpage Index
* Método responsável por se testar a implementação
* do método "createStack" de uma pilha estática.
* Não recebe parâmetros e retorna 1 caso tenha
* funcionado como esperado e 0 caso contrário.
*/
bool TestePilhaSTC::teste_create() {
    try {
        PilhaSTC* temp = NULL;
        temp = temp->createStack();
        estado = SUCESSO;
    }
    catch(std::invalid_argument& ia) {
        std::cout << ia.what() << std::endl;
        estado = FALHA;
    }
    return estado;
}

/**
* \mainpage Index
* Método responsável por se testar a implementação
* do método "isEmpty" de uma pilha estática.
* Não recebe parâmetros e retorna 1 caso tenha
* funcionado como esperado e 0 caso contrário.
*/
bool TestePilhaSTC::teste_IsEmpty() {
    try {
        estado = FALHA;
        PilhaSTC* temp = NULL;
        temp = temp->createStack();
        if (temp->size(temp) == 0) {
            estado = SUCESSO;
        }
    }
    catch(std::invalid_argument& ia) {
        std::cout << ia.what() << std::endl;
    }
    return estado;
}

/**
* \mainpage Index
* Método responsável por se testar a implementação
* do método "isFull" de uma pilha estática.
* Não recebe parâmetros e retorna 1 caso tenha
* funcionado como esperado e 0 caso contrário.
*/
bool TestePilhaSTC::teste_IsFull() {
    try {
        estado = FALHA;
        PilhaSTC* temp = NULL;
        temp = temp->createStack();
        ItemType dado;      // dado para testar a função
        dado.valor = 123;   // valor genérico
        int i = 0;
        for (i; i < CAPACIDADE_INICIAL; i++) {
            temp->push(temp, dado);
        }
        if (temp->size(temp) == CAPACIDADE_INICIAL) {
            estado = SUCESSO;
        }
    }
    catch(std::invalid_argument& ia) {
        std::cout << ia.what() << std::endl;
    }
    return estado;
}

/**
* \mainpage Index
* Método responsável por se testar a implementação
* do método "push" de uma pilha estática.
* Não recebe parâmetros e retorna 1 caso tenha
* funcionado como esperado e 0 caso contrário.
*/
bool TestePilhaSTC::teste_push() {
    try {
        estado = FALHA;
        PilhaSTC* temp = NULL;
        temp = temp->createStack();
        ItemType dado;
        dado.valor = -456;
        temp->push(temp, dado);
        if (temp->top(temp).valor == dado.valor) {
            estado = SUCESSO;
        }
    }
    catch(std::invalid_argument& ia) {
        std::cout << ia.what() << std::endl;
    }
    return estado;
}

/**
* \mainpage Index
* Método responsável por se testar a implementação
* do método "pop" de uma pilha estática.
* Não recebe parâmetros e retorna 1 caso tenha
* funcionado como esperado e 0 caso contrário.
*/
bool TestePilhaSTC::teste_pop() {
    try {
        estado = FALHA;
        PilhaSTC* temp = NULL;
        temp = temp->createStack();
        ItemType dado1, dado2;
        dado1.valor = 555;
        dado2.valor = 666;
        temp->push(temp, dado1);
        temp->push(temp, dado2);
        if (temp->top(temp).valor == dado2.valor) {
            temp->pop(temp);
            if (temp->top(temp).valor == dado1.valor) {
                estado = SUCESSO;
            }
        }
    }
    catch(std::invalid_argument& ia) {
        std::cout << ia.what() << std::endl;
    }
    return estado;
}

/**
* \mainpage Index
* Método responsável por se testar a implementação
* do método "top" de uma pilha estática.
* Não recebe parâmetros e retorna 1 caso tenha
* funcionado como esperado e 0 caso contrário.
*/
bool TestePilhaSTC::teste_top() {
    try {
        estado = FALHA;
        PilhaSTC* temp = NULL;
        temp = temp->createStack();
        ItemType dado1;
        dado1.valor = 123;
        temp->push(temp, dado1);
        if (temp->top(temp).valor == dado1.valor) {
            estado = SUCESSO;
        }
    }
    catch(std::invalid_argument& ia) {
        std::cout << ia.what() << std::endl;
    }
    return estado;
}

/**
* \mainpage Index
* Método responsável por se testar a implementação
* do método "size" de uma pilha estática.
* Não recebe parâmetros e retorna 1 caso tenha
* funcionado como esperado e 0 caso contrário.
*/
bool TestePilhaSTC::teste_size() {
    try {
        estado = FALHA;
        PilhaSTC* temp = NULL;
        temp = temp->createStack();
        ItemType dado1;
        dado1.valor = 745;
        if (temp->size(temp) == 0) {
            temp->push(temp, dado1);
            if (temp->size(temp) == 1) {
                estado = SUCESSO;
            }
        }
    }
    catch (std::invalid_argument& ia) {
        std::cout << ia.what() << std::endl;
    }
    return estado;
}

/**
* \mainpage Index
* Método responsável por se testar a implementação
* do método "setSize" de uma pilha estática.
* Não recebe parâmetros e retorna 1 caso tenha
* funcionado como esperado e 0 caso contrário.
*/
bool TestePilhaSTC::teste_setSize() {
    try {
        estado = FALHA;
        PilhaSTC* temp = NULL;
        temp = temp->createStack();
        ItemType dado;
        dado.valor = 123;
        int TAMANHO_INICIAL, TAMANHO_FINAL;
        TAMANHO_INICIAL = 10;
        TAMANHO_FINAL = 3;
        for (int i = 0; i < TAMANHO_INICIAL; i++) {
            temp->push(temp, dado);
        }
        if (temp->size(temp) == TAMANHO_INICIAL) {
            temp->setSize(temp, TAMANHO_FINAL);
            if (temp->size(temp) == TAMANHO_FINAL) {
                estado = SUCESSO;
            }
        }
    }
    catch (std::invalid_argument& ia) {
        std::cout << ia.what() << std::endl;
    }
    return estado;
}

/**
* \mainpage Index
* Método responsável por se testar a implementação
* do método "destroy" de uma pilha estática.
* Não recebe parâmetros e retorna 1 caso tenha
* funcionado como esperado e 0 caso contrário.
*/
bool TestePilhaSTC::teste_destroy() {
    try {
        estado = FALHA;
        PilhaSTC* temp = NULL;
        temp = temp->createStack();
        ItemType dado;
        dado.valor = 555;
        for (int i = 0; i < 5; i++) {
            temp->push(temp, dado);
        }
        temp->destroyStack(temp);
        estado = SUCESSO;
    }
    catch(std::invalid_argument& ia) {
        std::cout << ia.what() << std::endl;
    }
    return estado;
}

////////////////////// GTEST //////////////////////

/**
* \mainpage Index
* Implementação do framework "catch" de todas os
* métodos da pilha estática.
* Consiste em invocar todos os métodos de teste
* e comparar seus retornos com "1", representando
* o cenário de sucesso.
*/
TEST_CASE("Testes Pilha estatica", "testeSTC") {
    TestePilhaSTC teste;
    REQUIRE(teste.teste_create() == 1);
    REQUIRE(teste.teste_destroy() == 1);
    REQUIRE(teste.teste_pop() == 1);
    REQUIRE(teste.teste_push() == 1);
    REQUIRE(teste.teste_top() == 1);
    REQUIRE(teste.teste_size() == 1);
    REQUIRE(teste.teste_setSize() == 1);
    REQUIRE(teste.teste_IsFull() == 1);
    REQUIRE(teste.teste_IsEmpty() == 1);
}

/**
* \mainpage Index
* Implementação do framework "catch" de todas os
* métodos da pilha dinâmica.
* Consiste em invocar todos os métodos de teste
* e comparar seus retornos com "1", representando
* o cenário de sucesso.
*/
TEST_CASE("Testes Pilha dinamica", "testeD") {
    TestePilhaD teste;
    REQUIRE(teste.teste_create() == 1);
    REQUIRE(teste.teste_destroy() == 1);
    REQUIRE(teste.teste_pop() == 1);
    REQUIRE(teste.teste_push() == 1);
    REQUIRE(teste.teste_top() == 1);
    REQUIRE(teste.teste_size() == 1);
    REQUIRE(teste.teste_setSize() == 1);
    REQUIRE(teste.teste_IsFull() == 1);
    REQUIRE(teste.teste_IsEmpty() == 1);
}
