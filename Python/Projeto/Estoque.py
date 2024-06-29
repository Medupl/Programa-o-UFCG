import sqlite3
banco=sqlite3.connect('Controle Estoque.db')
from Cadastro import *
  
# Função para aumentar estoque
def aum_prod():
    with banco:
        ex = banco.cursor()
        cod = verint(' Digite o código do produto: ')
        ex.execute(f"SELECT Descrição FROM PRODUTO WHERE Código={cod}") # Selecionando o Produto.
        prod=ex.fetchall()
        print(f' Descrição: {prod[0][0]}')
        ex.execute(f"SELECT Estoque FROM PRODUTO WHERE Código={cod}") # Puxando estoque do produto.
        est_ant = ex.fetchall()
        print(f' Estoque Atual: {est_ant[0][0]}')
        aum_est = verfloat(' Quantidade: ')
        aum_est = aum_est + float(est_ant[0][0])  # Ajustando estoque e atualizando
        ex.execute(f"UPDATE PRODUTO SET Estoque = ? WHERE Código= ? ", (aum_est, cod))
    return aum_est


# Função para diminuir estoque
def dmn_prod():
    with banco:
        ex = banco.cursor()
        cod = verint(' Digite o código do produto: ')
        ex.execute(f"SELECT Descrição FROM PRODUTO WHERE Código={cod}") # Selecionando o Produto.
        prod = ex.fetchall()
        print(f' Descrição: {prod[0][0]}')
        ex.execute(f"SELECT Estoque FROM PRODUTO WHERE Código={cod}") # Puxando estoque do produto.
        est_ant = ex.fetchall()
        print(f' Estoque Atual: {est_ant[0][0]}')
        dmn_est = verfloat(' Quantidade: ')
        dmn_est = float(est_ant[0][0]) - dmn_est # Ajustando estoque e atualizando
        ex.execute(f"UPDATE PRODUTO SET Estoque = ? WHERE Código= ? ", (dmn_est, cod))
    return dmn_est


# Relatório de produtos
def ajuste_estoque():
    cabecalho('Ajuste Etoque')
    try:
        menu(['Aumentar Estoque','Diminuir Estoque'])
        while True:
            aj=int(input('Qual ajuste deseja fazer: '))
            if aj==1:   # Caso deseje aumentar estoque 
                cabecalho('Aumentar Estoque')
                aum_est=aum_prod()
                print(f' Estoque Atualizado: {aum_est}')
                break
            elif aj==2: # Caso deseje diminuir estoque 
                cabecalho('Diminuir Estoque')
                dmn_est = dmn_prod()
                print(f' Estoque Atualizado: {dmn_est}')
                break
            else:
                print('\033[31mErro: Opção Inválida. Digite novamente\033[m')
    except Exception as erro:
        print(erro)
        print('\033[31mErro: Opção Inválida. Digite novamente\033[m')
        
    
# Função para entrada de produtos por nota de fornecedor.        
def ent_prod():
    try:
        with banco:
            ex = banco.cursor()  # Iniciando a interação com o banco.
            cabecalho('Entrada de Notas')   # Cabeçalho para ajudar no visual.
            cod_forn = verint(' Digite o código do Fornecedor: ')
            ex.execute(f"SELECT Razão_Social FROM FORNECEDOR WHERE Código={cod_forn}")
            forn=ex.fetchall()    # Puxando Fornecedor e mostrando na tela
            print(f' Fornecedor: {forn[0][0]}')
            id_nota=verint(' Digite o N° da nota: ')
            data_emissao=verstr(' Data Emissão: ')
            data_entrada=verstr(' Data Entrada: ')
            vl_nota=verfloat(' Valor total da Nota: ')
            while True:   # Laço para inserir vários produtos numa nota.
                cp=verint(' Digite o código do produto: ')
                ex.execute(f"SELECT Descrição FROM PRODUTO WHERE Código={cp}")
                prod=ex.fetchall()   # Puxando produto e mostrando na tela.
                print(f' Produto: {prod[0][0]}')
                emb=verstr(' Embalagem do produto: ')
                it=verfloat(' Itens na Embalagem: ')
                quant=verfloat(' Quantidade: ')
                preco_custo=verfloat(' Preço Custo: ')
                vl_prod=(quant*preco_custo)
                ent_nota=[cod_forn,forn[0][0],id_nota,data_emissao,data_entrada,cp,prod[0][0],emb,it,quant,preco_custo,vl_prod]
                # ent_nota é uma lista que recebe todos os valores que serão inseridos na tabela.
                entrada=("""INSERT INTO ENTRADA_NOTAS (cod, Fornecedor, N°_nota, Data_Emissão, Data_Entrada, Código_Produto, 
                         Produto, Embalagem, Itens, Quant, Preço_Custo, Custo_Total) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)""")
                ex.execute(entrada,ent_nota)
                ex.execute(f"SELECT Estoque FROM PRODUTO WHERE Código={cp}")
                est_ant = ex.fetchall()
                aum_est = (quant*it) + float(est_ant[0][0]) # Ajuste de estoque
                ex.execute(f"UPDATE PRODUTO SET Estoque = ? WHERE Código= ? ", (aum_est, cp))
                preco_custo=preco_custo/it
                ex.execute(f"UPDATE PRODUTO SET Preço_Custo=%.3f"%preco_custo) # Ajuste de Custo
                sair=verstr(' Deseja Gravar a nota S(SIM): ')
                if sair=='S':
                    break
    except Exception as erro:
        print(erro)
        print('\033[31mErro: Na Entrada da nota.\033[m')
        
        
