# Marcos Eduardo Araújo
# Matr.: 121210541

# Programa deve calcular a aproximação de 𝑒 até um erro absoluto minímo
# O programa deve solicitar o valor de 𝑥 e o erro absoluto minímo
# Use a função exp da biblioteca math para obter o valor real de referência.

print('\n           Série Taylor')
import math
x=float(input('\n Digite um valor pra x: '))
erro_min=float(input('\n Informe o erro minimo absoluto: '))
# Pegando o valor de referencia e colocando valores iniciais pra variaveis
v_ref=math.exp(x)
v_aprx=0
erro_abs=1
i=0
# Iniciando while ate o erro minimo ser alcançado
while not erro_abs<=erro_min :
  fat=math.factorial(i) # Pegando o fatorial
  v_aprx=v_aprx+(x**i)/fat
  erro_abs=math.fabs(v_aprx-v_ref) # Determinando o erro absoluto
  i+=1
print(f'\n O valor aproximado de e^(x) é: {v_aprx}')
print (f'\n O número de interações foi: {i}')

print('\n Obrigado! Saindo do Programa...')