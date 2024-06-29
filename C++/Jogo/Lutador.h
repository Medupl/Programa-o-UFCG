#ifndef LUTADOR_H
#define LUTADOR_H

class Lutador : public Personagens{
	
	private:
		string modo_luta;
		
	public:
		Lutador(string = " ",string = " ", int = 0, float = 0.0, float = 0.0, string = " ");
		~Lutador();
		
		void set_modo_luta(string);
		string get_modo_luta();	
		
};

#endif
