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
