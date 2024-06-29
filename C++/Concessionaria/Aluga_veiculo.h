#ifndef ALUGUEL_VEICULO_H
#define ALUGUEL_VEICULO_H

struct Data{
	// Struct para armazenar as datas.
	int dia;
	int mes;
	int ano;
};

struct Hora{
	// Struct para armazenar as horas.
	int hora;
	int minuto;
};

class Aluguel_veiculo{
	
	private:
		Data data_entrada;
		Hora hora_entrada;
		Data data_saida;
		Hora hora_saida;
		std :: string modelo;
		std :: string marca;
		int ano_carro;
		float diaria;
		Hora hora_retirada;
		Data data_retirada;
		Hora hora_devolucao;
		Data data_devolucao;
		float valor_aluguel;
		int tempo_utilizado;
		void calc_valor_aluguel();
		void cal_tempo_utilizado();
		
	public:
		Aluguel_veiculo();
		~Aluguel_veiculo();
		void setModelo(std :: string);
		void setMarca(std :: string);
		void setAno_Carro(int);
		void setDiaria(float);
		void setHora_Retirada(int,int);
		void setData_Retirada(int,int,int);
		void setHora_Devolucao(int,int);
		void setData_Devolucao(int,int,int);
		
		std :: string getModelo();
		std :: string getMarca();
		int getAno_Carro();
		float getDiaria();
		Hora getHora_Retirada();
		Data getData_Retirada();
		Hora getHora_Devolucao();
		Data getData_Devolucao();
		float getValor_aluguel();
		int getTempo_utilizado();
	
};

#endif
