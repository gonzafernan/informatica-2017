utf8_text = open('No se culpe a nadie.txt', 'r+').read()
unicode_data = utf8_text.decode('utf8')
print len(unicode_data)

lista1 = unicode_data.split(".")
print len(lista1)

lista2 = unicode_data.split(" ")
print len(lista2)
