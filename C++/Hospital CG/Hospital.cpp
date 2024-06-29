/*
  Discente: Marcos Eduardo
  Curso: Engenharia Eletrica      Turma: 01        LVP  08
  Professor: Marcus Salerno - Tecnicas de Programa��o
*/
# include "Hospital.h"

/*
 Funcionalidades obrigat�rias do sistema:
- Deve ser poss�vel adicionar um paciente na fila de espera, sua posi��o deve ser definida de acordo com a ordem de chegada. 
- Deve ser poss�vel atender um paciente. Sempre que isso � feito o paciente sai da fila e seus dados s�o registrados na lista de pacientes atendidos.
- Deve ser poss�vel remover um paciente da fila  pelo registro, nesse caso seus dados n�o s�o registrados.
- Deve ser poss�vel exibir o nome e registro de todos os pacientes na fila.
- Deve ser poss�vel exibir os dados de um paciente espec�fico de acordo com o seu registro.
- Deve ser poss�vel exibir um relat�rio com os dados de todos os pacientes que j� foram atendidos, ordenados do mais recente para o mais antigo (� necess�rio fazer ordenar o vetor antes de exibir).
*/

Hospital :: Hospital(){			// Construtor zera por ser um vetor.
}

Hospital :: ~Hospital(){		// Iniciando o destrutor.
		cout << "\n\n       Obrigado! Saindo do Programa...\n";
}

bool Hospital :: addPaciente(Paciente cadastro, unsigned registro){
	// Adiciona novos pacientes e ordena de sua posi��o de acordo com a ordem de chegada e verifica se o paciente ja esta cadastrado.
	for(unsigned i = 0; i < filaEspera.size(); i++){
		if(filaEspera.size() != 0 and filaEspera[i].getRegistro() == registro){ 
			return false;
		}
	}
	while(!listaAtendidos.empty()){
		if(listaAtendidos.size() != 0 and listaAtendidos.top().getRegistro() == registro){
			return false;
		}
		else{	
			listaAtendidos.pop();  
		}				
	}		
	filaEspera.push_back(cadastro);
	return true;	
}

bool Hospital :: atenderPaciente(){
	// Atender pacientes da fila e registrar na lista de pacientes atendidos.
	if(filaEspera.size() == 0){ 
		return false;
	}
    else{
		listaAtendidos.push(filaEspera[0]);
		cout << "\n\n   Atendendo o paciente: " << listaAtendidos.top().getNome() << "		Registro: " << listaAtendidos.top().getRegistro();
		filaEspera.erase(filaEspera.begin());
		return true;
	}
}

bool Hospital :: removerPaciente(unsigned registro){
	// Remove os pacientes da fila e n�o registra os dados.
	for(unsigned i = 0; i < filaEspera.size(); i++){
		if(filaEspera.size() != 0 and filaEspera[i].getRegistro() == registro){ 
			filaEspera.erase(filaEspera.begin()+i);
			return true;
		}
	}
	return false;
}

bool Hospital :: exibirFila(){
	// Exibi os dados dos pacientes da fila.
	cout << "\n\n	Cliente " << "\t   Registro " << "\t   Motivo " << "\n";
	if(filaEspera.size() == 0){ 
		return false;
	}
	else{	
		for(unsigned i = 0; i < filaEspera.size(); i++){		
			cout << setfill(' ') << setw(30) << left << filaEspera[i].getNome() << setw(13) << left << filaEspera[i].getRegistro() << setw(20) << left << filaEspera[i].getMotivoEntrada() << endl;
		}
		cout << "\n\n===================================================================\n\n";
		return true;
	}	
}

bool Hospital :: exibirPaciente(unsigned registro){
	// Exibi os dados dos pacientes da fila.
	stack < Paciente > aux = listaAtendidos;
	cout << "\n\n	Paciente " << "\t   Registro " << "\t   Motivo " << "\n";
	for(unsigned i = 0; i < filaEspera.size(); i++){
		if(filaEspera.size() != 0 and filaEspera[i].getRegistro() == registro){ 
			cout << setfill(' ') << setw(30) << left << filaEspera[i].getNome() << setw(13) << left << filaEspera[i].getRegistro() << setw(20) << left << filaEspera[i].getMotivoEntrada() << endl;
			return true;
		}
	}	
	while(!aux.empty()){
		if(aux.size() != 0 and aux.top().getRegistro() == registro){
			cout << setfill(' ') << setw(30) << left << aux.top().getNome() << setw(13) << left << aux.top().getRegistro() << setw(20) << left << aux.top().getMotivoEntrada() << endl;
			return true;
		}
		else{	
			aux.pop();  
		}		
      }   	   	
	cout << "\n\n===================================================================\n\n";

	return false;
}

bool Hospital :: pacientesAtendidos(){
	// Exibi as informa��es de todos os pacientes atendidos.
	cout << "\n\n	Cliente " << "\t   Registro " << "\t   Motivo " << "\n";
	stack < Paciente > aux = listaAtendidos;
	if(aux.size() == 0){ 
		return false;
	  }	
	else{	
		for(unsigned i = 0; i < listaAtendidos.size(); i++){
			cout << setfill(' ') << setw(30) << left << aux.top().getNome() << setw(13) << left << aux.top().getRegistro() << setw(20) << left << aux.top().getMotivoEntrada() << endl;
			aux.pop();
	  }	
	    cout << "\n\n===================================================================\n\n";
		return true;
	}
			
}
