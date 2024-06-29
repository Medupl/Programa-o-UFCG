#include "Personagens.h"

Personagens :: Personagens(){
	nome = " ";
	arma = " ";
	quantidade_vida = 0;
	dano = 0.0;
	alcance = 0.0;
}

Personagens :: ~Personagens(){
}

void Personagens :: set_nome(string nome){
	this -> nome = nome;
}

void Personagens :: set_arma(string arma){
	this -> arma = arma;
}

void Personagens :: set_quantidade_vida(int quantidade_vida){
	this -> quantidade_vida = quantidade_vida;
}

void Personagens :: set_dano(float dano){
	this -> dano = dano;
}

void Personagens :: set_alcance(float alcance){
	this -> alcance = alcance;
}
		
string Personagens :: get_nome(){
	return nome;
}

string Personagens :: get_arma(){
	return arma;
}

int Personagens :: get_quantidade_vida(){
	return quantidade_vida;
}

float Personagens :: get_dano(){
	return dano;
}

float Personagens :: get_alcance(){
	return alcance;
}
