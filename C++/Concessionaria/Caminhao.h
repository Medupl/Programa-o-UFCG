/*
  Discente: Marcos Eduardo
  Mat.: 121210541
  Curso: Engenharia Eletrica      Turma: 01        LVP  10
  Professor: Marcus Salerno - Tecnicas de Programa��o
*/
# ifndef CAMINHAO_H
# define CAMINHAO_H

// Iniciando a cria��o da classe Carro para receber as informa��es.

class Caminhao : public Veiculo{
	
  private:
  	string tipo_caminhao;
  	string modelo_caminhao;
  	int capacidade;
  	int rank;
	
  public:
  	Caminhao(string = " ",string = " ",string = " ",int = 0,double = 0.0,int = 0,int = 0);
  	~Caminhao();
  	void setTipoCaminhao(string);
	void setModeloCaminhao(string);
	void setCapacidade(int);
	void setRank(int);
	
	string getTipoCaminhao();
	string getModeloCaminhao();	
	int getCapacidade();
	int getRank();
		
};

# endif