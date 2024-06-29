# include <iostream>
# include <locale>
# include <string>
# include <iomanip>
# include <vector>
# include <cstdlib>
# include <algorithm>
# include <fstream>

using namespace std;
# include "Cliente.cpp"
# include "Produto.cpp"
# include "ProdutoUND.cpp"
# include "ProdutoKG.cpp"
# include "Funcionario.cpp"
# include "Estoque.cpp"

int main(){

setlocale(LC_ALL,"Portuguese");
Estoque cadastro;
int op;
string senha, login;
string nome_cliente;

	ofstream arquivo_cliente;
	arquivo_cliente.open("Cliente.txt");

	if (!arquivo_cliente){
			cout<<"\n	Não foi possível abrir o arquivo"<<endl;
			return(-1);
	}

	arquivo_cliente.close();

	ofstream arquivo_funcionario;
	arquivo_funcionario.open("Funcionario.txt");

	if (!arquivo_funcionario){
			cout<<"\n	Não foi possível abrir o arquivo"<<endl;
			return(-1);
	}

	ofstream arquivo_prod_und;
	arquivo_prod_und.open("ProdutosUnd.txt");

	if (!arquivo_prod_und){
			cout<<"\n	Não foi possível abrir o arquivo"<<endl;
			return(-1);
	}

	arquivo_prod_und.close();

	ofstream arquivo_kg;
	arquivo_kg.open("ProdutosKg.txt");

	if (!arquivo_kg){
			cout<<"\n	Não foi possível abrir o arquivo"<<endl;
			return(-1);
	}

	arquivo_kg.close();

	ofstream arquivo_pedido_und;
	arquivo_pedido_und.open("PedidoUnd.txt");

	if (!arquivo_pedido_und){
			cout<<"\n	Não foi possível abrir o arquivo"<<endl;
			return(-1);
	}

	arquivo_pedido_und.close();

	ofstream arquivo_pedido_kg;
	arquivo_pedido_kg.open("PedidoKg.txt");

	if (!arquivo_pedido_kg){
			cout<<"\n	Não foi possível abrir o arquivo"<<endl;
			return(-1);
	}

	arquivo_pedido_kg.close();

	ofstream arquivo_venda_und;
	arquivo_venda_und.open("VendaUnd.txt");

	if (!arquivo_venda_und){
			cout<<"\n	Não foi possível abrir o arquivo"<<endl;
			return(-1);
	}

	arquivo_venda_und.close();

	ofstream arquivo_venda_kg;
	arquivo_venda_kg.open("VendaKg.txt");

	if (!arquivo_venda_kg){
			cout<<"\n	Não foi possível abrir o arquivo"<<endl;
			return(-1);
	}

	arquivo_venda_kg.close();

	while(true){
		system("cls");

    	cadastro.getPrintLinhas();
    	cout<<"\n                    SMART STORY                     "<<endl;
    	cadastro.getPrintLinhas();
    	cout<<"\n\n	1 - Fazer cadastro"<<endl
    	<<"	2 - Fazer login"<<endl
    	<<"	0 - Sair\n\n";
    	cadastro.getPrintLinhas();

		cout<<"\n\n	Informe a Opção desejada: ";
    	cin>>op;

    	if(op == 0)
        	break;
    	system("cls");

    	switch(op){
        	case 1:		// Realiza os cadastros dos dados.
                cadastro.getPrintLinhas();
    			cout<<"\n                    SMART STORY                     ";
    			cout<<"\n                   FAZER CADASTRO                     "<<endl;
    			cadastro.getPrintLinhas();
                cout<<"\n\n	1 - Vendedor"<<endl
                <<"	2 - Cliente"<<endl
                <<"	0 - Retornar ao menu principal"<<endl<<endl;
                cadastro.getPrintLinhas();

				cout<<"\n\n	Informe a Opção desejada: ";
                cin>>op;
                system("cls");

                if(op == 0){
                    break;
				}

                else if(op == 1){
					if(cadastro.add_funcionario() == 1){
						cout << "\n	Funcionário cadastrado com sucesso.\n";
					}
					else{
						cout << "\n Erro ao tentar cadastar o funcionï¿½rio.\n";
					}
                }

                else if(op == 2){
					if(cadastro.add_cliente() == 1){
						cout << "\n	Cliente cadastrado com sucesso.\n";
					}
					else{
						cout << "\n Erro ao tentar cadastar o cliente.\n";
					}
                }

                else{
                	cadastro.getPrintLinhas();
                    cout << "\n\n			Opção Inválida !\n";
					cout << " 			Tente novamente. \n\n";
					cadastro.getPrintLinhas();
					cout << endl;
                    break;
                }
				break;

        	case 2:		// Realiza o login dos
            	cadastro.getPrintLinhas();
    			cout<<"\n                    SMART STORY                     ";
    			cout<<"\n                    FAZER LOGIN                     "<<endl;
    			cadastro.getPrintLinhas();
            	cout<<"\n\n	1 - Vendedor"<<endl
                <<"	2 - Cliente"<<endl
                <<"	0 - Retornar ao menu principal"<<endl<<endl;
                cadastro.getPrintLinhas();

				cout<<"\n\n	Informe a Opção desejada: ";
                cin>>op;
                system("cls");

                if(op == 0){
                    break;
				}

                else if(op == 1){
					
                	cadastro.getPrintLinhas();
    				cout<<"\n                    SMART STORY                     ";
    				cout<<"\n                   LOGIN VENDEDOR                   "<<endl;
    				cadastro.getPrintLinhas();
    				cout<<"\n\n	Informe seu login: ";
                	cin>>login;
                	cout<<"\n	Informe sua senha: ";
                	cin>>senha;
					if(cadastro.login_funcionario(senha,login) == 1){
						cadastro.menu_funcionario(login);
					}
					else{
						cout << "\n Erro ao tentar fazer o login do funcionário.\n";
					}
                }

                else if(op == 2){
					int resp;
                	cadastro.getPrintLinhas();
    				cout<<"\n                    SMART STORY                     ";
    				cout<<"\n                   LOGIN CLIENTE                   "<<endl;
    				cadastro.getPrintLinhas();
    				cout<<"\n\n	Informe seu login: ";
                	cin>>login;
                	cout<<"\n	Informe sua senha: ";
                	cin>>senha;
					if(cadastro.login_cliente(senha,login) == 1){
								Produto prod;
								while(true){
									system("cls");

									cout<<"\n                    SMART STORY                     \n";
									cadastro.getPrintLinhas();
									cout << "\n		Seja bem-vindo, " << prod.getNomeClienteNota() << ": ";
									cout<< prod.getNomeClienteNota();
									cout << "\n 	Menu Cliente.\n";
									cadastro.getPrintLinhas();
									cout << "\n\n   1 - Carrinho.\n"
									<< "   2 - Listar Produtos. \n"	
   	 	     						<< "   3 - Mais Vendidos.\n"
 	    	 						<< "   4 - Meus pedidos.\n"
 	 	 	 						<< "   0 - Logout.\n\n";
 	 	 	 						cadastro.getPrintLinhas();
 	 	 	 						cout << "\n\n	Digite a Opção que deseja realizar: ";
 	 	 	 						cin >> resp;

 	 	 	 						if(resp == 0){
        								break;
									}
									system("cls");

									switch(resp){
										case 1:
											// Acionando a função do carrinho.
											if(cadastro.carrinho() == 0){
												break;
											}
										
										case 2:
											// Acionando a lista de mais vendidos.
											if(cadastro.listar_produtos() == 1){
												cout << "\n 	Lista exibida com sucesso.\n";
											}
											else{
												cout << "\n 	Lista vazia. 	Infelizmente não temos Produtos cadastrados!\n";
											}
											break;		

										case 3:
											// Acionando a lista de mais vendidos.
											if(cadastro.mais_vendidos() == 1){
												cout << "\n 	Lista exibida com sucesso.\n";
											}
											else{
												cout << "\n 	Lista vazia. 	Infelizmente não temos venda pra comparar!\n";
											}
											break;

										case 4:
											// Mostrando a lista dos pedidos dos clientes.
											if(cadastro.meus_pedidos() == 0){
												break;
											}

										default:
											cadastro.getPrintLinhas();
											cout << "\n			Smart Store.\n";
											cadastro.getPrintLinhas();
											cout << "\n\n			Opção Inválida !\n";
											cout << " 			Tente novamente. \n\n";
											break;
									}

 	 	 	 						 system("pause");
								}
							
						
					}
					else{
						cout << "\n Erro ao tentar fazer o login do cliente.\n";
					}
				}

                else{
                	cadastro.getPrintLinhas();
                    cout << "\n\n			Opção Inválida !\n";
					cout << " 			Tente novamente. \n\n";
					cadastro.getPrintLinhas();
					cout << endl;
                    break;
                }
                break;

	    	default:
				cadastro.getPrintLinhas();
				cout << "\n			Smart Store.\n";
	    		cadastro.getPrintLinhas();
				cout << "\n\n			Opção Inválida !\n";
				cout << " 			Tente novamente. \n\n";
				break;
		}

		system("pause");
	}
	return 0;
}