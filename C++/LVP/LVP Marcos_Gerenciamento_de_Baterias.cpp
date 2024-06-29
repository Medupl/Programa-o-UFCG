/*
  Discente: Marcos Eduardo
  Mat.: 121210541
  Curso: Engenharia Eletrica      Turma: 01        LVP  05
*/
# include <iostream>
# include <locale>
# include <cmath>
# include <string>
using namespace std;

/*O programa dever� inicializar o valor dos atributos dos dados sensoriados atrav�s do construtor e demonstrar a utiliza��o 
do m�todo destrutor atrav�s de uma mensagem de sinaliza��o da execu��o do m�todo. O programa dever� imprimir os valores sensoriados 
e seus respectivos estados, contidos nos m�todos de impress�o.*/

class Baterias{
    // Atribuindos as vari�veis privadas da classe Baterias.
    float tensao_inst_bateria, temperatura_bateria, corrente_bateria, nivel_carga_bateria;
    float valor_corrente_sobrecarga, potencia_sistema, limite_estado_carga, limite_temperatura;
	void calc_potencia(); // Fun��o privada para calculo.

    public:
    // Atribuindos as fun��es para acessar as vari�veis privadas da classe.
    Baterias(); // Construtor.
  	~Baterias(); // Destrutor.
  	void setTensaoInstBateria(float);
  	void setTemperaturaBateria(float);
  	void setCorrenteBateria(float);
  	void setNivelCargaBateria(float);
  	void setValorCorrenteSobrecarga(float);
  	void setParametros(float,float);
  	float getTensaoInstBateria();
  	float getTemperaturaBateria();
  	float getCorrenteBateria();
  	float getNivelCargaBateria();
  	float getValorCorrenteSobrecarga();
  	float getPotenciaSistema(); 
	float getLimiteEstadoCarga();
	float getLimiteTemperatura();
	string situacao_est_carga();
	string situacao_temperatura();
	string situacao_corrente();
  	
};

Baterias :: Baterias(){		// Construtor que vai ser iniciado no come�o do sistema
	// Iniciando todas as variaveis com valor zero para evitar lixos.
    tensao_inst_bateria = temperatura_bateria = corrente_bateria = 0;
    nivel_carga_bateria = valor_corrente_sobrecarga = 0;
    limite_estado_carga = limite_temperatura = 0;
}

Baterias :: ~Baterias(){	// Destrutor para limpar a mem�ria e mostrar a mensagem de verifica��o.
    cout << "\n\n  Testes realizados com Sucesso!!!";
    cout << "\n\n       Obrigado! Saindo do Programa...\n";
}

void Baterias :: setTensaoInstBateria(float tensao){
	// Inserindo valores a vari�vel privada pela fun��o set.
	tensao_inst_bateria = (tensao>0) ? tensao : 0;
}

void Baterias :: setTemperaturaBateria(float temp){
	// Inserindo valores a vari�vel privada pela fun��o set.
	temperatura_bateria = (temp>0) ? temp : 0;
}

void Baterias :: setCorrenteBateria(float corrente){
	// Inserindo valores a vari�vel privada pela fun��o set.
	corrente_bateria = (corrente>0) ? corrente : 0;
}

void Baterias :: setNivelCargaBateria(float nivel){
	// Inserindo valores a vari�vel privada pela fun��o set.
	nivel_carga_bateria = (nivel>0) ? nivel : 0;
}

void Baterias :: setValorCorrenteSobrecarga(float sobrecarga){
	// Inserindo valores a vari�vel privada pela fun��o set.
	valor_corrente_sobrecarga = (sobrecarga>0) ? sobrecarga : 0;
}

void Baterias :: setParametros(float lim_carga, float lim_temp){
	// Inserindo valores a vari�vel privada pela fun��o set.
	limite_estado_carga = lim_carga;
	limite_temperatura = lim_temp;
}

float Baterias :: getTensaoInstBateria(){
	// Puxando valores da vari�vel privada pela fun��o get, para serem exibidas ao us�ario.
	return tensao_inst_bateria;
}

float Baterias :: getTemperaturaBateria(){
	// Puxando valores da vari�vel privada pela fun��o get, para serem exibidas ao us�ario.
	return temperatura_bateria;
}

float Baterias :: getCorrenteBateria(){
	// Puxando valores da vari�vel privada pela fun��o get, para serem exibidas ao us�ario.
	return corrente_bateria;
}

