# Escriba un programa que pida un número positivo de 3 a 6 cifras al usuario y luego
# imprima los 3 números capicúa que se encuentren más cercanos. Considerar que los
# valores capicúa más cercanos pueden ser mayores o menores al valor de referencia.

def capicua(numero):
    """Recibe un número o cadena, obtiene su cadena invertida y verifica si ésta es capicua"""
    cadena = str(numero)
    invert = cadena[::-1]
    if cadena == invert:
        print("cadena: ", cadena, "Invertida: ", invert)
        return True
    else:
        return False

ingreso = True
while ingreso:
    referencia = int(input("Ingrese un número positivo de 3 a 6 cifras\n"))
    # Verificación de longitud de número ingresado
    if len(str(referencia)) < 3 or len(str(referencia)) > 6:  # Se utiliza str para poder validar el comando len
        print("Número no válido.\n")
    else:
        ingreso = False

# Obtención  de números capicúa
cont = 0  # Contador de números capicúa superiores
valores = []  # Lista contenedora de números capicúa
# ' numero2 = numero.copy() '  Comando utilizado para copiar listas. Probablemente utilizable para variables
# referencia = int(numero)  Otra opción para copiar valores por valor
numero = referencia + 1
numero2 = referencia - 1
while cont < 3:
    if capicua(numero):
        cont += 1
        valores.append(numero)
    numero += 1
cont = 0  # Contador de números capicúa inferiores
while cont < 3:
    if capicua(numero2):
        cont += 1
        valores.append(numero2)
    numero2 -= 1
# print("valores: ", valores) #  PRINT DE PRUEBA!!

# Obtención de los 3 números capicúa más cercanos al número referencia
cont = 0  # Contador posicional de la lista valores
capicua_final = [0] * 4  # Lista de capicúas finales ordenados
for i in valores:  # i también puede entenderse como valores[cont]
    if cont < 3:
        capicua_final[cont] = i
    else:  # Luego de tener 3 valores fijos en la lista capicua_final, se insertarán los valores en la lista si estos están
           # más cerca de la referencia que los prefijados. Cabe aclarar que los únicos valores que serán impresos son los primeros 3 o 4
        if abs(i - referencia) <= abs(capicua_final[0] - referencia):
            capicua_final.insert(0, i)
        elif abs(i - referencia) <= abs(capicua_final[1] - referencia):
            capicua_final.insert(1, i)
        elif abs(i - referencia) <= abs(capicua_final[2] - referencia):
            capicua_final.insert(2, i)
    # print("Iteración: ", cont, "\ncapicua_final: ", capicua_final)  # PRINT DE PRUEBA!!
    cont += 1

# Print de los 3 o 4 capicúas más cercanos al número referencia
if abs(capicua_final[2] - referencia) == abs(capicua_final[3] - referencia):
    print("Valores capicúa más cercanos (4): ", capicua_final[0:4])
else:
    print("Valores capicúa más cercanos (3): ", capicua_final[0:3])
# print("abs(capicua_final[2] - referencia): ", abs(capicua_final[2] - referencia), "\nabs(capicua_final[3] - referencia): ", abs(capicua_final[3] - referencia))  # PRINT DE PRUEBA!!
