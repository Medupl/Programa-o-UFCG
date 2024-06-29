import sqlite3
banco=sqlite3.connect('Controle Estoque.db')
from Cadastro import *

# Relatório de produtos
def relatorio_produto():
    cabecalho('Produtos')
    print('Cod.''  Descrição    ''   Seção    ''     Est. ''  Emb. '' Itens''  Custo''   Venda')
    print(f'{linha()}------------------')
    try:
        with banco:
            ex=banco.cursor()
            ex.execute("SELECT * FROM PRODUTO") # Selecionaando tabela de Produto.
            rel_prod=ex.fetchall()
            ql = len(rel_prod)  # Usando len para saber quantas linhas tem na tabela Produto.
            for i in range(ql): # Usando o for para imprimir todas as linhas
                print(f'{rel_prod[i][0]:<5}{rel_prod[i][1]:<16}{rel_prod[i][2]:<15}{rel_prod[i][3]:<8}{rel_prod[i][4]:<6}{rel_prod[i][5]:<6}{rel_prod[i][6]:<8}{rel_prod[i][7]:<8}')
    except Exception as erro:  # Essa parte de ":<5" é o alinhamento a esquerda com 5 caracteres.
        print(erro)
        print('\033[31mErro ao exibir as informções do Produto\033[m')


# Relatório de fornecedores
def relatorio_fornecedor():
    cabecalho('Fornecedor')
    print(f'{linha()}{linha()}{linha()}')
    print('Cod.'' Fornecedor   ''      CNPJ/CPF    ''   Endereço   ''    Bairro ''         Município    ''  CEP''     UF''   Contato   ''        E-mail')
    print(f'{linha()}{linha()}{linha()}')
    try:
        with banco:
            ex = banco.cursor()
            ex.execute("SELECT * FROM FORNECEDOR") # Selecionaando tabela de Fornecedor.
            rel_forn = ex.fetchall()
            ql = len(rel_forn)  # Usando len para saber quantas linhas tem na tabela Fornecedor.
            for i in range(ql): # Usando o for para imprimir todas as linhas
                print(f'{rel_forn[i][0]:<5}{rel_forn[i][1]:<17}{rel_forn[i][2]:<14}{rel_forn[i][3]:<17}{rel_forn[i][4]:<15}{rel_forn[i][5]:<15}{rel_forn[i][6]:<10}{rel_forn[i][7]:<4}{rel_forn[i][8]:<15}{rel_forn[i][9]:<25}')
    except Exception as erro:  # Essa parte de ":<5" é o alinhamento a esquerda com 5 caracteres.
        print(erro)
        print('\033[31mErro ao exibir as informções do Fornecedor\033[m')


# Relatórios de Clientes
def relatorio_cliente():
    cabecalho('Cliente')
    print(f'{linha()}{linha()}{linha()}')
    print('Cod.''  Cliente     ''      CNPJ/CPF    ''   Endereço   ''   Bairro  ''       Município    ''  CEP''     UF''   Contato   ''        E-mail')
    print(f'{linha()}{linha()}{linha()}')
    try:
        with banco:
            ex = banco.cursor()
            ex.execute("SELECT * FROM CLIENTE")
            rel_cl = ex.fetchall()
            ql = len(rel_cl)     # Usando len para saber quantas linhas tem na tabela Cliente.
            for i in range(ql):  # Usando o for para imprimir todas as linhas.
                print(f'{rel_cl[i][0]:<5}{rel_cl[i][1]:<17}{rel_cl[i][2]:<14}{rel_cl[i][3]:<15}{rel_cl[i][4]:<15}{rel_cl[i][5]:<15}{rel_cl[i][6]:<10}{rel_cl[i][7]:<4}{rel_cl[i][8]:<15}{rel_cl[i][9]:<25}')
    except Exception as erro:   # Essa parte de ":<5" é o alinhamento a esquerda com 5 caracteres.
        print(erro)
        print('\033[31mErro ao exibir as informções do Cliente\033[m')


# Relatório de entrada de produtos por nota
def relatorio_ent_prod():
    cabecalho('Entrada de produtos por nota')
    print(f'{linha()}{linha()}{linha()}')
    print('Cód.' '  Fornecedor' '     N° da nota' '   Data Emissão' ' Data Entrada'  '   Cód. Prod.' '   Produto' '   Embalagem' '   Itens' '   Quant.' '   Preço Custo' '   Custo Total')
    print(f'{linha()}{linha()}{linha()}')
    try:
        with banco:
            ex=banco.cursor() # Iniciando interação com o banco
            ex.execute("SELECT * FROM ENTRADA_NOTAS") # Selecionando tabela de Entrada de Notas.
            rel_ent=ex.fetchall()
            ql= len(rel_ent) # Usando len para saber quantas linhas tem na tabela Entrada de Notas.
            for i in range(ql): # Usando o for para imprimir todas a linhas.
                print(f'{rel_ent[i][0]:<5}{rel_ent[i][1]:<17}{rel_ent[i][2]:<12}{rel_ent[i][3]:<15}{rel_ent[i][4]:<18}{rel_ent[i][5]:<7}{rel_ent[i][6]:<15}{rel_ent[i][7]:<9}{rel_ent[i][8]:<8}{rel_ent[i][9]:<11}{rel_ent[i][10]:<13}{rel_ent[i][11]:<8}')
    except Exception as erro:
        print(erro)
        print('\033[31mErro ao exibir as informções da entrada de produtos por nota\033[m')


# Relatório de saída de produtos por nota
def relatorio_sai_prod():
    cabecalho('Saída de produtos por nota')
    print(f'{linha()}{linha()}{linha()}')
    print('Cód.' '     Cliente  ' '     N° Nota' '    Data Emissão' '   Data Ent.'  '    Cód. Prod.' '   Produto' '   Embalagem' '   Itens' '   Quant.' '   Preço Custo' '   Custo Total')
    print(f'{linha()}{linha()}{linha()}')
    try:
        with banco:
            ex=banco.cursor() # Iniciando interação com o banco
            ex.execute("SELECT * FROM SAIDA_NOTAS") # Selecionando tabela de Saída de  Notas.
            rel_sai=ex.fetchall()
            ql= len(rel_sai) # Usando len para saber quantas linhas tem na tabela Saída de Notas.
            for i in range(ql): # Usando o for para imprimir todas a linhas.
                print(f'{rel_sai[i][0]:<5}{rel_sai[i][1]:<20}{rel_sai[i][2]:<9}{rel_sai[i][3]:<15}{rel_sai[i][4]:<18}{rel_sai[i][5]:<7}{rel_sai[i][6]:<15}{rel_sai[i][7]:<9}{rel_sai[i][8]:<8}{rel_sai[i][9]:<11}{rel_sai[i][10]:<13}{rel_sai[i][11]:<8}')
    except Exception as erro:
        print(erro)
        print('\033[31mErro ao exibir as informções da saída de produtos por nota\033[m')


# Função para gerar relatórios
def relatorio():
    menu(['Produto','Fornecedor','Cliente','Entrada Nota','Saída Nota'])
    while True:
        try:
            er=int(input('Qual função deseja executar: '))
            if er==1:
                relatorio_produto()
                break
            elif er==2:
                relatorio_fornecedor()
                break
            elif er==3:
                relatorio_cliente()
                break
            elif er == 4:
                relatorio_ent_prod()
                break
            elif er == 5:
                relatorio_sai_prod()
                break
            else:
                print('\033[31mErro: Opção Inválida. Digite novamente\033[m')
        except Exception as erro:
            print(erro)
            print('\033[31mErro: Opção Inválida. Digite novamente\033[m')