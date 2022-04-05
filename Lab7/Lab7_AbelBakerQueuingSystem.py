import random 
n = 4 
IAT = []
IATProb = []
cumIATProb = []
cumIATProbmax = []
cumIATProbmin = []
print("Enter the values for time between arrivals: ")
for i in range(0,n):
    iat =  int(input())
    IAT.append(iat)

print("Enter the probabilities for time between arrivals: ")
for i in range(0,n):
    iat_prob =  float(input())
    iat_prob = round(iat_prob,2)
    IATProb.append(iat_prob)
    if(i==0):
        cumIATProb.append(IATProb[i])
        cumIATProbmin.append(1)
        cumIATProbmax.append(cumIATProb[i]*100)
        
    else:
        cumiatprob = round((IATProb[i] + cumIATProb[i-1]),2)
        cumIATProb.append(cumiatprob) 
        cumIATProbmin.append((cumIATProb[i-1]*100 + 1))
        cumIATProbmax.append(cumIATProb[i]*100)

# service time for Abel  


sa = open("d:\Course Collection E\ACADEMIC\Summer-2021\Simulation & Modeling\Simulation Lab\Lab7\serviceAbel.txt",mode = "r" ,newline = None)
AbelST = []
number = sa.readlines()
for line in number:
            AbelST.append(line.split(",") )
ServiceAbel = []
for sublist in AbelST:
    for item in sublist:
        ServiceAbel.append(item)

for i in range(0,len(ServiceAbel)):
   ServiceAbel[i] = int(ServiceAbel[i])
sa.close()

cumSA = []
ServiceAbelmin = []
ServiceAbelmax = []

for i in range(0,len(ServiceAbel)):
    if(i==0):
        cumSA.append(ServiceAbel[i])
        ServiceAbelmin.append(1)
        ServiceAbelmax.append(cumSA[i]*100)
    else:
        cumsa = round((ServiceAbel[i] + cumSA[i-1]),2)
        cumSA.append(cumSA) 
        ServiceAbelmin.append((cumSA[i-1]*100 + 1))
        ServiceAbelmax.append(cumSA[i]*100)

        



#service time for Baker  


sb = open("d:\Course Collection E\ACADEMIC\Summer-2021\Simulation & Modeling\Simulation Lab\Lab7\servicebaker.txt",mode = "r" ,newline = None)
BakerST = []
number = sb.readlines()
for line in number:
            BakerST.append(line.split(",") )
ServiceBaker = []
for sublist in BakerST:
    for item in sublist:
        ServiceBaker.append(item)

for i in range(0,len(ServiceBaker)):
    ServiceBaker[i] = int(ServiceBaker[i])
sb.close()

cumSB = []
ServiceBakermin = []
ServiceBakermax = []

for i in range(0,len(ServiceBaker)):
    if(i==0):
        cumSB.append(ServiceBaker[i])
        ServiceBakermin.append(1)
        ServiceBakermax.append(cumSB[i]*100)
    else:
        cumsb = round((ServiceBaker[i] + cumSB[i-1]),2)
        cumSA.append(cumSB) 
        ServiceBakermin.append((cumSB[i-1]*100 + 1))
        ServiceBakermax.append(cumSB[i]*100)



# probabilities for Abel


pa = open("d:\Course Collection E\ACADEMIC\Summer-2021\Simulation & Modeling\Simulation Lab\Lab7\probAbel.txt",mode = "r" ,newline = None)
Abelprob = []
number = pa.readlines()
for line in number:
            Abelprob.append(line.split(",") )
ProbAbel = []
for sublist in Abelprob:
    for item in sublist:
        ProbAbel.append(item)

for i in range(0,len(ProbAbel)):
    ProbAbel[i] = float(ProbAbel[i])
pa.close()


# probabilities for Baker    


pb = open("d:\Course Collection E\ACADEMIC\Summer-2021\Simulation & Modeling\Simulation Lab\Lab7\probBaker.txt",mode = "r" ,newline = None)
Bakerprob = []
number = pb.readlines()
for line in number:
            Bakerprob.append(line.split(",") )
ProbBaker = []
for sublist in Bakerprob:
    for item in sublist:
        ProbBaker.append(item)

for i in range(0,len(ProbBaker)):
    ProbBaker[i] = float(ProbBaker[i])
pb.close()


step = int(input("How many Customer should come:  "))

IATrandom = []
for i in range(0,step):
    if (i==0):
        IATrandom.append(0)
    else:    
        iatrandom = random.randint(0,99)
        IATrandom.append(iatrandom)

Servicerandom = []
for i in range(0,step):
    service_random = random.randint(0,99)
    Servicerandom.append(service_random)




IATtable = []

for i in range(0,len(IATrandom)):
    if(i==0):
        IATtable.append(0)
    else:
        if(IATrandom[i]>=cumIATProbmin[i] and IATrandom[i]<=cumIATProbmax[i]):
            IATtable.append(IAT[i])

CAT = []
for i in range(0,len(IATtable[i])):
    if(i==0):
        CAT.append(0)
    else:
        cat = IATtable[i]+CAT[i-1]
        CAT.append(cat)

SBB= []
SBA = []
STA = []
STB= []
SEB = []
SEA = []
WT = []
TS = []
IT = []

for i in range(0,len(Servicerandom)):
    if (i == 0):
        for j in range(0,4):
            if(Servicerandom[j]>=ServiceBakermin[j] and Servicerandom[j]<=ServiceBakermax[j]):
                SBB.append(0)
                STB.append(ServiceBaker[j])
                seb = STB[j]-SBB[j]
                SEB.append(seb)
                WT.append(0)
                TS.append(WT[j]+STB[j])
                IT.append(0)
                SBA.append(0)
                STA.append(0)
                SEA.append(0)


print("IAT = ", IAT)
print("IATprob = ", IATProb)
print("cumIATProb = ", cumIATProb)
print("ServiceAbel = ", ServiceAbel)
print("ServiceBaker = ", ServiceBaker)
print("ProbAbel = ", ProbAbel)
print("ProbBaker = ", ProbBaker)
print("IATRandom = ", IATrandom)
print("ServiceRandom = ", Servicerandom)



    

