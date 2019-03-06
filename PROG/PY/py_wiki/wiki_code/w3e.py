#!/usr/bin/env python
# MAKE A FEW CALCULATIONS
print ('\nMAKE A FEW CALCULATIONS\n')

# Distance / rate
raw_input("1.Input a rate and a distance")
rate = float(input("Rate: "))
distance =float(input("Distance: "))
print ('Time:', distance/rate,'\n')
raw_input ()

# Rectangle
raw_input("2.Calculate information about a rectangle")
length = float(input("Length: "))
width = float(input("Width: "))
print ('Area', length * width)
print ('Perimeter', 2 * length + 2 * width,'\n')
raw_input ()

# Converts Fahrenheit to Celsius
raw_input("3. Convert Fahrenheit to Celsius")
temp = float(input("T (F): "))
print ('\nT (C): ', (temp - 32.0) * 5.0 / 9.0, '\n\n')
raw_input("   exit")
print ('\n')
