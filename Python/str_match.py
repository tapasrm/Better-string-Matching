def str_match(t,p):
	n=len(t)
	m=len(p)
	i=0
	while i<n :
		j=0
		k=p[0]
		while t[i]==p[j]:
			k+=p[j+1]
			i+=1
			j+=1
			if(j>=m or i>=n):
				break
			print("Found : ", k)
			if(k == p) :
				print("Pattern found at "+str((i-m)+1))
				i-=1
				k=''
		if(i<n and t[i]==p[0]):
			continue
		i+=1


t = 'dddddddddddddddddddddddd'
p = 'lazy'
str_match(t,p)