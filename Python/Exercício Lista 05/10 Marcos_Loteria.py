# Marcos Eduardo Araújo
# Matr.: 121210541

# Em um jogo de loteria, o apostador deve selecionar 3 (três) números 
# de uma lista de interios no intervalo de [0; 100].  A ordem do sorteio importa.
# Escreva um programa capaz de simular uma partida 
# e calcular a quantidade de jogadas necessárias para acertar um determinado jogo pré definido.

print('\n           Loteria')
import random
while True:
    print('\n Informe Valores no intervalo [0,100]')
    sort01=int(input(' Informe o primeiro número que foi sorteado : '))
    sort02=int(input(' Informe o primeiro número que foi sorteado: '))
    sort03=int(input(' Informe o primeiro número que foi sorteado: '))
    # O while só para de rodar quando os valores estiverem dentro do intervalo.
    if sort01>=0 and sort01<=100 and sort02>=0 and sort02<=100 and sort03>=0 and sort03<=100 :
        break
    print(' Valor precisa está dentro do intervalo [0,100]. Informe novamente.')
i=0
while True:
    # Usando random pra simular um sorteio da loteria.
    bola01=random.randint(0,100)
    bola02=random.randint(0,100)
    bola03=random.randint(0,100)
    i=i+1
    # Comando só para quando os valores forem iguais.
    if (sort01==bola01) and (sort02==bola02) and (sort03==bola03) :
        break
print(f'\n Foram necessárias {i} jogadas aleatórias para ganhar o jogo: {sort01}, {sort02} e {sort03}.')

print('\n Obrigado! Saindo do Programa...')