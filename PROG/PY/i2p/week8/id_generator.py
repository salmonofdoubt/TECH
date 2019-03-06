import random

def main():

	file = open('used_ids.txt','r')
	used_id = []
	for x in file:
		used_id.append(int(x))
	file.close()
	
	while True:
		id = random.randint(100000,999999)
		if id in used_id:
			pass
		else:
			print 'your user id is ' + str(id)
			used_id.append(id)
			break	
	
	file2 = open('used_ids.txt','w')
	for x in used_id:
		file2.write(str(x) + '\n')
	file2.close()

if __name__ == '__main__':
  main()