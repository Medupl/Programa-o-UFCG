# ifndef PRODUTOUND_H
# define PRODUTOUND_H


class Produto_und : public Produto{ // herdando os atributos da classe base//

	string embalagem_und;
	int quantidade_und;
	int quantidade_vendida_und;

  public:

	Produto_und(int = 0, string = " ", double = 0.0, string = " ", string = " ", int = 0, string = " ", int = 0, int = 0);
	~Produto_und();

	void setEmbalagemUnd(string);
	void setQuantidadeUnd(int);
	void setQuantidadeVendidaUnd(int);

	string getEmbalagemUnd();
	int getQuantidadeUnd();
	int getQuantidadeVendidaUnd();
};

# endif
