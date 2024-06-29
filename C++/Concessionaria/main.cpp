/*
  Discente: Marcos Eduardo
  Mat.: 121210541
  Curso: Engenharia Eletrica      Turma: 01        LVP  10
  Professor: Marcus Salerno - Tecnicas de Programação
*/
# include <iostream>
# include <locale>
# include <iomanip>
# include <cstring>
# include <vector>
# include <cstdlib>
# include <algorithm>
# include <fstream>
/*
Para utilizar o sistema da Concessionária, haverá um menu que será acessado pelo funcionário. 
O funcionário poderá entrar no sistema informando uma senha (que deverá ser verificada na hora do acesso). 
As funcionalidades do funcionário são: vender um veículo (nesse caso o veículo deve ser retirado do vetor), 
cadastrar um veículo (verificar se o número do chassi ainda não foi cadastrado e inserir no vetor), 
mostrar todos os veículos disponíveis na Concessionária (listar o vetor). Se for um carro, 
a listagem será por ordem alfabética do modelo do carro, e se for caminhão, a ordem será em função do ranking.

Realizar salvamento e leitura do LVP.
*/
using namespace std;
# include "Veiculo.cpp"
# include "Carro.cpp"
# include "Caminhao.cpp"
# include "Concessionaria.cpp"

int main(){
	
	setlocale(LC_ALL, "Portuguese");
	Concessionaria loja;
	Carro car;
	Caminhao truck;
	int resp,senha,tipo,modelo,ano;
	string nome, usuario;
	string modelo_carro,modelo_caminhao, chassi;
	double preco;
	
	ofstream arquivo_car;
	arquivo_car.open("Carro.txt");
	
	if (!arquivo_car){
			cout<<"Não foi possível abrir o arquivo"<<endl;
			return(-1);
	} 
	
	arquivo_car.close(); 
	
	ofstream arquivo_truck;
	arquivo_truck.open("Caminhao.txt");
	
	if (!arquivo_truck){
			cout<<"Não foi possível abrir o arquivo"<<endl;
			return(-1);
	} 
	
	arquivo_truck.close(); 
	
	while(true){
		system("cls");
		
		loja.getPrintLinhas();
		cout << "\n			Login -  Concessionária.\n";
		loja.getPrintLinhas();
		cout << "\n\n   1 - Novo Cadastro.\n"
             << "   2 - Fazer Login.\n"
			 << "   0 - Sair.\n\n";	
		loja.getPrintLinhas();
        cout << endl
		<< endl << "   Digite a opção que deseja realizar: ";
        cin >> resp;
        
		if(resp == 0){
			break;
		}
        system("cls");
		
		switch(resp){
		case 1:
			// Cadastro de um novo Funcionario.
			loja.getPrintLinhas();							
			cout << "\n			Novo Cadastro.\n";
	    	loja.getPrintLinhas();
	    	cout << "\n\n    Informe seu nome: ";
	    	cin.ignore();
	    	getline(cin,nome);
	    	loja.setNome(nome);
	    	cout << "\n    Informe seu nome de usuário, " << loja.getNome() << ": ";
	    	cin >> usuario;
	    	cout << "\n    Informe sua senha (somente números inteiros): ";
	    	cin >> senha;
	    	cout << "\n\n    Usuário cadastrado com sucesso. \n\n";
	    	loja.setUsuario(usuario);
	    	loja.setSenhaAcesso(senha);
			break;
		
		case 2:
			// Verificação de login.
			loja.getPrintLinhas();							
			cout << "\n			Login.\n";
	    	loja.getPrintLinhas();
	    	cout << "\n\n    Informe seu nome de usuário: ";
	    	cin >> usuario;
	    	cout << "\n    Informe sua senha (somente números inteiros): ";
	    	cin >> senha;
  			if (loja.login(usuario,senha)==1){
	    		cout << "\n\n        Seja bem-vindo!   " << loja.getNome() << "\n\n";
	    		system("pause");
	    		
	    		while(true){
					system("cls");
		
					loja.getPrintLinhas();
					cout << "\n			Concessionária.\n";
					loja.getPrintLinhas();
					cout << "\n\n   1 - Cadastrar Carro.\n"
             	 	 << "   2 - Cadastrar Caminhão.\n"
             	 	 << "   3 - Vender Carro.\n"
             	 	 << "   4 - Vender Caminhão.\n"
             	 	 << "   5 - Listar Carros.\n"
             	 	 << "   6 - Listar Caminhões.\n"
			 	 	 << "   0 - Logout.\n\n";	
					loja.getPrintLinhas();
        			cout << endl
					<< endl << "   Digite a opção que deseja realizar: ";
        			cin >> resp;
        
					if(resp == 0){
			   	   		break;
					}
       	   	   	    system("cls");
		
					switch(resp){
					case 1:
						// Cadastrando novo carro.
	    				loja.getPrintLinhas();
						cout << "\n			Cadastrar Carro.\n";
						loja.getPrintLinhas();
						cout << "\n\n			Tipos de Carros: \n"
						<< "\n   1 - Sedan.   2 - SUV.   3 - Picape.   4 - Crossover.   5 - Hatch.\n"
						<< "   Informe o tipo do Carro: ";
						cin >> tipo;
						if (tipo==1){
							car.setTipoCarro("Sedan");
							cout << "\n\n			Modelos de Carros: \n"
							<< "\n   1 - Polo.   2 - Fiesta.   3 - Prisma.\n"
							<< "   Informe o modelo do Carro: ";
							cin >> modelo;
							modelo_carro = " ";
							modelo_carro = (modelo==1) ? "Polo" : modelo_carro;	
							modelo_carro = (modelo==2) ? "Fiesta" : modelo_carro;
							modelo_carro = (modelo==3) ? "Prisma" : modelo_carro;					
							car.setModeloCarro(modelo_carro);
						}
						else if (tipo==2){
							car.setTipoCarro("SUV");
							cout << "\n\n			Modelos de Carros: \n"
							<< "\n   1 - Tracker.   2 - Compass.   3 - HVR.\n"
							<< "   Informe o modelo do Carro: ";
							cin >> modelo;
							modelo_carro = (modelo==1) ? "Tracker" : modelo_carro;	
							modelo_carro = (modelo==2) ? "Compass" : modelo_carro;
							modelo_carro = (modelo==3) ? "HVR" : modelo_carro;					
							car.setModeloCarro(modelo_carro);
						}
						else if (tipo==3){
							car.setTipoCarro("Picape");
							cout << "\n\n			Modelos de Carros: \n"
							<< "\n   1 - Pampa.   2 - Saveiro.   3 - Toro.	4 - Hilux.\n"
							<< "   Informe o modelo do Carro: ";
							cin >> modelo;
							modelo_carro = (modelo==1) ? "Pampa" : modelo_carro;	
							modelo_carro = (modelo==2) ? "Saveiro" : modelo_carro;
							modelo_carro = (modelo==3) ? "Toro" : modelo_carro;	
							modelo_carro = (modelo==4) ? "Hilux" : modelo_carro;				
							car.setModeloCarro(modelo_carro);
						}
						else if (tipo==4){
							car.setTipoCarro("Crossover");
							cout << "\n\n			Modelos de Carros: \n"
							<< "\n   1 - Duster.   2 - Renegate.   3 - EcoSport.\n"
							<< "   Informe o modelo do Carro: ";
							cin >> modelo;
							modelo_carro = (modelo==1) ? "Duster" : modelo_carro;	
							modelo_carro = (modelo==2) ? "Renegate" : modelo_carro;
							modelo_carro = (modelo==3) ? "EcoSport" : modelo_carro;					
							car.setModeloCarro(modelo_carro);
						}
						else if (tipo==5){
							car.setTipoCarro("Hatch");
							cout << "\n\n			Modelos de Carros: \n"
							<< "\n   1 - Gol.   2 - Uno.   3 - Corsa.\n"
							<< "   Informe o modelo do Carro: ";
							cin >> modelo;
							modelo_carro = (modelo==1) ? "Gol" : modelo_carro;	
							modelo_carro = (modelo==2) ? "Uno" : modelo_carro;
							modelo_carro = (modelo==3) ? "Corsa" : modelo_carro;					
							car.setModeloCarro(modelo_carro);
						}
						else{
							cout << "\n\n			Opção Inválida !\n";
							break;
						}						
							cout << "\n   Informe o chassi do carro: ";
							cin.ignore();
							getline(cin,chassi);
							cout << "\n   Informe o ano de fabricação: ";
							cin >> ano;
							cout << "\n   Informe o preço do carro: ";
							cin >> preco;
							car.setNumeroChassi(chassi);
							car.setAnoFabricacao(ano);
							car.setPreco(preco);
							if (loja.cadastrar_carro(car,chassi) == 1){		// Adicionar e comparar.
								cout << "\n\n   Carro cadastrado com sucesso!\n\n";
							}
							else{
								cout << "\n\n   Carro já existe. Não foi possível cadastrar o carro!\n\n";
							}
							break;	
						
					case 2:
						// Cadastrando novo caminhão.
	    				loja.getPrintLinhas();
						cout << "\n			Cadastrar Caminhão.\n";
						loja.getPrintLinhas();
						cout << "\n\n			Tipos de Caminhões: \n"
						<< "\n   1 - Toco.   2 - Truck.   3 - Carreta Simples.   4 - Carreta Eixo Estendido.\n"
						<< "   Informe o tipo do Caminhão: ";
						cin >> tipo;
						if (tipo==1){
							truck.setTipoCaminhao("Toco");
							cout << "\n\n			Modelos de Caminhões: \n"
							<< "\n   1 - Vw 15190.   2 - Ford F11000.   3 - Scania P340.\n"
							<< "   Informe o modelo do Carro: ";
							cin >> modelo;
							modelo_caminhao = " ";
							modelo_caminhao = (modelo==1) ? "Vw 15190" : modelo_caminhao;	
							modelo_caminhao = (modelo==2) ? "Ford F11000" : modelo_caminhao;
							modelo_caminhao = (modelo==3) ? "Scania P340" : modelo_caminhao;					
							truck.setModeloCaminhao(modelo_caminhao);
							truck.setCapacidade(5);
						}
						else if (tipo==2){
							truck.setTipoCaminhao("Truck");
							cout << "\n\n			Modelos de Caminhões: \n"
							<< "\n   1 - Vw 24250.   2 - Mb 1620.   3 - Ford Cargo 2428.\n"
							<< "   Informe o modelo do Carro: ";
							cin >> modelo;
							modelo_caminhao = " ";
							modelo_caminhao = (modelo==1) ? "Vw 24250" : modelo_caminhao;	
							modelo_caminhao = (modelo==2) ? "Mb 1620" : modelo_caminhao;
							modelo_caminhao = (modelo==3) ? "Ford Cargo 2428" : modelo_caminhao;					
							truck.setModeloCaminhao(modelo_caminhao);
							truck.setCapacidade(11);
						}
						else if (tipo==3){
							truck.setTipoCaminhao("Carreta Simples");
							cout << "\n\n			Modelos de Caminhões: \n"
							<< "\n   1 - Volvo Fh 540.   2 - Ford Cargo 1933.\n"
							<< "   Informe o modelo do Carro: ";
							cin >> modelo;
							modelo_caminhao = " ";
							modelo_caminhao = (modelo==1) ? "Volvo Fh 540" : modelo_caminhao;	
							modelo_caminhao = (modelo==2) ? "Ford Cargo 1933" : modelo_caminhao;				
							truck.setModeloCaminhao(modelo_caminhao);
							truck.setCapacidade(25);
						}
						else if (tipo==4){
							truck.setTipoCaminhao("Carreta Eixo Estendido");
							cout << "\n\n			Modelos de Caminhões: \n"
							<< "\n   1 - Man Tgx 28440.   2 - Volvo Fh 440.\n"
							<< "   Informe o modelo do Carro: ";
							cin >> modelo;
							modelo_caminhao = " ";
							modelo_caminhao = (modelo==1) ? "Man Tgx 28440" : modelo_caminhao;	
							modelo_caminhao = (modelo==2) ? "Volvo Fh 440" : modelo_caminhao;				
							truck.setModeloCaminhao(modelo_caminhao);
							truck.setCapacidade(33);
						}
						else{
							cout << "\n\n			Opção Inválida !\n";
							break;
						}						
							cout << "\n   Informe o chassi do caminhão: ";
							cin.ignore();
							getline(cin,chassi);
							cout << "\n   Informe o ano de fabricação: ";
							cin >> ano;
							cout << "\n   Informe o preço do caminhão: ";
							cin >> preco;
							truck.setRank(0);						// Fiz uma função para alimentar o rank.
							truck.setNumeroChassi(chassi);
							truck.setAnoFabricacao(ano);
							truck.setPreco(preco);
							if (loja.cadastrar_caminhao(truck,chassi,modelo_caminhao) == 1){		// Adicionar e comparar.
								cout << "\n\n   Caminhão cadastrado com sucesso!\n\n";
							}
							else{
								cout << "\n\n   Caminhão já existe. Não foi possível cadastrar o caminhão!\n\n";
							}
							break;
						
					case 3:
						// Vender Carros.
						loja.getPrintLinhas();
						cout << "\n			Vender Carros.\n";
						loja.getPrintLinhas();
						cout << "\n\n   Informe o chassi do carro que vai ser vendido: ";
						cin >> chassi;
						if(loja.vender_carro(chassi) == 1){
							cout << "\n\n   Carro vendido com sucesso.\n\n";
						}
						else{
							cout << "\n\n   Nenhum Carro registrado!\n\n";
						}
						break;
					
					case 4:
						// Vender Caminhões.
						loja.getPrintLinhas();
						cout << "\n			Vender Caminhões.\n";
						loja.getPrintLinhas();
						cout << "\n\n   Informe o chassi do caminhão que vai ser vendido: ";
						cin >> chassi;
						if(loja.vender_caminhao(chassi) == 1){
							cout << "\n\n   Caminhão vendido com sucesso.\n\n";
						}
						else{
							cout << "\n\n   Nenhum Caminhão registrado!\n\n";
						}
						break;	
						
					case 5:
						// Listar todos os carros.
						loja.getPrintLinhas();
						cout << "\n			Listar Carros.\n";
						loja.getPrintLinhas();
						if(loja.mostrar_carros() == 1){
							cout << "\n\n   Lista exibida com sucesso.\n\n";
						}
						else{
							cout << "\n\n   Nenhum Carro registrado!\n\n";
						}
						break;
					
					case 6:
						// Listar todos os caminhões.
						loja.getPrintLinhas();
						cout << "\n			Listar Caminhões.\n";
						loja.getPrintLinhas();
						if(loja.mostrar_caminhoes() == 1){
							cout << "\n\n   Lista exibida com sucesso.\n\n";
						}
						else{
							cout << "\n\n   Nenhum Caminhão registrado!\n\n";
						}
						break;
													
					default:
						loja.getPrintLinhas();							
						cout << "\n			Concessionária.\n";
	    				loja.getPrintLinhas();							
						cout << "\n\n			Opção Inválida !\n";
						cout << " 			Tente novamente. \n\n";	
						break; 	
			   	   	}
			   	   	
			   	   	system("pause");
				}   	
			}		
			else{
				cout << "\n\n   Funcionário não Cadastrado! Tente novamente.\n\n";
			}
			break;
		
		default:
			loja.getPrintLinhas();							
			cout << "\n			Concessionária.\n";
	    	loja.getPrintLinhas();							
			cout << "\n\n			Opção Inválida !\n";
			cout << " 			Tente novamente. \n\n";	
			break; 
		} 		
		
		system("pause");			
	}
	
	return 0;
	
}