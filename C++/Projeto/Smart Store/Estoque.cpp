#include "Estoque.h"

Estoque::Estoque(){	
	// Abrindo as informações salvas para serem usadas no programa.
	ifstream arquivo_funcionario;
	arquivo_funcionario.open("Funcionario.txt");
	string funcionario;
  	string senha_funcionario;
  	string cpf_funcionario;

	if(arquivo_funcionario.is_open()){
		while(!arquivo_funcionario.eof()){
			// Lendo o arquivo com a lista de funcionários.
			arquivo_funcionario >> cpf_funcionario;
			if (arquivo_funcionario.eof()){
				break;
			}
			arquivo_funcionario.ignore();
			getline(arquivo_funcionario,funcionario);
			arquivo_funcionario >> senha_funcionario;

			Funcionario Func_aux(cpf_funcionario,funcionario,senha_funcionario);
			Cadastro_Funcionario.push_back(Func_aux);
		}
		arquivo_funcionario.close();
	}
	else{
		cout<<"\n	Não foi possível abrir o arquivo.\n"<<endl;
	 }

	ifstream arquivo_cliente;
	arquivo_cliente.open("Cliente.txt");
	string nome_cliente;
  	string senha_cliente;
  	string endereco;
  	string cpf_cliente;

	if(arquivo_cliente.is_open()){
		while(!arquivo_cliente.eof()){
			// Lendo o arquivo com a lista de funcionários.
			arquivo_cliente >> cpf_cliente;
			if (arquivo_cliente.eof()){
				break;
			}
			arquivo_cliente.ignore();
			getline(arquivo_cliente,nome_cliente);
			arquivo_cliente >> senha_cliente;
			arquivo_cliente.ignore();
			getline(arquivo_cliente,endereco);

			Cliente Cliente_aux(cpf_cliente,nome_cliente,senha_cliente,endereco);
			Cadastro_Cliente.push_back(Cliente_aux);
		}
		arquivo_cliente.close();
	}
	else{
		cout<<"\n	Não foi possível abrir o arquivo.\n"<<endl;
	 }

	string Descricao;
	int Codigo;
	string Secao;
	double Preco;
	string Fornecedor;
	int Validade;

	ifstream arquivo_und;
	arquivo_und.open("ProdutosUnd.txt");
	string embalagem_und;
	int quantidade_und;
	int quantidade_vendida_und;

	if(arquivo_und.is_open()){
		while(!arquivo_und.eof()){
			// Lendo o arquivo com a lista de Produtos und.
			arquivo_und >> Codigo;
			if (arquivo_und.eof()){
				break;
			}
			arquivo_und.ignore();
			getline(arquivo_und,Descricao);
			arquivo_und >> Preco;
			arquivo_und >> Secao;
			arquivo_und.ignore();
			getline(arquivo_und,Fornecedor);
			arquivo_und >> Validade;
			arquivo_und.ignore();
			getline(arquivo_und,embalagem_und);
			arquivo_und >> quantidade_und;
			arquivo_und >> quantidade_vendida_und;
			Produto_und Und_aux(Codigo,Descricao,Preco,Secao,Fornecedor,Validade,
			embalagem_und,quantidade_und,quantidade_vendida_und);
			Cadastro_und.push_back(Und_aux);
		}
		arquivo_und.close();
	}
	else{
		cout<<"\n	Não foi possível abrir o arquivo.\n"<<endl;
	 }

	ifstream arquivo_kg;
	arquivo_kg.open("ProdutosKg.txt");
	string embalagem_kg;
	float quantidade_kg;
	float quantidade_vendida_kg;

	if(arquivo_kg.is_open()){
		while(!arquivo_kg.eof()){
			// Lendo o arquivo com a lista de Produtos und.
			arquivo_kg >> Codigo;
			if (arquivo_kg.eof()){
				break;
			}
			arquivo_kg.ignore();
			getline(arquivo_kg,Descricao);
			arquivo_kg >> Preco;
			arquivo_kg >> Secao;
			arquivo_kg.ignore();
			getline(arquivo_kg,Fornecedor);
			arquivo_kg >> Validade;
			arquivo_kg.ignore();
			getline(arquivo_kg,embalagem_kg);
			arquivo_kg >> quantidade_kg;
			arquivo_kg >> quantidade_vendida_kg;
			Produto_kg Kg_aux(Codigo,Descricao,Preco,Secao,Fornecedor,Validade,
			embalagem_kg,quantidade_kg,quantidade_vendida_kg);
			Cadastro_kg.push_back(Kg_aux);
		}
		arquivo_kg.close();
	}
	else{
		cout<<"\n	Não foi possível abrir o arquivo.\n"<<endl;
	 }
	 
}

Estoque::~Estoque(){
	salvar_arquivos();					// Chamando a função salvar.
	cout << "\n\n       Finalizando Programa...\n";
	cout << "\n       Obrigado por utilizar nossos serviços.\n";
}

void Estoque:: getPrintLinhas(){
	//  Imprimi uma linha para ajudar no visual.
	cout << "===================================================================";
}

bool Estoque:: add_cliente(){
	// Adiciona um 	novo cliente.
	Cliente cad_cliente;
	string cpf_cliente;
	string name_cliente, senha_cliente, endereco_cliente;

	getPrintLinhas();
	cout<<"\n                    SMART STORY                     ";
	cout<<"\n		CADASTRAMENTO DE CLIENTE."<<endl;
	getPrintLinhas();
    cout<<"\n\n	Informe seu nome para cadastro: ";
    cin.ignore();
    getline(cin,name_cliente);
    cad_cliente.setNomeCliente(name_cliente);
    cout<<"\n	Informe seu CPF, "<<cad_cliente.getNomeCliente()<<": ";
    cin>>cpf_cliente;
    cout<<"\n	Informe sua senha, "<<cad_cliente.getNomeCliente()<<": ";
    cin>>senha_cliente;
    cout<<"\n	Informe seu endereço, "<<cad_cliente.getNomeCliente()<<": ";
    cin.ignore();
    getline(cin,endereco_cliente);
    for(unsigned i = 0; i < Cadastro_Cliente.size(); i++){
		if(Cadastro_Cliente.size() != 0 and Cadastro_Cliente[i].getCpfCliente() == cpf_cliente){
			return false;
		}
	}
	cad_cliente.setCpfCliente(cpf_cliente);
	cad_cliente.setSenhaCliente(senha_cliente);
	cad_cliente.setEnderecoCliente(endereco_cliente);
	Cadastro_Cliente.push_back(cad_cliente);
	return true;
}

bool Estoque:: add_funcionario(){
	// Adiciona um 	novo funcionario.
	Funcionario cad_loja;
	string cpf_funcionario;
	string name_funcionario, senha_funcionario, endereco_cliente;

	getPrintLinhas();
	cout<<"\n                    SMART STORY                     ";
	cout<<"\n		CADASTRAMENTO DE FUNCIONÁRIO."<<endl;
	getPrintLinhas();
    cout<<"\n\n	Informe seu nome para cadastro: ";
    cin.ignore();
    getline(cin,name_funcionario);
    cad_loja.setFuncionario(name_funcionario);
    cout<<"\n	Informe seu CPF, "<<cad_loja.getFuncionario()<<": ";
    cin>>cpf_funcionario;
    cout<<"\n	Informe sua senha, "<<cad_loja.getFuncionario()<<": ";
    cin>>senha_funcionario;
    for(unsigned i = 0; i < Cadastro_Funcionario.size(); i++){
		if(Cadastro_Funcionario.size() != 0 and Cadastro_Funcionario[i].getCpfFuncionario() == cpf_funcionario){
			return false;
		}
	}
	cad_loja.setCpfFuncionario(cpf_funcionario);
	cad_loja.setSenhaFuncionario(senha_funcionario);
	Cadastro_Funcionario.push_back(cad_loja);
	return true;
}

bool Estoque:: login_cliente(string senha, string cpf){
	// Realiza login do cliente.
	Produto prod;
	string nome_cliente_nota;
	
	for(unsigned i = 0; i < Cadastro_Cliente.size(); i++){
		if (cpf == Cadastro_Cliente[i].getCpfCliente() and senha == Cadastro_Cliente[i].getSenhaCliente()){
			nome_cliente_nota = Cadastro_Cliente[i].getNomeCliente();
			prod.setNomeClienteNota(nome_cliente_nota);
			prod.setCpfClienteNota(cpf);
			return true;
		}
	}
	return false;
}

bool Estoque:: login_funcionario(string senha, string cpf){
	// Realiza login do funcionario.
	for(unsigned i = 0; i < Cadastro_Funcionario.size(); i++){
		if (cpf == Cadastro_Funcionario[i].getCpfFuncionario() and senha == Cadastro_Funcionario[i].getSenhaFuncionario()){
			return true;
		}
	}
	return false;
}

