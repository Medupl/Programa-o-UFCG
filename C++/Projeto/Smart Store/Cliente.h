# ifndef CLIENTE_H
# define CLIENTE_H

class Cliente{
	
  private:
  	
  	string nome_cliente;
  	string senha_cliente;
  	string endereco;
  	string cpf_cliente;
  	
  public:
  	
  	Cliente(string = " ", string = " ", string = " ", string = " ");
  	~Cliente();
  	
  	void setNomeCliente(string);
	void setCpfCliente(string);
	void setSenhaCliente(string);
	void setEnderecoCliente(string);
	
	string getNomeCliente();
	string getCpfCliente();
	string getSenhaCliente();
	string getEnderecoCliente();
	
};

# endif