def saida_prod():
    try:
        with banco:
            ex = banco.cursor()  # Iniciando a interação com o banco.
            cabecalho('Saída de Notas')   # Cabeçalho para ajudar no visual.
            cod_cli = verint(' Digite o código do Cliente: ')
            ex.execute(f"SELECT Nome FROM CLIENTE WHERE Código={cod_cli}")
            cli=ex.fetchall()  # Puxando Cliente e mostrando na tela
            print(f' Fornecedor: {cli[0][0]}')
            id_nota=verint(' Digite o N° da nota: ')
            data_emissao=verstr(' Data Emissão: ')
            data_entrada=verstr(' Data Entrada: ')
            vl_nota=verfloat(' Valor total da Nota: ')
            while True: # Laço para inserir vários produtos numa nota.
                cp=verint(' Digite o código do produto: ')
                ex.execute(f"SELECT Descrição FROM PRODUTO WHERE Código={cp}")
                prod=ex.fetchall()  # Puxando produto e mostrando na tela.
                print(f' Produto: {prod[0][0]}')
                emb=verstr(' Embalagem do produto: ')
                it=verfloat(' Itens na Embalagem: ')
                quant=verfloat(' Quantidade: ')
                preco_custo=verfloat(' Preço Custo: ')
                vl_prod=(quant*preco_custo)
                saida_nota=[cod_cli,cli[0][0],id_nota,data_emissao,data_entrada,cp,prod[0][0],emb,it,quant,preco_custo,vl_prod]
                # saida_nota é uma lista que recebe todos os valores que serão inseridos na tabela.
                entrada=("""INSERT INTO SAIDA_NOTAS (cod, Cliente , N°_nota, Data_Emissão, Data_Entrada, Código_Produto, 
                         Produto, Embalagem, Itens, Quant, Preço_Custo, Custo_Total) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)""")
                ex.execute(entrada,saida_nota)
                ex.execute(f"SELECT Estoque FROM PRODUTO WHERE Código={cp}")
                est_ant = ex.fetchall()
                dmn_est = (quant*it) - float(est_ant[0][0]) # Ajuste de estoque.
                ex.execute(f"UPDATE PRODUTO SET Estoque = ? WHERE Código= ? ", (dmn_est, cp))
                sair=verstr(' Deseja Gravar a nota S(SIM): ')
                if sair=='S':
                    break
    except Exception as erro:
        print(erro)
        print('\033[31mErro: Na Entrada da nota.\033[m')
        
        
# Função para ajustar estoque
def estoque():
    menu(['Ajuste Estoque','Entrada','Saída'])
    while True:
        try:
            ee=int(input('Qual função deseja executar: '))
            if ee==1:
                ajuste_estoque()
                break
            elif ee==2:
                ent_prod()
                break
            elif ee==3:
                saida_prod()
                break
            else:
                print('\033[31mErro: Opção Inválida. Digite novamente\033[m')
        except Exception as erro:
            print(erro)
            print('\033[31mErro: Opção Inválida. 7Digite novamente\033[m')