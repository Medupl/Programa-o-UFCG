/*
  Discente: Marcos Eduardo
  Mat.: 121210541
  Curso: Engenharia Eletrica      Turma: 01        LVP  10
  Professor: Marcus Salerno - Tecnicas de Programação
*/
# ifndef CARRO_H
# define CARRO_H

// Iniciando a criação da classe Carro para receber as informações.

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