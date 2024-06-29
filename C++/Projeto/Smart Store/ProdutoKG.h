# ifndef PRODUTOKG_H
# define PRODUTOKG_H


class Produto_kg : public Produto{ // herdando os tributos da classe base//

	string embalagem_kg;
	float quantidade_kg;
	float quantidade_vendida_kg;
	
  public:
  	
	Produto_kg(int = 0, string = " ", double = 0.0, string = " ", string = " ", int = 0, string = " ", float = 0, float = 0); 
	~Produto_kg();
	
	void setEmbalagemKg(string);
	void setQuantidadeKg(float);
	void setQuantidadeVendidaKg(float);
	
	string getEmbalagemKg();
	float getQuantidadeKg();
	float getQuantidadeVendidaKg();
};

# endif