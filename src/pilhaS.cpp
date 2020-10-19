// Copyright Henrique de Miranda Carrer 2020

/**
 * @file pilhaS.cpp
 * @author Henrique Carrer
 * @brief Arquvio referentes aos métodos de Pilha estática
 * @version 0.1
 *
 * @copyright Copyright (c) 2020
 *
 */

#include "pilha.hpp"

/////////////////////////// Métodos da Pilha estática /////////////////////

/**
* \mainpage
* Método responsável por se criar a pilha
* estática. Não possui parâmetros e retorna
* uma pilha estática.
*/
PilhaSTC* PilhaSTC::createStack() {
    PilhaSTC *temp = reinterpret_cast<PilhaSTC*>(malloc(sizeof(PilhaSTC)));
    temp->topo = -1;
    temp->tamanho = 0;
    temp->capacidade = CAPACIDADE_INICIAL;
    return temp;
}

/**
* \mainpage
* Método responsável por se deletar a pilha
* estática. Recebe a pilha a ser deletada como
* parâmetro e não retorna nada.
*/
void PilhaSTC::destroyStack(PilhaSTC* pilha) {
    for (int i = 0; i < pilha->tamanho; i++) {
        pilha->pop(pilha);
    }
    free(pilha);
    pilha = NULL;
}

/**
* \mainpage
* Método responsável por se adicionar um item
* a pilha. Recebe como parâmetros a pilha em que
* o item será adicionado e o dado do tipo ItemType
* que será adicionado, respectivamente. Não retorna nada.
* Envia um erro caso a pilha esteja cheia.
*/
void PilhaSTC::push(PilhaSTC *pilha, ItemType dado) {
    if (pilha->topo + 1 >= pilha->capacidade) {
        throw(std::invalid_argument) "Erro, a pilha já está cheia!";
    } else {
        pilha->topo++;
        pilha->vetor[topo].valor = dado.valor;
        pilha->tamanho++;
    }
}

/**
* \mainpage
* Método responsável por se acessar o elemento do
* topo da pilha. Recebe a pilha a ser acessada como
* parâmetro e retorna-o como um ItemType.
* Envia um erro caso a pilha esteja vazia.
*/
ItemType PilhaSTC::top(PilhaSTC* pilha) {
    if (pilha->topo == -1) {
        throw(std::invalid_argument) "A pilha está vazia";
    } else {
        return pilha->vetor[topo];
    }
}

/**
* \mainpage
* Método responsável por se excluir o item do topo
* da pilha. Recebe a pilha em que se deseja retirar
* o elemento do topo como parâmetro. Retorna o elemento
* retirado como ItemType.
* Envia um erro caso a pilha esteja vazia.
*/
ItemType PilhaSTC::pop(PilhaSTC* pilha) {
    if (pilha->topo == -1) {
        throw(std::invalid_argument) "Erro! A pilha está vazia";
    } else {
        pilha->topo--;
        pilha->tamanho--;
        return pilha->vetor[topo];
    }
}

/**
* \mainpage
* Método responsável por se dizer o tamanho atual
* da pilha. Recebe como parâmetro a pilha em que
* se quer saber o tamanho. Retorna um inteiro referente
* a esse tamanho.
*/
int PilhaSTC::size(PilhaSTC* pilha) {
    return pilha->tamanho;
}

/**
* \mainpage
* Método responsável por se alterar o tamanho da pilha.
* Recebe como parâmetro a pilha em que a mudança deve
* ser feita e um inteiro referente ao tamanho que a pilha
* terá depois de concluído, respectivamente. Retorna 1
* caso tenha dado certo.
*/
bool PilhaSTC::setSize(PilhaSTC* pilha, int tamanho) {
    pilha = reinterpret_cast<PilhaSTC*>\
    (realloc(pilha, tamanho*sizeof(ItemType)));
    pilha->capacidade = tamanho;
    if (pilha->tamanho > tamanho) {
        pilha->tamanho = tamanho;
    }
    return 1;
}
