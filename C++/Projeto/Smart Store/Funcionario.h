# ifndef FUNCIONARIO_H
# define FUNCIONARIO_H

class Funcionario{
	
  	string funcionario;
  	string senha_funcionario;
  	string cpf_funcionario;
  	
  public:
  	
  	Funcionario(string = " ", string = " ", string = " ");
  	~Funcionario();
  	
	void setFuncionario(string);
	void setCpfFuncionario(string);
	void setSenhaFuncionario(string);
	
	string getFuncionario();
	string getCpfFuncionario();
	string getSenhaFuncionario();
	
};

# endif