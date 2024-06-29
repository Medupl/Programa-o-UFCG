# Marcos Eduardo Araújo
# Matr.: 121210541

# Programa deve recebe 5 valores de resistências ligadas em paralelo 
# e retorna a resistência elétrica equivalente da rede de resistores.

print('             Resistência elétrica')
#Criando função para fazer o cálculo.
def r5tot(n):
    i=1
    rt=0
    while not i>n: #Laço para receber os valores.
        r=float(input('\n Digite o valor da resistência: '))
        rt+=1/r
        i+=1
    rt=1/rt
    return rt
n=int(input('\n Digite quantas resistências estão ligadas: '))
#Imprimindo e chamando a função.
print(f'\n A resistência elétrica equivalente da rede é:{r5tot(n)}')

print('\n Obrigado! Saindo do Programa...')