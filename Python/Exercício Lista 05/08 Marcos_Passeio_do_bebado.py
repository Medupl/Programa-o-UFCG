# Marcos Eduardo Araújo
# Matr.: 121210541

# Em um passeio aleatório unidimensional de um bêbado, a posição 𝑥 do bêbado é computado
# Programa deve  calcula o número de passos necessários para que o caminhante 
# alcance uma fronteira B. O programa deve solicitar ao usuário o valor de B.

print('\n           Passeio do bêbado')
import random
while True:
    frontb=float(input('\n Informe um valor para a fronteira B: '))
    if frontb>0:
        break
    print(' Valor pra B precisa ser maior que zero. Informe novamente.')
i=0
posx=0
while posx<frontb :
    s=random.random()
    posx=posx+s
    i+=1
print(f'\n Foram feitos {i} passos para completar de B>={frontb}.')

print('\n Obrigado! Saindo do Programa...')