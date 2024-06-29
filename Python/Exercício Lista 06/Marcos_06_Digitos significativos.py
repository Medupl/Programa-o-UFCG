# Marcos Eduardo Araújo
# Matr.: 121210541

# Programa deve receber um inteiro e mostre quantos dígitos significativos 
# este inteiro possui. 

print('             Digitos Significativos')
def conta_digitos(num):
    i=1
    while (num//10)>0:
        i+=1
        num=num//10
    return i 
num=int(input('\n Digite um número inteiro: '))
print(f'\n O número {num} possui {conta_digitos(num)} digitos.')

print('\n Obrigado! Saindo do Programa...')