s = input()

count = 0
for i in range(len(s)):
	for j in range(i+1,len(s)):
		print("i:",i," j:",j," s: ",s[0:i]+s[j:len(s)])
		count += int(s[0:i]+s[j:len(s)])
	
print(count)
