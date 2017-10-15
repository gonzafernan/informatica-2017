def impr(tateti):  # imprime la matriz
    print("\n")
    for i in range(0, 3):
        for j in range(0, 3):
            print(tateti[i][j], " ", end="")
        print("\n")


def iguales(vec):  # si los tres valores de la lista vec son O o X retorna True
    if vec.count('O') == 3 or vec.count('X') == 3:
        return True
    else:
        return False


def inline(tateti):
    aux = []
    for i in tateti:
        if iguales(i):
            return True
    for i in range(0, 3):
        for j in range(0, 3):
            if i == j:
                aux.append(tateti[i][j])
    if iguales(aux):
        return True
    aux = []
    for j in range(0, 3):
        if iguales(aux):
            return True
        aux = []
        for i in tateti:
            aux.append(i[j])
    if tateti[2][0] == tateti[1][1] == tateti[0][2] == 'O':
        return True
    if tateti[2][0] == tateti[1][1] == tateti[0][2] == 'X':
        return True
    return False


def turno(a):  # entrada 'X' o 'O'
    b = 0
    while b < 1:
        i = input("Ingrese fila y columna de su movimiento\n")
        j = input()
        if not i.isnumeric() or not j.isnumeric():
            impr(tateti)
            print("\nFila o columna ingresada no es un número")
            continue
        i = int(i)-1
        j = int(j)-1
        if i not in [0, 1, 2] or j not in [0, 1, 2]:
            print("Coordenada no válida")
            continue
        if tateti[i][j] == 'X' or tateti[i][j] == 'O':
            impr(tateti)
            print("Esa posición ya está ocupada")
            continue
        tateti[i][j] = a
        if inline(tateti):
            impr(tateti)
            print("Ganaste!")
            return True
        impr(tateti)
        break
    return False


def termina(act, a):
    if act:
        return True
    if a == 9:
        print("Empate!")
        return True
    return False


h, k = 3, 3
tateti = [["-" for x in range(h)]for y in range(k)]
a = 0
c = 0
print("\nLas filas y columnas van de 1 a 3")
impr(tateti)
while c < 1:
    act = turno('X')
    a += 1
    if termina(act, a):
        break
    act = turno('O')
    a += 1
    if termina(act, a):
        break
