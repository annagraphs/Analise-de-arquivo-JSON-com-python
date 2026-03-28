import json # biblioteca pra trabalhar com o arquivo

with open('dados.json', 'r', encoding='utf-8') as arquivo_valores: # abre o arquivo e o armazena
    dados = json.load(arquivo_valores)

valores = [] # cria o vetor que vai receber os valores do arquivo

for i in dados: # looping para percorrer os dados do arquivo
    valores.append(i['valor']) # aloca os valores no vetor

# auxiliares para descobrir maior e menor
numMaior = valores[0]
numMenor = valores[0]

for j in valores:
    if j > numMaior:
        numMaior = j
    if j < numMenor and j != 0:
        numMenor = j

print(f"esse é o maior valor que podemos encontrar no histórico de faturamento diário {numMaior}")
print(f"esse é o menor valor que podemos encontrar no histórico de faturamento diário {numMenor}")

# auxiliares para descobrir media, soma dos valores dividida pela quantidade de valores
soma = sum(valores)
mediaMensal = soma / len(valores)
contador = 0

# contador de quantas vezes o valor diário excedeu o valor da média
for k in valores:
    if k > mediaMensal:
        contador += 1

print(f"Essa é a quantidade de dias nos quais o faturamento diário foi maior que a média mensal: {contador}")
