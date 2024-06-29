/*
  Discente: Marcos Eduardo
  Mat.: 121210541
  Curso: Engenharia Eletrica      Turma: 01        LVP  10
  Professor: Marcus Salerno - Tecnicas de Programação
*/
# include "Caminhao.h"

// Arquivo para realizar as funções da classe Caminhao.

Caminhao :: Caminhao(string tipo_caminhao, string modelo_caminhao, string numero_chassi, 
	int ano_fabricacao, double preco, int capacidade, int rank){
		setTipoCaminhao(tipo_caminhao);
		setModeloCaminhao(modelo_caminhao);
		setAnoFabricacao(ano_fabricacao);
		setNumeroChassi(numero_chassi);
		setPreco(preco);
		setCapacidade(capacidade);
		setRank(rank);		
}

Caminhao :: ~Caminhao(){
}
						//		Funções set para inserir valores nas variaveis.
void Caminhao :: setTipoCaminhao(string tipo_cm){
	tipo_caminhao = tipo_cm;
}

void Caminhao :: setModeloCaminhao(string modelo_cm){
	modelo_caminhao = modelo_cm;
}

void Caminhao :: setCapacidade(int capacidade){
	this -> capacidade = capacidade;
}

void Caminhao :: setRank(int rank){
	this -> rank = rank;
}

						// 		Funções get para mostrar os valores das variaveis.
string Caminhao :: getTipoCaminhao(){
	return tipo_caminhao;
}	

string Caminhao :: getModeloCaminhao(){
	return modelo_caminhao;
}	

int Caminhao :: getCapacidade(){
	return capacidade;
}	

int Caminhao :: getRank(){
	return rank;
}				