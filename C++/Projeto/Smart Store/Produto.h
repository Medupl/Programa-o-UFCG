#ifndef PRODUTO_H
#define PRODUTO_H

/* Determinando uma classe para as informações do produto */

class Produto{
	
	protected:
		
		string Descricao;
		int Codigo;
		string Secao;
		double Preco;
		string Fornecedor;
		int Validade;
		double Desconto;
		double Preco_total;
		double valor_nota;
		
		
	public:
		
		Produto();
		
		string nome_cliente_nota;
		string cpf_cliente_nota;
		int numero_nota;		
		
		void setNomeClienteNota(string);
		void setCpfClienteNota(string);
		void setNumeroNota(int); 
		void setDescricao(string);
		void setCodigo(int);
		void setSecao(string);
		void setFornecedores(string);
		void setPreco(double);
		void setValidade(int);
		void setDesconto(double);
		void setValorNota(double);
		void setPrecoTotal(double);
		
		string getCpfClienteNota();
		string getNomeClienteNota();
		int getNumeroNota();
		string getDescricao();
		int getCodigo();
		string getSecao();
		string getFornecedores();
		double getPreco();
		int getValidade();
		double getDesconto();
		double getValorNota();
		double getPrecoTotal();
		
};

#endif