void Estoque:: menu_funcionario(string cpf){
	// Mostar as opções do funcionario.
	int resp;
	for(unsigned i = 0; i < Cadastro_Funcionario.size(); i++){
		if(cpf == Cadastro_Funcionario[i].getCpfFuncionario()){
			while(true){
				system("cls");

				cout<<"\n                    SMART STORY                     \n";
				getPrintLinhas();
				cout << "\n		Seja bem-vindo, " << Cadastro_Funcionario[i].getFuncionario() << ": ";
				cout << "\n 	Menu Lojista.\n";
				getPrintLinhas();
				cout << "\n\n   1 -	Adicionar Produto.\n"
   	 	        << "   2 -	Alterar Produto.\n"
				<< "   3 -  Remover Produto.\n"
				<< "   4 -  Relatórios.\n"
 	    	    << "   5 -  Vender.\n"
 	 	 	    << "   0 -  Logout.\n\n";
 	 	 	    getPrintLinhas();
				cout << "\n\n	Digite a Opção que deseja realizar: ";
 	 	 	 	cin >> resp;

 	 	 	 	 if(resp == 0){
					break;
				}
				system("cls");

				switch(resp){
					case 1:
						// Acionando a função para adicionar produtos.
						if(add_produto() == 1){
							cout << "\n		Produto adicionado com sucesso.\n";
						}
						else{
							cout << "\n Erro ao cadastrar produto.\n";
						}
						break;

					case 2:
						// Acionando a função para realizar alteraï¿½ï¿½es de produtos.
						if(alterar_produto() == 1){
							cout << "\n 	Produto alterado com sucesso.\n";
						}
						else{
							cout << "\n 	Erro ao alterar o produto.\n";
						}
						break;

					case 3:
						// Acionando a função para remover produtos.
						if(remover_produto() == 1){
							cout << "\n 	Produto removido com sucesso.\n";
						}
						else{
							cout << "\n 	Erro ao alterar o produto.\n";
						}
						break;

					case 4:
						// Acionando a função para puxar os relatï¿½rios de todas as vendas.
						if(relatorios() == 1){
							cout << "\n 	Relatórios exibidos com sucesso.\n";
						}
						else{
							cout << "\n 	Erro ao puxar os Relatï¿½rios.\n";
						}
						break;

					case 5:
						// Acionando a função para realizar as vendas dos produtos.
							while(true){
									system("cls");

									cout<<"\n                    SMART STORY                     ";
									cout<<"\n	            VENDAS						\n";
									getPrintLinhas();
									cout << "\n\n   1 - Vender.\n"
									<< "   2 - Pedidos Clientes. \n"	
 	 	 	 						<< "   0 - Menu Principal.\n\n";
 	 	 	 						getPrintLinhas();
 	 	 	 						cout << "\n\n	Digite a Opção que deseja realizar: ";
 	 	 	 						cin >> resp;

 	 	 	 						if(resp == 0){
        								break;
									}
									system("cls");
									
									if(resp == 1){
										getPrintLinhas();
										cout<<"\n                    SMART STORY                     ";
										cout<<"\n		   REALIZAR VENDAS						\n";
										getPrintLinhas();
										cout << "\n\n   1 - Adicionar produtos a nota.\n"
										<< "   2 - Cancelar Venda. \n"	
										<< "   3 - Finalizar Venda. \n"	
 	 	 	 							<< "   0 - Menu Principal.\n\n";
 	 	 	 							getPrintLinhas();
 	 	 	 							cout << "\n\n	Digite a Opção que deseja realizar: ";
 	 	 	 							cin >> resp;
 	 	 	 							
 	 	 	 							if(resp == 0){
											break;
										}
										system("cls");
										
										if(resp == 1){
											if(add_produto_venda() == 1){
												cout << "\n\n Produtos adicionados com sucesso. \n";
											}
											else{
												cout << "\n\n Erro ao tentar adicionar os produtos. \n";
											}
										}
										else if(resp == 2){
											if(cancela_venda() == 1){
												cout << "\n\n Venda cancelada com sucesso. \n";
											}
											else{
												cout << "\n\n Erro ao tentar cancelar a venda. \n";
											}
										}
										else if(resp == 3){
											if(finalizar_venda() == 1){
												cout << "\n\n Venda finalizada com sucesso. \n";
											}
											else{
												cout << "\n\n Erro ao tentar finalizar a Venda. \n";
											}
										}
										else{
                							getPrintLinhas();
                    						cout << "\n\n			Opção Inválida !\n";
											cout << " 			Tente novamente. \n\n";
											getPrintLinhas();
											cout << endl;
                    						break;
                						}
                						break;
									}
									else if(resp == 2){
										getPrintLinhas();
										cout<<"\n                    SMART STORY                     ";
										cout<<"\n	         PEDIDOS DOS CLIENTES					\n";
										getPrintLinhas();
										cout << "\n\n   1 - Finalizar Pedido de Cliente.\n"
										<< "   2 - Cancelar Pedido de Cliente. \n"	
 	 	 	 							<< "   0 - Menu Principal.\n\n";
 	 	 	 							getPrintLinhas();
 	 	 	 							cout << "\n\n	Digite a Opção que deseja realizar: ";
 	 	 	 							cin >> resp;
 	 	 	 							
 	 	 	 							if(resp == 0){
											break;
										}
										system("cls");
										
										if(resp == 1){
											if(finalizar_pedido() == 1){
												cout << "\n\n Pedido cliente finalizado com sucesso. \n";
											}
											else{
												cout << "\n\n Erro ao tentar finalizar pedido de cliente. \n";
											}
										}
										if(resp == 2){
											if(cancelar_pedido() == 1){
												cout << "\n\n Pedido cliente cancelado com sucesso. \n";
											}
											else{
												cout << "\n\n Erro ao tentar cancelar pedido de cliente. \n";
											}
										}
									}	
									else{
                						getPrintLinhas();
                    					cout << "\n\n			Opção Inválida !\n";
										cout << " 			Tente novamente. \n\n";
										getPrintLinhas();
										cout << endl;
                    					break;
                					}
                					break;
							}
							break;

					default:
						getPrintLinhas();
						cout << "\n			Smart Store.\n";
	    				getPrintLinhas();
						cout << "\n\n			Opção Inválida !\n";
						cout << " 			Tente novamente. \n\n";
						break;
				}

 	 	 	    system("pause");
			}
		}
	}
}

bool Estoque:: add_produto(){
	// Função para adicionar produto.
	int Codigo;
	string Descricao;
	string Secao;
	double Preco;
	string Fornecedor;
	int Validade;
	int op;

	while(true){
		system("cls");

		getPrintLinhas();
    	cout<<"\n                    SMART STORY                     ";
    	cout<<"\n                 ADICIONAR PRODUTO                     "<<endl;
    	getPrintLinhas();
    	cout<<"\n\n	1 - Adicionar Produto Und."<<endl
    	<<"	2 - Adicionar Produto Kg."<<endl
    	<<"	0 - Retornar ao menu principal"<<endl<<endl;
   		getPrintLinhas();

		cout<<"\n\n	Informe a opção desejada: ";
    	cin>>op;
    	system("cls");

    	if(op == 0){
		   	break;
		}

    	else if(op == 1){
			Produto_und Prod_und;
			int quantidade_und;

			getPrintLinhas();
    		cout<<"\n                    SMART STORY                     ";
    		cout<<"\n                 ADICIONAR PRODUTO UND                    "<<endl;
    		getPrintLinhas();
			cout<<"\n	INFORMAÇÕES DO PRODUTO:\n"<<endl;
			cout<<"\n	Informe o codigo: ";
			cin>>Codigo;
			for(unsigned i = 0; i < Cadastro_und.size(); i++){
				if(Cadastro_und.size() != 0 and Cadastro_und[i].getCodigo() == Codigo){
					return false;
				}
			}
			for(unsigned i = 0; i < Cadastro_kg.size(); i++){
				if(Cadastro_kg.size() != 0 and Cadastro_kg[i].getCodigo() == Codigo){
					return false;
				}
			}
			cout<<"\n	Informe o nome: ";
			cin.ignore();
			getline(cin,Descricao);
			cout<<"\n	Informe a seção: ";
			cin>>Secao;
			cout<<"\n	Informe o preço: ";
			cin>>Preco;
			cout<<"\n	Informe o fornecedor: ";
			cin.ignore();
			getline(cin,Fornecedor);
			cout<<"\n	Informe a validade: ";
			cin>>Validade;
			cout<<"\n	Informe a quantidades: ";
			cin>>quantidade_und;

			Prod_und.setCodigo(Codigo);
			Prod_und.setDescricao(Descricao);
			Prod_und.setSecao(Secao);
			Prod_und.setPreco(Preco);
			Prod_und.setFornecedores(Fornecedor);
			Prod_und.setValidade(Validade);
			Prod_und.setEmbalagemUnd("UN");
			Prod_und.setQuantidadeUnd(quantidade_und);

			Cadastro_und.push_back(Prod_und);
			return true;

		}

		else if(op == 2){
			Produto_kg Prod_kg;
			float quantidade_kg;

			getPrintLinhas();
    		cout<<"\n                    SMART STORY                     ";
    		cout<<"\n                 ADICIONAR PRODUTO KG                    "<<endl;
    		getPrintLinhas();
			cout<<"\n	INFORMAÇÕES DO PRODUTO:\n"<<endl;
			cout<<"\n	Informe o codigo: ";
			cin>>Codigo;
			for(unsigned i = 0; i < Cadastro_und.size(); i++){
				if(Cadastro_und.size() != 0 and Cadastro_und[i].getCodigo() == Codigo){
					return false;
				}
			}
			for(unsigned i = 0; i < Cadastro_kg.size(); i++){
				if(Cadastro_kg.size() != 0 and Cadastro_kg[i].getCodigo() == Codigo){
					return false;
				}
			}
			cout<<"\n	Informe o nome: ";
			cin.ignore();
			getline(cin,Descricao);
			cout<<"\n	Informe a seção: ";
			cin>>Secao;
			cout<<"\n	Informe o preço: ";
			cin>>Preco;
			cout<<"\n	Informe o fornecedor: ";
			cin.ignore();
			getline(cin,Fornecedor);
			cout<<"\n	Informe a validade: ";
			cin>>Validade;
			cout<<"\n	Informe a quantidades: ";
			cin>>quantidade_kg;

			Prod_kg.setCodigo(Codigo);
			Prod_kg.setDescricao(Descricao);
			Prod_kg.setSecao(Secao);
			Prod_kg.setPreco(Preco);
			Prod_kg.setFornecedores(Fornecedor);
			Prod_kg.setValidade(Validade);
			Prod_kg.setEmbalagemKg("KG");
			Prod_kg.setQuantidadeKg(quantidade_kg);

			Cadastro_kg.push_back(Prod_kg);
			return true;
	 	}


		else{
        	getPrintLinhas();
        	cout << "\n\n			Opção Inválida !\n";
			cout << " 			Tente novamente. \n\n";
			getPrintLinhas();
			cout << endl;
			system("pause");
    	}
    	break;
	}
	return false;
}

