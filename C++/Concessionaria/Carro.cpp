/*
  Discente: Marcos Eduardo
  Mat.: 121210541
  Curso: Engenharia Eletrica      Turma: 01        LVP  10
  Professor: Marcus Salerno - Tecnicas de Programação
*/
# include "Carro.h"

// Arquivo para realizar as funções da classe Carro.

Carro :: Carro(string tipo_carro, string modelo_carro, string numero_chassi, 
				int ano_fabricacao, double preco){
		setTipoCarro(tipo_carro);
		setModeloCarro(modelo_carro);
		setAnoFabricacao(ano_fabricacao);
		setNumeroChassi(numero_chassi);
		setPreco(preco);					
}

Carro :: ~Carro(){
}
						//		Funções set para inserir valores nas variaveis.
void Carro :: setTipoCarro(string tipo_cr){
	tipo_carro = tipo_cr;
}

void Carro :: setModeloCarro(string modelo_cr){
	modelo_carro = modelo_cr;
}
						// 		Funções get para mostrar os valores das variaveis.
string Carro :: getTipoCarro(){
	return tipo_carro;
}	

string Carro :: getModeloCarro(){
	return modelo_carro;
}								