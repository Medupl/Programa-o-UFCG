#include "ProdutoKG.h"

Produto_kg:: Produto_kg(int Codigo, string Descricao, double Preco, string Secao, 
		string Fornecedor, int Validade, string embalagem_kg, float quantidade_kg, 
		float quantidade_vendida_kg){
			setCodigo(Codigo);
			setDescricao(Descricao);
			setPreco(Preco);
			setSecao(Secao);
			setFornecedores(Fornecedor);
			setValidade(Validade);
			setEmbalagemKg(embalagem_kg);
			setQuantidadeKg(quantidade_kg);	
			setQuantidadeVendidaKg(quantidade_vendida_kg);			
}

Produto_kg :: ~Produto_kg(){
}	
////////////////// FUNCOES SET ATRIBUIR VALORES ////////////////////////////////
void Produto_kg :: setEmbalagemKg(string embalagem_kg){
	 this -> embalagem_kg = embalagem_kg;
}

void Produto_kg :: setQuantidadeKg(float quantidade_kg){
	 this -> quantidade_kg = quantidade_kg;
}

void Produto_kg :: setQuantidadeVendidaKg(float quantidade_vendida_kg){
	this -> quantidade_vendida_kg = quantidade_vendida_kg;
}
////////////////// FUNCOES GET ATRIBUIR VALORES ////////////////////////////////
string Produto_kg :: getEmbalagemKg(){
	return embalagem_kg;
}

float Produto_kg:: getQuantidadeKg(){
    return  quantidade_kg;
}

float Produto_kg :: getQuantidadeVendidaKg(){
	return quantidade_vendida_kg;
}