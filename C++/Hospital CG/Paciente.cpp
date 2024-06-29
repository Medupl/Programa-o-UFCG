/*
  Discente: Marcos Eduardos
  Curso: Engenharia Eletrica      Turma: 01        LVP  08
  Professor: Marcus Salerno - Tecnicas de Programa��o
*/
# include "Paciente.h"

// Arquivo para realizar as fun��es da classe Paciente.

Paciente :: Paciente(){
	// Construtor.
	nome = " ";
	motivo_entrada = " ";
	registro = 0;
}
						//		Fun��es set para inserir valores nas variaveis.
void Paciente :: setNome(string nome){
	this -> nome = nome;
}

void Paciente :: setMotivoEntrada(string motivo){
	motivo_entrada = motivo;
}

void Paciente :: setRegistro(unsigned registro){
	this -> registro = registro;
}
						// 		Fun��es get para mostrar os valores das variaveis.
string Paciente :: getNome(){
	return nome;
}	

string Paciente :: getMotivoEntrada(){
	return motivo_entrada;
}

unsigned Paciente :: getRegistro(){
	return registro;
}	

void Paciente :: getPrintLinhas(){
	//  Imprimi uma linha para ajudar no visual.
	cout << "===================================================================";
}							