bool Estoque:: alterar_produto(){
	// Função para alterar produto.
	int Codigo;
	string Descricao;
	string Secao;
	double Preco;
	string Fornecedor;
	int Validade;
	int op;
	int validador;
	
	while(true){
    	system("cls");

		getPrintLinhas();
    	cout<<"\n                    SMART STORY                     ";
    	cout<<"\n                  ALTERAR PRODUTO                     "<<endl;
    	getPrintLinhas();
    	cout<<"\n\n	1 - Alterar Produto Und."<<endl
    	<<"	2 - Alterar Produto Kg."<<endl
    	<<"	0 - Retornar ao menu principal"<<endl<<endl;
    	getPrintLinhas();

		cout<<"\n\n	Informe a opção desejada: ";
    	cin>>op;
    	system("cls");

    	if(op == 0){
			break;
		}

    	else if(op == 1){
    		Produto_und Prod_und;
			int quantidade_und;

    		getPrintLinhas();
    		cout<<"\n                    SMART STORY                     ";
    		cout<<"\n                 ALTERAR PRODUTO UND                    "<<endl;
    		getPrintLinhas();
			cout << "\n\n	Informe o código do produto que deseja fazer alteração: ";
    		cin >> Codigo;
    		cout << endl;
    		getPrintLinhas();
    		validador = 0;
    		for(unsigned i = 0; i < Cadastro_und.size(); i++){	// Imprimir informações para ajudar nas alterações.
    			if(Codigo == Cadastro_und[i].getCodigo()){
    				cout << "\n\n  Código\tDescrição \t Seção \t    Preço \t Fornecedor \t    Validade \tEmbalagem \t Quantidade \n\n";
    				getPrintLinhas();
					cout << "\n   " << setfill(' ') << setw(7) << left << Cadastro_und[i].getCodigo()
					<< setw(20) << left << Cadastro_und[i].getDescricao()
					<< setw(15) << left << Cadastro_und[i].getSecao()
					<< setw(13) << left << Cadastro_und[i].getPreco()
					<< setw(20) << left << Cadastro_und[i].getFornecedores()
					<< setw(15) << left << Cadastro_und[i].getValidade()
					<< setw(15) << left << Cadastro_und[i].getEmbalagemUnd()
					<< setw(15) << left << Cadastro_und[i].getQuantidadeUnd() << endl;
					getPrintLinhas();
					Cadastro_und.erase(Cadastro_und.begin()+i);

					cout<<"\n\n	Informe o nome: ";
					cin.ignore();
					getline(cin,Descricao);
					cout<<"\n	Informe a seção: ";
					cin>>Secao;
					cout<<"\n	Informe o preço: ";
					cin>>Preco;
					cout<<"\n	Informe o fornecedor: ";
					cin.ignore();
					getline(cin,Fornecedor);
					cout<<"\n	Informe a validade: ";
					cin>>Validade;
					cout<<"\n	Informe a quantidades: ";
					cin>>quantidade_und;

					Prod_und.setCodigo(Codigo);
					Prod_und.setDescricao(Descricao);
					Prod_und.setSecao(Secao);
					Prod_und.setPreco(Preco);
					Prod_und.setFornecedores(Fornecedor);
					Prod_und.setValidade(Validade);
					Prod_und.setEmbalagemUnd("UN");
					Prod_und.setQuantidadeUnd(quantidade_und);

					Cadastro_und.push_back(Prod_und);
					validador = validador+1;
					return true;
				}
			}
			break;
		}

		else if(op == 2){
    		Produto_kg Prod_kg;
			int quantidade_kg;

    		getPrintLinhas();
    		cout<<"\n                    SMART STORY                     ";
    		cout<<"\n                 ALTERAR PRODUTO KG            "<<endl;
    		getPrintLinhas();
    		cout << "\n\n	Informe o código do produto que deseja fazer alteração: ";
    		cin >> Codigo;
    		cout << endl;
    		getPrintLinhas();
    		validador = 0;
			for(unsigned i = 0; i < Cadastro_kg.size(); i++){	// Imprimir informações para ajudar nas alterações.
    			if(Codigo == Cadastro_kg[i].getCodigo()){
    				cout << "\n\n  Código\tDescrição \t Seção \t    Preço \t Fornecedor \t    Validade \tEmbalagem \t Quantidade \n\n";
    				getPrintLinhas();
					cout << "\n   " << setfill(' ') << setw(7) << left << Cadastro_kg[i].getCodigo()
					<< setw(20) << left << Cadastro_kg[i].getDescricao()
					<< setw(15) << left << Cadastro_kg[i].getSecao()
					<< setw(13) << left << Cadastro_kg[i].getPreco()
					<< setw(20) << left << Cadastro_kg[i].getFornecedores()
					<< setw(15) << left << Cadastro_kg[i].getValidade()
					<< setw(15) << left << Cadastro_kg[i].getEmbalagemKg()
					<< setw(15) << left << Cadastro_kg[i].getQuantidadeKg() << endl;
					getPrintLinhas();
					Cadastro_kg.erase(Cadastro_kg.begin()+i);

					cout<<"\n\n	Informe o nome: ";
					cin.ignore();
					getline(cin,Descricao);
					cout<<"\n	Informe a seção: ";
					cin>>Secao;
					cout<<"\n	Informe o preço: ";
					cin>>Preco;
					cout<<"\n	Informe o fornecedor: ";
					cin.ignore();
					getline(cin,Fornecedor);
					cout<<"\n	Informe a validade: ";
					cin>>Validade;
					cout<<"\n	Informe a quantidades: ";
					cin>>quantidade_kg;

					Prod_kg.setCodigo(Codigo);
					Prod_kg.setDescricao(Descricao);
					Prod_kg.setSecao(Secao);
					Prod_kg.setPreco(Preco);
					Prod_kg.setFornecedores(Fornecedor);
					Prod_kg.setValidade(Validade);
					Prod_kg.setEmbalagemKg("KG");
					Prod_kg.setQuantidadeKg(quantidade_kg);

					Cadastro_kg.push_back(Prod_kg);
					validador = validador+1;
					return true;
				}
			}
			break;
		}

		else{
        	getPrintLinhas();
        	cout << "\n\n			Opção Inválida !\n";
			cout << " 			Tente novamente. \n\n";
			getPrintLinhas();
			cout << endl;
			system("pause");
			break;
    	}
		break;
	}
	if(validador == 0){
		return false;
	}
	else{
		return true;
	}
}

bool Estoque:: remover_produto(){
	// Função para remover produto.
	int op;
	int Codigo;
	while(true){
		system("cls");

		getPrintLinhas();
    	cout<<"\n                    SMART STORY                     ";
    	cout<<"\n                  REMOVER PRODUTO                     "<<endl;
    	getPrintLinhas();
    	cout<<"\n\n	1 - Remover Produto Und."<<endl
    	<<"	2 - Remover Produto Kg."<<endl
    	<<"	0 - Retornar ao menu principal"<<endl<<endl;
    	getPrintLinhas();

		cout<<"\n\n	Informe a opção desejada: ";
    	cin>>op;
  	  	system("cls");

    	if(op == 0){
    		break;
		}

		else if(op == 1){
			getPrintLinhas();
    		cout<<"\n                    SMART STORY                     ";
    		cout<<"\n                 REMOVER PRODUTO UND                    "<<endl;
    		getPrintLinhas();
			cout << "\n\n	Informe o código do produto que deseja excluir: ";
    		cin >> Codigo;
    		cout << endl;
    		getPrintLinhas();
    		for(unsigned i = 0; i < Cadastro_und.size(); i++){
        		if(Cadastro_und.size() != 0 and Cadastro_und[i].getCodigo() == Codigo){
            		Cadastro_und.erase(Cadastro_und.begin()+i);
            		return true;
        		}
    		}
			break;
		}

		else if(op == 2){
			getPrintLinhas();
    		cout<<"\n                    SMART STORY                     ";
    		cout<<"\n                 REMOVER PRODUTO KG                    "<<endl;
    		getPrintLinhas();
			cout << "\n\n	Informe o código do produto que deseja excluir: ";
    		cin >> Codigo;
    		cout << endl << endl;
    		getPrintLinhas();
    		for(unsigned i = 0; i < Cadastro_kg.size(); i++){
        		if(Cadastro_kg.size() != 0 and Cadastro_kg[i].getCodigo() == Codigo){
            		Cadastro_kg.erase(Cadastro_kg.begin()+i);
        			return true;
				}
    		}
			break;
		}

		else{
        	getPrintLinhas();
        	cout << "\n\n			Opção Inválida !\n";
			cout << " 			Tente novamente. \n\n";
			getPrintLinhas();
			cout << endl;
			system("pause");
			break;
    	}
	}
	return false;
}

