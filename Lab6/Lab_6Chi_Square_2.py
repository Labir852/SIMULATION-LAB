import random
f = open("d:\Course Collection E\ACADEMIC\Summer-2021\Simulation & Modeling\Simulation Lab\Lab6\Lab_6Random_Number.txt",mode = "r" ,newline = None)
randomNumber = []
number = f.readlines()
for line in number:
            randomNumber.append(line.split("\t" or "\n" or " ") )
flat_list = []
for sublist in randomNumber:
    for item in sublist:
        flat_list.append(item)

for i in range(0,len(flat_list)):
    flat_list[i] = int(flat_list[i])

print(type(flat_list[5]))
f.close()

