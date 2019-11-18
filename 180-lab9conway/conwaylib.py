import random 

class conway:
   def __init__(self, list1, list2, val):
      self.list1 = list1
      self.list2 = list2
      self.store = []  
      self.nextstate = []
      for i in range(0,list1,1):
         list2var = []
         nextstatevar = []
         for j in range(0,list2,1):
            nextstatevar += [0]
            if val == "zeros":
               list2var = list2var + [0]
            elif val == "random":
               list2var = list2var + [random.randint(0,1)]
            else:
               print("ERR: not a valid value")
         self.store = self.store + [list2var]
         self.nextstate = self.nextstate + [nextstatevar]

   def getDisp(self):
      conwaystr = ""
      for i in self.store:
         list2str = ""
         for j in i:
            if j == 1:
               list2str = list2str + "*"
            elif j == 0:
               list2str = list2str + " "
            else:
               return False
         conwaystr = conwaystr + list2str + "\n"
      return conwaystr

   def printDisp(self):
      if self.getDisp() == False:
         return False
      else:
         print(self.getDisp())
         return True

   def setPos(self,row,col,val):
      if val != 0 and val!= 1:
         return False
      elif row > len(self.store)-1 or col > len(self.store[0])-1:
         return False
      else:
         self.store[row][col] = val
         return True

#assume that accessing the [-1] index of a list returns the last value in the list
   def getNeighbors(self,row,col):
      accum = []
      if row > len(self.store)-1 or col > len(self.store[0])-1:
         return False
      for i in range(-1,2,1):
         for j in range(-1,2,1):
            if i == 0 and j == 0:
               accum = accum
            elif (row + i > len(self.store)-1) and (col + j > len(self.store[0])-1):
               accum += [self.store[0][0]]
            elif row + i > len(self.store)-1:
               accum += [self.store[0][col+j]]
            elif col + j > len(self.store[0])-1:
               accum += [self.store[row+i][0]]
            else:
               accum += [self.store[row+i][col+j]]
              
      return accum

   def evolve(self, rule):      
      for i in range(0,self.list1,1):
         for j in range(0,self.list2,1): 
            self.nextstate[i][j] = rule(self.store[i][j],self.getNeighbors(i,j))

      for i in range(0,self.list1,1):
         self.store[i] = list(self.nextstate[i])
      return True

def main():
   x=conway(1,1,"random")
   print(x.setPos(1,0,1))
   x.printDisp()
   print(x.getNeighbors(1,0))

#main()
