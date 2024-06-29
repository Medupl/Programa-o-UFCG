import sqlite3
from Cadastro import *
from Relatórios import *
from Estoque import *

# Criando o banco do nosso programa
banco=sqlite3.connect('Controle Estoque.db')
ex=banco.cursor()
try:
    with banco:
        # Criando tabela de Saída de Notas
        ex.execute("""CREATE TABLE IF NOT EXISTS SAIDA_NOTAS(cod INTEGER, Cliente TEXT, N°_nota INTEGER, Data_Emissão TEXT, Data_Entrada TEXT , 
                  Código_Produto INTEGER, Produto TEXT, Embalagem TEXT, Itens REAL, Quant REAL, Preço_Custo REAL, Custo_Total REAL)""")
        # Criando tabela de Entrada de Notas
        ex.execute("""CREATE TABLE IF NOT EXISTS ENTRADA_NOTAS(cod INTEGER, Fornecedor TEXT, N°_nota INTEGER, Data_Emissão TEXT, Data_Entrada TEXT , 
                  Código_Produto INTEGER, Produto TEXT, Embalagem TEXT, Itens REAL, Quant REAL, Preço_Custo REAL, Custo_Total REAL)""")
        # Criando tabela de Clientes
        ex.execute("""CREATE TABLE IF NOT EXISTS CLIENTE(Código INTEGER, Nome TEXT, CNPJ_CPF TEXT, Endereço TEXT, Bairro TEXT, 
                   Munícipio TEXT, CEP TEXT, UF TEXT, Contato TEXT, Email TEXT)""")
        # Criando tabela da Loja
        ex.execute("""CREATE TABLE IF NOT EXISTS LOJA(Razão_Social TEXT, CNPJ_CPF TEXT, Atividade TEXT, Endereço TEXT, 
                   Bairro TEXT, Munícipio TEXT, CEP TEXT, UF TEXT, Contato TEXT, Email TEXT)""")
        # Criando tabela de Fornecedor
        ex.execute("""CREATE TABLE IF NOT EXISTS FORNECEDOR(Código INTEGER, Razão_Social TEXT, CNPJ_CPF TEXT, Endereço TEXT,
                   Bairro TEXT, Munícipio TEXT, CEP TEXT, UF TEXT, Contato TEXT, Email TEXT)""")
        # Criando tabela de Produtos
        ex.execute("""CREATE TABLE IF NOT EXISTS PRODUTO(Código INTEGER, Descrição TEXT, Seção TEXT, Estoque REAL, Embalagem TEXT,
                   Itens REAL, Preço_Custo REAL, Preço_Venda REAL, PRIMARY KEY('Código'))""")
except Exception as erro:
    print(erro)
    print('\033[31mErro ao criar tabelas.\033[m')

# Chamando Menu do Programa
while True:
    cabecalho('RAMV - Controle Estoque')
    menu(['Cadastro Loja','Cadastro Produto','Cadastro Fornecedor','Cadastro Cliente',
'Relatórios','Estoque','Sair do Sistema'])
    try:
        funcao=int(input('Qual função deseja executar: '))
        if funcao==1:
            cabecalho('Cadastro Loja')
            loja()
        elif funcao==2:
            cabecalho('Cadastro Produto')
            produto()
        elif funcao==3:
            cabecalho('Cadastro Fornecedor')
            fornecedor()
        elif funcao==4:
            cabecalho('Cadastro Cliente')
            cliente()
        elif funcao==5:
            cabecalho('Relatórios')
            relatorio()
        elif funcao==6:
            cabecalho('Estoque')
            estoque()
        elif funcao==7:
            cabecalho('Obrigado! Saindo do Programa...')
            break
        else:
            print('\033[31mErro: Opção Inválida. Digite novamente\033[m')
    except Exception as erro:
        print(erro)
        print('\033[31mErro: Opção Inválida. Digite novamente\033[m')
        continue