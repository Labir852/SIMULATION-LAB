import random
n = int(input("Enter the number of random numbers: "))
alpha = float(input("Enter the value of alpha: "))
alpha = round(alpha,2)
Dalpha = float(input("Enter the value of D alpha: "))
Dalpha=round(Dalpha,3)

R = []

for i in range(0,n):
    R.append(round(random.random(),2))

R.sort()
Dp = []
Dm = []

for i in range(0,n):
    a = i/n
    if(a>=R[i]):
        Dp.append(round(a-R[i],2))
    else:
        Dp.append(0)
    if(i==0):
        Dm.append(R[i])
        continue
    else:
        b = (i-1)/n
        if(R[i]>=b):
            Dm.append(round(R[i]-b,2))
        else:
            Dm.append(0)

DpMax = max(Dp)
DmMax = max(Dm)

D = max(DpMax,DmMax)

print("n= ",n)
print("alpha = ",alpha)
print("Dalpha = ",Dalpha)
print("Given Random numbers are: ",R)
print("D+ = ",Dp ,"\n and maximum of D+ is ", DpMax)
print("D- = ",Dm,"\n and maximum of D- is ", DmMax)
print("Largest Deviation D = ",D)


if(D < Dalpha):
    CL= int(round(1-alpha,2)*100)
    print(f"Given random numbers are uniform at {CL}% confidence level")
else:
    print("Given random numbers are not uniform")