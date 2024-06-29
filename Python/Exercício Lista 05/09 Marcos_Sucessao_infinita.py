# Marcos Eduardo Araújo
# Matr.: 121210541

# Programa deve  calcular uma sucessão infinita
# receber um determinado valor para 𝑚 e imprimir na tela o resultado de cada 𝐼𝑛.

print('\n           Sucessão infinita')
import math
e=math.e
vm=int(input('\n Digite um valor para m: '))
cont_n=0
vali=(1/e)*(e-1)
while True:
    print(f'\n O valor de I{cont_n} é: {vali}.')
    vali=1-(cont_n+1)*vali
    if cont_n>=vm:
        break
    cont_n+=1
    
print('\n Obrigado! Saindo do Programa...')