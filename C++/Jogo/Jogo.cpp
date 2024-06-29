#include "Jogo.h"

Jogo :: Jogo(){
	
	string nome,arma,municao,classificacao, modo_luta;
	int quantidade_vida;
	float dano,alcance;
	
	ifstream arquivo_lutador;
	arquivo_lutador.open("Lutador.txt");
	
	if(arquivo_lutador.is_open()){
		while(!arquivo_lutador.eof()){
			// Lendo o arquivo com a lista de carros.
			getline(arquivo_lutador,nome);
			if (arquivo_lutador.eof()){ 
				break;
			}
			getline(arquivo_lutador,arma);
			arquivo_lutador >> quantidade_vida;
			arquivo_lutador >> dano;
			arquivo_lutador >> alcance;
			getline(arquivo_lutador,modo_luta);
			Lutador lutador_aux(nome, arma, quantidade_vida, dano, alcance, modo_luta);
			
			arquivo_lutador.ignore();
		}
		arquivo_lutador.close();
	}
	else{
		cout<<"Não foi possível abrir o arquivo"<<endl;
	 }
	 
	 ifstream arquivo_atirador;
	arquivo_atirador.open("Atirador.txt");
	
	if(arquivo_atirador.is_open()){
		while(!arquivo_atirador.eof()){
			// Lendo o arquivo com a lista de carros.
			getline(arquivo_atirador,nome);
			if (arquivo_atirador.eof()){ 
				break;
			}
			getline(arquivo_atirador,arma);
			arquivo_atirador >> quantidade_vida;
			arquivo_atirador >> dano;
			arquivo_atirador >> alcance;
			getline(arquivo_atirador,municao);
			getline(arquivo_atirador,classificacao);
			Atirador Atirador_aux(nome, arma, quantidade_vida, dano, alcance, municao, classificacao);
		
			arquivo_atirador.ignore();
		}
		arquivo_atirador.close();
	}
	else{
		cout<<"Não foi possível abrir o arquivo"<<endl;
	 }
}

Jogo :: ~Jogo(){
	cout << "\n\t\tPrograma Finalizado com sucesso.";
	cout << "\n\t\tSaindo do programa...";
	salvar_arquivos();
}

void Jogo :: getPrintLinhas(){
	//  Imprimi uma linha para ajudar no visual.
	cout << "===================================================================";
}

bool Jogo :: adiciona_lutador(Lutador jogadorB){
	if(JogadorB.empty()){
		JogadorB.push_back(jogadorB);
	}
	else{
		for(int i=0; i < JogadorB.size(); i++){
			if(JogadorB[i].get_nome() == jogadorB.get_nome()){
				return false;
			}
		}
		JogadorB.push_back(jogadorB);
		return true;
	}	
}

bool Jogo :: excluir_lutador(){
	string nome;
	if(JogadorB.empty()){
		cout << "\n\t Lista vazia.\n";
		return false;
	}
	else{	
	    cout << "\n\t Informe o nome do Lutador: ";
	    cin.ignore();
		getline(cin,nome);
		for(int i=0; i < JogadorB.size(); i++){
			if(JogadorB[i].get_nome() == nome){
				JogadorB.erase(JogadorB.begin()+i);
				return true;
			}
		}
		return false;
	}
}


bool Jogo :: exibir_lutador(){
	string nome;
	if(JogadorB.empty()){
		return false;
	}
	else{
		cout << "\n\t Informe o nome do Lutador: ";
	    cin.ignore();
		getline(cin,nome);
		getPrintLinhas();
		cout << "\n\n   Nome Lutador\t\tModo Luta\t Arma \t Qnt. Vida \t Dano \t Alcance \n\n";
		for(int i=0; i < JogadorB.size(); i++){
			if(JogadorB[i].get_nome() == nome){
				cout << "   " << setfill(' ') << setw(20) << left << JogadorB[i].get_nome()
				<< setw(18) << left << JogadorB[i].get_modo_luta()
				<< setw(13) << left << JogadorB[i].get_arma()
				<< setw(13) << left << JogadorB[i].get_quantidade_vida()
				<< setw(10)	<< left << JogadorB[i].get_dano()
				<< setw(10)	<< left << JogadorB[i].get_alcance() << endl;
			}
		}
		cout << "\n\n===================================================================\n\n";
		return true;
	}
}

bool ordenaLutador(Lutador A, Lutador B){
  	if (A.get_nome() < B.get_nome())
	   return true;   
	return false;
}