bool Estoque:: relatorios(){
	// Função para acessar os relatorios.
	int op;

	while(true){
		system("cls");

    	getPrintLinhas();
    	cout<<"\n                    SMART STORY                     ";
    	cout<<"\n                    RELATÁRIOS                    "<<endl;
    	getPrintLinhas();
    	cout << "\n\n	1 - Listar funcionarios." << endl
    	<< "	2 - Listar clientes." << endl
    	<< "	3 - Listar produtos." << endl
    	<< "	4 - Relatório de vendas." << endl
    	<< "	0 - Sair\n\n";
    	getPrintLinhas();

		cout<<"\n\n	Informe a Opção desejada: ";
    	cin>>op;

    	if(op == 0)
        	break;
    	system("cls");

    	switch(op){
    		case 1:
    			getPrintLinhas();
    			cout<<"\n                    SMART STORY                     ";
    			cout<<"\n                 LISTAR FUNCIONARIOS                    "<<endl;
    			getPrintLinhas();
    			cout << "\n\n   Nome Funcionário   \t\t CPF\n\n";
    			for(unsigned i = 0; i < Cadastro_Funcionario.size(); i++){
    				cout << "   " << setfill(' ') << setw(30) << left << Cadastro_Funcionario[i].getFuncionario()
					<< setw(15) << left << Cadastro_Funcionario[i].getCpfFuncionario() << endl;
				}
				getPrintLinhas();	
				cout << endl << endl;	
    			break;
    		
    		case 2:
    			getPrintLinhas();
    			cout<<"\n                    SMART STORY                     ";
    			cout<<"\n                 LISTAR CLIENTES                    "<<endl;
    			getPrintLinhas();
    			cout << "\n\n   Nome Cliente   \t CPF \t\t Endereço \n\n";
    			for(unsigned i = 0; i < Cadastro_Cliente.size(); i++){
    				cout << "   " << setfill(' ') << setw(20) << left << Cadastro_Cliente[i].getNomeCliente()
    				<< setw(15) << left << Cadastro_Cliente[i].getCpfCliente()
					<< setw(30) << left << Cadastro_Cliente[i].getEnderecoCliente() << endl;
				}		
				if(Cadastro_Cliente.size() == 0){
					cout << "\n\n	 Não há cadastro de Clientes. \n\n";
					cout << endl;
				}
				getPrintLinhas();
				cout << endl << endl;
    			break;
    		
    		 case 3:
    				getPrintLinhas();
					cout<<"\n                    SMART STORY                     ";
					cout<<"\n                   LISTAR PRODUTOS                   "<<endl;
    				getPrintLinhas();
					cout<<"\n\n		1- Produtos UND"            <<endl;
					cout<<"		2- Produtos KG"     	 	<<endl;
					cout<<"\n\n Escolha a Opção desejada: ";
					cin>> op;
					if(op == 1){
						cout<<"\n              LISTA DE TODOS OS PRODUTOS UND                   "<<endl;
    					getPrintLinhas();
    					cout << "\n\n  Código: \tDescrição: \t Preço: \t Seção: \t Validade: \t Embalagem: \t Quantidade: \t Quantidade Vendida:\n\n";
						if(Cadastro_und.size() == 0 ){
							return false;
						}
						else{
							for(unsigned i = 0; i < Cadastro_und.size(); i++){
								cout << "   " << setfill(' ') << setw(7) << left << Cadastro_und[i].getCodigo()
								<< setw(25) << left << Cadastro_und[i].getDescricao() 
								<< setw(15) << left << Cadastro_und[i].getPreco()
								<< setw(15) << left << Cadastro_und[i].getSecao() 
								<< setw(20) << left << Cadastro_und[i].getValidade()
								<< setw(15) << left << Cadastro_und[i].getEmbalagemUnd ()
                            	<< setw(20) << left << Cadastro_und[i].getQuantidadeUnd()
                            	<< setw(15) << left << Cadastro_und[i].getQuantidadeVendidaUnd()<< endl;
							}
							getPrintLinhas();
							cout << endl << endl;
						} 
					}	
					else if (op == 2){
						cout<<"\n              LISTA DE TODOS OS PRODUTOS KG                   "<<endl;
    					getPrintLinhas();
    					cout << "\n\n  Código: \tDescrição: \t Preço: \t Seção: \t Validade: \t Embalagem: \t Quantidade: \t Quantidade Vendida:\n\n";
						if(Cadastro_kg.size() == 0 ){
							return false;
						}
						else{
							for(unsigned i = 0; i < Cadastro_kg.size(); i++){
								cout << "   " << setfill(' ') << setw(7) << left << Cadastro_kg[i].getCodigo()
								<< setw(25) << left << Cadastro_kg[i].getDescricao() 
								<< setw(15) << left << Cadastro_kg[i].getPreco()
								<< setw(15) << left << Cadastro_kg[i].getSecao() 
								<< setw(20) << left << Cadastro_kg[i].getValidade()
								<< setw(15) << left << Cadastro_kg[i].getEmbalagemKg ()
                            	<< setw(20) << left << Cadastro_kg[i].getQuantidadeKg()
                            	<< setw(15) << left << Cadastro_kg[i].getQuantidadeVendidaKg()<< endl;
							}
							getPrintLinhas();
							cout << endl << endl;
						} 
				   	}
					else{
                		getPrintLinhas();
                    	cout << "\n\n			Opção Inválida !\n";
						cout << " 			Tente novamente. \n\n";
						getPrintLinhas();
						cout << endl;
                    	break;
                	}
					break;
    		
    		case 4:
    			unsigned tam;	
    			
    			getPrintLinhas();
    			cout<<"\n                    SMART STORY                     ";
    			cout<<"\n                   RELATÓRIOS DE VENDAS                    "<<endl;
    			getPrintLinhas();
    			cout << endl;
    			if(venda_und.size() > venda_kg.size()){
            			tam = venda_und.size();
        		}
        		else{
           	 	 	    tam =venda_kg.size();
        		}
    			for(unsigned y = 0; y < tam; y++){
    				if(tam >  venda_kg.size()){
    					cout<<"Cliente: " <<venda_und[y].getNomeClienteNota()<<"    Nº Nota    "<<venda_und[y].getNumeroNota();
					}	
    				if(tam >  venda_und.size()){
    					cout<<"Cliente: " <<venda_kg[y].getNomeClienteNota()<<"    Nº Nota    "<<venda_kg[y].getNumeroNota();
					}
    				cout << "\n\n  Código: \tDescrição: \t Preço:\t Embalagem: \t Quantidade: \t Preço Total:\n\n";
					if(y > venda_und.size() or y > venda_und.size()){
								break;
					}
					while(true){	
						for(unsigned t = 0; t < venda_und.size(); t++){
						if(venda_und[y].getCpfClienteNota() == venda_und[t].getCpfClienteNota()){			
							cout << "   " << setfill(' ') << setw(7) << left << venda_und[t].getCodigo()
							<< setw(25) << left << venda_und[t].getDescricao() 
							<< setw(15) << left << venda_und[t].getPreco()
							<< setw(15) << left << venda_und[t].getEmbalagemUnd()
                        	<< setw(20) << left << venda_und[t].getQuantidadeUnd()
                        	<< setw(15) << left << venda_und[t].getPrecoTotal()<< endl;
						}
						}
						for(unsigned t = 0; t < venda_kg.size(); t++){
						if(venda_kg[y].getCpfClienteNota() == venda_kg[t].getCpfClienteNota()){
							cout << "   " << setfill(' ') << setw(7) << left << venda_kg[t].getCodigo()
							<< setw(25) << left << venda_kg[t].getDescricao() 
							<< setw(15) << left << venda_kg[t].getPreco()
							<< setw(15) << left << venda_kg[t].getEmbalagemKg()
                        	<< setw(20) << left << venda_kg[t].getQuantidadeKg()
                        	<< setw(15) << left << venda_kg[t].getPrecoTotal()<< endl;
						}
						}
						break;	
						
					} 
					getPrintLinhas();
					cout << endl << endl;
				}
				if(tam == 0 ){
					cout << "\n\n Nenhuma venda realizada. Tente mais tarde. ";
				}
				break;

			default:
				getPrintLinhas();
				cout << "\n			Smart Store.\n";
	    		getPrintLinhas();
				cout << "\n\n			Opção Inválida !\n";
				cout << " 			Tente novamente. \n\n";
				break;
		}

 	 	system("pause");
	}
	return true;
}

bool ordenaProdutoUndRank(Produto_und A, Produto_und B){
	//Ordenação de rank//
  	if (A.getQuantidadeVendidaUnd() > B.getQuantidadeVendidaUnd()){
	   return true; 
	  }     
	return false;
}

bool ordenaProdutoKgRank(Produto_kg A, Produto_kg B){
	//Ordenação de rank//
  	if (A.getQuantidadeVendidaKg() > B.getQuantidadeVendidaKg()){
	   return true; 
	  }     
	return false;
}	

