#! /usr/bin/python

class Course():
  def __init__(self,name,max_num_students,students,Room,Schedule):
    self.name = name
    self.max_num_students = int(max_num_students)
    self.students = list(students)
    self.Room = Room
    self.Schedule = Schedule
  
  def add_student(self):
    for x in range(self.max_num_students):
      self.name = raw_input('enter LDAP: ')
      if self.name not in self.students:
        self.students.append(self.name)
  
  def drop_student(self):
    self.name = raw_input('enter LDAP to remove: ')
    if self.name in self.students:
      self.students.remove(self.name)
    else:
      print 'user not found'
  
  def reschedule(self):
    self.Schedule = raw_input('enter new schedule: ')
  
  def change_room(self):
    self.Room = raw_input('enter new room: ')
  
  def number_participants(self):
    print str(len(self.students)-1)

class Intro2Programming(Course):
  def nag_students(self):
    print 'Do your homework!start early!'
  def check_homework(self):
    for x in self.students:
      print x + ' did you do your homework?'

myCourse = Course(name = 'geography',
                  max_num_students = '2',
                  students = ' ',
                  Room = 'yellow',
                  Schedule = '12.00pm')
myCourse.add_student()
myCourse.drop_student()
myCourse.reschedule()
myCourse.change_room()
myCourse.number_participants()

myCourse2 = Intro2Programming(name = 'computing',
                              max_num_students = '3',
                              students = '',
                              Room = 'green',
                              Schedule = '11.00pm') 


myCourse2.add_student()
myCourse2.drop_student()
myCourse2.reschedule()
myCourse2.nag_students()
myCourse2.check_homework()