bool Jogo :: exibir_lutadores(){
	if(JogadorB.empty()){
		return false;
	}
	else{
		cout << "\n\n   Nome Lutador\t\tModo Luta\t Arma \t Qnt. Vida \t Dano \t Alcance \n\n";
		sort(JogadorB.begin(), JogadorB.end(), ordenaLutador);
		for(int i=0; i < JogadorB.size(); i++){
				cout << "   " << setfill(' ') << setw(20) << left << JogadorB[i].get_nome()
				<< setw(18) << left << JogadorB[i].get_modo_luta()
				<< setw(13) << left << JogadorB[i].get_arma()
				<< setw(13) << left << JogadorB[i].get_quantidade_vida()
				<< setw(10)	<< left << JogadorB[i].get_dano()
				<< setw(10)	<< left << JogadorB[i].get_alcance() << endl;
		}
		cout << "\n\n===================================================================\n\n";
		return true;
	}
}

bool Jogo :: adiciona_atirador(Atirador jogadorA){
	if(JogadorA.empty()){
		JogadorA.push_back(jogadorA);
	}
	else{
		for(int i=0; i < JogadorA.size(); i++){
			if(JogadorA[i].get_nome() == jogadorA.get_nome()){
				return false;
			}
		}
		JogadorA.push_back(jogadorA);
		return true;
	}	
}

bool Jogo :: excluir_atirador(){
	string nome;
	if(JogadorA.empty()){
		cout << "\n\t Lista vazia.\n";
		return false;
	}
	else{	
	    cout << "\n\t Informe o nome do Atirador: ";
	    cin.ignore();
		getline(cin,nome);
		for(int i=0; i < JogadorA.size(); i++){
			if(JogadorA[i].get_nome() == nome){
				JogadorA.erase(JogadorA.begin()+i);
				return true;
			}
		}
		return false;
	}
}


bool Jogo :: exibir_atirador(){
	string nome;
	if(JogadorA.empty()){
		return false;
	}
	else{
		cout << "\n\t Informe o nome do Atirador: ";
	    cin.ignore();
		getline(cin,nome);
		getPrintLinhas();
		cout << "\n\n   Nome Atirador\tArma\t\tMunição \t Qnt. Vida \t Dano \t Alcance \tClassificação\n\n";
		for(int i=0; i < JogadorA.size(); i++){
			if(JogadorA[i].get_nome() == nome){
				cout << "   " << setfill(' ') << setw(20) << left << JogadorA[i].get_nome()
				<< setw(18) << left << JogadorA[i].get_arma()
				<< setw(18) << left << JogadorA[i].get_municao()
				<< setw(15) << left << JogadorA[i].get_quantidade_vida()
				<< setw(10)	<< left << JogadorA[i].get_dano()
				<< setw(15)	<< left << JogadorA[i].get_alcance() 
				<< setw(20)	<< left << JogadorA[i].get_classificacao() << endl;
			}
		}
		cout << "\n\n===================================================================\n\n";
		return true;
	}
}

bool ordenaAtirador(Atirador A, Atirador B){
  	if (A.get_nome() < B.get_nome())
	   return true;   
	return false;
}

bool Jogo :: exibir_atiradores(){
	if(JogadorA.empty()){
		return false;
	}
	else{
		cout << "\n\n   Nome Lutador\t\tModo Luta\t Arma \t Qnt. Vida \t Dano \t Alcance \n\n";
		sort(JogadorA.begin(), JogadorA.end(), ordenaAtirador);
		for(int i=0; i < JogadorA.size(); i++){
				cout << "   " << setfill(' ') << setw(20) << left << JogadorA[i].get_nome()
				<< setw(18) << left << JogadorA[i].get_arma()
				<< setw(13) << left << JogadorA[i].get_municao()
				<< setw(13) << left << JogadorA[i].get_quantidade_vida()
				<< setw(10)	<< left << JogadorA[i].get_dano()
				<< setw(10)	<< left << JogadorA[i].get_alcance() 
				<< setw(20)	<< left << JogadorA[i].get_classificacao() << endl;
		}
		cout << "\n\n===================================================================\n\n";
		return true;
	}
}

