import csv



def main():
  data_file = open('contributions.csv','rU')
  dictReader_data= csv.DictReader(data_file)
  dict_data = {}
  list1 = []
  list2 = []
	
	
  for row_dict in dictReader_data:
    list1.append(row_dict)	
	
  for x in list1:
    list2.append(x['OFFICE'])
	 
  data_file = open('contributions.csv','rU')
  dictReader_data= csv.DictReader(data_file)
  dict_data = {}
  list3 = []
  list4 = []
	
  for row_dict in dictReader_data:
    list3.append(row_dict)
		
  for row_dict in list3:
    list4.append(row_dict['CONTRIBUTION'])

  z = zip(list2,list4)

  for x in z:
    new_dict[x] = dict(x)
	
  print new_dict
	

if __name__ == '__main__':
	main()

