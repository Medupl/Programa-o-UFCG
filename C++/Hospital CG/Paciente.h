/*
  Discente: Marcos Eduardo
  Curso: Engenharia Eletrica      Turma: 01        LVP  08
  Professor: Marcus Salerno - Tecnicas de Programação
*/
# ifndef PACIENTE_H
# define PACIENTE_H

// Iniciando a criação da classe Paciente que vai receber as informações dos pacientes.

class Paciente{		// Criando as variaveis privates e as funções publicas.
	
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
