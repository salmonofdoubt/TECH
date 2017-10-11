### BASICS ###
$ awk '{print $2, $1}' names.txt            # prints 2nd and 1st field of each line
                                            # '' talks to shell, {} is the action
$ awk '{print $2$1}' names.txt              # concats
$ awk '{print $2", "$1}' names.txt          # concats

$ awk '{print NF, $0}' names.txt            # NF nuber of fields
$ awk '/up/{print NF, $0}' dukeofyork.txt   # regex, only those containing "up"
$ awk 'NF==6{print NF, $0}' dukeofyork.txt  # only NF == 6
$ awk 'NF==6' dukeofyork.txt                # only NF == 6

$ awk '/up/{print "_up_:", NF, $0} /down/ {print "_down_:", NF, $0}' dukeofyork.txt
                                            # multiple actions

### FLAGS ### 
cat swap 
{print $2, $1}

$ awk -f swap names.txt                     # -f file

$ awk '{print $2}'                          # -F Following argument: detect seperator in input "," 
one,two,three
n/a

$ awk -F, '{print $2}'                      
one,two,three
two 

$ awk Ft '{print $2}'                      
one     two     three
two

$ awk -v hi=hello, '{print hi $2}' names.txt    # -v a variable


### INPUT OUTPUT ### 
awk '{print NF, $0}'                        # waits on stdin (terminal)
awk '{print NF, $0}' < dukeofyork.txt       # takes that file

uptime | awk '{print NF, $0}'               # takes a command's output
                                            # sends to another command, output to file
awk '{print NF, $0}' < dukeofyork.txt | sort -n                                          
awk '{print NF, $0}' < dukeofyork.txt | sort -n > out.txt

### INBUILT VARS FS, RS, OFS, ORS (FIELDS AND RECORDS) ### 
$ cat onebigline.txt                        # , is field sep, ! is record sep
one,two,three!four,five,six!seven,eight,nine!ten,eleven,twelve

$ awk '{FS=","; print $2}'                  # FS input FieldSeperator, ; is a new statement
                                            # so at first execution seperator is space
$ awk 'BEGIN{FS=","} {print $2}'            # hence BEGIN

$ awk 'BEGIN{FS=",";RS="!"} {print $2}' onebigline.txt    
                                            # FS file sep, RS record sep
$ awk 'BEGIN{FS="\n";RS=""} {name=$1;address=$2;citystatezip=$3; \
print name","address","citystatezip}' multiaddress.txt
                                            # FS is new line, RS is blank line 
 
$ cat names.txt
Gretchen Galloway
Isaac Steele
...
                                            # on output: OFS is new line, ORS is blank line
$ awk 'BEGIN{OFS=", ";ORS=" | "} {print $2, $1}' names.txt
Galloway, Gretchen | Steele, Isaac | ...

$ awk 'BEGIN{FS=","; OFS="\t"} {print $1, $2, $3}' nameemailavg.csv
                                            # exercise, note that OFS cannot work on $0

