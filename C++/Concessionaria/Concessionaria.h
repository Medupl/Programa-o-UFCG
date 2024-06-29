/*
  Discente: Marcos Eduardo
  Mat.: 121210541
  Curso: Engenharia Eletrica      Turma: 01        LVP  10
  Professor: Marcus Salerno - Tecnicas de Programa��o
*/

# ifndef CONCESSIONARIA_H
# define CONCESSIONARIA_H

// Iniciando a cria��o da classe Concessionaria para realizar as fun��es.

class Concessionaria{
	vector < Carro > Cadastro_Carro;
	vector < Caminhao > Cadastro_Caminhao;
	vector < Caminhao > Classsificacao;			// para classificar.
	string nome, usuario;
	int senha_acesso;
	
  public:
  	Concessionaria();
  	~Concessionaria();
  	void setNome(string);
  	void setUsuario(string);
  	void setSenhaAcesso(int);
  	
  	string getNome();
  	string getUsuario();
  	int getSenhaAcesso();
  	
  	bool login(string,int);								// Verifica��o de login.
	bool cadastrar_carro(Carro,string);					// Cadastra os Carros.
	bool cadastrar_caminhao(Caminhao,string,string);	// Cadastra os Caminh�es.
	bool vender_carro(string);							// Realiza as vendas dos carros.
	bool vender_caminhao(string);						// Realiza as vendas dos caminhoes.
	bool mostrar_carros();								// Mostra todos os carros.
	bool mostrar_caminhoes();							// Mostra todos os caminhoes.
	void salvar_arquivos();								// Salvar.
	void getPrintLinhas();								// Imprimi uma linha para ajudar no visual.
	
};

# endif