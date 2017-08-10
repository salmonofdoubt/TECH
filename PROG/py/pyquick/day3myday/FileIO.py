#!/usr/bin/python

# Let's create a file and write it to disk.
filename = "test.dat"
# Let's create some data:
done = 0
namelist = []
while not done:
  name = raw_input("Enter a name:")
  if type(name) == type(""):
    namelist.append(name)
  else:
    break
    
# Create a file object:
# in "write" mode
FILE = open(filename,"w")

# Write all the lines at once:
FILE.writelines(namelist)
    
# Alternatively write them one by one:
for name in namelist:
    FILE.write(name)
    
FILE.close()




# This is the standard boilerplate that calls the main() function.
if __name__ == '__main__':
  main()
