
def strtolist(st1):  # toma un str y devuelve una list de un str por caracter
    lista = [str(x) for x in str(st1)]
    return lista


def listtostr(lista):  # toma una lista de str y da un str con los componentes
    string = ''
    for i in lista:
        string = string + i
    return string


def nbiint(binario):  # recibe una list de str bin y devuelve un int decimal
    # NON-BUILT-IN binario a decimal
    long = len(binario)
    dec = 0
    for i in range(0, long):
        dec = dec + int(binario[-1-i])*2**(i)
    return dec


def nbioct(binario):  # recibe una list de str bin y devuelve un str octal
    # NON-BUILT-IN binario a octal
    long = len(binario)
    aux2 = list(binario)
    while (long % 3 != 0):
        aux2.insert(0, '0')
        long = len(aux2)
    aux = []
    a = 0
    b = 0
    octal = []
    while b < long/3:
        while a < 3:
            aux.append(aux2.pop(0))
            a = a + 1
        octal.append(str(nbiint(aux)))
        aux = []
        b = b + 1
        a = 0
    return listtostr(octal)


def nbihex(binario):
    # NON-BUILT-IN binario a hexadecimal
    long = len(binario)
    aux2 = list(binario)
    while (long % 4 != 0):
        aux2.insert(0, '0')
        long = len(aux2)
    aux = []
    a = 0
    b = 0
    hexad = []
    while b < long/4:
        while a < 4:
            aux.append(str(aux2.pop(0)))
            a = a + 1
        hexad.append(str(nbiint(aux)))
        aux = []
        b = b + 1
        a = 0
    for i in range(0, len(hexad)):
        if hexad[i] == '10':
            hexad[i] = 'A'
        elif hexad[i] == '11':
            hexad[i] = 'B'
        elif hexad[i] == '12':
            hexad[i] = 'C'
        elif hexad[i] == '13':
            hexad[i] = 'D'
        elif hexad[i] == '14':
            hexad[i] = 'E'
        elif hexad[i] == '15':
            hexad[i] = 'F'
    return listtostr(hexad)


binario = input("Ingrese un número en binario\n")
print("Si NO desea usar built-in functions ingrese A")
print("Si desea usar built-in functions ingrese B")
inc = input()

if inc == "a" or inc == "A":  # SIN built-in functions
    binario = tuple(strtolist(binario))  # para que binario no pueda variar
    decimal = nbiint(binario)  # non-built-in bin to decimal
    octal = nbioct(binario)  # non-built-in bin to oct
    hexad = nbihex(binario)  # non-built-in bin to hex
elif inc == "b" or inc == "B":  # CON built-in functions
    decimal = int(binario, 2)
    octal = '%o' % decimal
    hexad = '%X' % decimal

num = [decimal, octal, hexad]
base = ['decimal', 'octal', 'hexadecimal']

for i in range(0, len(num)):
    print("El numero ingresado, en %s, es %s" % (base[i], num[i]))
