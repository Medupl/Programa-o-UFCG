#ifndef JOGO_H
#define JOGO_H

class Jogo{
	
	private:
		vector <Atirador> JogadorA;
		vector <Lutador> JogadorB;
	
	public:
		Jogo();
		~Jogo();
		
		bool adiciona_lutador(Lutador);
		bool excluir_lutador();
		bool exibir_lutador();
		bool exibir_lutadores();
		
		bool adiciona_atirador(Atirador);
		bool excluir_atirador();
		bool exibir_atirador();
		bool exibir_atiradores();
		
		bool combate_lutadores();
		bool combate_atiradores();
		void salvar_arquivos();
		void getPrintLinhas();
	
};

#endif
