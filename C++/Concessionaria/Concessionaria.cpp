/*
  Discente: Marcos Eduardo
  Mat.: 121210541
  Curso: Engenharia Eletrica      Turma: 01        LVP  10
  Professor: Marcus Salerno - Tecnicas de Programação
*/

# include "Concessionaria.h"

Concessionaria :: Concessionaria(){
	nome = " ";
	usuario = " ";
	senha_acesso = 0;
	
	int ano;
	string modelo_carro,chassi,tipo;
	double preco;
		
	ifstream arquivo_car;
	arquivo_car.open("Carro.txt");
	
	if(arquivo_car.is_open()){
		while(!arquivo_car.eof()){
			// Lendo o arquivo com a lista de carros.
			getline(arquivo_car,tipo);
			if (arquivo_car.eof()){ 
				break;
			}
			getline(arquivo_car,modelo_carro);
			getline(arquivo_car,chassi);
			arquivo_car >> ano;
			arquivo_car >> preco;
			Carro Car_aux(tipo, modelo_carro, chassi, ano, preco);
			Cadastro_Carro.push_back(Car_aux);
			arquivo_car.ignore();
		}
		arquivo_car.close();
	}
	else{
		cout<<"Não foi possível abrir o arquivo"<<endl;
	 }
	 
	int ano_cm, capacidade, rank;
	string modelo_caminhao,chassi_cm,tipo_cm;
	double preco_cm;
	 
	ifstream arquivo_truck;
	arquivo_truck.open("Caminhao.txt"); 
	
	if(arquivo_truck.is_open()){
		while(!arquivo_truck.eof()){
			// Lendo o arquivo com a lista de caminhões.
			getline(arquivo_truck,tipo_cm);
			if (arquivo_truck.eof()){ 
				break;
			}	
			getline(arquivo_truck,modelo_caminhao);
			getline(arquivo_truck,chassi_cm);
			arquivo_truck >> ano_cm;
			arquivo_truck >> preco_cm;
			arquivo_truck >> capacidade;
			arquivo_truck >> rank;
			Caminhao Truck_aux(tipo_cm,modelo_caminhao,chassi_cm,ano_cm,preco_cm,capacidade,rank);
			Cadastro_Caminhao.push_back(Truck_aux);
			arquivo_truck.ignore();
		}
		arquivo_truck.close();
	}
	else{
		cout<<"Não foi possível abrir o arquivo"<<endl;
	 } 				
			
}

Concessionaria :: ~Concessionaria(){
	
	salvar_arquivos();			// chamando a função salvar.	
	cout << "\n\n       Obrigado! Saindo do Programa...\n";
}

void Concessionaria :: setNome(string nome){
	this -> nome = nome;
}

void Concessionaria :: setUsuario(string usuario){
	this -> usuario = usuario;
}

void Concessionaria :: setSenhaAcesso(int senha){
	senha_acesso = senha;
}

string Concessionaria :: getNome(){
	return nome;
}

string Concessionaria :: getUsuario(){
	return usuario;
}

int Concessionaria :: getSenhaAcesso(){
	return senha_acesso;
}

bool Concessionaria :: login(string user, int pass){
	// Verificação de login.
	if (user == usuario and pass == senha_acesso){
		return true;
	}
	else{
		return false;
	}
}

bool Concessionaria :: cadastrar_carro(Carro car, string chassi){
	// Cadastra os Carros.
	for(unsigned i = 0; i < Cadastro_Carro.size(); i++){
		if(Cadastro_Carro.size() != 0 and Cadastro_Carro[i].getNumeroChassi() == chassi){
			return false;
		}
	}
	Cadastro_Carro.push_back(car);
	return true;	
}

bool Concessionaria :: cadastrar_caminhao(Caminhao truck, string chassi, string modelo){
	// Cadastra os Carros.
	for(unsigned i = 0; i < Cadastro_Caminhao.size(); i++){
		if(Cadastro_Caminhao.size() != 0 and Cadastro_Caminhao[i].getNumeroChassi() == chassi){
			return false;
		}
	}
	Cadastro_Caminhao.push_back(truck);
	for(unsigned j = 0; j < Classsificacao.size(); j++){
		if(Classsificacao.size() != 0 and Classsificacao[j].getModeloCaminhao() ==  modelo){
			cout << endl;
		}
	}
	Classsificacao.push_back(truck);
	return true;	
}

bool Concessionaria :: vender_carro(string chassi){
	// Realiza as vendas dos carros.
	for(unsigned i = 0; i < Cadastro_Carro.size(); i++){
		if(Cadastro_Carro.size() != 0 and Cadastro_Carro[i].getNumeroChassi() == chassi){
			Cadastro_Carro.erase(Cadastro_Carro.begin()+i);
			return true;
		}
	}
	return false;
}

bool ordenaRank(Caminhao A, Caminhao B){
  	if (A.getRank() > B.getRank())
	   return true;   
	return false;
}

