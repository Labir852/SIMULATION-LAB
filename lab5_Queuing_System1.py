import random

customer = int(input("how many customers to take: "))
MDT = float(input("Enter the Mean Deviation value for Time Between Arrival: "))
SDT = float(input("Enter the standard Deviation value for Time Between Arrival: "))
MDS =  float(input("Enter the Mean Deviation value for Service: "))
SDS = float(input("Enter the standard Deviation value For Service: "))



TimeBetArrivals = []
for i in range(0,customer):    
    n = round(random.uniform(-3, 3), 3)
    TimeBetArrivals.append(n)

ServiceTime = []
for i in range(0,customer):    
    n = round(random.uniform(-3,3), 3)
    ServiceTime.append(n)

IAT=[]
CAT=[]
SB=[]
ST = []
SE = []
WT = []
IT = []
for i in range(0,customer):
    iat = round((MDT+SDT*TimeBetArrivals[i]),3)
    IAT.append(iat)
    st = round((MDS + SDS*ServiceTime[i]),3)
    ST.append(st)
    if(i==0):
        CAT.append(IAT[i])
        SB.append(CAT[i])
        SE.append(SB[i]+ST[i])
        WT.append(0.00)
        IT.append(CAT[i])
        continue
    else:
        cat= round((IAT[i]+CAT[i-1]),3)
        CAT.append(cat)
        sb = round((max(SE[i-1],CAT[i])),3)
        SB.append(sb)
        se =  round((SB[i]+ST[i]),3)
        SE.append(se)
        wt = round((SE[i-1]-CAT[i]),3)
        if(wt<0):
            WT.append(0.000)
        else:
            WT.append(wt)
        it = round((CAT[i]-SE[i-1]),3)
        if(it<0):
            IT.append(0.000)
        else:
            IT.append(it)
print("\nIAT = ", IAT )
print("\nCAT = ", CAT )
print("\nSB = ", SB )
print("\nST = ", ST )
print("\nWT = ", WT )
print("\nSE = ", SE )
print("\nIT = ", IT )

sumWT=0
for time in WT:
    sumWT+=time
sumIT=0
for t in IT:
    sumIT+=t

print("Total Time Elapsed: ",CAT[-1], " mins")
print("Total Customer waiting time: ",round(sumWT,3), " mins")
print("Total Server Idle time: ",round(sumIT,3)," mins")

AWT = round((sumWT/customer),3)

print ("Average Waiting Time : ", AWT, " per arrival.")
PCU = round((((SE[-1]-sumIT)/SE[-1])*100),2)
print(f"Percentage Capacity Utilization: {PCU}% ")




