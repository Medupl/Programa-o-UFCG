# Marcos Eduardo Araújo
# Matr.: 121210541

# Programa deve solicitar um número real e 
# em seguida o programa imprime a raiz quadrado desse número.

print('\n           Raiz quadrada')
import math     # Importando biblioteca
while True:
    numreal=float(input('\n Digite um número: '))
    if numreal==0 : # Caso digite zero encerra o comando while
        break
    raiz=math.sqrt(numreal)
    print(f' A raiz quadrada é: {raiz}')
    print('\n Caso deseje sair digite zero(0).')

print('\n Obrigado! Saindo do Programa...')