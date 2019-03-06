mport os, sys, urllib
savepath = '/home/$USER/.checkurls/'

errormsg = '%s: %s: No such file or directory'
urlspath = savepath + 'urls.txt'
for path in savepath, urlspath:
	if not os.path.exists(path):
		print errormsg % (__file__, path)
		sys.exit(0)
urlfile = open(urlspath, 'r').readlines(); urlstring = ''
for url in urlfile:
	if not 'http://' in url:
		url = 'http://' + url
	url = url.replace('\n', '')
	filename = url.replace('/', '%2f')
	if '-v' in sys.argv:
		print '%s: %s ...' % (__file__, url)
	if not os.path.isfile(savepath + filename):
		urllib.urlretrieve(url, savepath + filename)
	filelines = open(savepath + filename, 'r').readlines()
	urllines = urllib.urlopen(url).readlines()
	if not filelines == urllines:
		open(savepath + filename, 'w').writelines(urllines)
		urlstring += '"' + url + '" '

if urlstring:
	os.popen('firefox ' + urlstring)
else:
	if '-v' in sys.argv:
		print '%s: nothing for today' % __file__
