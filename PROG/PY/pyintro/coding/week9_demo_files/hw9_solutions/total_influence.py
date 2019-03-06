import re
import urllib

def ExtractInfo(who_text, data):
  dimensions = [('cost_centers', r'<cost_center_number>(\d+)</cost_center_number'),
                ('ee_types', r'<employee_type>(\w+)</employee_type'),
                ('offices', r'<location>(\w+-\w+)-.+?</location>')]

  for dimension in dimensions:
    datum_match = re.search(dimension[1], who_text)
    if dimension[0] == 'ee_types':
      data[datum_match.group(1).lower()] += 1
    else:
      if datum_match.group(1) not in data[dimension[0]]:
        data[dimension[0]].append(datum_match.group(1))

  return data


def GetReports(parent_ldap, to_crawl, data):
  ldap = to_crawl.pop()
  ldap_who_url = 'https://orginfo.corp.google.com/' + ldap + '?format=xml'
  url_file = urllib.urlopen(ldap_who_url)
  ldap_who_text = url_file.read()
  if ldap != parent_ldap:
    data = ExtractInfo(ldap_who_text, data)

  reportees_match = re.search(r'<reportees>(.+)</reportees>', ldap_who_text)

  # Reportees exist
  if reportees_match:
    reportees_text = reportees_match.group(1)
    reportees = re.findall(r'<email>(\w+)</email>', reportees_text)
    data['total_reportees'] += len(reportees)
    to_crawl.extend(reportees)

  if to_crawl:
    return GetReports(parent_ldap=parent_ldap,
                      to_crawl=to_crawl,
                      data=data)
  else:
    return data

def main():
  ldap = raw_input('Enter an ldap: ')
  results = GetReports(ldap, [ldap], {'cost_centers': [],
                                      'offices': [],
                                      'total_reportees': 0,
                                      'employee': 0,
                                      'intern': 0,
                                      'temp': 0,
                                      'vendor': 0,
                                      'contractor': 0})

  print ''
  print 'Total Reportees: ' + str(results['total_reportees'])
  print 'Total Offices: ' + str(len(results['offices']))
  print 'Total Cost Centers: ' + str(len(results['cost_centers']))
  print 'Total Employees: ' + str(results['employee'])
  print 'Total Interns: ' + str(results['intern'])
  print 'Total Temps: ' + str(results['temp'])
  print 'Total Vendors: ' + str(results['vendor'])
  print 'Total Contractors: ' + str(results['contractor'])


if __name__ == '__main__':
  main()