bool Estoque:: mais_vendidos(){
    // Função para mostrar os 10 mais vendidos.
    getPrintLinhas();
    cout<<"\n                    SMART STORY                     ";
    cout<<"\n              MAIS VENDIDOS PRODUTO UND                    "<<endl;
    getPrintLinhas();
    cout << "\n\n   Código   \tDescrição \t Quantidade \t Seção \t Validade \n\n";
	if(venda_und.size() == 0 and venda_kg.size() == 0){
		return false;
	}
	else{
		sort(Cadastro_und.begin(),Cadastro_und.end(),ordenaProdutoUndRank);
		for(unsigned i = 0; i < 6; i++){
			cout << "   " << setfill(' ') << setw(7) << left << Cadastro_und[i].getCodigo()
			<< setw(20) << left << Cadastro_und[i].getDescricao() 
			<< setw(10) << left << Cadastro_und[i].getQuantidadeUnd() 
			<< setw(15) << left << Cadastro_und[i].getSecao() 
			<< setw(15) << left << Cadastro_und[i].getValidade() << endl;
		}
		cout << "\n\n===================================================================\n\n";
		cout<<"\n              MAIS VENDIDOS PRODUTO KG                    "<<endl;
    	getPrintLinhas();
		sort(Cadastro_kg.begin(),Cadastro_kg.end(),ordenaProdutoKgRank);
		for(unsigned i = 0; i < 6; i++){
			cout << "   " << setfill(' ') << setw(7) << left << Cadastro_und[i].getCodigo()
			<< setw(20) << left << Cadastro_kg[i].getDescricao() 
			<< setw(10) << left << Cadastro_kg[i].getQuantidadeKg() 
			<< setw(15) << left << Cadastro_kg[i].getSecao() 
			<< setw(15) << left << Cadastro_kg[i].getValidade() << endl;	
		}	
		cout << "\n\n===================================================================\n\n";
		return true;
	}
}

bool Estoque:: listar_produtos(){
    // Função para mostrar todos os produtos tanto para UND e KG (VersÃ£o do Cliente)
	getPrintLinhas();
	cout<<"\n                    SMART STORY                     ";
    cout<<"\n              LISTA DE TODOS OS PRODUTOS UND                   "<<endl;
    getPrintLinhas();
    cout << "\n\n  Código  Descrição \t     Preço  \tSeção  \t\tValidade \n\n";
	if(Cadastro_und.size() == 0 and Cadastro_kg.size() == 0){
		return false;
	}
	else{
		for(unsigned i = 0; i < Cadastro_und.size(); i++){
			cout << "   " << setfill(' ') << setw(7) << left << Cadastro_und[i].getCodigo()
			<< setw(20) << left << Cadastro_und[i].getDescricao() 
			<< setw(10) << left << Cadastro_und[i].getPreco() 
			<< setw(15) << left << Cadastro_und[i].getSecao() 
			<< setw(15) << left << Cadastro_und[i].getValidade() << endl;
		}
		getPrintLinhas();
		cout << endl;
		cout<<"\n                   LISTA DE TODOS OS PRODUTOS KG                      "<<endl;
    	getPrintLinhas();
		cout << "\n\n  Código  Descrição \t     Preço  \tSeção  \t\tValidade \n\n";
		for(unsigned i = 0; i < Cadastro_kg.size(); i++){
			cout << "   " << setfill(' ') << setw(7) << left << Cadastro_kg[i].getCodigo()
			<< setw(20) << left << Cadastro_kg[i].getDescricao() 
			<< setw(10) << left << Cadastro_kg[i].getPreco() 
			<< setw(15) << left << Cadastro_kg[i].getSecao() 
			<< setw(15) << left << Cadastro_kg[i].getValidade() << endl;
		}
		getPrintLinhas();
	}
    return true;
}

bool Estoque:: carrinho(){
    // Função para acessar o carrinho.
    int resp;
    while(true){
		system("cls");

    	getPrintLinhas();
    	cout<<"\n                    SMART STORY                     ";
    	cout<<"\n              	    MEU CARRINHO                    "<<endl;
    	getPrintLinhas();
    	cout << "\n\n   1 - Adicionar Produto.\n"
		<< "   2 - Excluir Carrinho. \n"	
   	 	<< "   3 - Finalizar Carrinho.\n"
 	 	<< "   0 - Menu Principal.\n\n";
 	 	getPrintLinhas();
 	 	cout << "\n\n	Digite a opção que deseja realizar: ";
 	 	cin >> resp;

 	 	if(resp == 0){
        	return false;
		}
    	system("cls");

    	switch(resp){
			case 1:
				if(adicionar_produto_carrinho() == 1){
					cout << "\n\n	Produtos adicionados com sucesso. \n\n";
				}
				else{
					cout << "\n\n	Erro ao adicionar produtos no carrinho. Tente novamente! \n\n";
				}
				break;
			
			case 2:
				if(excluir_carrinho() == 1){
					cout << "\n\n	Produtos excluidos com sucesso. \n\n";
				}
				else{
					cout << "\n\n	Erro ao tentar excluir os produtos do carrinho. Tente novamente! \n\n";
				}
				break;
			case 3:
				if(finalizar_carrinho() == 1){
					cout << "\n\n	Pedido finalizado com sucesso. \n\n";
				}
				else{
					cout << "\n\n	Erro ao tentar finalizar o pedido. Tente novamente! \n\n";
				}
				break;
			
			default:
				getPrintLinhas();
				cout << "\n			Smart Store.\n";
	    		getPrintLinhas();
				cout << "\n\n			Opção Inválida !\n";
				cout << " 			Tente novamente. \n\n";
				break;
		}
		
 	 	system("pause");
	}
}

bool Estoque :: meus_pedidos(){
    // Funï¿½ï¿½o para acessar os pedidos.
    return true;
}

bool Estoque:: adicionar_produto_carrinho(){
	// Adiciona Pedido no carrinho.
	Cliente pessoa;
	Produto_und prod_und;
	Produto_kg prod_kg;
	Produto prod;
	double Preco_total;
	double Valor_nota;
	int quantidade_und;
	float quantidade_kg;
	int estoque_und;
	float estoque_kg;
	int codigo; 
	string resp;
	int numero_pedido;
	int verificador;
	
	numero_pedido = prod_und.getNumeroNota() + 1;
	while(true){
		system("cls");
		
		getPrintLinhas();
 		cout<<"\n                    SMART STORY                     ";
    	cout<<"\n             ADICIONAR PRODUTO NO CARRINHO                   "<<endl;
    	getPrintLinhas();
    	cout << "\n\n  Código\tDescrição \tQuantidade \t Preço Unit. \t Preço Total. \n\n";
    	for(unsigned i = 0; i < aux_pedido_und.size(); i++){
			cout << "   " << setfill(' ') << setw(10) << left << aux_pedido_und[i].getCodigo()
			<< setw(25) << left << aux_pedido_und[i].getDescricao() 
			<< setw(15) << left << aux_pedido_und[i].getQuantidadeUnd() 
			<< setw(15) << left << aux_pedido_und[i].getPreco() 
			<< setw(15) << left << aux_pedido_und[i].getPrecoTotal() << endl;
		}
		getPrintLinhas();
		cout<<"\n              		PRODUTOS KG                    ";
		cout << "\n\n  Código\tDescrição \tQuantidade \t Preço Unit. \t Preço Total. \n\n";
		for(unsigned i = 0; i < aux_pedido_kg.size(); i++){
			cout << "   " << setfill(' ') << setw(10) << left << aux_pedido_kg[i].getCodigo()
			<< setw(25) << left << aux_pedido_kg[i].getDescricao() 
			<< setw(15) << left << aux_pedido_kg[i].getQuantidadeKg() 
			<< setw(15) << left << aux_pedido_kg[i].getPreco() 
			<< setw(15) << left << aux_pedido_kg[i].getPrecoTotal() << endl;	
		}	
		getPrintLinhas();
		cout << endl;
		verificador = 0;
		cout << "\n\n	Digite o código que deseja incluir: ";
		cin >> codigo;
		for(unsigned i = 0; i < Cadastro_und.size(); i++){
			if(codigo == Cadastro_und[i].getCodigo()){
				cout << Cadastro_und[i].getDescricao() << "		Valor: " << Cadastro_und[i].getPreco() << endl;
				cout <<	"\n	Digite a quantidade desejada: ";
				cin >> quantidade_und;
				estoque_und = Cadastro_und[i].getQuantidadeUnd() - quantidade_und;
				if(estoque_und < 1){
					return false;
				}
				else{
					Preco_total = quantidade_und * Cadastro_und[i].getPreco();
					Valor_nota = Valor_nota + Preco_total;
					cout << "\n Valor total: " << Preco_total << endl;
					prod_und.setNumeroNota(numero_pedido);
					prod_und.setCpfClienteNota(prod.getCpfClienteNota());
					prod_und.setNomeClienteNota(prod.getNomeClienteNota());
					prod_und.setCodigo(codigo);
					prod_und.setDescricao(Cadastro_und[i].getDescricao());
					prod_und.setEmbalagemUnd(Cadastro_und[i].getEmbalagemUnd());
					prod_und.setQuantidadeUnd(quantidade_und);
					prod_und.setPreco(Cadastro_und[i].getPreco());
					prod_und.setPrecoTotal(Preco_total);
					prod_und.setValorNota(Valor_nota);
					aux_pedido_und.push_back(prod_und);
					verificador=verificador+1;
				}	
			}
		}
		for(unsigned i = 0; i < Cadastro_kg.size(); i++){
			if(codigo == Cadastro_kg[i].getCodigo()){
				cout << Cadastro_kg[i].getDescricao() << "		Valor: " << Cadastro_kg[i].getPreco() << endl;
				cout <<	"\n	Digite a quantidade desejada: ";
				cin >> quantidade_kg;
				estoque_kg = Cadastro_kg[i].getQuantidadeKg() - quantidade_kg;
				if(estoque_kg < 0.1){
					return false;
				}
				else{
					Preco_total = quantidade_kg * Cadastro_kg[i].getPreco();
					Valor_nota = Valor_nota + Preco_total;
					cout << "\n Valor total: " << Preco_total << endl;
					prod_kg.setNumeroNota(numero_pedido);
					prod_kg.setCpfClienteNota(prod.getCpfClienteNota());
					prod_kg.setNomeClienteNota(prod.getNomeClienteNota());
					prod_kg.setCodigo(codigo);
					prod_kg.setDescricao(Cadastro_kg[i].getDescricao());
					prod_kg.setEmbalagemKg(Cadastro_kg[i].getEmbalagemKg());
					prod_kg.setQuantidadeKg(quantidade_kg);
					prod_kg.setPreco(Cadastro_kg[i].getPreco());
					prod_kg.setPrecoTotal(Preco_total);
					prod_kg.setValorNota(Valor_nota);
					aux_pedido_kg.push_back(prod_kg);
					verificador=verificador+1;
				}
			}
		}	
		if(verificador == 0){
			return false;
		}
	}
	return true;
}

