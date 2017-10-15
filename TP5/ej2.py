# Escriba un programa que pida un numero positivo de 3 a 6 cifras al
# usuario y luego imprima los 3 números capicúa que se encuentren más cercanos.
# Considerar que los valores capicúa más cercanos pueden ser mayores o
# menores al valor de referencia


def capicua(num):  # recibe un entero y devuelve un valor booleano
    nums = str(num)
    numinv = nums[::-1]  # invierte el string
    if nums == numinv:
        return True
    else:
        return False


ref = input("Ingrese un número positivo de 3 a 6 cifras\n")
if len(ref) < 3 or len(ref) > 6:
    print("Número de cifras no válido, ingrese otro valor")
    quit()

v = []  # list donde se guardan los capicuas mas cercanos
for i in [1, -1]:
    ref2 = int(ref)
    a = 0
    while a < 3:
        ref2 = ref2 + i
        if capicua(ref2):
            a = a + 1
            v.append(ref2)
print(v)
dist = []
for i in v:  # encuentra las distancias de ref a los cap cercanos
    dist.append(abs(int(ref) - i))
print(dist)
# ver caso ref=55555, qué hacemos
ind = 0
a = 0
res = []
while a < 3:
    a = a + 1
    b = min(dist)
    ind = dist.index(b)
    # solucion del caso de 55555??
    # if (a == 2 and dist.count(b) > 1):
    #     a = a - 1
    res.append(v.pop(ind))
    dist.remove(b)
print("Los 3 números capicúa más cercanos a %s son:" % ref)
for i in res:
    print(i)
#
#
#
#
#
#
#
