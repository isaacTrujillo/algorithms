tuple = (2, 4, "Zas perros")
setExampple = {2,1,3}
dic = dict(num1 = "num1", num2 = "num2")

def using_tuple(num1, num2, name):
    print("num1: "+str(num1)+", num2: "+str(num2)+" "+name)

def using_set(num1, num2):
    print(num1, num2)

def using_dic(num1, num2):
    print(num1, num2)
    
# using_tuple(*tuple)
# using_set(*setExampple)
# using_dic(**dic)
# print( {x: y for x in tuple for y in setExampple} ) 
a = [1,2,3]
print(a)