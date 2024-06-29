# include "Cliente.h"

Cliente :: Cliente(string cpf_cliente, string nome_cliente, string senha_cliente, 
					string endereco){
	setNomeCliente(nome_cliente);
	setCpfCliente(cpf_cliente);
	setSenhaCliente(senha_cliente);
	setEnderecoCliente(endereco);
}

Cliente :: ~Cliente(){
}
	// Funções set, para inserir valores.
void Cliente :: setNomeCliente(string nome_cliente){
	this -> nome_cliente = nome_cliente;
}

void Cliente :: setCpfCliente(string cpf_cliente){
	this -> cpf_cliente = cpf_cliente;
}

void Cliente :: setSenhaCliente(string senha_cliente){
	this -> senha_cliente = senha_cliente;
}

void Cliente :: setEnderecoCliente(string endereco){
	this -> endereco = endereco;
}
	// Funções get, para puxar os valores.
string Cliente :: getNomeCliente(){
	return nome_cliente;
}

string Cliente :: getCpfCliente(){
	return cpf_cliente;
}

string Cliente :: getSenhaCliente(){
	return senha_cliente;
}

string Cliente :: getEnderecoCliente(){
	return endereco;
}