float Baterias :: getNivelCargaBateria(){
	// Puxando valores da vari�vel privada pela fun��o get, para serem exibidas ao us�ario.
	return nivel_carga_bateria;
}

float Baterias :: getPotenciaSistema(){
	// Puxando valores da vari�vel privada pela fun��o get, para serem exibidas ao us�ario.
	calc_potencia();
	return potencia_sistema;
}

float Baterias :: getLimiteEstadoCarga(){
	// Puxando valores da vari�vel privada pela fun��o get, para serem exibidas ao us�ario.
	return limite_estado_carga;
}

float Baterias :: getLimiteTemperatura(){
	// Puxando valores da vari�vel privada pela fun��o get, para serem exibidas ao us�ario.
	return limite_temperatura;
}

void Baterias :: calc_potencia(){
	// Fun��o privada para realizar calculo da potencia.
	potencia_sistema = corrente_bateria * tensao_inst_bateria;
}

string Baterias :: situacao_est_carga(){
	// Fun��o para classificar a situa��o do estado de carga.
	if (nivel_carga_bateria < limite_estado_carga){
		return "Estado de carga anormal. (Estado de Alerta!!!)";
	}
	else{
		return "Estado de carga normal.";
	}
}

string Baterias :: situacao_temperatura(){
	// Fun��o para classificar a situa��o da temperatura da bateria.
	if (temperatura_bateria > limite_temperatura){
		return "Temperatura anormal (estado de alerta!!!)";
	}
	else{
		return "Temperatura normal.";
	}
}

string Baterias :: situacao_corrente(){
	// Fun��o para classificar a situa��o da corrente.
	if (corrente_bateria < valor_corrente_sobrecarga){
		return "Corrente normal";
	}
	else{
		return "Corrente anormal. (estado de alerta!!!)";
	}
}

int main() {
    setlocale(LC_ALL,"Portuguese");
    Baterias bms;
    // Declarando as vari�veis do objeto bms.
    float tensao_instantania, valor_corrente, temperatura, sobrecarga, nivel_carga;
    float limite_estado_carga, limite_temperatura;
    
    cout << "\n			Gerenciamento de Baterias.\n";
    // Recebendo as informa��es para o gerenciamento das baterias.
  	cout << "\n Informe o valor da tens�o instant�nea, em Volts (V): ";
	cin >> tensao_instantania;
	cout << "\n Informe o valor da corrente que passa pela bateria, em Ampere (A): "; 
	cin >> valor_corrente;
	cout << "\n Informe o valor da temperatura da bateria, em graus Celsius (�C): ";
	cin >> temperatura;
	cout << "\n Informe o valor da corrente de sobrecarga (valor m�ximo) em Ampere (A): ";
	cin >> sobrecarga;
	cout << "\n Informe o n�vel da carga da bateria, em porcentagem (%): ";
	cin >> nivel_carga;
	limite_estado_carga = 30; // em porcentagem, valor para realizar a compara��o e retornar a situa��o.
	limite_temperatura = 25; // em Celcius, valor para realizar a compara��o e retornar a situa��o.
	
	// Atribuindo valores a cada atributo correspondente.
	bms.setTensaoInstBateria(tensao_instantania);
	bms.setCorrenteBateria(valor_corrente);
	bms.setTemperaturaBateria(temperatura);
	bms.setValorCorrenteSobrecarga(sobrecarga);
	bms.setNivelCargaBateria(nivel_carga);
	bms.setParametros(limite_estado_carga,limite_temperatura);
	
	// Exibindo os valores do sistema de gerenciamento de baterias.
	cout << "\n			- - - Relat�rio   - - -\n";
	cout << "\n A tens�o da bateria �: " << bms.getTensaoInstBateria() << "V";
	cout << "\n A corrente da bateria �: " << bms.getCorrenteBateria() << "A	- - -	" << bms.situacao_corrente();
	cout << "\n A pot�ncia da bateria �: " << bms.getPotenciaSistema() << "W";
	cout << "\n A Temperatura da bateria: " << bms.getTemperaturaBateria() << "�C	- - -	" << bms.situacao_temperatura();
	cout << "\n O estado da carga est� em: " << bms.getNivelCargaBateria() << "%	- - -	" << bms.situacao_est_carga();
  	
    return 0;
}