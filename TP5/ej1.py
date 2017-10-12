def bin_int(binario, l):
    ent = 0
    count = 0
    for i in binario:
        count = count + 1
        a = int(i)
        ent = ent + a * (2 ** (l - count))
    return ent


def bin_oct(binario, l):
    while l % 3 != 0:
        binario.insert(0, '0')
        l = len(binario)
    i = 0
    octal = []
    suma = []
    l = len(binario)
    while i < l / 3:
        suma = [binario[3 * i], binario[3 * i + 1], binario[3 * i + 2]]
        aux = bin_int(suma, 3)
        octal.append(str(aux))
        i = i + 1
    i = 0
    suma = ""
    for i in octal:
        suma = suma + i
    return suma


def bin_hex(binario, l):
    while l % 4 != 0:
        binario.insert(0, '0')
        l = len(binario)
    i = 0
    hexdec = []
    suma = []
    l = len(binario)
    while i < l / 4:
        suma = [binario[4 * i], binario[4 * i + 1], binario[4 * i + 2], binario[4 * i + 3]]
        aux = bin_int(suma, 4)
        if aux == 10:
            aux = 'A'
        elif aux == 11:
            aux = 'B'
        elif aux == 12:
            aux = 'C'
        elif aux == 13:
            aux = 'D'
        elif aux == 14:
            aux = 'E'
        elif aux == 15:
            aux = 'F'
        hexdec.append(str(aux))
        i = i + 1
    i = 0
    suma = ""
    for i in hexdec:
        suma = suma + i
    return suma


print("Elija opcion (1) para utilizar built-in functions.")
print("Elija opcion (2) para no utilizar built-in functions.")
opcion = input()
print("Introducir binario:")
binario = input()
if opcion == '1':
    entero = int(binario, 2)
    print("Binario a entero: " + str(entero))
    hexdec = '%X' % entero
    print("Binario a hexadecimal: " + str(hexdec))
    octal = '%o' % entero
    print("Binario a octal: " + str(octal))
elif opcion == '2':
    binario = [str(x) for x in str(binario)]
    l = len(binario)
    entero = bin_int(binario, l)
    print("Binario a entero: " + str(entero))
    octal = bin_oct(binario, l)
    print("Binario a octal: " + octal)
    hexdec = bin_hex(binario, l)
    print("Binario a hexadecimal: " + hexdec)