bool Jogo :: combate_lutadores(){
	string player1,player2;
	
	if(JogadorB.size() < 2){
		return false;
	}
	else{
		cout << "\n\t Informe o nome do Primeiro lutador: ";
		cin.ignore();
		getline(cin,player1);
		cout << "\n\t Informe o nome do Primeiro lutador: ";
		getline(cin,player2);
		if(player1 == player2){
			return false;
		}
		else{
			for(int i=0; i < JogadorB.size(); i++){
				if(JogadorB[i].get_nome() == player1){
					for(int j=0; j < JogadorB.size(); j++){
						if(JogadorB[j].get_nome() == player2){	
							if((JogadorB[i].get_dano() > JogadorB[j].get_dano()) and 
							(JogadorB[i].get_alcance() > JogadorB[j].get_alcance())){
								cout << "\n\t O Vencedor do Combate foi o Lutador: " << JogadorB[i].get_nome();
								JogadorB[j].set_quantidade_vida(JogadorB[j].get_quantidade_vida()-1);
								return true;
							}
							else if((JogadorB[j].get_dano() > JogadorB[i].get_dano()) and 
							(JogadorB[j].get_alcance() > JogadorB[i].get_alcance())){
								cout << "\n\t O Vencedor do Combate foi o Lutador: " << JogadorB[j].get_nome();
								JogadorB[i].set_quantidade_vida(JogadorB[i].get_quantidade_vida()-1);
							}
							else{
								cout << "\n\t Não foi encontrado as condições para vitória.";
								cout << "\n\t O combate foi declarado como Empate.";
								return true;
							}
				    	}
					}
				}
			}
		}
		return true;
	}
}

bool Jogo :: combate_atiradores(){
	string player1,player2;
	if(JogadorA.size() < 2){
		return false;
	}
	else{
		cout << "\n\t Informe o nome do Primeiro lutador: ";
		cin.ignore();
		getline(cin,player1);
		cout << "\n\t Informe o nome do Primeiro lutador: ";
		getline(cin,player2);
		if(player1 == player2){
			return false;
		}
		else{
			for(int i=0; i < JogadorA.size(); i++){
				if(JogadorA[i].get_nome() == player1){
					for(int j=0; j < JogadorA.size(); j++){
						if(JogadorA[j].get_nome() == player2){	
							if((JogadorA[i].get_dano() > JogadorA[j].get_dano()) and 
							(JogadorA[i].get_alcance() > JogadorA[j].get_alcance())){
								cout << "\n\t O Vencedor do Combate foi o Lutador: " << JogadorA[i].get_nome();
								JogadorA[j].set_quantidade_vida(JogadorA[j].get_quantidade_vida()-1);
								return true;
							}
							else if((JogadorA[j].get_dano() > JogadorA[i].get_dano()) and 
							(JogadorA[j].get_alcance() > JogadorA[i].get_alcance())){
								cout << "\n\t O Vencedor do Combate foi o Lutador: " << JogadorA[j].get_nome();
								JogadorA[i].set_quantidade_vida(JogadorA[i].get_quantidade_vida()-1);
							}
							else{
								cout << "\n\t Não foi encontrado as condições para vitória.";
								cout << "\n\t O combate foi declarado como Empate.";
								return true;
							}
				    	}
					}
				}
			}
		}
		return true;
	}
}

void Jogo :: salvar_arquivos(){
	ofstream arquivo_lutador;
	arquivo_lutador.open("Lutador.txt");
	
	if (arquivo_lutador.is_open()){
		for(int i=0; i<JogadorB.size();i++){
			arquivo_lutador<<JogadorB[i].get_nome()<<endl;
			arquivo_lutador<<JogadorB[i].get_arma()<<endl;
			arquivo_lutador<<JogadorB[i].get_quantidade_vida()<<endl;
			arquivo_lutador<<JogadorB[i].get_dano()<<endl;
			arquivo_lutador<<JogadorB[i].get_alcance()<<endl;
			arquivo_lutador<<JogadorB[i].get_modo_luta()<<endl;
		}
		arquivo_lutador.close();
	}else{
		cout<<"Não foi possível gravar no arquivo"<<endl;
	} 
	
	ofstream arquivo_atirador;
	arquivo_atirador.open("Atirador.txt");
	
	if (arquivo_atirador.is_open()){
		for(int i=0; i<JogadorB.size();i++){
			arquivo_atirador<<JogadorA[i].get_nome()<<endl;
			arquivo_atirador<<JogadorA[i].get_arma()<<endl;
			arquivo_atirador<<JogadorA[i].get_quantidade_vida()<<endl;
			arquivo_atirador<<JogadorA[i].get_dano()<<endl;
			arquivo_atirador<<JogadorA[i].get_alcance()<<endl;
			arquivo_atirador<<JogadorA[i].get_municao()<<endl;
			arquivo_atirador<<JogadorA[i].get_classificacao()<<endl;
		}
		arquivo_atirador.close();
	}else{
		cout<<"Não foi possível gravar no arquivo"<<endl;
	} 
}
