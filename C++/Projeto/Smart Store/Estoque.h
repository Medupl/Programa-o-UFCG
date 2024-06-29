#ifndef ESTOQUE_H	
#define ESTOQUE_H

class Estoque{
	
  protected:
  		
	vector <Cliente> Cadastro_Cliente;
	vector <Funcionario> Cadastro_Funcionario;
	vector < Produto_und > Cadastro_und;
	vector < Produto_kg > Cadastro_kg;
	
	vector < Produto_und > venda_und;
	vector < Produto_kg > venda_kg;
	vector < Produto_und > aux_venda_und;
	vector < Produto_kg > aux_venda_kg;
	
	vector < Produto_und > aux_pedido_und;
	vector < Produto_kg > aux_pedido_kg;
	vector <Produto_und> Pedido_und;
	vector <Produto_kg> Pedido_kg;
	
public:
	
	Estoque();
	~Estoque();
	
	bool add_cliente();						// Adiciona um 	novo cliente.
	bool add_funcionario();					// Adiciona um 	novo funcionario.
	bool login_cliente(string,string);		// Realiza login do cliente.
	bool login_funcionario(string,string);	// Realiza login do funcionario.
	void menu_cliente(string);				// Mostar as op��es do cliente.
	void menu_funcionario(string);			// Mostar as op��es do funcionario.
	
	bool add_produto();						// Fun��o para adicionar produto.
	bool alterar_produto();					// Fun��o para remover produto por unidade.
	bool remover_produto();					// Fun��o para remover produto por kilo.
	bool relatorios();						// Fun��o para acessar os relatorios.
	bool listar_produtos();					// Fun��o para mostrar todos os produtos.
	bool mais_vendidos();					// Fun��o para mostrar os mais vendidos.
	
	bool carrinho();						// Fun��o para acessar o carrinho.
	bool meus_pedidos();					// Fun��o para acessar os pedidos.
	bool adicionar_produto_carrinho();		// Adiciona Pedido no carrinho.
	bool finalizar_carrinho();				// Finaliza pedido no carrinho.
	bool excluir_carrinho();				// Excluir todos os produto do carrinho.
	
	bool finalizar_pedido();				// Finaliza pedido dos clientes.
	bool cancelar_pedido();					// Cancela pedido de clientes, caso precise.
	bool add_produto_venda();				// Adiciona produto a venda.
	bool finalizar_venda();					// Finaliza venda.
	bool cancela_venda();					// Cancela venda.
	
	void salvar_arquivos();					// Salvar as informa��es em arquivo txt.
	void getPrintLinhas();					// Imprimi uma linha para ajudar no visual.
	
};

#endif