#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include "pilha.hpp"
#include "teste_pilha.hpp"



//////////////////////////Testes Pilha Dinâmica///////////////////////
bool TestePilhaD::teste_create() {
    Pilha* temp = temp->createStack();
    estado = SUCESSO;
    return estado;
}

bool TestePilhaD::teste_destroy() {
    try {
        Pilha* temp = temp->createStack();
        temp->destroyStack(temp);
        if(temp->size(temp) == 0) {       //Como o atributo TOPO da pilha é privado, deve-se
            estado = SUCESSO;               //testar com o tamanho final da pilha e não para onde aponta.
        } else {
            std::cout << "A pilha não está sendo destruída corretamente" << std::endl;
            estado = FALHA;
        }
    }
    catch(std::invalid_argument& ia) {
        std::cout << ia.what() << std::endl;
        estado = FALHA;
    }
    return estado;
}

bool TestePilhaD::teste_push() {
    try {
        ItemType valido;
        valido.valor = 10;
        Pilha* temp = temp->createStack();
        temp->push(temp, valido);
        if(temp->top(temp)->valor != valido.valor) {
            std::cout << "Erro ao dar push no elemento válido" << std::endl;
            estado = FALHA;
        } else {
            estado = SUCESSO;
        }
    }
    catch(std::invalid_argument& ia) {
        std::cout << ia.what() << std::endl;
        estado = FALHA;
    }
    return estado;
}

