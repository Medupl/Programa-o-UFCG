/*
  Discente: Marcos Eduardo
  Curso: Engenharia Eletrica      Turma: 01        LVP  08
  Professor: Marcus Salerno - Tecnicas de Programa��o
*/
# include <iostream>
# include <string>
# include <vector>
# include <cstdlib>
# include <stack>
# include <locale>
# include <iomanip>

using namespace std;
# include "Paciente.cpp"
# include "Hospital.cpp"

/*
 Funcionalidades obrigat�rias do sistema:
- Deve ser poss�vel adicionar um paciente na fila de espera, sua posi��o deve ser definida de acordo com a ordem de chegada. 
- Deve ser poss�vel atender um paciente. Sempre que isso � feito o paciente sai da fila e seus dados s�o registrados na lista de pacientes atendidos.
- Deve ser poss�vel remover um paciente da fila  pelo registro, nesse caso seus dados n�o s�o registrados.
- Deve ser poss�vel exibir o nome e registro de todos os pacientes na fila.
- Deve ser poss�vel exibir os dados de um paciente espec�fico de acordo com o seu registro.
- Deve ser poss�vel exibir um relat�rio com os dados de todos os pacientes que j� foram atendidos, ordenados do mais recente para o mais antigo (� necess�rio fazer ordenar o vetor antes de exibir).
*/

int main(){
	
	setlocale(LC_ALL, "Portuguese");
	Paciente Cadastro;
	Hospital Fila;
	string nome, motivo;
	unsigned registro,resp;
	
	while(true){
		system("cls");
		
		Cadastro.getPrintLinhas();
		cout << "\n			Hospital de CG.\n";
		cout << "		      - Sala de espera -\n";
		Cadastro.getPrintLinhas();
		cout << "\n\n   1 - Adiconar Paciente.\n"
             << "   2 - Atender Pacinete.\n"
             << "   3 - Remover Paciente da fila.\n"
             << "   4 - Exibir fila.\n"
             << "   5 - Exibir dados de um Paciente.\n"
             << "   6 - Exibir lista de pacientes atendidos.\n"
             << "   0 - Sair.\n\n";
        Cadastro.getPrintLinhas();								// Linha para ajudar no visual.
        cout << endl
		<< endl << "   Digite a op��o que deseja realizar: ";
        cin >> resp;
        
		if(resp == 0){
			// Caso digite essa op��o o sistema Finaliza as perguntas.
			break;
		}
        system("cls");					
        switch(resp){							// Fun��o Condicional, para evitar uso em execesso de if e else.
        case 1:	
        	Cadastro.getPrintLinhas();							
	    	cout << "\n			Adiconar Paciente.\n";
	    	Cadastro.getPrintLinhas();							
			// Pedindo informa��es do Paciente. 
			cout << "\n\n   Informe o nome do paciente: ";
			cin.ignore();
			getline(cin, nome);
			Cadastro.setNome(nome);
			cout << "\n   Informe o registro do paciente, " << Cadastro.getNome() << ": ";
			cin >> registro;
			cout << "\n   Informe o movito de entrada do paciente, " << Cadastro.getNome() << ": ";
			cin.ignore();
			getline(cin, motivo);
			
			Cadastro.setRegistro(registro);
			Cadastro.setMotivoEntrada(motivo);
			if (Fila.addPaciente(Cadastro,registro) == 1){		// Passando pois parametros, para um ser comparado.
				cout << "\n\n   Paciente cadastrado na fila com sucesso!\n\n";
			}
			else{
				cout << "\n\n   Paciente j� existe. N�o foi poss�vel cadastrar o paciente!\n\n";
			}
			break;
		
		case 2:
			Cadastro.getPrintLinhas();							
	    	cout << "\n			Atender Paciente.\n";
	    	Cadastro.getPrintLinhas();							
			// Atendendo pacientes.
			if (Fila.atenderPaciente() == 1){
				cout << "\n\n   Paciente atendido com sucesso!\n\n";
			}
			else{
				cout << "\n\n   Fila vazia: Nenhum paciente na fila de espera!\n\n";
			}
			break;
		
		case 3:
			Cadastro.getPrintLinhas();							
	    	cout << "\n			Remover Paciente da fila.\n";
	    	Cadastro.getPrintLinhas();
	    	// Removendo pacientes.
			cout << "\n   Informe o registro o paciente que deseja remover: ";
			cin >> registro;
	    	if (Fila.removerPaciente(registro) == 1){
				cout << "\n\n   Paciente removido da fila com sucesso!\n\n";
			}
			else{
				cout << "\n\n   Paciente n�o encontrado!\n\n";
			}
			break;
		
		case 4:
			Cadastro.getPrintLinhas();							
	    	cout << "\n			Exibir fila.\n";
	    	Cadastro.getPrintLinhas();
	    	// Exibindo fila de espera.
	    	if (Fila.exibirFila() == 1){
				cout << "\n\n   Lista exibida com sucesso.\n\n";
			}
			else{
				cout << "\n\n   Nenhum paciente na fila de espera!\n\n";
			}
			break;
		
		case 5:
			Cadastro.getPrintLinhas();							
	    	cout << "\n			Exibir dados de um Paciente.\n";
	    	Cadastro.getPrintLinhas();  
	    	// Exibir dados de um paciente.
	    	cout << "\n   Informe o registro o paciente que deseja as informa��es: ";
			cin >> registro;
			if (Fila.exibirPaciente(registro) == 1){
				cout << "\n\n   Informa��es do paciente exibida com sucesso.\n\n";
			}
			else{
				cout << "\n\n   Paciente n�o encontrado!\n\n";
			}
			break;  
		
		case 6:
			Cadastro.getPrintLinhas();							
	    	cout << "\n			Exibir lista de pacientes atendidos.\n";
	    	Cadastro.getPrintLinhas();  
	    	// Exibido pacientes atendidos.
			if (Fila.pacientesAtendidos() == 1){
				cout << "\n\n   Informa��es dos pacientes atendidos exibida com sucesso.\n\n";
			}
			else{
				cout << "\n\n    Relat�rio vazio: N�o h� pacientes no relat�rio.\n\n";
			}
			break;  	
        
		default:
    		Cadastro.getPrintLinhas();							
			cout << "\n			Hospital de CG.\n";
			cout << "		      - Sala de espera -\n";
	    	Cadastro.getPrintLinhas();							
			cout << "\n\n			Op��o Inv�lida !\n";
			cout << " 			Tente novamente. \n\n";	
			break; 
		} 		
		
		system("pause");
	}
	
	return 0;
	
}
