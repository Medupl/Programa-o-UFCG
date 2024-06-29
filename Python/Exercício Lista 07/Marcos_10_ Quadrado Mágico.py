#Função para calcular a soma da matriz
def soma_matriz(matriz):
    soma1=0
    soma2=soma1
    soma3=0
    linha=len(matriz)
    coluna=len(matriz[0])
    for i in range(linha):
        for j in range(coluna):
            soma1=soma1+(matriz[i][j])
            if i==j:
                soma3=soma3+(matriz[i][j])
        if (i!=0) and (soma1!=soma2):
            return False
        soma2=soma1
        soma1=0
    if (soma3!=soma2):
        return False
    soma3=0
    for j in range(coluna):
        for i in range(linha):
            soma1=soma1+(matriz[i][j])
            if i+j==coluna-1:
                soma3=soma3+(matriz[i][j])
        if (j!=0) and (soma1!=soma2):
            return False
        soma2=soma1
        soma1=0
    if (soma3!=soma2):
        return False        
    return True


# Função para criar as duas matrizes
def cria_matriz(n) :
    lista = []
    for i in range(n):
        linha = []
        for j in range(n):
            num = int(input(f'[{i},{j}]: '))
            linha.append(num)
        lista.append(linha)
    return lista


# Função Principal para iniciar as Matrizes
def matriz_perfeita():
    while True:
        n=int(input('Digite a dimensão da matriz: '))
        if n<1:
            continue
        else:
            break
    matriz=cria_matriz(n)
    quad_mag=soma_matriz(matriz)
    print(matriz)
    if quad_mag:
        print("\nQuadrado mágico")
    else:
        print("\nNão é quadrado mágico")
            

# Chamando a função principal 
print('             Quadrado Mágico\n')
matriz_perfeita()
print('\n       Obrigado! Saindo do Programa...')