# Informática 2017 - TP5 - Ejercicio 3
#
# Escriba un programa que abra el siguiente archivo de texto (a descargar de
# http://bit.ly/noseculpeanadie) y retorne las siguientes estadísticas:
# a) Cantidad de caracteres
# b) Cantidad de oraciones. Una oración culmina con un punto.
# c) Cantidad de palabras. Una palabra se separa de la otra por un espacio.
# d) La/s palabra/s de más de 6 caracteres que más veces se repite en el texto.

t = open('No se culpe a nadie.txt', 'r')
texto = t.read()
oraciones = texto.split(".")
palabras = texto.split(" ")
print("En el archivo hay %d caracteres, %d oraciones y %d palabras\n"
      % (len(texto), len(oraciones), len(palabras)))

pal6 = []  # str que contiene las palabras con más de 6 caracteres
pal = []  # str auxiliar (los str son inmutables)

# pasa las mayús a min y elimina puntos, comas y \n de la lista de palabras
for i in palabras:
    pal.append(i.lower().replace(",", "").replace(".", "")
               .replace("\n", ""))

for i in pal:
    if len(i) > 6:
        pal6.append(i)

rep = []  # contiene la cantidad de veces que se repite cada palabra de pal6
for i in pal6:
    rep.append(pal6.count(i))

print('La palabra de más de 6 caracteres que más se repite es "%s"\n'
      % pal6[rep.index(max(rep))])

t.close()
