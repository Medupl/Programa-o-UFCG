# include "Aluga_veiculo.h"

Aluguel_veiculo :: Aluguel_veiculo(){
	// Construtor para inicializar as variaveis, evitando mostrar lixo.
	std :: string modelo = " ";
	std :: string marca = " ";
	int ano_carro = 0;
	float diaria = 0.0;
	int dia = 0;
	float valor_aluguel = 0.0;
	int tempo_utilizado = 0;
	hora_entrada.hora = 0;
	hora_entrada.minuto = 0;
	hora_saida.hora = 0;
	hora_saida.minuto = 0;
	data_entrada.dia = 0;
	data_entrada.mes = 0;
	data_entrada.ano = 0;
	data_saida.dia = 0;
	data_saida.mes = 0;
	data_saida.ano = 0;
}

Aluguel_veiculo :: ~Aluguel_veiculo(){
	// Destrutor.
	std :: cout << std :: endl <<"   Programa Finalizado com sucesso." << std :: endl;	
}
	// Funções sets para inserir valores;
void Aluguel_veiculo :: setModelo(std :: string modelo){
	this -> modelo = modelo;
}

void Aluguel_veiculo :: setMarca(std:: string marca){
	this -> marca = marca;
}

void Aluguel_veiculo :: setAno_Carro(int ano_carro){
	this -> ano_carro = ano_carro;
}

void Aluguel_veiculo :: setDiaria(float diaria){
	this -> diaria = diaria;
}

void Aluguel_veiculo :: setHora_Retirada(int hora,int minuto){
	this -> hora_entrada.hora = hora;
	this -> hora_entrada.minuto = minuto;
}
void Aluguel_veiculo :: setData_Retirada(int dia,int mes,int ano){
	data_entrada.dia = dia;
	data_entrada.mes = mes;
	data_entrada.ano = ano;
}
void Aluguel_veiculo :: setHora_Devolucao(int hora,int minuto){
	hora_saida.hora = hora;
	hora_saida.minuto = minuto;
}
void Aluguel_veiculo :: setData_Devolucao(int dia, int mes, int ano){
	data_saida.dia = dia;
	data_saida.mes = mes;
	data_saida.ano = ano;
}
	// Funções gets para puxar os valores das variaveis;
std :: string Aluguel_veiculo :: getModelo(){
	return modelo;
}
std :: string Aluguel_veiculo :: getMarca(){
	return marca;
}
int Aluguel_veiculo :: getAno_Carro(){
	return ano_carro;
}
float Aluguel_veiculo :: getDiaria(){
	return diaria;
}

float Aluguel_veiculo :: getValor_aluguel(){
	calc_valor_aluguel();			//	Chamando função que realiza o cálculo do valor a ser pago.
	return valor_aluguel;
}

int Aluguel_veiculo :: getTempo_utilizado(){
	cal_tempo_utilizado();			//	Chamndo função que realiza o calculo do tempo utilizado em horas.
	return tempo_utilizado;
}
	
Hora Aluguel_veiculo :: getHora_Retirada(){
	return hora_entrada;
}

Data Aluguel_veiculo :: getData_Retirada(){
	return data_entrada;
}

Hora Aluguel_veiculo :: getHora_Devolucao(){
	return hora_saida;
}

Data Aluguel_veiculo :: getData_Devolucao(){
	return data_saida;
}

void Aluguel_veiculo :: calc_valor_aluguel(){
	// função que realiza o cálculo do valor a ser pago.
	getTempo_utilizado();
	valor_aluguel = tempo_utilizado * (diaria/24);	
}
void Aluguel_veiculo :: cal_tempo_utilizado(){
	// função que realiza o calculo do tempo utilizado em horas.
	/*std :: cout << data_saida.dia << std :: endl;
	std :: cout << data_saida.dia << std :: endl;
	std :: cout << data_saida.dia << std :: endl;
	std :: cout << data_saida.dia << std :: endl;
	std :: cout << data_saida.dia << std :: endl;
	std :: cout << data_saida.dia << std :: endl;*/
	tempo_utilizado = ((data_saida.dia-data_entrada.dia)*24)+(hora_saida.hora-hora_entrada.hora)+(hora_saida.minuto-hora_entrada.minuto);
}
