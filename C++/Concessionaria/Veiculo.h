/*
  Discente: Marcos Eduardo
  Mat.: 121210541
  Curso: Engenharia Eletrica      Turma: 01        LVP  10
  Professor: Marcus Salerno - Tecnicas de Programação
*/
# ifndef VEICULO_H
# define VEICULO_H

// Iniciando a criação da classe Veículo para receber as informações.

class Veiculo{		
  protected:	
	int ano_fabricacao;
	string numero_chassi;
	double preco;
	
  public:
  	Veiculo();
  	void setAnoFabricacao(int);
	void setNumeroChassi(string);
	void setPreco(double);
	
	int getAnoFabricacao();
	string getNumeroChassi();
	double getPreco();	
	
};

# endif