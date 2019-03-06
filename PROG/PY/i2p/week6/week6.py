#! /usr/bin/python

class CashRegister():
  def __init__(self,name,tot_cash,lastTrans,TotTrans):
    self.name = name
    self.tot_cash = tot_cash
    self.lastTrans = lastTrans
    self.TotTrans = TotTrans
	
  def Transact(self):
    self.tot_cash = []
    self.TotTrans = []
    self.lastTrans = int(raw_input('enter money: '))
    self.tot_cash.append(self.lastTrans)
		
		
    for x,y in enumerate(self.tot_cash):
      self.TotTrans.append(x+1)
      print self.TotTrans

  def make_change(self):
			self.TotTrans.replace()
		
  def Empty_out(self):
    del self.tot_cash[:]
			
		
  def Show_last_trans(self):
    print self.lastTrans
		
  def Clear_history(self):
    del self.TotTrans[:]
	
	

my_CashRegister = CashRegister(name = 'peppo',
			       tot_cash = 0,
			       lastTrans = 0,
			       TotTrans = 0)

my_CashRegister.Transact()
my_CashRegister.Empty_out()
my_CashRegister.Show_last_trans()
my_CashRegister.Clear_history()