bool Estoque:: finalizar_carrinho(){
	// Finaliza pedido no carrinho.
	int estoque_und;
	float estoque_kg;
	Produto Prod;
	string resp;
	
	getPrintLinhas();
 	cout<<"\n                    SMART STORY                     ";
    cout<<"\n             	  FINALIZAR CARRINHO                   "<<endl;
    getPrintLinhas();
    if(aux_pedido_kg.size() != 0 and aux_pedido_und.size() != 0){
    	cout << "\n\n	Deseja finalizar o carrinho, com Nº do pedido " 
		<< aux_pedido_und[0].getNumeroNota() + 1 << " ? S (Sim) / N(Não): ";
		cin >> resp;
		if(resp == "s" or resp == "S"){
			for(unsigned i = 0; i < aux_pedido_und.size(); i++){ // Atualizando estoque.
				if(aux_pedido_und[i].getNumeroNota() < Prod.getNumeroNota()+1){
					aux_pedido_und[i].setNumeroNota(Prod.getNumeroNota()+1);
				}
				for(unsigned j = 0; j < Cadastro_und.size(); j++){
					if(aux_pedido_und[i].getCodigo() == Cadastro_und[j].getCodigo()){
						estoque_und = Cadastro_und[j].getQuantidadeUnd() - aux_pedido_und[i].getQuantidadeUnd();
						if(estoque_und < 0){
							return false;
						}
						else{
							Cadastro_und[j].setQuantidadeUnd(estoque_und);
						}
					}
				}
			}	
			while(!aux_pedido_und.size() == 0){
				Pedido_und.push_back(aux_pedido_und.front());
				aux_pedido_und.erase(aux_pedido_und.begin());
			}
			
			for(unsigned k = 0; k < aux_pedido_kg.size(); k++){ // Atualizando estoque.
				if(aux_pedido_kg[k].getNumeroNota() < Prod.getNumeroNota()+1){
					aux_pedido_kg[k].setNumeroNota(Prod.getNumeroNota()+1);
				}
				for(unsigned n = 0; n < Cadastro_kg.size(); n++){
					if(aux_pedido_kg[k].getCodigo() == Cadastro_kg[n].getCodigo()){
						estoque_kg = Cadastro_kg[n].getQuantidadeKg() - aux_pedido_kg[k].getQuantidadeKg();
						if(estoque_kg < 0){
							return false;
						}
						else{
							Cadastro_kg[n].setQuantidadeKg(estoque_kg);
						}
					}
				}
			}
			while(!aux_pedido_kg.size() == 0){
				Pedido_kg.push_back(aux_pedido_kg.front());
				aux_pedido_kg.erase(aux_pedido_kg.begin());
			}
		}
		return true;
	}	
	else{
		return false;
	}
}

bool Estoque:: excluir_carrinho(){
	// Excluir todos os produto do carrinho.
	string resp;
	
	getPrintLinhas();
 	cout<<"\n                    SMART STORY                     ";
    cout<<"\n             EXCLUIR PRODUTOS DO CARRINHO                   "<<endl;
    getPrintLinhas();
    if(aux_pedido_kg.size() != 0 and aux_pedido_und.size() != 0){
		cout << "\n\n	Todos os produtos do carrinho, com N° do pedido " 
		<< aux_pedido_und[0].getNumeroNota() + 1 << " serão excluídos. ";
		cout << "\n\n 	Deseja Confirmar? S (sim) / N (Não): ";
		cin >> resp;
		if(resp == "s" or resp == "S"){
			while(!aux_pedido_und.size() == 0){
				aux_pedido_und.erase(aux_pedido_und.begin());
			}
			while(!aux_pedido_kg.size() == 0){
				aux_pedido_kg.erase(aux_pedido_kg.begin());
			}	
		}
		return true;
	}
	else{
		return false;
	}
}

bool Estoque::finalizar_pedido(){
	// Finaliza pedido dos clientes.
	Produto Prod;
	
	getPrintLinhas();
 	cout<<"\n                    SMART STORY                     ";
    cout<<"\n             FINALIZAR PEDIDO CLIENTE                   "<<endl;
    getPrintLinhas();
    if(Pedido_und.size() != 0 and Pedido_kg.size() != 0){
    	/*for(int a = 0; a < Prod.getNumeroNota(); a++){
    		for(int b = 0; a < Prod.getNumeroNota(); b++){
				if(ped_cliente.getPedidoUnd()[a].getNumeroNota() != venda_und[b].getNumeroNota() and 
				   ped_cliente.getPedidoKg()[a].getNumeroNota() != venda_kg[b].getNumeroNota()){
					   cout << ped_cliente.getPedidoUnd()[a].getNumeroNota() << "Cliente: " << ped_cliente.getPedidoUnd()[a].getNomeClienteNota();
					   cout << ped_cliente.getPedidoKg()[a].getNumeroNota() << "Cliente: " << ped_cliente.getPedidoKg()[a].getNomeClienteNota();
				   }
			}
		}
		ped_cliente.getPrintLinhas();
    	cout << "\n\n	Deseja finalizar qual pedido de cliente: ";
		cin >> resp;	
		verificador = 0;
		for(unsigned c = 0; c < ped_cliente.getPedidoUnd().size(); c++){
			if(ped_cliente.getPedidoUnd()[c].getNumeroNota() == resp){
				venda_und.push_back(ped_cliente.getPedidoUnd()[c]);
				verificador=verificador+1;
			}
		}	
		for(unsigned d = 0; d < ped_cliente.getPedidoKg().size(); d++){
			if(ped_cliente.getPedidoKg()[d].getNumeroNota() == resp){
				venda_kg.push_back(ped_cliente.getPedidoKg()[d]);
				verificador=verificador+1;
			}
		}
		if(verificador == 0){
			return false;
		}
		else{
			return true;
		}*/
			cout<< "f";
	}	
	else{
		cout<< "g";
	}
	return false;
}

bool Estoque::cancelar_pedido(){
	// Cancela pedido de clientes, caso precise.
	Produto Prod;
	Produto_und prod_und;
	int resp;
	int verificador;
	
	getPrintLinhas();
 	cout<<"\n                    SMART STORY                     ";
    cout<<"\n               EXCLUIR PEDIDO CLIENTE                  "<<endl;
    getPrintLinhas();
    if(Pedido_und.size() != 0 and Pedido_kg.size() != 0){
    	for(int a = 0; a < Prod.getNumeroNota(); a++){
    		for(int b = 0; a < Prod.getNumeroNota(); b++){
				if(Pedido_und[a].getNumeroNota() != venda_und[b].getNumeroNota() and 
				   Pedido_kg[a].getNumeroNota() != venda_kg[b].getNumeroNota()){
					   cout << Pedido_und[a].getNumeroNota() << "Cliente: " << Pedido_und[a].getNomeClienteNota();
					   cout << Pedido_kg[a].getNumeroNota() << "Cliente: " << Pedido_kg[a].getNomeClienteNota();
				   }
			}
		}
		getPrintLinhas();
    	cout << "\n\n	Deseja cancelar qual pedido de cliente: ";
		cin >> resp;	
		verificador = 0;
		for(unsigned c = 0; c < Pedido_und.size(); c++){
			if(Pedido_und[c].getNumeroNota() == resp){
				Pedido_und.erase(Pedido_und.begin()+c);
				verificador=verificador+1;
			}
		}	
		for(unsigned d = 0; d < Pedido_kg.size(); d++){
			if(Pedido_kg[d].getNumeroNota() == resp){
				Pedido_kg.erase(Pedido_kg.begin()+d);
				verificador=verificador+1;
			}
		}
		if(verificador == 0){
			return false;
		}
		else{
			return true;
		}
	}	
	else{
		return false;
	}
}

