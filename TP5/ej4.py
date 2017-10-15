# Informática 2017 - TP5 - Ejercicio 4
#
# Dada la siguiete estructura de datos que representa un listado hipotético
# de alumnos de esta cátedra:
# informática = [...
#               ...]
# Escriba un programa que:
# 1. Agregue un valor a cada alumno con clave 'condición' que indique si
# 'recursa', 'regular' o 'promoción' siguiendo las reglas de evaluación
# descriptas en el programa de la cátedra
# 2. Imprima por pantalla un listado que indique el nombre y la condición
# de cada alumno en forma de lista.
# 3. Indique un resumen estadístico: Total de alumnos, cantidad de alumnos por
# condición y promedio general de todas las notas de todos los alumnos.


def cond(dicc):
    notasfinal = []
    a = 0
    if not dicc['entregoTPs?']:
        return 'recursa'

    for i in dicc['notas']:
        if i < 6:
            notasfinal.append(dicc['recuperatorios'][a])
            a += 1
        else:
            notasfinal.append(i)

    for i in notasfinal:
        if i < 6:
            return 'recursa'

    if notasfinal[0]*0.3 + notasfinal[1]*0.3 + notasfinal[2]*0.4 >= 7:
        return 'promociona'
    else:
        return 'regular'


informatica = [
    {
        'apellido': 'Aronofsky',
        'entregoTPs?': True,
        'notas': [6, 7, 6],
    },
    {
        'apellido': 'Nolan',
        'entregoTPs?': True,
        'notas': [7, 3, 6],
        'recuperatorios': [6],
    },
    {
        'apellido': 'Bielinsky',
        'entregoTPs?': False,
        'notas': [7, 8, 8],
    },
    {
        'apellido': 'Miyazaki',
        'entregoTPs?': True,
        'notas': [4, 4, 6],
        'recuperatorios': [4, 7],
    }
]

for i in informatica:
    i['condicion'] = cond(i)
    print(i['apellido'], end=" ")
    print(i['condicion'])

rec = 0
reg = 0
prom = 0
allnotas = []

for i in informatica:
    if i['condicion'] == 'regular':
        reg += 1
    elif i['condicion'] == 'recursa':
        rec += 1
    elif i['condicion'] == 'promociona':
        prom += 1
    for j in i['notas']:
        allnotas.append(j)
    if 'recuperatorios' in i:
        for j in i['recuperatorios']:
            allnotas.append(j)
sum = 0
for i in allnotas:
    sum = sum + i
promedio = sum/len(allnotas)

print("\nHay %d estudiantes, de los cuales %d promocionan, %d son regulares "
      "y %d recursan" % (len(informatica), prom, reg, rec))

print("El promedio general de todas las notas de todos los alumnos es %.3f"
      % promedio)
