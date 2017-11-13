# La empresa de mantenimiento La pinturita desea calcular calcular la cantidad
# latas de pintura necesarias del mismo color para pintar las paredes de todas
# las habitaciones de una casa. Se conoce la siguiente información. Las puertas
# son de 0.75 x 2.00 m (ancho x alto) y las ventanas sond e 1.20 x 1.50 m. La
# pintura tiene las siguientes características:
# - Cada litro rinde (por mano): 14 m**2. Viene en latas de 1,4,10 y 20 litros
# La información variable consiste de:
# -ancho, largo y alto de cada habitación
# -Cantidad de cada tipo de aberturas en cada habitación
# -Cantidad de manos a pintar
# El programa debe determinar la cantidad de latas de pintura a utilizar de
# manera tal que se minimice el costo total, informando al usuario dicho costo
# La lata de 1L cuesta $50, la de 4L cuesta $170, la de 10L cuesta $400 y la de
# 20L cuesta $700. Observe que mientras menos latas se compren menos se paga.

ancho = float(input("Ingrese el ancho, largo y alto de la habitación, "
                    "en metros\nAncho="))
largo = float(input("Largo="))
alto = float(input("Alto="))
puertas = float(input("Ingrese cantidad de puertas y ventanas, en ese orden\n"
                "Puertas="))
ventanas = float(input("Ventanas="))
manos = int(input("Ingrese cantidad de manos a pintar\nCantidad de manos="))
area_a_pintar = manos*(2*(ancho*alto + largo*alto) - puertas*1.5 -
                       ventanas*1.8)
litros = area_a_pintar/14
l20 = litros//20
l10 = (litros % 20) // 10
l4 = ((litros % 20) % 10) // 4
l1 = (((litros % 20) % 10) % 4)//1
if (((litros % 20) % 10) % 4) % 1 < 1:
    l1 = l1 + 1
costo = l20*700 + l10*400 + l4*170 + l1*50

print("El precio total será de $%.2f" % costo)
print("Habrá que comprar %d latas de 20L, %d latas de 10L, %d latas de 4L"
      "y %d latas de 1L" % (l20, l10, l4, l1))
