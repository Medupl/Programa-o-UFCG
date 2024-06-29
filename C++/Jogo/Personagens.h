#ifndef PERSONAGENS_H
#define PERSONAGENS_H

class Personagens{
	
	protected:
		string nome;
		string arma;
		int quantidade_vida;
		float dano;
		float alcance;
		
	public:
		Personagens();
		~Personagens();
		
		void set_nome(string);
		void set_arma(string);
		void set_quantidade_vida(int);
		void set_dano(float);
		void set_alcance(float);
		
		string get_nome();
		string get_arma();
		int get_quantidade_vida();
		float get_dano();
		float get_alcance();
	
};

#endif
