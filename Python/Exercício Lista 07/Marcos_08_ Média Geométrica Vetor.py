import random
# Função para calcular a média aritmética do vetor.
def media_vetor(x):
    prod=1
    n=len(x)
    for i in range(n):
        prod=prod*x[i]
    mediaG=prod**(1/n)
    return mediaG


# Função para criar o vetor
def criar_vetor(n):
    x=[]
    for i in range(n):
        num=random.uniform(0,100)
        x.append(num)
    return x


# Função Principal para iniciar o vetor
def vetor():
    while True:
        n=int(input('Quantos índices o vetor terá: '))
        if n<1:
            continue
        else:
            break
    x=criar_vetor(n)
    mediaG=media_vetor(x)
    print(f'\n A média geométrica do Vetor X é: {mediaG}')


# Chamando a função principal 
print('             Média Geométrica Vetor\n')
vetor()
print('\n       Obrigado! Saindo do Programa...')