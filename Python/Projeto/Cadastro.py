import sqlite3
banco=sqlite3.connect('Controle Estoque.db')

# Linha para melhor Visualização
def linha(tam=50):
    return ('\033[1m-\033[m')*tam


# Criando o Cabeçalho do projeto
def cabecalho(texto):
    print(linha())
    print(f'\033[1m{texto.center(50)}\033[m')
    print(linha())


# Criando função para o menu
def menu(lista):
    c=1
    for item in lista:
        print(f'\033[1m{c} - {item}\033[m')
        c=c+1
    print(linha())


# Trata o erro de número inteiro
def verint(num):
    while True:
        try:
            n_int=(input(num))
            if n_int.isnumeric():
                break
        except:
            print('\033[31mErro: Opção Inválida. Digite novamente\033[m')
            continue
    return n_int
            

# Trata o erro de valor string 
def verstr(texto):
    while True:
        try:
            v_str=str(input(texto))
        except:
            print('\033[31mErro ao cadastrar as informções.\033[m')
            continue
        if v_str=='':
            continue
        else:
            return v_str.upper()


# Trata o erro de valor float 
def verfloat(txt):
    while True:
        try:
            v_float=float(input(txt))
        except:
            print('\033[31mErro ao cadastrar as informções.\033[m')
            continue
        else:
            return v_float


# Função pra receber as informações de produto.
def produto():
    try:
        ep=[]
        ep.append('%.3d'%(int(verint('Código do Produto: '))))
        ep.append('%.15s'%(verstr('Descrição do Produto: ')))
        ep.append('%.13s'%(verstr('Seção: ')))
        ep.append('%.3f'%(verfloat('Estoque: ')))
        ep.append('%.3s'%(verstr('Embalagem(UN,CX,KG): ')))
        ep.append('%.3f'%(verfloat('Quantidade Itens: ')))
        ep.append('%.3f'%(verfloat('Preço Custo: ')))
        ep.append('%.3f'%(verfloat('Preço Venda: ')))
        with banco:
            ex = banco.cursor()
            # Inserindo Valores na tabela Produto.
            query=(f"INSERT INTO PRODUTO (Código, Descrição, Seção, Estoque, Embalagem, Itens, Preço_Custo, Preço_Venda) VALUES (?, ?, ?, ?, ?, ?, ?, ?)")
            ex.execute(query,ep)
    except Exception as erro:
        print(erro)
        print('\033[31mErro ao cadastrar as informções do Produto\033[m')


# Função pra receber as informações de fornecedor.
def fornecedor():
    try:
        ef=[]
        ef.append('%.3d'%(int(verint('Código do Fornecedor: '))))
        ef.append('%.15s'%(verstr('Nome/Razão Social: ')))
        ef.append('%.14s'%(verint('CNPJ/CPF: ')))
        ef.append('%.16s'%(verstr('Endereço: ')))
        ef.append('%.13s'%(verstr('Bairro: ')))
        ef.append('%.13s'%(verstr('Município: ')))
        ef.append('%.8s'%(verint('CEP: ')))
        ef.append('%.2s'%(verstr('UF: ')))
        ef.append('%.13s'%(verint('Contato: ')))
        ef.append('%.25s'%(verstr('Email: ')))
        with banco:
            ex = banco.cursor()
            # Inserindo Valores na tabela Fornecedor.
            query = ("INSERT INTO FORNECEDOR (Código, Razão_Social, CNPJ_CPF, Endereço, Bairro, Munícipio, CEP, UF, Contato, Email) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)")
            ex.execute(query, ef)
    except Exception as erro:
        print(erro)
        print('\033[31mErro ao cadastrar as informções do Fornecedor.\033[m')


# Função pra receber as informações de cliente.
def cliente ():
    try:
        ec = []
        ec.append('%.3d'%(int(verint('Código do Cliente: '))))
        ec.append('%.15s'%(verstr('Nome/Razão Social: ')))
        ec.append('%.14s'%(verint('CNPJ/CPF: ')))
        ec.append('%.16s'%(verstr('Endereço: ')))
        ec.append('%.13s'%(verstr('Bairro: ')))
        ec.append('%.13s'%(verstr('Município: ')))
        ec.append('%.8s'%(verint('CEP: ')))
        ec.append('%.2s'%(verstr('UF: ')))
        ec.append('%.13s'%(verint('Contato: ')))
        ec.append('%.25s'%(verstr('Email: ')))
        with banco:
            ex = banco.cursor()
            # Inserindo Valores na tabela Cliente.
            query = ("INSERT INTO CLIENTE (Código , Nome, CNPJ_CPF, Endereço, Bairro, Munícipio, CEP, UF, Contato, Email) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)")
            ex.execute(query, ec)
    except Exception as erro:
        print(erro)
        print('\033[31mErro ao cadastrar as informções do Cliente.\033[m')


# Função pra receber as informações da loja.
def loja():
    try:
        el=[]
        el.append('%.15s'%(verstr('Nome/Razão Social: ')))
        el.append('%.14s'%(verint('CNPJ/CPF: ')))
        el.append('%.15s'%(verstr('Atividade Economica(CNAE): ')))
        el.append('%.16s'%(verstr('Endereço: ')))
        el.append('%.13s'%(verstr("Bairro: ")))
        el.append('%.13s'%(verstr('Munícipio: ')))
        el.append('%.8s'%(verint('CEP: ')))
        el.append('%.2s'%(verstr('UF: ')))
        el.append('%.13s'%(verint('Contato: ')))
        el.append('%.25s'%(verstr('Email: ')))
        with banco:
            ex = banco.cursor()
            # Inserindo Valores na tabela Loja.
            query = ("INSERT INTO LOJA (Razão_Social, CNPJ_CPF, Atividade, Endereço, Bairro, Munícipio, CEP, UF, Contato, Email) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)")
            ex.execute(query, el)
    except Exception as erro:
        print(erro)
        print('\033[31mErro ao cadastrar as informções do Produto\033[m')