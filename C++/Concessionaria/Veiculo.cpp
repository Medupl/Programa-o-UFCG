/*
  Discente: Marcos Eduardo
  Mat.: 121210541
  Curso: Engenharia Eletrica      Turma: 01        LVP  10
  Professor: Marcus Salerno - Tecnicas de Programação
*/
# include "Veiculo.h"

// Arquivo para realizar as funções da classe Veiculo.

Veiculo :: Veiculo(){
	ano_fabricacao = 0;
	numero_chassi = " ";
	preco = 0.0;
}
						//		Funções set para inserir valores nas variaveis.
void Veiculo :: setAnoFabricacao(int ano_fabr){
	ano_fabricacao = ano_fabr;
}

void Veiculo :: setNumeroChassi(string num_chassi){
	numero_chassi = num_chassi;
}

void Veiculo :: setPreco(double preco){
	this -> preco = preco;
}
						// 		Funções get para mostrar os valores das variaveis.
int Veiculo :: getAnoFabricacao(){
	return ano_fabricacao;
}	

string Veiculo :: getNumeroChassi(){
	return numero_chassi;
}

double Veiculo :: getPreco(){
	return preco;
}								