bool Estoque::add_produto_venda(){
	// Adiciona produto a venda.
    Produto_und prod_und;
    Produto_kg prod_kg;
    Produto prod;
    int quantidade_und;
    float quantidade_kg;
    int estoque_und;
    float estoque_kg;
    double Preco_total;
    double Valor_nota;
    int codigo; 
    string resp;
    int numero_venda;
	string cpf_cliente;
	int verificador;
	numero_venda = prod_und.getNumeroNota() + 1;	

	cout<< "\n\n 	Digite o cpf do cliente que deseja realizar a venda: ";
	cin >> cpf_cliente;
	verificador = 0;
	for(unsigned x = 0; x < Cadastro_Cliente.size(); x++){
		if(cpf_cliente == Cadastro_Cliente[x].getCpfCliente()){
		while(true){
			system("cls");
		
			getPrintLinhas();
 			cout<<"\n                    SMART STORY                     ";
    		cout<<"\n              	  ADICIONAR PRODUTO                    "<<endl;
    		getPrintLinhas();
    		cout<<"\n              		PRODUTOS UND                    ";
    		cout << "\n\n  Código\tDescrição \tQuantidade \t Preço Unit. \t Preço Total. \n\n";
    		for(unsigned i = 0; i < aux_venda_und.size(); i++){
				cout << "   " << setfill(' ') << setw(10) << left << aux_venda_und[i].getCodigo()
				<< setw(25) << left << aux_venda_und[i].getDescricao() 
				<< setw(15) << left << aux_venda_und[i].getQuantidadeUnd() 
				<< setw(15) << left << aux_venda_und[i].getPreco() 
				<< setw(15) << left << aux_venda_und[i].getPrecoTotal() << endl;
			}
			getPrintLinhas();
			cout<<"\n              		PRODUTOS KG                    ";
			cout << "\n\n  Código\tDescrição \tQuantidade \t Preço Unit. \t Preço Total. \n\n";
			for(unsigned i = 0; i < aux_venda_kg.size(); i++){
				cout << "   " << setfill(' ') << setw(10) << left << aux_venda_kg[i].getCodigo()
				<< setw(25) << left << aux_venda_kg[i].getDescricao() 
				<< setw(15) << left << aux_venda_kg[i].getQuantidadeKg() 
				<< setw(15) << left << aux_venda_kg[i].getPreco() 
				<< setw(15) << left << aux_venda_kg[i].getPrecoTotal() << endl;	
			}	
			getPrintLinhas();
			cout << endl;
			verificador = 0;
			cout<< "\n\n Digite o código que deseja incluir: ";
			cin>>codigo;
			for(unsigned i = 0;i < Cadastro_und.size(); i++){
				if(codigo == Cadastro_und[i].getCodigo()){
					cout << Cadastro_und[i].getDescricao() << "		Valor: " << Cadastro_und[i].getPreco() << endl;
					cout << "\n Digite a quantidade desejada: ";
					cin >> quantidade_und;
					estoque_und = Cadastro_und[i].getQuantidadeUnd() - quantidade_und;
					if(estoque_und < 1){
						return false;
					}
					else{	
						Preco_total = quantidade_und * Cadastro_und[i].getPreco();
						Valor_nota = Valor_nota + Preco_total;
						cout <<"\n Valor total: "<<Preco_total<<endl;
						prod_und.setNumeroNota(numero_venda);
						prod_und.setCpfClienteNota(cpf_cliente);
						prod_und.setNomeClienteNota(Cadastro_Cliente[x].getNomeCliente());
						prod_und.setCodigo(codigo);
						prod_und.setDescricao(Cadastro_und[i].getDescricao());
						prod_und.setEmbalagemUnd(Cadastro_und[i].getEmbalagemUnd());
						prod_und.setQuantidadeUnd(quantidade_und);
						prod_und.setPreco(Cadastro_und[i].getPreco());
						prod_und.setPrecoTotal(Preco_total);
						prod_und.setValorNota(Valor_nota);
                		aux_venda_und.push_back(prod_und);
						verificador=verificador+1;
					}	
				}
			}
			for(unsigned i = 0;i < Cadastro_kg.size(); i++){
				if(codigo == Cadastro_kg[i].getCodigo()){
					cout << Cadastro_kg[i].getDescricao() << "		Valor: " << Cadastro_kg[i].getPreco() << endl;
					cout << "\n Digite a quantidade desejada: ";
					cin >> quantidade_kg;
					estoque_kg = Cadastro_kg[i].getQuantidadeKg() - quantidade_kg;
					if(estoque_kg < 0.1){
						return false;
					}
					else{
						Preco_total = quantidade_kg * Cadastro_kg[i].getPreco();
						Valor_nota = Valor_nota + Preco_total;
						cout <<"\n Valor total: "<<Preco_total<<endl;
						prod_kg.setNumeroNota(numero_venda);
						prod_kg.setCpfClienteNota(cpf_cliente);
						prod_kg.setNomeClienteNota(Cadastro_Cliente[x].getNomeCliente());
						prod_kg.setCodigo(codigo);
						prod_kg.setDescricao(Cadastro_kg[i].getDescricao());
						prod_kg.setEmbalagemKg(Cadastro_kg[i].getEmbalagemKg());
						prod_kg.setQuantidadeKg(quantidade_kg);
						prod_kg.setPreco(Cadastro_kg[i].getPreco());   
						prod_kg.setPrecoTotal(Preco_total);
						prod_kg.setValorNota(Valor_nota);
                		aux_venda_kg.push_back(prod_kg);
						verificador=verificador+1;
					}	
				}
			}
			if(verificador == 0){
				return false;
			}
			cout << "\n Deseja adicionar mais algum produto? S (Sim) / N (Não) :";
			cin >> resp;
			if(resp == "n" or resp == "N"){
				break;
			}
		}
		}
		else{
			return false;
		}
		
	}
	if(verificador == 0){
		return false;
	}
	else{
		return true;
	}
	return false;		
}

bool Estoque::finalizar_venda(){
	// Finaliza venda.
	int estoque_und;
	float estoque_kg;
	Produto Prod;
	string resp;
	
	getPrintLinhas();
 	cout<<"\n                    SMART STORY                     ";
    cout<<"\n             	  FINALIZAR VENDA                   "<<endl;
    getPrintLinhas();
    if(aux_venda_kg.size() != 0 or aux_venda_und.size() != 0){
    	cout << "\n\n	Deseja finalizar a venda, com N° de venda: " 
		<< aux_venda_und[0].getNumeroNota() + 1 << " ? S (Sim) / N(Não): ";
		cin >> resp;
		if(resp == "s" or resp == "S"){
			for(unsigned i = 0; i < aux_venda_und.size(); i++){ // Atualizando estoque.
				if(aux_venda_und[i].getNumeroNota() < Prod.getNumeroNota()+1){
					aux_venda_und[i].setNumeroNota(Prod.getNumeroNota()+1);
				}
				for(unsigned j = 0; j < Cadastro_und.size(); j++){
					if(aux_venda_und[i].getCodigo() == Cadastro_und[j].getCodigo()){
						estoque_und = Cadastro_und[j].getQuantidadeUnd() - aux_venda_und[i].getQuantidadeUnd();
						if(estoque_und < 0){
							return false;
						}
						else{
							Cadastro_und[j].setQuantidadeUnd(estoque_und);
							estoque_und = Cadastro_und[j].getQuantidadeVendidaUnd() + aux_venda_und[i].getQuantidadeUnd();
							Cadastro_und[j].setQuantidadeVendidaUnd(estoque_und);
						}
					}
				}
			}	
			while(!aux_venda_und.size() == 0){
				venda_und.push_back(aux_venda_und.front());
				aux_venda_und.erase(aux_venda_und.begin());
			}
			
			for(unsigned k = 0; k < aux_venda_kg.size(); k++){ // Atualizando estoque.
				if(aux_venda_kg[k].getNumeroNota() < Prod.getNumeroNota()+1){
					aux_venda_kg[k].setNumeroNota(Prod.getNumeroNota()+1);
				}
				for(unsigned n = 0; n < Cadastro_kg.size(); n++){
					if(aux_venda_kg[k].getCodigo() == Cadastro_kg[n].getCodigo()){
						estoque_kg = Cadastro_kg[n].getQuantidadeKg() - aux_venda_kg[k].getQuantidadeKg();
						if(estoque_kg < 0){
							return false;
						}
						else{
							Cadastro_kg[n].setQuantidadeKg(estoque_kg);
							estoque_kg = Cadastro_kg[n].getQuantidadeVendidaKg() + aux_venda_kg[k].getQuantidadeKg();
							Cadastro_kg[n].setQuantidadeVendidaKg(estoque_kg);
						}
					}
				}
			}
			while(!aux_venda_kg.size() == 0){
				venda_kg.push_back(aux_venda_kg.front());
				aux_venda_kg.erase(aux_venda_kg.begin());
			}
		}
		return true;
	}	
	else{
		return false;
	}
}

bool Estoque::cancela_venda(){
	// Cancela venda.
	int verificador;
	int numero_nota;
	
		getPrintLinhas();
    	cout<<"\n                    SMART STORY                     ";
    	cout<<"\n                   CANCELA VENDA                   "<<endl;
 	   	getPrintLinhas();
 	   	if(aux_venda_und.size() == 0 and aux_venda_kg.size() == 0){
				return false;
		}
       	cout << "\n\n	Informe o número da venda que deseja excluir: ";
 		cin >> numero_nota;
 		cout << endl << endl;
 		getPrintLinhas();
 		verificador = 0;
  		for(unsigned i = 0; i < aux_venda_und.size(); i++){
           	if(aux_venda_und.size() != 0 and aux_venda_und[i].getNumeroNota() == numero_nota){
            		aux_venda_und.erase(aux_venda_und.begin()+i);
            		verificador=verificador+1;
			}
		}
		for(unsigned i = 0; i < aux_venda_kg.size(); i++){
           	if(aux_venda_kg.size() != 0 and aux_venda_kg[i].getNumeroNota() == numero_nota){
            		aux_venda_kg.erase(aux_venda_kg.begin()+i);
            		verificador=verificador+1;
			}
		}
		if(verificador == 0){
			return false;
		}	
		else{
			return true;
		}
}    

