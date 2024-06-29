# Marcos Eduardo Araújo
# Matr.: 121210541

# Programa deve receber o nome de dois irmãos e sua altura,
# a taxa de crescimento por ano de cada irmão,
# No final, o programa deve imprimir quantos meses serão necessários 
# para que o irmão mais baixo seja maior que o irmão mais alto

print('\n           Altura')
prim_irmao=input('\n Digite o nome do primeiro irmão: ')
seg_irmao=input('\n Digite o nome do segundo irmão: ')
alt_prim_irmao=float(input('\n Informe a altura do primeiro irmão (Metros): '))
alt_seg_irmao=float(input('\n Informe a altura do segundo irmão (Metros): '))
tx_prim_irmao=int(round(float(input('\n Qual a taxa de crescimento anual do primeiro irmão (cm): '))))
tx_seg_irmao=float(input('\n Qual a taxa de crescimento anual do segundo irmão (cm): '))
# Como a altura está em metros e a taxa cm precisamos transformar
alt_prim_irmao*=100
alt_seg_irmao*=100
# Como a taxa foi informada anual e a pergunta está em meses
tx_prim_irmao/=12
tx_seg_irmao/=12
if (alt_prim_irmao>alt_seg_irmao and tx_prim_irmao>tx_seg_irmao) or (alt_seg_irmao>alt_prim_irmao and tx_seg_irmao>tx_prim_irmao) :
    print('\n Não será possível o irmão mais baixo ficar mais alto')
i=0
if alt_prim_irmao>alt_seg_irmao :
    while alt_prim_irmao>=alt_seg_irmao:
        alt_prim_irmao+=tx_prim_irmao
        alt_seg_irmao+=tx_seg_irmao
        i+=1
    print(f'\n Será nescessário {i} meses para {seg_irmao} ser mair que {prim_irmao}.')
elif alt_prim_irmao>alt_seg_irmao :
    while alt_seg_irmao>=alt_prim_irmao:
        alt_prim_irmao+=tx_prim_irmao
        alt_seg_irmao+=tx_seg_irmao
        i+=1
    print(f'\n Será nescessário {i} meses para {prim_irmao} ser mair que {seg_irmao}.')

print('\n Obrigado! Saindo do Programa...')