bool TestePilhaD::teste_top() {
    try {
        ItemType valido1, valido2;     //valido2 é o topo
        valido1.valor = 99;    
        valido2.valor = 123;
        Pilha* temp = temp->createStack();
        temp->push(temp, valido1);
        temp->push(temp, valido2);
        if(temp->top(temp)->valor != valido2.valor){
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
    return estado;
}

bool TestePilhaD::teste_pop() {
    try{
        Pilha* temp = temp->createStack();
        ItemType dado1, dado2;
        dado1.valor = 123;
        dado2.valor = 765;
        temp->push(temp, dado1);
        temp->push(temp, dado2);
        if(temp->top(temp)->valor == dado2.valor) {
            temp->pop(temp);
            if(temp->top(temp)->valor == dado1.valor) {
                estado = SUCESSO;
            }
            else {
                estado = FALHA;
            }
        } else {
            estado = FALHA;
        }
    }
    catch(std::invalid_argument& ia) {
        std::cout << ia.what() << std::endl;
        estado = FALHA;
    }
    return estado;
}

bool TestePilhaD::teste_size() {
    try {
        Pilha* temp = temp->createStack();
        int tamanhoComparador = temp->size(temp) + 1;           // Trecho criado pois
        ItemType dado;                                            // o atributo tamanho
        dado.valor = 20;                                          // da classe Pilha é
        temp->push(temp, dado);                                 // inacessível, por isso foi adicionado um novo dado a pilha para assim se comparar.
       if(temp->size(temp) == tamanhoComparador) {
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
    return estado;
}

bool TestePilhaD::teste_setSize() {
    try {
        int TAMANHO_TESTE = 2;                                   //Caso TAMANHO_TESTE seja um valor maior que o atual da pilha, cairá no catch
        Pilha* temp = temp->createStack();
        ItemType dado;
        dado.valor = 123;
        for(int i=0; i<10; i++) {
            temp->push(temp, dado);               //Adicionando 10 itens a pilha
        }
        if(temp->setSize(temp, 30) == 0) {          //Deve retornar 0 pois a pilha implementada não permite mudar seu tamanho para algum maior ou igual ao atual
            temp->setSize(temp, TAMANHO_TESTE);
            if(temp->size(temp) == TAMANHO_TESTE) {
                estado = SUCESSO;
            } else {
                std::cout << "Erro ao mudar o tamanho da pilha" << std::endl;
                estado = FALHA;
            }
        } else {
            estado = FALHA;
        }
    }
    catch(std::invalid_argument& ia) {
        std::cout << ia.what() << std::endl;
        estado = FALHA;
    }
    return estado;
}

bool TestePilhaD::teste_IsFull() {
    try {
        int capacidadeMaxima = pilha->size(pilha);
        Pilha* temp = temp->createStack();
        if(temp->isFull(temp) == 0) {
            estado = SUCESSO;
        } else {
            std::cout << "A pilha está cheia" << std::endl;  //como se trata de uma pilha de alocação
            estado = FALHA;                                  //dinâmica, ela nunca deve estar cheia. Sendo assim,
        }                                                    //retorna como um erro caso a função testada aponte como cheia.
    }
    catch(std::invalid_argument& ia) {
        std::cout << ia.what() << std::endl;
        estado = FALHA;
    }
    return estado;
}

bool TestePilhaD::teste_IsEmpty() {
    try {
        Pilha* temp = temp->createStack();
        if(temp->isEmpty(temp) == 1) {
            estado = SUCESSO;
        } else {
            estado = FALHA;
            std::cout << "Ocorreu um erro e a pilha criada não está vazia" << std::endl;
        }
    }
    catch(std::invalid_argument& ia) {
        std::cout << ia.what() << std::endl;
        estado = FALHA;
    }
    return estado;
}




//////////////////////////Testes Pilha Estática///////////////////////
bool TestePilhaSTC::teste_create() {
    try {
        PilhaSTC* temp = pilha.createStack();
        estado = SUCESSO;
    }
    catch(std::invalid_argument& ia) {
        std::cout << ia.what() << std::endl;
        estado = FALHA;
    }
    return estado;
}

bool TestePilhaSTC::teste_IsEmpty() {
    try {
        PilhaSTC* temp = temp->createStack();
        if(temp->size(temp) == 0) {
            estado = SUCESSO;
        } else {
            estado = FALHA;
        }
    }
    catch(std::invalid_argument& ia) {
        std::cout << ia.what() << std::endl;
        estado = FALHA;
    }
    return estado;
}

bool TestePilhaSTC::teste_IsFull() {
    try {
        PilhaSTC* temp = temp->createStack();
        ItemType dado;      //dado para testar a função
        dado.valor = 123;   //valor genérico
        int i=0;
        for(i; i < CAPACIDADE_INICIAL; i++) {
            temp->push(temp, dado);
        }
        if(temp->size(temp) == CAPACIDADE_INICIAL) {
            estado = SUCESSO;
        } else {
            estado = FALHA;
        }
    }
    catch(std::invalid_argument& ia) {
        std::cout << ia.what() << std::endl;
        estado = FALHA;
    }
    return estado;
}

bool TestePilhaSTC::teste_push() {
    try {
        PilhaSTC* temp = temp->createStack();
        ItemType dado, dado2;
        dado.valor = -456;
        dado2.valor = 789;
        temp->push(temp, dado);
        temp->push(temp, dado2);
        if(temp->top(temp).valor == dado2.valor) {
            estado = SUCESSO;
        } else{
            estado = FALHA;
        }
    }
    catch(std::invalid_argument& ia) {
        std::cout << ia.what() << std::endl;
        estado = FALHA;
    }
    return estado;
}

bool TestePilhaSTC::teste_pop() {
    try {
        PilhaSTC* temp = temp->createStack();
        ItemType dado1, dado2;
        dado1.valor = 555;
        dado2.valor = 666;
        temp->push(temp, dado1);
        temp->push(temp, dado2);
        if(temp->top(temp).valor == dado2.valor) {
            temp->pop(temp);
            if(temp->top(temp).valor == dado1.valor) {
                estado = SUCESSO;
            }
            else {
                estado = FALHA;
            }
        } else {
            estado = FALHA;
        }
    }
    catch(std::invalid_argument& ia) {
        std::cout << ia.what() << std::endl;
        estado = FALHA;
    }
    return estado;
}

bool TestePilhaSTC::teste_top() {
    try {
        PilhaSTC* temp = temp->createStack();
        ItemType dado1, dado2;
        dado1.valor = 123;
        dado2.valor = 654;
        temp->push(temp, dado1);
        if(temp->top(temp).valor == dado1.valor) {
            temp->push(temp, dado2);
            if(temp->top(temp).valor == dado2.valor) {
                estado = SUCESSO;
            }
            else {
                estado = FALHA;
            }
        } else {
            estado = FALHA;
        }
    }
    catch(std::invalid_argument& ia) {
        std::cout << ia.what() << std::endl;
        estado = FALHA;
    }
    return estado;
}

bool TestePilhaSTC::teste_size() {
    try{
        PilhaSTC* temp = temp->createStack();
        ItemType dado1, dado2;
        dado1.valor = 745;
        dado2.valor = 1234123;
        if(temp->size(temp) == 0) {
            temp->push(temp, dado1);
            if(temp->size(temp) == 1) {
                temp->push(temp, dado2);
                if(temp->size(temp) == 2) {
                    estado = SUCESSO;
                }
                else {
                    estado = FALHA;
                }
            }
            else {
                estado = FALHA;
            }
        }
        else {
            estado = FALHA;
        }
    }
    catch(std::invalid_argument& ia) {
        std::cout << ia.what() << std::endl;
        estado = FALHA;
    }
    return estado;
}

bool TestePilhaSTC::teste_setSize() {
    try {
        PilhaSTC* temp = temp->createStack();
        ItemType dado;
        dado.valor = 123;
        int TAMANHO_INICIAL, TAMANHO_FINAL;
        TAMANHO_INICIAL = 10;
        TAMANHO_FINAL = 3;
        for(int i=0; i<TAMANHO_INICIAL; i++) {
            temp->push(temp, dado);
        }
        if(temp->size(temp) == TAMANHO_INICIAL) {
            temp->setSize(temp, TAMANHO_FINAL);
            if(temp->size(temp) == TAMANHO_FINAL) {
                estado = SUCESSO;
            }
            else {
                estado = FALHA;
            }
        } else {
            estado = FALHA;
        }
    }
    catch(std::invalid_argument& ia) {
        std::cout << ia.what() << std::endl;
        estado = FALHA;
    }
    return estado;
}

bool TestePilhaSTC::teste_destroy() {
    try {
        PilhaSTC* temp = temp->createStack();
        ItemType dado;
        dado.valor = 555;
        for(int i=0; i<5; i++) {
            temp->push(temp, dado);
        }
        //std::cout << &temp << std::endl;
        temp->destroyStack(temp);
        estado = SUCESSO;
    }
    catch(std::invalid_argument& ia) {
        std::cout << ia.what() << std::endl;
        estado = FALHA;
    }
    return estado;
}

////////////////////// GTEST //////////////////////

TEST_CASE( "Testes Pilha estatica", "testeSTC" ) {
    TestePilhaSTC teste;
    REQUIRE( teste.teste_create() == 1 );
    REQUIRE( teste.teste_destroy() == 1 );
    REQUIRE( teste.teste_pop() == 1 );
    REQUIRE( teste.teste_push() == 1 );
    REQUIRE( teste.teste_top() == 1 );
    REQUIRE( teste.teste_size() == 1 );
    REQUIRE( teste.teste_setSize() == 1 );
    REQUIRE( teste.teste_IsFull() == 1 );
    REQUIRE( teste.teste_IsEmpty() == 1 );
}

TEST_CASE( "Testes Pilha dinamica", "testeD" ) {
    TestePilhaD teste;
    REQUIRE( teste.teste_create() == 1 );
    REQUIRE( teste.teste_destroy() == 1 );
    REQUIRE( teste.teste_pop() == 1 );
    REQUIRE( teste.teste_push() == 1 );
    REQUIRE( teste.teste_top() == 1 );
    REQUIRE( teste.teste_size() == 1 );
    REQUIRE( teste.teste_setSize() == 1 );
    REQUIRE( teste.teste_IsFull() == 1 );
    REQUIRE( teste.teste_IsEmpty() == 1 );
}