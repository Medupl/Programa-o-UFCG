import random
def fEAM(matrizF, matrizG):
    dif=0
    linha=len(matrizF)
    coluna=len(matrizF[0])
    for i in range(linha):
        for j in range(coluna):
            dif=dif+abs(matrizF[i][j]-matrizG[i][j])
    EMA=dif/(linha*coluna)
    return EMA


# Função para criar as duas matrizes
def cria_matriz(n) :
    lista = []
    for i in range(n):
        linha = []
        for j in range(n):
            den = random.randint(1,10)
            num = random.randint(1,100)/den
            linha.append(num)
        lista.append(linha)
    return lista


# Função Principal para iniciar as Matrizes
def matriz():
    while True:
        n=int(input('Digite a dimensão da matriz: '))
        if n<1:
            continue
        else:
            break
    matrizF = cria_matriz(n)
    matrizG = cria_matriz(n)
    print(matrizF)
    print(matrizG)

    EMA = fEAM(matrizF, matrizG)
    print(f'\nO Erro médio absoluto é: {str(EMA)}')


# Chamando a função principal 
print('             Erro Médio Quadrático\n')
matriz()
print('\n       Obrigado! Saindo do Programa...')