import random
# Função para calcular a média das matrizes.
def media_matriz(matrizF, matrizG):
    mediaMF=0
    mediaMG=0
    linha=len(matrizF)
    coluna=len(matrizF[0])
    for i in range(linha):
        for j in range(coluna):
            mediaMF=mediaMF+(matrizF[i][j])
            mediaMG=mediaMG+(matrizG[i][j])
    mediaMF=mediaMF/(linha*coluna)
    mediaMG=mediaMG/(linha*coluna)
    return mediaMF,mediaMG


# Função para calcular o coeficiente de correlação.
def cc_matriz(matrizF, matrizG):
    mediaMF,mediaMG=media_matriz(matrizF, matrizG)
    prod_var=0
    difMF=0
    difMG=0
    linha=len(matrizF)
    coluna=len(matrizF[0])
    for i in range(linha):
        for j in range(coluna):
            prod_var=prod_var+((matrizF[i][j]-mediaMF)*(matrizG[i][j]-mediaMG))
            difMF=difMF+(matrizF[i][j]-mediaMF)**2
            difMG=difMG+(matrizG[i][j]-mediaMG)**2
    r=prod_var/((difMF*difMG)**(1/2))
    return r


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

    r = cc_matriz(matrizF, matrizG)
    print(f'\n A Coeficiente de Correlação é: {r}')


# Chamando a função principal 
print('             Coeficiente de Correlação\n')
matriz()
print('\n       Obrigado! Saindo do Programa...')