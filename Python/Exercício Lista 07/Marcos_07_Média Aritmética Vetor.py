import random
# Função para calcular a média aritmética do vetor.
def media_vetor(x):
    mediaV=0
    n=len(x)
    for i in range(n):
        mediaV=mediaV+x[i]
    mediaV=mediaV/n
    return mediaV


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
    mediaV=media_vetor(x)
    print(f'\n A média aritmética do Vetor X é: {mediaV}')


# Chamando a função principal 
print('             Média Aritmética Vetor\n')
vetor()
print('\n       Obrigado! Saindo do Programa...')