# Marcos Eduardo Araújo
# Matr.: 121210541

# Programa deve receber vários números reais no intervalo fechado entre [100, 200].
# Ao final imprima quantos números dentro do intervalo foram digitados 
# e quantos números fora do intervalo (com exceção do zero) foram digitados.

print('\n           Intervalo 100 a 200')
soma_d_int=0
soma_f_int=0
i=0
while True:
    num=float(input('\n Digite um número: '))
    if num==0 : # Comando para parar o while
        break
    i+=1
    if i%10==0 : # Só uma lembraça pro usúario, caso não saiba sair
        print('\n Caso deseje sair digite zero(0).')
    if num>=100 and num<=200 :
        soma_d_int+=1
    else:
        soma_f_int+=1
print(f'\n Foram digitados {soma_d_int} números dentro do intervalo.')
print(f'\n Foram digitados {soma_f_int} números fora do intervalo.')

print('\n Obrigado! Saindo do Programa...')