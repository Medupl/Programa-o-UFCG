# Marcos Eduardo Araújo
# Matr.: 121210541

# Programa deve imprimir todos os números da sequência -5 e 5.
# Excluindo zero.

print('\n           Sequência')
seq=-5
lista_seq = []
    # Iniciando o while para imprimir os números.
while seq<=5 :
  lista_seq.append(seq)
  seq+=0.5
lista_seq.remove(0)
print('\n',lista_seq)  
print('\n Obrigado! Saindo do Programa...')