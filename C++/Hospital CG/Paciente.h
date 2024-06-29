/*
  Discente: Marcos Eduardo
  Curso: Engenharia Eletrica      Turma: 01        LVP  08
  Professor: Marcus Salerno - Tecnicas de Programa��o
*/
# ifndef PACIENTE_H
# define PACIENTE_H

// Iniciando a cria��o da classe Paciente que vai receber as informa��es dos pacientes.

class Paciente{		// Criando as variaveis privates e as fun��es publicas.
	
	string nome;
	string motivo_entrada;
	unsigned registro;
	
  public:
  	Paciente();
  	void setNome(string);
	void setMotivoEntrada(string);
	void setRegistro(unsigned);
	
	string getNome();
	string getMotivoEntrada();
	unsigned getRegistro();
	void getPrintLinhas();			//  Imprimi uma linha para ajudar no visual.	
	
};

# endif
