# Marcos Eduardo Araújo
# Matr.: 121210541

# Programa deve receber o raio r de uma esfera
# Calcular o volume e sua área.

print('             Raio da esfera')
import math
p=math.pi
def vol_esf():  # Calculando volume
    vol=(4/3)*p*(r_esf**3)
    return vol
def area_esf():  # Calculando a área
    area=4*p*(r_esf**2)
    return area
# Recebendo o valor do raio da esfera
while True:
    r_esf=float(input('\n Digite o raio da esfera: '))
    if r_esf==0 or r_esf<0:
        break
    print(' Digite zero(0), caso deseje sair.')
    print(f'\n O volume da esfera é: {vol_esf()}')
    print(f' A área da esfera é: {area_esf()}')

print('\n Obrigado! Saindo do Programa...')