#include "LVP_7_Static.h"

float Conta_de_Poupanca :: taxa_juros_anual = 0;

Conta_de_Poupanca :: Conta_de_Poupanca(float saldo_poupanca){
	setSaldo_poupanca(saldo_poupanca);
}

Conta_de_Poupanca :: ~Conta_de_Poupanca(){
	cout << "Programa finalizado com sucesso.";
}

void Conta_de_Poupanca :: setTaxa_juros_anual(float taxa_juros){
	taxa_juros_anual = taxa_juros;
}

void Conta_de_Poupanca :: setSaldo_poupanca(float saldo_poupanca){
	this -> saldo_poupanca = saldo_poupanca;
}

float Conta_de_Poupanca :: getTaxa_juros_anual(){
	return taxa_juros_anual;
}

float Conta_de_Poupanca :: getSaldo_poupanca() const{
	return saldo_poupanca;
}

float Conta_de_Poupanca :: getRendimento_mensal(){
	calc_rendimento_mensal();
	return rendimento_mensal;
}

void Conta_de_Poupanca :: calc_rendimento_mensal(){
	rendimento_mensal = (getSaldo_poupanca() * taxa_juros_anual)/1200;
	rendimento_mensal += getSaldo_poupanca();
}
