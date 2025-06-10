import math
import random

largura_matriz = 3
altura_matriz = 3
matriz_principal = []

def ehPrimo(n):
    if n < 2:
        return False
    i = 2
    while i <= math.isqrt(n):
        if n % i == 0:
            return False  # aqui retorna False porque achou divisor
        i += 1
    return True  # é  se não achou divisor

# Inicializando matriz
for i in range(altura_matriz):
    linha_atual = []
    for j in range(largura_matriz):
        linha_atual.append(random.randint(0, 3999))
    matriz_principal.append(linha_atual)

# Printando matriz
for linha in matriz_principal:
    print(linha)

n_primos = 0
# Contando primos
for altura in range(altura_matriz):
    for largura in range(largura_matriz):
        n = matriz_principal[altura][largura]
        if ehPrimo(n):
            n_primos += 1
            print(n)

print(n_primos)
