# Marcos Eduardo Araújo
# Matr.: 121210541

# Programa deve receber números enquanto forem positivos e no final 
# imprime quantos números foram digitados e a média de todos os numeros digitados.

print('\n           Números positivos')
cont=0
media=0
i=0
while True:
    num=float(input('\n Digite um número positivo: '))
    if num<=0 :
        break
    i+=1
    if i%3==0: # Comando pra lembrar úsuario pra não tornar o programa chato.
        print('\n Caso deseje sair digite zero(0).')
    cont=cont+1
    media=media+num
print(f'\n Foram digitados {cont} números.')
print(f'\n A média dos números digitados é: {media/cont}')

print('\n Obrigado! Saindo do Programa...')