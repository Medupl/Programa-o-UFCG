#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <cstdlib>
#include <iomanip>
#include <algorithm>
#include <fstream>

using namespace std;

#include "Personagens.cpp"
#include "Lutador.cpp"
#include "Atirador.cpp"
#include "Jogo.cpp"

int main(){
	
	Jogo jogadores;
	Atirador JogadorA;
	Lutador JogadorB;
	
	setlocale(LC_ALL, "Portuguese");
	string nome;
	int quantidade_vida;
	float dano;
	float alcance;
	string arma;
	string municao;
	string modo_luta;
	int resp;
	
	ofstream arquivo_lutador;
	arquivo_lutador.open("Lutador.txt");
	
	if (!arquivo_lutador){
			cout<<"Não foi possível abrir o arquivo"<<endl;
			return(-1);
	} 
	
	arquivo_lutador.close(); 
	
	ofstream arquivo_atirador;
	arquivo_atirador.open("Atirador.txt");
	
	if (!arquivo_atirador){
			cout<<"Não foi possível abrir o arquivo"<<endl;
			return(-1);
	} 
	
	arquivo_atirador.close(); 
	
	while(true){
		system("cls");
		jogadores.getPrintLinhas();
		cout << "\n			Gladiadores.\n";
		jogadores.getPrintLinhas();
		cout << "\n\n    1 - Adicionar um Lutador.\n"
         	 << "    2 - Excluir um Lutador.\n"
         	 << "    3 - Exibir um Lutador.\n"
        	 << "    4 - Exibir todos os Lutadores.\n"
         	 << "    5 - Adicionar um Atirador.\n"
         	 << "    6 - Excluir um Atirador.\n"
         	 << "    7 - Exibir um Atirador.\n"
        	 << "    8 - Exibir todos os Atiradores.\n"
        	 << "    9 - Combate Lutadores.\n"
         	 << "   10 - Combate Atiradores.\n"
			 << "    0 - Logout.\n\n";	
		jogadores.getPrintLinhas();
        cout << endl
		<< endl << "   Digite a opção que deseja realizar: ";
        cin >> resp;
        
		if(resp == 0){
			break;
		}
     	system("cls");
		
		switch(resp){
			case 1:
				jogadores.getPrintLinhas();							
				cout << "\n			Adicionar um Lutador.\n";
	    		jogadores.getPrintLinhas();	
				cout << "\n\t Informe o nome do Lutador: ";
				cin.ignore();
				getline(cin,nome);
				cout << "\n\t Informe a quantidade de vida do Lutador: ";
				cin >> quantidade_vida;
				cout << "\n\t Informe o modo de luta do Lutador "
					 << "\n\t (D = Desarmado ou A = Armado): ";
				cin >> modo_luta;
				if(modo_luta == "D" or modo_luta == "d"){
					modo_luta = "Desarmado";
					arma = " ";
				}	 
				else{
					modo_luta = "Armado";
					cout << "\n\t Informe o tipo da arma: ";
					cin >> arma;
				}
				cout << "\n\t Informe o poder de dano do Lutador: ";
				cin >> dano;
				cout << "\n\t Informe o valor de alcance do Lutador: ";
				cin >> alcance;
				if(alcance > 3){
					alcance = 3.0;
				}
				alcance = (alcance > 0) ? alcance : 0;
				
				JogadorB.set_nome(nome);
				JogadorB.set_modo_luta(modo_luta);
				JogadorB.set_arma(arma);
				JogadorB.set_quantidade_vida(quantidade_vida);
				JogadorB.set_dano(dano);
				JogadorB.set_alcance(alcance);
				
				if (jogadores.adiciona_lutador(JogadorB) == 1){
					cout << "\n\t Lutador adiconado com sucesso.\n\n";
				}
				else{
					cout << "\n\t Erro ao adicionar o Lutador.\n\n";
				}
				
				break;
				
			case 2:
				jogadores.getPrintLinhas();							
				cout << "\n			Excluir um Lutador.\n";
	    		jogadores.getPrintLinhas();	
				if(jogadores.excluir_lutador() == 1){
					cout << "\n\t Lutador excluído com sucesso.\n\n";
				}
				else{
					cout << "\n\t Erro ao tentar excluir o Lutador.\n\n";
				}
				
				break;	
				
			case 3:
				jogadores.getPrintLinhas();							
				cout << "\n			Exibir um Lutador.\n";
	    		jogadores.getPrintLinhas();	
	    		if(jogadores.exibir_lutador() == 1){
	    			cout << "\n\t Lutador exibido com sucesso.\n\n";
				}
				else{
					cout << "\n\t Erro ao tentar exibir um Lutador.\n\n";
				}
	    		
				break;
			
			case 4:
				jogadores.getPrintLinhas();							
				cout << "\n			Exibir todos Lutadores.\n";
	    		jogadores.getPrintLinhas();	
	    		if(jogadores.exibir_lutadores() == 1){
	    			cout << "\n\t Lutadores exibidos com sucesso.\n\n";
				}
				else{
					cout << "\n\t Erro ao tentar exibir os Lutadores.\n\n";
				}
	    		
				break;	
				
			case 5:
				jogadores.getPrintLinhas();							
				cout << "\n			Adicionar um Atirador.\n";
	    		jogadores.getPrintLinhas();	
				cout << "\n\t Informe o nome do Atirador: ";
				cin.ignore();
				getline(cin,nome);
				cout << "\n\t Informe a quantidade de vida do Atirador: ";
				cin >> quantidade_vida;
				cout << "\n\t Informe o tipo da arma do Atirador: ";
				cin >> arma;
				cout << "\n\t Informe o tipo de munição do Atirador: ";
				cin >> municao;
				cout << "\n\t Informe o poder de dano do Atirador: ";
				cin >> dano;
				cout << "\n\t Informe o valor de alcance do Atirador: ";
				cin >> alcance;
				if(alcance > 50.0){
					alcance = 50.0;
				}
				alcance = (alcance > 10) ? alcance : 10;
				
				JogadorA.set_nome(nome);
				JogadorA.set_arma(arma);
				JogadorA.set_municao(municao);
				JogadorA.set_quantidade_vida(quantidade_vida);
				JogadorA.set_dano(dano);
				JogadorA.set_alcance(alcance);
				JogadorA.get_classificacao();
				
				if (jogadores.adiciona_atirador(JogadorA) == 1){
					cout << "\n\t Atirador adiconado com sucesso.\n\n";
				}
				else{
					cout << "\n\t Erro ao adicionar o Atirador.\n\n";
				}
				
				break;
				
			case 6:
				jogadores.getPrintLinhas();							
				cout << "\n			Excluir um Atirador.\n";
	    		jogadores.getPrintLinhas();	
				if(jogadores.excluir_atirador() == 1){
					cout << "\n\t Atirador excluído com sucesso.\n\n";
				}
				else{
					cout << "\n\t Erro ao tentar excluir o Atirador.\n\n";
				}
				
				break;	
				
			case 7:
				jogadores.getPrintLinhas();							
				cout << "\n			Exibir um Atirador.\n";
	    		jogadores.getPrintLinhas();	
	    		if(jogadores.exibir_atirador() == 1){
	    			cout << "\n\t Atirador exibido com sucesso.\n\n";
				}
				else{
					cout << "\n\t Erro ao tentar exibir um Atirador.\n\n";
				}
	    		
				break;
			
			case 8:
				jogadores.getPrintLinhas();							
				cout << "\n			Exibir todos Atiradores.\n";
	    		jogadores.getPrintLinhas();	
	    		if(jogadores.exibir_atiradores() == 1){
	    			cout << "\n\t Atiradores exibidos com sucesso.\n\n";
				}
				else{
					cout << "\n\t Erro ao tentar exibir os Atiradores.\n\n";
				}
	    		
				break;	
				
			case 9:
				jogadores.getPrintLinhas();							
				cout << "\n			Combate Lutadores.\n";
	    		jogadores.getPrintLinhas();	
	    		if(jogadores.combate_lutadores() == 1){
	    			cout << "\n\t Combate realizado com sucesso.\n\n";
				}
				else{
					cout << "\n\t Erro ao tentar realizar o Combate.\n\n";
				}
	    		
				break;
			
			case 10:
				jogadores.getPrintLinhas();							
				cout << "\n			Combate Atiradores.\n";
	    		jogadores.getPrintLinhas();	
	    		if(jogadores.combate_atiradores() == 1){
	    			cout << "\n\t Combate realizado com sucesso.\n\n";
				}
				else{
					cout << "\n\t Erro ao tentar realizar o Combate.\n\n";
				}
	    		
				break;			
				
			default:
				jogadores.getPrintLinhas();							
				cout << "\n			Gladiadores.\n";
	    		jogadores.getPrintLinhas();							
				cout << "\n\n			Opção Inválida !\n";
				cout << " 			Tente novamente. \n\n";	
				
				break; 
						
		}
		system("pause");
	}
	return 0;
	
}
