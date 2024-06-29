#include "Lutador.h"

Lutador :: Lutador(string nome, string arma, int quantidade_vida, float dano, 
						float alcance, string modo_luta){
							
	set_nome(nome);
	set_arma(arma);
	set_quantidade_vida(quantidade_vida);
	set_dano(dano);
	set_alcance(alcance);
	set_modo_luta(modo_luta);						
	
}

Lutador :: ~Lutador(){
}

void Lutador :: set_modo_luta(string modo_luta){
	this -> modo_luta =modo_luta;
}

string Lutador :: get_modo_luta(){
	return modo_luta;
}
