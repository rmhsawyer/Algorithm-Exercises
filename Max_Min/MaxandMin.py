import random




def main():
	maximum = -1000
	minimum = 1000
	numberlist = []
	for j in range(0,1000):
		numberlist.append(random.randint(1,10000)) 
	size = len(numberlist)
	i = 0
	while(i<size and i+1 <size):
		if	numberlist[i] <numberlist[i+1]:
			if	numberlist[i]< minimum:
				minimum = numberlist[i]
			if numberlist[i+1] > maximum:
				maximum = numberlist[i+1]
		else:
			if	numberlist[i+1] <minimum:
				minimum= numberlist[i+1]
			if	numberlist[i] >maximum:	
				maximum = numberlist[i]
		i = i+2

	if size%2 != 0:
		if numberlist[size - 1] <minimum:
			minimum = numberlist[size-1]
		if numberlist[size -1]  >maximum:
			maximum = numberlist[size-1]
 

	print("maximum is: %d" % maximum)
	print("minimum is: %d" % minimum)



if __name__ == "__main__":
    main()