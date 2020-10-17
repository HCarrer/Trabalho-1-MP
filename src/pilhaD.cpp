#include "pilha.hpp"



///////////////////////////Métodos da Pilha dinâmica/////////////////////
Pilha* Pilha::createStack() {
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->topo = NULL;
    p->tamanho = 0;
    std::cout << "Criado" << std::endl;
    return p;
}


void Pilha::destroyStack(Pilha* pilha) {
    if(!pilha->isEmpty(pilha)) {
        while(pilha->topo != NULL) {
            pilha->pop(pilha);
        }
        if(pilha->topo == NULL) {
            std::cout << "todos elementos retirados" << std::endl;
        }
        free(pilha);
    } else {
        std::cout << "Falha ao deletar pilha pois está vazia" << std::endl; ///////ERRO
    }
} 


void Pilha::push(Pilha* pilha, ItemType dado) {
    ItemType* n = (ItemType *) malloc(sizeof(ItemType));
    n->valor = dado.valor;
    n->seguinte = pilha->topo;
    pilha->topo = n;
    pilha->tamanho++;
}

ItemType* Pilha::pop(Pilha* pilha) {
    if(pilha->topo != NULL) {
        ItemType *temp = pilha->topo;
        pilha->topo = pilha->topo->seguinte;
        free(temp);
        pilha->tamanho--;
        std::cout << "popado" << std::endl;
        return pilha->topo;
    } else {
        throw std::invalid_argument ("Erro ao popar elementar! A pilha está vazia");
        return NULL;
    }
}

ItemType* Pilha::top(Pilha* pilha) {
    if(pilha->topo == NULL) {

        throw std::invalid_argument ("Erro ao ver o topo da pilha pois está vazia!");
        return NULL;

    } else {
    return pilha->topo;
    }
}

int Pilha::size(Pilha* pilha) {
    if(pilha->tamanho >= 0) {
        return pilha->tamanho;
    } else {
        throw std::invalid_argument ("Tamanho inválido de pilha.");
    }
}

bool Pilha::isEmpty(Pilha* pilha) {
    if(pilha->topo == NULL) {
        return true;
    } else {
        return false;
    }
}

bool Pilha::isFull(Pilha* pilha) {
    if(pilha) {
        return 0;
        //sempre retprna 0 pois, ao se tratar de alocação dinâmica, a pilha nunca estará cheia
    } else {
        return 1;
    }
}

bool Pilha::setSize(Pilha* pilha, int tamanho) {
    if(tamanho >= pilha->tamanho) {
        throw std::invalid_argument ("O tamanho indicado já é maior ou igual ao tamanho atual da piha. Nada foi feito.");
        return 0;
    }
    else {
        int temp = pilha->size(pilha);
        for (int i = 0; i < temp - tamanho; i++) {
            pilha->pop(pilha);
        }
        std::cout << "Foram deletados " << temp - tamanho << " elementos" << std::endl;
        return 1;
    }
}


