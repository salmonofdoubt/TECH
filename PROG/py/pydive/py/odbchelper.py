"""odbchelper.py sample script
"""

__author__ = "Mark Pilgrim (mark@diveintopython.org)"
__version__ = "$Revision: 1.2 $"
__date__ = "$Date: 2004/05/05 21:57:19 $"
__copyright__ = "Copyright (c) 2001 Mark Pilgrim"
__license__ = "Python"

def buildConnectionString(params):
	"""Build a connection string from a dictionary
	Returns string.
	"""
	return ";".join(["%s=%s" % (k, v) for k, v in params.items()])

if __name__ == "__main__":
	myParams = {"server":"mpilgrim", \
				"database":"master", \
				"uid":"sa", \
				"pwd":"secret"
				}
	print(buildConnectionString(myParams))