bool Concessionaria :: vender_caminhao(string chassi){
	string modelo;
	int rank;
	// Realiza as vendas dos Caminhões.
	for(unsigned i = 0; i < Cadastro_Caminhao.size(); i++){
		if(Cadastro_Caminhao.size() != 0 and Cadastro_Caminhao[i].getNumeroChassi() == chassi){
			modelo = Cadastro_Caminhao[i].getModeloCaminhao();
			Cadastro_Caminhao.erase(Cadastro_Caminhao.begin()+i);
			for(unsigned j = 0; j < Cadastro_Caminhao.size(); j++){
				if(Cadastro_Caminhao.size() != 0 and Cadastro_Caminhao[j].getModeloCaminhao() == modelo){
					rank = Cadastro_Caminhao[j].getRank();
					rank = rank + 1;
					Cadastro_Caminhao[j].setRank(rank);
				}	
				for(unsigned l = 0; l < Cadastro_Caminhao.size(); l++){
					if(Classsificacao.size() != 0 and Classsificacao[l].getModeloCaminhao() == modelo){
						Classsificacao[l].setRank(rank);
					}
				}	
			}
			// Classificação na venda.
			sort(Classsificacao.begin(),Classsificacao.end(),ordenaRank);
			for(unsigned k = 0; k < Classsificacao.size(); k++){
				if(Cadastro_Caminhao[i].getRank() == Classsificacao[k].getRank()){
					if(k < 11){
						cout << "\n Classificação: Ótima ";
					}
					else if (k > 10 and k < 21){
						cout << "\n Classificação: Muito Boa ";
					}
					else{
						cout <<"\nNão Classificado";
					}
					return true;
				}
			}	
			return true;		
		}
	}
	return false;
}

bool ordenaCarroAlfabeto(Carro A, Carro B){
  	if (A.getModeloCarro() < B.getModeloCarro())
	   return true;   
	return false;
}

bool ordenaCaminhaoRank(Caminhao A, Caminhao B){
  	if (A.getRank() > B.getRank())
	   return true;   
	return false;
}

bool Concessionaria :: mostrar_carros(){
	// Mostra todos os carros.
	cout << "\n\n   Tipo Carro \tModelo Carro \t Número Chassi \t Ano Fabricação \tPreço \n\n";
	if(Cadastro_Carro.size() == 0){
		return false;
	}
	else{
		sort(Cadastro_Carro.begin(),Cadastro_Carro.end(),ordenaCarroAlfabeto);
		for(unsigned i = 0; i < Cadastro_Carro.size(); i++){
			cout << "   " << setfill(' ') << setw(15) << left << Cadastro_Carro[i].getTipoCarro()
			<< setw(15) << left << Cadastro_Carro[i].getModeloCarro() 
			<< setw(20) << left << Cadastro_Carro[i].getNumeroChassi() 
			<< setw(20) << left << Cadastro_Carro[i].getAnoFabricacao() 
			<< setw(10) << left << Cadastro_Carro[i].getPreco() << endl;
		}
		cout << "\n\n===================================================================\n\n";
		return true;
	}
}

bool Concessionaria :: mostrar_caminhoes(){
	// Mostra todos os carros.
	cout << "\n\n  Tipo Caminhão \t\tModelo Caminhão \tNúmero Chassi \t Ano Fabricação      Preço \tCapacidade.\n\n";
	if(Cadastro_Caminhao.size() == 0){
		return false;
	}
	else{
		sort(Cadastro_Caminhao.begin(),Cadastro_Caminhao.end(),ordenaCaminhaoRank);
		for(unsigned i = 0; i < Cadastro_Caminhao.size(); i++){
			cout << "   " << setfill(' ') << setw(30) << left << Cadastro_Caminhao[i].getTipoCaminhao() 
			<< setw(25) << left << Cadastro_Caminhao[i].getModeloCaminhao() 
			<< setw(20) << left << Cadastro_Caminhao[i].getNumeroChassi() 
			<< setw(15) << left << Cadastro_Caminhao[i].getAnoFabricacao() 
			<< setw(13) << left << Cadastro_Caminhao[i].getPreco() 
			<< setw(5)  << left << Cadastro_Caminhao[i].getCapacidade() << "ton" << endl;
		}
		cout << "\n\n===================================================================\n\n";
		return true;
	}
}

void Concessionaria :: salvar_arquivos(){
	// Função para salvar arquivo.
	
	ofstream arquivo_car;
	arquivo_car.open("Carro.txt",ios::trunc);
	// Salvando a lista de carro.
	if (arquivo_car.is_open()){
		for (unsigned i=0;i<Cadastro_Carro.size();i++){
			arquivo_car<<Cadastro_Carro[i].getTipoCarro()<<endl;
			arquivo_car<<Cadastro_Carro[i].getModeloCarro()<<endl;
			arquivo_car<<Cadastro_Carro[i].getNumeroChassi()<<endl;
			arquivo_car<<Cadastro_Carro[i].getAnoFabricacao()<<endl;
			arquivo_car<<Cadastro_Carro[i].getPreco()<<endl;	
		}
		arquivo_car.close();
	}else{
		cout<<"Não foi possível gravar no arquivo"<<endl;
	}
	
	ofstream arquivo_truck;
	arquivo_truck.open("Caminhao.txt",ios::trunc);
	// Salvando a lista de caminhão.
	if (arquivo_truck.is_open()){
		for (unsigned i=0;i<Cadastro_Caminhao.size();i++){
			arquivo_truck<<Cadastro_Caminhao[i].getTipoCaminhao()<<endl;
			arquivo_truck<<Cadastro_Caminhao[i].getModeloCaminhao()<<endl;
			arquivo_truck<<Cadastro_Caminhao[i].getNumeroChassi()<<endl;
			arquivo_truck<<Cadastro_Caminhao[i].getAnoFabricacao()<<endl;
			arquivo_truck<<Cadastro_Caminhao[i].getPreco()<<endl;
			arquivo_truck<<Cadastro_Caminhao[i].getCapacidade()<<endl;	
			arquivo_truck<<Cadastro_Caminhao[i].getRank()<<endl;
		}
		arquivo_truck.close();
	}else{
		cout<<"Não foi possível gravar no arquivo"<<endl;
	}
}

void Concessionaria :: getPrintLinhas(){
	//  Imprimi uma linha para ajudar no visual.
	cout << "===================================================================";
}	