void Estoque:: salvar_arquivos(){
	// Salvar as informações em arquivo txt.

	ofstream arquivo_cliente;
	arquivo_cliente.open("Cliente.txt",ios::trunc);
	// Salvando a lista de clientes.
	if (arquivo_cliente.is_open()){
		for (unsigned i=0;i<Cadastro_Cliente.size();i++){
			arquivo_cliente<<Cadastro_Cliente[i].getCpfCliente()<<endl;
			arquivo_cliente<<Cadastro_Cliente[i].getNomeCliente()<<endl;
			arquivo_cliente<<Cadastro_Cliente[i].getSenhaCliente()<<endl;
			arquivo_cliente<<Cadastro_Cliente[i].getEnderecoCliente()<<endl;
		}
		arquivo_cliente.close();
	}else{
		cout<<"\n 	Não foi possível abrir o arquivo."<<endl;
	}

	ofstream arquivo_funcionario;
	arquivo_funcionario.open("Funcionario.txt",ios::trunc);
	// Salvando a lista de Funcionarios.
	if (arquivo_funcionario.is_open()){
		for (unsigned i=0;i<Cadastro_Funcionario.size();i++){
			arquivo_funcionario<<Cadastro_Funcionario[i].getCpfFuncionario()<<endl;
			arquivo_funcionario<<Cadastro_Funcionario[i].getFuncionario()<<endl;
			arquivo_funcionario<<Cadastro_Funcionario[i].getSenhaFuncionario()<<endl;
		}
		arquivo_funcionario.close();
	}else{
		cout<<"\n	Não foi possível abrir o arquivo."<<endl;
	}

	ofstream arquivo_und;
	arquivo_und.open("ProdutosUnd.txt",ios::trunc);
	// Salvando a lista de clientes.
	if (arquivo_und.is_open()){
		for(unsigned i = 0; i < Cadastro_und.size(); i++){
            arquivo_und <<Cadastro_und[i].getCodigo()<<endl;
			arquivo_und <<Cadastro_und[i].getDescricao()<<endl;
			arquivo_und <<Cadastro_und[i].getPreco()<<endl;
			arquivo_und <<Cadastro_und[i].getSecao()<<endl;
            arquivo_und <<Cadastro_und[i].getFornecedores()<<endl;
			arquivo_und <<Cadastro_und[i].getValidade()<<endl;
			arquivo_und <<Cadastro_und[i].getEmbalagemUnd()<<endl;
			arquivo_und <<Cadastro_und[i].getQuantidadeUnd()<<endl;
			arquivo_und <<Cadastro_und[i].getQuantidadeVendidaUnd()<<endl;
		}
		arquivo_und.close();
	}else{
		cout<<"\n	Não foi possível abrir o arquivo."<<endl;
	}

	ofstream arquivo_kg;
	arquivo_kg.open("ProdutosKg.txt",ios::trunc);
	// Salvando a lista de clientes.
	if (arquivo_kg.is_open()){
		for(unsigned i = 0; i < Cadastro_kg.size(); i++){
            arquivo_kg <<Cadastro_kg[i].getCodigo()<<endl;
			arquivo_kg <<Cadastro_kg[i].getDescricao()<<endl;
			arquivo_kg <<Cadastro_kg[i].getPreco()<<endl;
			arquivo_kg <<Cadastro_kg[i].getSecao()<<endl;
            arquivo_kg <<Cadastro_kg[i].getFornecedores()<<endl;
			arquivo_kg <<Cadastro_kg[i].getValidade()<<endl;
			arquivo_kg <<Cadastro_kg[i].getEmbalagemKg()<<endl;
			arquivo_kg <<Cadastro_kg[i].getQuantidadeKg()<<endl;
			arquivo_kg <<Cadastro_kg[i].getQuantidadeVendidaKg()<<endl;
		}
		arquivo_kg.close();
	}else{
		cout<<"\n	Não foi possível abrir o arquivo."<<endl;
	}
	
	// Salvar arquivos de Pedido.
	
	ofstream arquivo_pedido_und;
	arquivo_pedido_und.open("PedidoUnd.txt",ios::trunc);
	// Salvando a lista de vendas por unidade.
	if (arquivo_pedido_und.is_open()){
		for(unsigned i = 0; i < Pedido_und.size(); i++){
			arquivo_pedido_und <<Pedido_und[i].getNumeroNota()<<endl;
            arquivo_pedido_und <<Pedido_und[i].getCpfClienteNota()<<endl;
			arquivo_pedido_und <<Pedido_und[i].getNomeClienteNota()<<endl;
			arquivo_pedido_und <<Pedido_und[i].getCodigo()<<endl;
			arquivo_pedido_und <<Pedido_und[i].getDescricao()<<endl;
            arquivo_pedido_und <<Pedido_und[i].getQuantidadeUnd()<<endl;
			arquivo_pedido_und <<Pedido_und[i].getPreco()<<endl;
			arquivo_pedido_und <<Pedido_und[i].getPrecoTotal()<<endl;
			arquivo_pedido_und <<Pedido_und[i].getValorNota()<<endl;
		}
		arquivo_pedido_und.close();
	}else{
		cout<<"\n	Não foi possível gravar no arquivo."<<endl;
	}
	
	ofstream arquivo_pedido_kg;
	arquivo_pedido_kg.open("PedidoKg.txt",ios::trunc);
	// Salvando a lista de vendas por unidade.
	if (arquivo_pedido_und.is_open()){
		for(unsigned i = 0; i < Pedido_kg.size(); i++){
			arquivo_pedido_kg <<Pedido_kg[i].getNumeroNota()<<endl;
            arquivo_pedido_kg <<Pedido_kg[i].getCpfClienteNota()<<endl;
			arquivo_pedido_kg <<Pedido_kg[i].getNomeClienteNota()<<endl;
			arquivo_pedido_kg <<Pedido_kg[i].getCodigo()<<endl;
			arquivo_pedido_kg <<Pedido_kg[i].getDescricao()<<endl;
            arquivo_pedido_kg <<Pedido_kg[i].getQuantidadeKg()<<endl;
			arquivo_pedido_kg <<Pedido_kg[i].getPreco()<<endl;
			arquivo_pedido_kg <<Pedido_kg[i].getPrecoTotal()<<endl;
			arquivo_pedido_kg <<Pedido_kg[i].getValorNota()<<endl;
		}
		arquivo_pedido_kg.close();
	}else{
		cout<<"\n	Não foi possível gravar no arquivo."<<endl;
	}  
	
	// Salvar arquivos de venda.
	
	ofstream arquivo_venda_und;
	arquivo_venda_und.open("VendaUnd.txt",ios::trunc);
	// Salvando a lista de vendas por unidade.
	if (arquivo_venda_und.is_open()){
		for(unsigned i = 0; i < venda_und.size(); i++){
			arquivo_venda_und <<venda_und[i].getNumeroNota()<<endl;
            arquivo_venda_und <<venda_und[i].getCpfClienteNota()<<endl;
			arquivo_venda_und <<venda_und[i].getNomeClienteNota()<<endl;
			arquivo_venda_und <<venda_und[i].getCodigo()<<endl;
			arquivo_venda_und <<venda_und[i].getDescricao()<<endl;
			arquivo_venda_und <<venda_und[i].getEmbalagemUnd()<<endl;
            arquivo_venda_und <<venda_und[i].getQuantidadeUnd()<<endl;
			arquivo_venda_und <<venda_und[i].getPreco()<<endl;
			arquivo_venda_und <<venda_und[i].getPrecoTotal()<<endl;
			arquivo_venda_und <<venda_und[i].getValorNota()<<endl;
		}
		arquivo_venda_und.close();
	}else{
		cout<<"\n	Não foi possível gravar no arquivo."<<endl;
	} 
	
	ofstream arquivo_venda_kg;
	arquivo_venda_kg.open("VendaKg.txt",ios::trunc);
	// Salvando a lista de vendas por unidade.
	if (arquivo_venda_und.is_open()){
		for(unsigned i = 0; i < venda_kg.size(); i++){
			arquivo_venda_kg <<venda_kg[i].getNumeroNota()<<endl;
            arquivo_venda_kg <<venda_kg[i].getCpfClienteNota()<<endl;
			arquivo_venda_kg <<venda_kg[i].getNomeClienteNota()<<endl;
			arquivo_venda_kg <<venda_kg[i].getCodigo()<<endl;
			arquivo_venda_kg <<venda_kg[i].getDescricao()<<endl;
			arquivo_venda_kg <<venda_kg[i].getEmbalagemKg()<<endl;
            arquivo_venda_kg <<venda_kg[i].getQuantidadeKg()<<endl;
			arquivo_venda_kg <<venda_kg[i].getPreco()<<endl;
			arquivo_venda_kg <<venda_kg[i].getPrecoTotal()<<endl;
			arquivo_venda_kg <<venda_kg[i].getValorNota()<<endl;
		}
		arquivo_venda_kg.close();
	}else{
		cout<<"\n	Não foi possível gravar no arquivo."<<endl;
	} 
}