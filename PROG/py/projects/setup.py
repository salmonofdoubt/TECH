try:
	from setuptools import setup
except ImportError:
	from distutils.core import setup
	
config = {
	'description': 'New Project',
	'author': 'Andre C. Baumann',
	'url': 'URL to get it at.',
	'download_url': 'Where to download it.',
	'author_email': 'andre.c.baumann@gmail.com',
	'version': '0.1',
	'install_requires': ['nose'],
	'packages': ['NAME'],
	'scripts': [],
	'name': 'new projectname'
}
setup(**config)