s=input()
n = len(s)
subtract = 0;
summ = 0
pow_2 = [1]*n
pow_11 = [1]*n
mod = int(10e9+7)

for i in range(1,n):
	pow_11[n-1-i] = (pow_11[n-i]*11)%mod
	pow_2[i] = (pow_2[i-1]*2)%mod;


for i in range(0,n):
	print("i:",i,"pow_2",pow_2[i],"pow_11",pow_11[i])
	temp = (pow_2[i]*pow_11[i])%mod
	temp = (temp*(int(s[i])-int('0')))%mod
	summ = (summ+temp)%mod

	subtract = (10*subtract)%mod
	subtract = (subtract+(int(s[i])-int('0')))%mod

print("sum:",summ,"subtract:",subtract)
print((summ-subtract)%mod)
