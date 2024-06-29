import random
# Função para calcular o EMQ
def cal_emq(matrizF, matrizG):
    dif=0
    linha=len(matrizF)
    coluna=len(matrizF[0])
    for i in range(linha):
        for j in range(coluna):
            dif=dif+(matrizF[i][j]-matrizG[i][j])**2
    emq=dif/(linha*coluna)
    return emq


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

    emq = cal_emq(matrizF, matrizG)
    print(f'\nO Erro Médio Quadrático (EMQ) é: {str(emq)}')


# Chamando a função principal 
print('             Erro Médio Quadrático\n')
matriz()
print('\n       Obrigado! Saindo do Programa...')