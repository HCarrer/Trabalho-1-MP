#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "pilha.hpp"
#include "teste_pilha.hpp"

using namespace std;

int main() {
	std::cout << "Hello Easy C++ project!" << std::endl;
	
	Pilha *pilha;
	ItemType dado, dado2, dado3, dado4, dado5, dado6, dado7, dado8;

	PilhaSTC *pilha2;

	dado.valor = 10;

	dado2.valor = 30;

	dado3.valor = 28;

	dado4.valor = 41;

	dado5.valor = 52;

	dado6.valor = 73;

	dado7.valor = 99;

	dado8.valor = 1000;

	TestePilhaD teste;

	teste.teste_create();
	std::cout << teste.estado << std::endl;

	teste.teste_setSize();
	std::cout << teste.estado << std::endl;	

	teste.teste_push();
	std::cout << teste.estado << std::endl;

	teste.teste_top();
	std::cout << teste.estado << std::endl;	

	teste.teste_pop();
	std::cout << teste.estado << std::endl;	

	teste.teste_size();
	std::cout << teste.estado << std::endl;	

	teste.teste_setSize();
	std::cout << teste.estado << std::endl;	

	return 0;
}