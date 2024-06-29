/*
  Discente: Marcos Eduardo
  Mat.: 121210541
  Curso: Engenharia Eletrica      Turma: 01        LVP  10
  Professor: Marcus Salerno - Tecnicas de Programa��o
*/
# ifndef CARRO_H
# define CARRO_H

// Iniciando a cria��o da classe Carro para receber as informa��es.

class Carro : public Veiculo{
	
  private:
  	string tipo_carro;
  	string modelo_carro;
	
  public:
  	Carro(string = " ",string = " ",string = " ",int = 0,double = 0.0);
  	~Carro();
  	void setTipoCarro(string);
	void setModeloCarro(string);
	
	string getTipoCarro();
	string getModeloCarro();	
		
};

# endif