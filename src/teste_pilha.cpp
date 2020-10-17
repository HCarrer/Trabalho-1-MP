#include "pilha.hpp"
#include "teste_pilha.hpp"

//////////////////////////Testes Pilha Dinâmica///////////////////////
void TestePilhaD::teste_create(){
    pilha = pilha->createStack();
    estado = SUCESSO;
}

void TestePilhaD::teste_push() {
    ItemType valido;
    valido.valor = 10;
    try{
        pilha->push(pilha, valido);
        if(pilha->top(pilha)->valor != valido.valor) {
            std::cout << "Erro ao dar push no elemento válido" << std::endl;
            estado = FALHA;
        } else {
            estado = SUCESSO;
        }
    }
    catch(std::invalid_argument) {
        std::cout << "Erro" << std::endl;
        estado = FALHA;
    }
}

void TestePilhaD::teste_top() {
    ItemType valido1, valido2;     //valido2 é o topo
    valido1.valor = 99;    
    valido2.valor = 123;
    try {
        pilha->push(pilha, valido1);
        pilha->push(pilha, valido2);
        if(pilha->top(pilha)->valor != valido2.valor){
            std::cout << "Erro ao ver o topo da pilha" << std::endl;
            estado = FALHA;
        } else {
            estado = SUCESSO;
        }
    }
    catch(std::invalid_argument& ia) {
        std::cout << ia.what() << std::endl;
        estado = FALHA;
    }
}

void TestePilhaD::teste_pop() {
    try{
        pilha->pop(pilha);
        estado = SUCESSO;
    }
    catch(std::invalid_argument& ia) {
        std::cout << ia.what() << std::endl;
        estado = FALHA;
    }
}

void TestePilhaD::teste_size() {
    try {
        int tamanhoComparador = pilha->size(pilha) + 1;           // Trecho criado pois
        ItemType dado;                                            // o atributo tamanho
        dado.valor = 20;                                          // da classe Pilha é
        pilha->push(pilha, dado);                                 // inacessível, por isso foi adicionado um novo dado a pilha para assim se comparar.
       if(pilha->size(pilha) == tamanhoComparador) {
           estado = SUCESSO;
       } else {
           std::cout << "Erro ao pegar o tamanho da pilha!" << std::endl;
           estado = FALHA;
       }
    }
    catch(std::invalid_argument& ia) {
        std::cout << ia.what() << std::endl;
        estado = FALHA;
    }
}

void TestePilhaD::teste_setSize() {
    int TAMANHO_TESTE = 2;                                //Caso TAMANHO_TESTE seja um valor maior que o atual da pilha, cairá no catch
    try {
        pilha->setSize(pilha, TAMANHO_TESTE);
        if(pilha->size(pilha) == TAMANHO_TESTE) {
            estado = SUCESSO;
        } else {
            std::cout << "Erro ao mudar o tamanho da pilha" << std::endl;
            estado = FALHA;
        }
    }
    catch(std::invalid_argument& ia) {
        std::cout << ia.what() << std::endl;
        estado = FALHA;
    }
}