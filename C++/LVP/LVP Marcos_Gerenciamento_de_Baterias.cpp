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

/*O programa deverá inicializar o valor dos atributos dos dados sensoriados através do construtor e demonstrar a utilização 
do método destrutor através de uma mensagem de sinalização da execução do método. O programa deverá imprimir os valores sensoriados 
e seus respectivos estados, contidos nos métodos de impressão.*/

class Baterias{
    // Atribuindos as variáveis privadas da classe Baterias.
    float tensao_inst_bateria, temperatura_bateria, corrente_bateria, nivel_carga_bateria;
    float valor_corrente_sobrecarga, potencia_sistema, limite_estado_carga, limite_temperatura;
	void calc_potencia(); // Função privada para calculo.

    public:
    // Atribuindos as funções para acessar as variáveis privadas da classe.
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

Baterias :: Baterias(){		// Construtor que vai ser iniciado no começo do sistema
	// Iniciando todas as variaveis com valor zero para evitar lixos.
    tensao_inst_bateria = temperatura_bateria = corrente_bateria = 0;
    nivel_carga_bateria = valor_corrente_sobrecarga = 0;
    limite_estado_carga = limite_temperatura = 0;
}

Baterias :: ~Baterias(){	// Destrutor para limpar a memória e mostrar a mensagem de verificação.
    cout << "\n\n  Testes realizados com Sucesso!!!";
    cout << "\n\n       Obrigado! Saindo do Programa...\n";
}

void Baterias :: setTensaoInstBateria(float tensao){
	// Inserindo valores a variável privada pela função set.
	tensao_inst_bateria = (tensao>0) ? tensao : 0;
}

void Baterias :: setTemperaturaBateria(float temp){
	// Inserindo valores a variável privada pela função set.
	temperatura_bateria = (temp>0) ? temp : 0;
}

void Baterias :: setCorrenteBateria(float corrente){
	// Inserindo valores a variável privada pela função set.
	corrente_bateria = (corrente>0) ? corrente : 0;
}

void Baterias :: setNivelCargaBateria(float nivel){
	// Inserindo valores a variável privada pela função set.
	nivel_carga_bateria = (nivel>0) ? nivel : 0;
}

void Baterias :: setValorCorrenteSobrecarga(float sobrecarga){
	// Inserindo valores a variável privada pela função set.
	valor_corrente_sobrecarga = (sobrecarga>0) ? sobrecarga : 0;
}

void Baterias :: setParametros(float lim_carga, float lim_temp){
	// Inserindo valores a variável privada pela função set.
	limite_estado_carga = lim_carga;
	limite_temperatura = lim_temp;
}

float Baterias :: getTensaoInstBateria(){
	// Puxando valores da variável privada pela função get, para serem exibidas ao usúario.
	return tensao_inst_bateria;
}

float Baterias :: getTemperaturaBateria(){
	// Puxando valores da variável privada pela função get, para serem exibidas ao usúario.
	return temperatura_bateria;
}

float Baterias :: getCorrenteBateria(){
	// Puxando valores da variável privada pela função get, para serem exibidas ao usúario.
	return corrente_bateria;
}

float Baterias :: getNivelCargaBateria(){
	// Puxando valores da variável privada pela função get, para serem exibidas ao usúario.
	return nivel_carga_bateria;
}

float Baterias :: getPotenciaSistema(){
	// Puxando valores da variável privada pela função get, para serem exibidas ao usúario.
	calc_potencia();
	return potencia_sistema;
}

float Baterias :: getLimiteEstadoCarga(){
	// Puxando valores da variável privada pela função get, para serem exibidas ao usúario.
	return limite_estado_carga;
}

float Baterias :: getLimiteTemperatura(){
	// Puxando valores da variável privada pela função get, para serem exibidas ao usúario.
	return limite_temperatura;
}

void Baterias :: calc_potencia(){
	// Função privada para realizar calculo da potencia.
	potencia_sistema = corrente_bateria * tensao_inst_bateria;
}

string Baterias :: situacao_est_carga(){
	// Função para classificar a situação do estado de carga.
	if (nivel_carga_bateria < limite_estado_carga){
		return "Estado de carga anormal. (Estado de Alerta!!!)";
	}
	else{
		return "Estado de carga normal.";
	}
}

string Baterias :: situacao_temperatura(){
	// Função para classificar a situação da temperatura da bateria.
	if (temperatura_bateria > limite_temperatura){
		return "Temperatura anormal (estado de alerta!!!)";
	}
	else{
		return "Temperatura normal.";
	}
}

string Baterias :: situacao_corrente(){
	// Função para classificar a situação da corrente.
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
    // Declarando as variáveis do objeto bms.
    float tensao_instantania, valor_corrente, temperatura, sobrecarga, nivel_carga;
    float limite_estado_carga, limite_temperatura;
    
    cout << "\n			Gerenciamento de Baterias.\n";
    // Recebendo as informações para o gerenciamento das baterias.
  	cout << "\n Informe o valor da tensão instantânea, em Volts (V): ";
	cin >> tensao_instantania;
	cout << "\n Informe o valor da corrente que passa pela bateria, em Ampere (A): "; 
	cin >> valor_corrente;
	cout << "\n Informe o valor da temperatura da bateria, em graus Celsius (ºC): ";
	cin >> temperatura;
	cout << "\n Informe o valor da corrente de sobrecarga (valor máximo) em Ampere (A): ";
	cin >> sobrecarga;
	cout << "\n Informe o nível da carga da bateria, em porcentagem (%): ";
	cin >> nivel_carga;
	limite_estado_carga = 30; // em porcentagem, valor para realizar a comparação e retornar a situação.
	limite_temperatura = 25; // em Celcius, valor para realizar a comparação e retornar a situação.
	
	// Atribuindo valores a cada atributo correspondente.
	bms.setTensaoInstBateria(tensao_instantania);
	bms.setCorrenteBateria(valor_corrente);
	bms.setTemperaturaBateria(temperatura);
	bms.setValorCorrenteSobrecarga(sobrecarga);
	bms.setNivelCargaBateria(nivel_carga);
	bms.setParametros(limite_estado_carga,limite_temperatura);
	
	// Exibindo os valores do sistema de gerenciamento de baterias.
	cout << "\n			- - - Relatório   - - -\n";
	cout << "\n A tensão da bateria é: " << bms.getTensaoInstBateria() << "V";
	cout << "\n A corrente da bateria é: " << bms.getCorrenteBateria() << "A	- - -	" << bms.situacao_corrente();
	cout << "\n A potência da bateria é: " << bms.getPotenciaSistema() << "W";
	cout << "\n A Temperatura da bateria: " << bms.getTemperaturaBateria() << "°C	- - -	" << bms.situacao_temperatura();
	cout << "\n O estado da carga está em: " << bms.getNivelCargaBateria() << "%	- - -	" << bms.situacao_est_carga();
  	
    return 0;
}