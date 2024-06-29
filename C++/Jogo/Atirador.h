#ifndef ATIRADOR_H
#define ATIRADOR_H

class Atirador : public Personagens{
	
	private:
		string municao;
		string classificacao;
		
	public:
		Atirador(string = " ", string = " ", int = 0, float = 0.0, float = 0.0, string = " ", string = " ");
		~Atirador();
		
		void set_municao(string);
		void calc_classificacao();
		
		string get_municao();
		string get_classificacao();
		
};

#endif
