# include "Funcionario.h"

Funcionario :: Funcionario(string cpf_funcionario, string funcionario, string senha_funcionario){
	setFuncionario(funcionario);
	setCpfFuncionario(cpf_funcionario);
	setSenhaFuncionario(senha_funcionario);
	
}

Funcionario :: ~Funcionario(){
}
	// Funções set, para inserir valores.
void Funcionario :: setFuncionario(string funcionario){
	this -> funcionario = funcionario;
}

void Funcionario :: setSenhaFuncionario(string senha_funcionario){
	this -> senha_funcionario = senha_funcionario;
}

void Funcionario :: setCpfFuncionario(string cpf_funcionario){
	this -> cpf_funcionario = cpf_funcionario;
}
	// Funções get, para puxar os valores.
string Funcionario :: getFuncionario(){
	return funcionario;
}

string Funcionario :: getSenhaFuncionario(){
	return senha_funcionario;
}

string Funcionario :: getCpfFuncionario(){
	return cpf_funcionario;
}