binario = '11011010111'
opcion = 2
if opcion == 1:
    entero = int(binario, 2)
    print("Binario a entero: " + str(entero))
    hexdec = '%X' % entero
    print("Binario a hexadecimal: " + str(hexdec))
    octal = '%o' % entero
    print("Binario a octal: " + str(octal))
elif opcion == 2:
    l = len(binario)
    ent = 0
    count = 0
    for i in binario:
        count = count + 1
        a = int(i)
        ent = ent + a * (2 ** (l - count))

    print("Binario a entero: " + str(ent))
