# 2.Escriba un programa que pida un número positivo de 3 a 6 cifras al usuario y luego
# imprima los 3 números capicúa que se encuentren más cercanos. Considerar que los
# valores capicúa más cercanos pueden ser mayores o menores al valor de referencia

def strtolist(numero):  #convertir una cadena o numero a una lista
    numero_list= [str(x) for x in str(numero)]
    return numero_list


def capicua(num):  #Recibe un entero y devuelve una lista
    i=1  #contador
    numlist = strtolist(num)
    largo = len(numlist)-1
    if len(numlist)> 6 or len(numlist) < 3:  #verifica si el numero ingresado tiene entre 3 y 6 cifras
        print("numero no valido")
        quit()

    num_up = num
    num_down = num
    cap = [0, 0, 0,]
    while i <= 3:
            if numlist[0] == numlist[largo] and numlist[1] == numlist[largo - 1]  and numlist[2] == numlist[largo-2]   and i == 1:
                cap[i-1] = num
                print('capicua nro ',i,' : ',cap[i-1])
                i += 1
            else:
                num_up += 1
                num_down -= 1
                num_up_list = strtolist(num_up)
                num_down_list = strtolist(num_down)
                if num_up_list[0] == num_up_list[len(num_up_list)-1] and num_up_list[1] == num_up_list[len(num_up_list) - 2]  and num_up_list[2] == num_up_list[len(num_up_list)-3]:
                    cap[i-1] = num_up
                    print('capicua nro ',i,' : ',cap[i-1])
                    i += 1
                if len(num_down_list) >= 3:
                    if num_down_list[0] == num_down_list[len(num_down_list)-1] and num_down_list[1] == num_down_list[len(num_down_list) - 2]  and num_down_list[2] == num_down_list[len(num_down_list)-3]:
                        cap[i-1] = num_down
                        print('capicua nro ',i,' : ',cap[i-1])
                        i += 1
                elif len(num_down_list) == 2:  #Para el caso de que el numero sea cercano a 100 y que pueda verificar numeros de 2 cifras
                    if num_down_list[0] == num_down_list[len(num_down_list)-1]:
                        cap[i-1] = num_down
                        print('capicua nro ',i,' : ',cap[i-1])
                        i += 1
    return cap


capicua(587)
