#include "pilha.hpp"

///////////////////////////Métodos da Pilha estática/////////////////////
PilhaSTC* PilhaSTC::createStack() {
    PilhaSTC *temp = (PilhaSTC*) malloc(sizeof(PilhaSTC));
    temp->topo = -1;
    temp->tamanho = 0;
    temp->capacidade = CAPACIDADE_INICIAL;
    std::cout << "Criado" << std::endl;
    return temp;
}

void PilhaSTC::destroyStack(PilhaSTC* pilha) {
    free(pilha);
    pilha = NULL;
    std::cout << "Pilha excluida com sucesso" << std::endl;
}

void PilhaSTC::push(PilhaSTC *pilha, ItemType dado) {
    if(pilha->topo + 1 >= pilha->capacidade) {
        throw(std::invalid_argument) "Erro, a pilha já está cheia!";
    } else {
        pilha->topo++;
        pilha->vetor[topo].valor = dado.valor;
        pilha->tamanho++;
        std::cout << "Item adicionado" << std::endl;
    }
}

ItemType PilhaSTC::top(PilhaSTC* pilha) {
    if(pilha->topo == -1){
        throw(std::invalid_argument) "A pilha está vazia";
    } else {
        return pilha->vetor[topo];
    }
}

ItemType PilhaSTC::pop(PilhaSTC* pilha) {
    if(pilha->topo == -1) {
        throw (std::invalid_argument) "Erro! A pilha está vazia";
    } else {
        pilha->topo--;
        pilha->tamanho--;
        std::cout << "Retirado" << std::endl;
        return pilha->vetor[topo];
    }
}

int PilhaSTC::size(PilhaSTC* pilha) {
    if(pilha->topo == -1) {
        std::cout << "Pilha vazia" << std::endl;
        return 0;
    } else {
        return pilha->tamanho;
    }
}

bool PilhaSTC::setSize(PilhaSTC* pilha, int tamanho) {
    if(tamanho > 0) {
        if(tamanho < pilha->capacidade) {
            if(tamanho < pilha->tamanho) {
                PilhaSTC* p = (PilhaSTC*) realloc(pilha, tamanho * sizeof(ItemType));
                pilha->capacidade = tamanho;
                pilha->tamanho = tamanho;
                pilha->topo = tamanho - 1;
                std::cout << "O tamanho da pilha foi diminuído para " << tamanho << std::endl;
                return 1;
            } else {
                PilhaSTC* p = (PilhaSTC*) realloc(pilha, tamanho * sizeof(ItemType));
                pilha->capacidade = tamanho;
                std::cout << "O tamanho foi alterado para " << tamanho << std::endl;
                return 1;
            }
        } else if(tamanho > pilha->capacidade) {
            PilhaSTC* p = (PilhaSTC*) realloc(pilha, tamanho * sizeof(ItemType));
            pilha->capacidade = tamanho;
            std::cout << "O tamanho da pilha foi aumentado para " << tamanho << std::endl;
            return 1;
        } else {
            std::cout << "O tamanho desejado é igual ao tamanho atual. Nada foi feito" << std::endl;
            return 0;
        }
    } else if (tamanho == 0){
        std::cout << "Tem certeza que quer deletar a pilha? Y/n" << std::endl;
        char opcao;
        std::cin >> opcao;
        if(opcao == 'Y') {
            PilhaSTC* p = (PilhaSTC*) realloc(pilha, tamanho * sizeof(ItemType));
            pilha->capacidade = tamanho;
            pilha->tamanho = tamanho;
            pilha->topo = tamanho - 1;
            return 1;
        } else {
            return 0;
        }
    }
}

ItemType PilhaSTC::show(PilhaSTC* pilha, int elemento) {
    if(elemento > pilha->capacidade) {
        throw (std::invalid_argument) "Esse elemento não existe";
    } else {
        std::cout << pilha->vetor[elemento-1].valor << std::endl;
        return pilha->vetor[elemento-1];
    }
}