#!/usr/bin/python2.6

import re

def main():
  data = {}
  for i in range(1, 8):
    file_text = open('earnest_' + str(i) + '.txt', 'r').read()
    file_text = file_text.replace('\r', '').replace('\n', '')
    lines = re.findall(r'<dl>(.+?)</dl>', file_text)

    for line in lines:
      charac_pattern = r'<strong>\s+<strong>(.+):</strong>\s+</strong>'
      charac_match = re.search(charac_pattern, line)
      character = charac_match.group(1)
      if character not in data:
        data[character] = {'questions': 0,
                           'exclamations': 0,
                           'words': 0,
                           'lines': 1}
      else:
        data[character]['lines'] += 1

      line_pattern = r'<span id=\"imp-\d+-\d+\">(.+)</span>\s+<br/>'
      actual_line_match = re.search(line_pattern, line)
      actual_line = actual_line_match.group(1)

      # Remove stage directions and vocab links
      extraneous_strs = [r'<span class=\"stage\">.+</span>',
                         r'<a href=.+?>']

      for extraneous_str in extraneous_strs:
        extraneous_matches = re.findall(extraneous_str, actual_line)
        for extraneous_match in extraneous_matches:
          actual_line = actual_line.replace(extraneous_match, '')

      # Remove stylistic <em> tags and leftover </a> tags
      stray_tags = ['<em>', '</em>', '</a>']
      for stray_tag in stray_tags:
        actual_line = actual_line.replace(stray_tag, '')

      attr_map = [('questions', r'\?'),
                  ('exclamations', r'!'),
                  ('words', r'(\w+)')]

      for attr in attr_map:
        match_list = re.findall(attr[1], actual_line)
        data[character][attr[0]] += len(match_list)

  print data

if __name__ == '__main__':
  main()
