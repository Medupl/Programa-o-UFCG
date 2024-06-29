#include "Atirador.h"

Atirador :: Atirador(string nome, string arma, int quantidade_vida, float dano,
						float alcance, string municao, string classificacao){
	
	set_nome(nome);
	set_arma(arma);
	set_quantidade_vida(quantidade_vida);
	set_dano(dano);
	set_alcance(alcance);
	set_municao(municao);
	this -> classificacao = classificacao;
}

Atirador :: ~Atirador(){
}

void Atirador :: set_municao(string municao){
	this -> municao = municao;
}

void Atirador :: calc_classificacao(){
	if((get_alcance() >= 10) and (get_alcance() <= 15)){
		classificacao = "Ruim";
	}
	else if((get_alcance() <= 25)){
		classificacao = "Bom";
	}
	else if((get_alcance() <= 40)){
		classificacao = "Muito Bom";
	}
	else if((get_alcance() <= 50)){
		classificacao = "Excelente";
	}
}

string Atirador :: get_municao(){
	return municao;
}

string Atirador :: get_classificacao(){
	calc_classificacao();
	return classificacao;
}
