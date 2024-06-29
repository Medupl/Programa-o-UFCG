# include "ProdutoUND.h"

Produto_und:: Produto_und(int Codigo, string Descricao, double Preco, string Secao,
		string Fornecedor, int Validade, string embalagem_und, int quantidade_und,
				int quantidade_vendida_und){
			setDescricao(Descricao);
			setCodigo(Codigo);
			setPreco(Preco);
			setSecao(Secao);
			setFornecedores(Fornecedor);
			setValidade(Validade);
			setEmbalagemUnd(embalagem_und);
			setQuantidadeUnd(quantidade_und);
			setQuantidadeVendidaUnd(quantidade_vendida_und);
}

Produto_und :: ~Produto_und(){
}
////////////////// FUNCOES SET ATRIBUIR VALORES ////////////////////////////////
void Produto_und :: setEmbalagemUnd(string embalagem_und){
	 this -> embalagem_und = embalagem_und;
}

void Produto_und :: setQuantidadeUnd(int quantidade_und){
	 this -> quantidade_und = quantidade_und;
}
void Produto_und :: setQuantidadeVendidaUnd(int quantidade_vendida_und){
	this -> quantidade_vendida_und = quantidade_vendida_und;
}
////////////////// FUNCOES GET ATRIBUIR VALORES ////////////////////////////////
string Produto_und :: getEmbalagemUnd(){
	return embalagem_und;
}

int Produto_und:: getQuantidadeUnd(){
    return  quantidade_und;
}

int Produto_und :: getQuantidadeVendidaUnd(){
	return quantidade_vendida_und;
}
