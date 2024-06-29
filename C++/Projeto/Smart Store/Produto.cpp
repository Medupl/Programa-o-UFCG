#include "Produto.h"

Produto::Produto(){	
	Descricao = " ";
	Codigo = 0;
	Secao = " ";
	Fornecedor = " ";
	Preco = 0.0;
	Desconto = 0.0;
	Validade = 0;
	nome_cliente_nota = " ";
	cpf_cliente_nota = " ";
	numero_nota = 0;
	valor_nota = 0;
	Preco_total = 0;
}

	// Funções set, para inserir valores.
void Produto::setDescricao(string Descricao){
	this-> Descricao = Descricao;
}

void Produto::setCodigo(int Codigo ){
	this-> Codigo = Codigo;
}

void Produto::setSecao(string Secao){
	this-> Secao = Secao;
}

void Produto::setFornecedores(string Fornecedor){
	this-> Fornecedor = Fornecedor;
}

void Produto::setPreco(double Preco){
	this-> Preco = Preco;
}

void Produto::setValidade(int Validade){
	this-> Validade = Validade;
}

void Produto::setDesconto(double Desconto){
	this-> Desconto = Desconto;
}

void Produto :: setCpfClienteNota(string cpf_cliente_nota){
	this -> cpf_cliente_nota = cpf_cliente_nota;
}

void Produto :: setNomeClienteNota(string nome_cliente_nota){
	this -> nome_cliente_nota = nome_cliente_nota;
}

void Produto::setNumeroNota(int numero_nota){
	this -> numero_nota = numero_nota;
}

void Produto:: setValorNota(double valor){
	this-> valor_nota = valor_nota;
}

void Produto:: setPrecoTotal(double Preco_total){
	this -> Preco_total = Preco_total;
}

	// Funções get, para puxar os valores.
string Produto::getDescricao(){
	return Descricao;
}

int Produto::getCodigo(){
	return Codigo;
}

string Produto::getSecao(){
	return Secao;
}

string Produto::getFornecedores(){
	return Fornecedor;
}

double Produto::getPreco(){
	return Preco;
}

int Produto::getValidade(){
	return Validade;
}

double Produto::getDesconto(){
	return Desconto;
}

string Produto :: getNomeClienteNota(){
	return nome_cliente_nota;
}

string Produto :: getCpfClienteNota(){
	return cpf_cliente_nota;
}

int Produto::getNumeroNota(){
	return numero_nota;
}

double Produto::getValorNota(){
	return valor_nota;
}

double Produto::getPrecoTotal(){
	return Preco_total;
}