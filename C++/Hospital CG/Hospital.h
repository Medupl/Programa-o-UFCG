/*
  Discente: Marcos Eduardo
  Curso: Engenharia Eletrica      Turma: 01        LVP  08
  Professor: Marcus Salerno - Tecnicas de Programa��o
*/
# ifndef HOSPITAL_H
# define HOSPITAL_H

// Iniciando a cria��o da classe Hospital que vai manipular as informa��es dos pacientes.

class Hospital{		// Criando as variaveis privates e as fun��es publicas.
	
	vector < Paciente > filaEspera;				// Criando o vetor.
	stack < Paciente > listaAtendidos;			// Criando uma lista de espera.e
	
  public:
  	Hospital();
  	~Hospital();
  	bool addPaciente(Paciente,unsigned);// Adiciona novos pacientes e compara se ja foram cadastrado.
	bool atenderPaciente();				// Atender pacientes da fila e registrar na lista de pacientes atendidos.
	bool removerPaciente(unsigned);		// Remove os pacientes da fila e n�o registra os dados.
	bool exibirFila();					// Exibi os dados dos pacientes da fila.
	bool exibirPaciente(unsigned);		// Exibi a informa��o de um paciente pesquisando pelo registro.
	bool pacientesAtendidos();			// Exibi as informa��es de todos os pacientes atendidos.
		
};

# endif
