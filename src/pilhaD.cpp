// Copyright Henrique de Miranda Carrer 2020

/**
 * @file pilhaD.cpp
 * @author Henrique Carrer
 * @brief Arquvio referentes aos métodos de Pilha dinâmica
 * @version 0.1
 *
 * @copyright Copyright (c) 2020
 *
 */

#include "pilha.hpp"


/////////////////////////// Métodos da Pilha dinâmica /////////////////////

/**
* \mainpage
* Método responsável por se criar uma nova pilha
* dinâmica. Não possui parâmetros e retorna uma
* pilha recém criada.
*/
Pilha* Pilha::createStack() {
    Pilha* p = reinterpret_cast<Pilha*>(malloc(sizeof(Pilha)));
    p->topo = NULL;
    p->tamanho = 0;
    std::cout << "Criado" << std::endl;
    return p;
}

/**
* \mainpage
* Método responsável por se destruir a pilha dinâmica.
* Recebe a pilha a ser deletada como parâmetro e não
* retorna nada.
*/
void Pilha::destroyStack(Pilha* pilha) {
    if (!pilha->isEmpty(pilha)) {
        while (pilha->topo != NULL) {
            pilha->pop(pilha);
        }
        if (pilha->topo == NULL) {
            std::cout << "todos elementos retirados" << std::endl;
        }
        free(pilha);
        pilha = NULL;
    } else {
        std::cout << "Falha ao deletar pilha pois está vazia" << std::endl;
    }
}

/**
* \mainpage
* Método responsável por se adicionar um elemento ao
* topo da pilha. Recebe como parâmetros a pilha em que
* o elemento será adicionado e o elemento a ser adicionado,
* respectivamente.
* Não retorna nada.
*/
void Pilha::push(Pilha* pilha, ItemType dado) {
    ItemType* n = reinterpret_cast<ItemType*>(malloc(sizeof(ItemType)));
    n->valor = dado.valor;
    n->seguinte = pilha->topo;
    pilha->topo = n;
    pilha->tamanho++;
}

/**
* \mainpage
* Método responsável por se retirar o elemento do topo
* da pilha. Recebe a pilha em que a mudança ocorrerá como
* parâmetro e retorna o elemento retirado como um ItemType.
* Lança um erro caso se tente retirar um elemento de uma
* pilha vazia.
*/
ItemType* Pilha::pop(Pilha* pilha) {
    if (pilha->topo != NULL) {
        ItemType *temp = pilha->topo;
        pilha->topo = pilha->topo->seguinte;
        free(temp);
        pilha->tamanho--;
        std::cout << "popado" << std::endl;
        return pilha->topo;
    } else {
        throw std::invalid_argument("Erro ao popar elemento! Pilha vazia");
        return NULL;
    }
}

/**
* \mainpage
* Método responsável por se acessar o elemento do topo da
* pilha. Recebe a pilha em que se deseja acessar como
* parâmetro e retorna o elemento do topo como ItemType.
* Lança um erro caso a pilha esteja vazia.
*/
ItemType* Pilha::top(Pilha* pilha) {
    if (pilha->topo == NULL) {
        throw std::invalid_argument("Erro ao ver o topo! Pilha vazia!");
        return NULL;

    } else {
    return pilha->topo;
    }
}

/**
* \mainpage
* Método responsável por se acessar o tamanho atual da
* pilha. Recebe a pilha em que se deseja saber o tamanho
* como parâmetro e retorna um inteiro referente a este
* tamanho.
* Lança um erro caso o tamanho seja um número negativo.
*/
int Pilha::size(Pilha* pilha) {
    if (pilha->tamanho >= 0) {
        return pilha->tamanho;
    } else {
        throw std::invalid_argument("Tamanho inválido de pilha.");
    }
}

/**
* \mainpage
* Método responsável por se saber se a pilha está vazia.
* Recebe a pilha a qual se quer saber tal informação como
* parâmetro e retorna 1 caso esteja vazia e 0 caso contrário.
*/
bool Pilha::isEmpty(Pilha* pilha) {
    if (pilha->topo == NULL) {
        return true;
    } else {
        return false;
    }
}

/**
* \mainpage
* Método responsável por se saber se a pilha está cheia.
* Recebe como parâmetro a pilha a qual se quer saber tal
* informação. Retorna 1 caso esteja cheia e 0 caso contrário.
*/
bool Pilha::isFull(Pilha* pilha) {
    return 0;
    // sempre retorna 0 pois, ao se tratar de alocação dinâmica,
    // a pilha nunca estará cheia
}

/**
* \mainpage
* Método responsável por se alterar o tamanho de uma pilha para
* o tamanho desejado. Recebe como parâmetros a pilha em que a
* mudança deverá ocorrer e o tamanho em que a pilha terá após
* concluído, respectivamente.
* Retorna 1 caso a mudança tenha dado certo e 0 caso o contrário.
*/
bool Pilha::setSize(Pilha* pilha, int tamanho) {
    if (tamanho >= pilha->tamanho) {
        std::cout << "Tamanho maior ou igual ao atual. Erro!" << std::endl;
        return 0;
    } else {
        int temp = pilha->size(pilha);
        for (int i = 0; i < temp - tamanho; i++) {
            pilha->pop(pilha);
        }
        std::cout << temp - tamanho << " elementos" << std::endl;
        return 1;
    }
}
