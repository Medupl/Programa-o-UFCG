#include <iostream>
#include <iomanip>
#include <locale>

//pleaseusing namespace std;
using std :: cout;
using std :: cin;
using std :: endl;
using std :: string;
#include "LVP_7_Static.cpp"

int main(){
	
	setlocale(LC_ALL, "Portuguese");
	Conta_de_Poupanca poupador_1, poupador_2;
	float saldo_poupanca;
	float taxa_juros_anual;
	
	cout << "--------------------------------------------" << endl;
	cout << " 		Gerenciador de Conta Poupanca        " << endl;
	cout << "--------------------------------------------" << endl << endl;
	cout << " Insira o valor a ser depositado do poupador 1 : ";
	cin >> saldo_poupanca;
	poupador_1.setSaldo_poupanca(saldo_poupanca);
	cout << "--------------------------------------------" << endl;
	cout << " Insira o valor a ser depositado do poupador 2 : ";
	cin >> saldo_poupanca;
	poupador_2.setSaldo_poupanca(saldo_poupanca);
	
	cout << "--------------------------------------------" << endl;
	cout << "	Informe a taxa de juros (%): ";
	cin >> taxa_juros_anual;
	Conta_de_Poupanca :: setTaxa_juros_anual(taxa_juros_anual);
	
	cout << endl << "--------------------------------------------" << endl;
	cout << endl << "\tO rendimento do poupador 1 é: " << poupador_1.getRendimento_mensal();
	cout << endl << "\tO rendimento do poupador 2 é: " << poupador_2.getRendimento_mensal() << endl;
	cout << "--------------------------------------------" << endl;
	
	return 0;
}
