#!/usr/bin/env python
# encoding: utf-8
"""
url_class..py
Created by André Baumann on 2011-12-13.
Copyright (c) 2011 __MyCompanyName__. All rights reserved.
"""

import os
import sys
import urllib

dir_name = 'python-downloads_http'
dir_name_http = 'python-downloads_http'
dir_name_ftp	= 'python_downloads_ftp'

class Downloader(object):
	def __init__(self, base_dir):
		self._base_dir = base_dir

	def _get(self, url):
		f = urllib.urlopen(url)
		data = f.read()
		f.close()
		return data

	def _save(self, data, destination):
		if os.path.exists(destination):
			return

		f = open(destination, 'w')
		f.write(data)
		f.close()

	def download(self, url):
		data = self._get(url)
		savefile_name = os.path.basename(url)	 # Not great (? and what not), but I
																					 # want to keep it simple.
		destination = os.path.join(self._base_dir, savefile_name)
		self._save(data, destination)
		return os.path.getsize(destination)


class Factory(Downloader):				# subclass to deal with available downloaders	
	def AvailableDownloaders(self, url):
		
		if url.startswith('http://' or 'ftp://'):
			pass
		
		else: raise UnsupportedURL('No suitable downloader available')		
		return
		

if __name__ == '__main__':
	if not os.path.isdir(dir_name):
		os.mkdir(dir_name)

	http_downloader = Downloader(dir_name_http)	# calls Downloader class
	ftp_downloader = Downloader(dir_name_ftp)
	
	while True:
		print '>>>',
		url = raw_input()
		AvailableDownloaders(url)
		
		if url.startswith('http://'):
			downloader = http_downloader
		if url.startswith('ftp://'):
			downloader = ftp_downloader
		else: 
			#pass factory class
			pass
	
		size = downloader.download(url)
		print 'Done (%d bytes).' % size

	#  Sample URLs:
	# 'http://docs.python.org/library/os.html'
	# 'http://www.prguitarman.com/comics/poptart1red1.gif'