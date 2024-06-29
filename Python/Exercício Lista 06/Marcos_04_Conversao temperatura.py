# Marcos Eduardo Araújo
# Matr.: 121210541

# Programa deve converte uma temperatura em graus Fahrenheit
# para graus Celsius ou Kelvin

print('             Converter temperatura')
def  convFahr(): 
    if conv=='c' or conv=='C': # Convertendo em Celcius
        cel=(fah-32)*5/9
        print(f'\n A temperatura em Celcius é: {cel}ºC')
    elif conv=='k' or conv=='K': # Convertendo em Kelvin
        kel=(fah-32)*5/9+273.15
        print(f'\n A temperatura em Celcius é: {kel}K')
while True:
    fah=float(input('\n Digite uma temperatura em Fahrenheit: '))
    conv=input('\n Como deseja converter? (C) para Celcius e (K) para Kelvin: ')
    convFahr()
    sair=input(' Deseja continuar? (S) Sim e (N) Não: ')
    if sair=='n' or sair=='N': # Condição para sair.
        break
    
print('\n Obrigado! Saindo do Programa...')