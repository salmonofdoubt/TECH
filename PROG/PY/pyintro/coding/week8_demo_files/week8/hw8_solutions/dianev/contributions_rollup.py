#!/usr/bin/python2.4

import xlrd
import xlwt

def main():
  # Open workbook
  
  xls_file = xlrd.open_workbook('contributions.xls')
  master_office_list = []
  
  sheet1 = xls_file.sheet_by_name('xls_data')

  # Convert Excel file into a list of lists
  for row_num in range(sheet1.nrows):
    master_office_list.append(sheet1.row_values(row_num))

  del master_office_list[0]
  
  

  # Office_rollup
  office_data = []
  
  # Pull list of offices and filter to a unique list
  for row_num in range(sheet1.nrows):
    office_data.append(sheet1.cell(row_num, 2).value)
    
  unique_office_list = []
  for office in office_data:
    if office in unique_office_list:
      ' '
    else:
      unique_office_list.append(office)

  unique_office_list.remove('OFFICE')

  # Determine data for each office
  office_write_data = [['OFFICE','SUM','MAX','MIN','AVERAGE']] 
 
  for unique_office in unique_office_list:
    my_list = []
    for row in master_office_list:
      if row[2] == unique_office:
        my_list.append(row[5])  
    max_val = max(my_list)
    min_val = min(my_list)
    total_sum = sum(my_list)
    average_val = sum(my_list)/float(len(my_list))
    office_data = []
    office_data.append(str(unique_office))
    office_data.append(str(total_sum))
    office_data.append(str(max_val))
    office_data.append(str(min_val))
    office_data.append(str(average_val))
    office_write_data.append(office_data)
  


  # Region_rollup
  
  region_data = []
  
  # Pull list of regions and filter to a unique list
  for row_num in range(sheet1.nrows):
    region_data.append(sheet1.cell(row_num, 3).value)
    
  unique_region_list = []
  for region in region_data:
    if region in unique_region_list:
      ' '
    else:
      unique_region_list.append(region)

  unique_region_list.remove('REGION')

  # Determine data for each region
  region_write_data = [['REGION','SUM','MAX','MIN','AVERAGE']] 
 
  for unique_region in unique_region_list:
    my_region_list = []
    for row in master_office_list:
      if row[3] == unique_region:
        my_region_list.append(row[5]) 
        
    max_val = max(my_region_list)
    min_val = min(my_region_list)
    total_sum = sum(my_region_list)
    average_val = sum(my_region_list)/float(len(my_region_list))
    region_data = []
    region_data.append(str(unique_region))
    region_data.append(str(total_sum))
    region_data.append(str(max_val))
    region_data.append(str(min_val))
    region_data.append(str(average_val))
    region_write_data.append(region_data)
  


  # OC_rollup
  
  oc_data = []
  
  # Pull list of OC members and filter to a unique list
  for row_num in range(sheet1.nrows):
    oc_data.append(sheet1.cell(row_num, 4).value)
    
  unique_oc_list = []
  for oc in oc_data:
    if oc in unique_oc_list:
      ' '
    else:
      unique_oc_list.append(oc)

  unique_oc_list.remove('OC_MEMBER')

  # Determine data for each OC member
  oc_write_data = [['OC MEMBER','SUM','MAX','MIN','AVERAGE']] 
 
  for unique_oc in unique_oc_list:
    my_oc_list = []
    for row in master_office_list:
      if row[4] == unique_oc:
        my_oc_list.append(row[5]) 
        
    max_val = max(my_oc_list)
    min_val = min(my_oc_list)
    total_sum = sum(my_oc_list)
    average_val = sum(my_oc_list)/float(len(my_oc_list))
    oc_data = []
    oc_data.append(str(unique_oc))
    oc_data.append(str(total_sum))
    oc_data.append(str(max_val))
    oc_data.append(str(min_val))
    oc_data.append(str(average_val))
    oc_write_data.append(oc_data)
  
  
  
  # Writing all data to excel sheet
  target_wb = xlwt.Workbook()
  
  target_sheet = target_wb.add_sheet('office_rollup')
  
  for row_num, row_data in enumerate(office_write_data):
    for col_num, col_value in enumerate(row_data):
      target_sheet.write(row_num, col_num, col_value)
  
  target_sheet = target_wb.add_sheet('region_rollup')
  
  for row_num, row_data in enumerate(region_write_data):
    for col_num, col_value in enumerate(row_data):
      target_sheet.write(row_num, col_num, col_value)
      
  target_sheet = target_wb.add_sheet('oc_rollup')
  
  for row_num, row_data in enumerate(oc_write_data):
    for col_num, col_value in enumerate(row_data):
      target_sheet.write(row_num, col_num, col_value)
  
  target_wb.save('contributions_output.xls')


  
if __name__ == '__main__':
  main()