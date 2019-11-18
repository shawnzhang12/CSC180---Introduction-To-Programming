#XIAOEN (SHAWN) ZHANG, 1005154921 
import random

def genBoard():
   unoccupied_board = [0, 0, 0, 0, 0, 0, 0, 0, 0]
   return unoccupied_board

###########################################################################

def printBoard(T):
#Returns false if T is not of type 'list'
   if not(type(T) == list):
      return False

#Returns false if either the list length or position value is invalid
   if not(len(T) == 9):
      return False
   else: 
      for position in T:
         if not(position == 0) and not(position == 1) and not(position == 2):
            return False

#Assigns board values for list value   
   i = 0
   pT = list(T)
   while i < 9:
      if T[i] == 1:
         pT[i] = "X"
         i = i + 1
      elif T[i] == 2:
         pT[i] = "O"
         i = i + 1
      else:
         pT[i] = str(i)
         i = i + 1
    
#Prints out board as specified, without a space and the end of lines 1, 3, 5
   print(" " + pT[0] + " | " + pT[1] + " | " + pT[2])
   print("---|---|---")
   print(" " + pT[3] + " | " + pT[4] + " | " + pT[5])
   print("---|---|---")
   print(" " + pT[6] + " | " + pT[7] + " | " + pT[8])
   return True
  
###########################################################################

def analyzeBoard(T):
#Returns -1("error") if argument T is not of type 'list'
   if not(type(T) == list):
      return -1

#Returns -1("error") if list length or list values are invalid
   if not(len(T) == 9):
      return -1
   else:
      for position in T:
         if not(position == 0) and not(position == 1) and not(position == 2): 
            return -1

#Returns -1("error") if one player has 2 or more 'placements' than the other
   countx = 0
   counto = 0
   for index in range(0, 9, 1):
      if T[index] == 1:
         countx = countx + 1
      elif T[index] == 2:
         counto = counto + 1

   if (countx - counto) >= 3 or (counto - countx) >= 3:
      return -1

   xwin = 0
   owin = 0
#Checks if there are any 3 X's in a line
   if T[0] == 1 and T[1] == 1 and T[2] == 1:
      xwin = 1
   elif T[3] == 1 and T[4] == 1 and T[5] == 1:
      xwin = 1
   elif T[6] == 1 and T[7] == 1 and T[8] == 1:
      xwin = 1
   elif T[0] == 1 and T[3] == 1 and T[6] == 1:
      xwin = 1
   elif T[1] == 1 and T[4] == 1 and T[7] == 1:
      xwin = 1
   elif T[2] == 1 and T[5] == 1 and T[8] == 1:
      xwin = 1
   elif T[0] == 1 and T[4] == 1 and T[8] == 1:
      xwin = 1
   elif T[2] == 1 and T[4] == 1 and T[6] == 1:
      xwin = 1

#Checks if there are any 3 O's in a line
   if T[0] == 2 and T[1] == 2 and T[2] == 2:
      owin = 2
   elif T[3] == 2 and T[4] == 2 and T[5] == 2:
      owin = 2
   elif T[6] == 2 and T[7] == 2 and T[8] == 2:    
      owin = 2
   elif T[0] == 2 and T[3] == 2 and T[6] == 2:
      owin = 2
   elif T[1] == 2 and T[4] == 2 and T[7] == 2:
      owin = 2
   elif T[2] == 2 and T[5] == 2 and T[8] == 2:
      owin = 2
   elif T[0] == 2 and T[4] == 2 and T[8] == 2:
      owin = 2
   elif T[2] == 2 and T[4] == 2 and T[6] == 2:
      owin = 2

#Returns -1("error") if both X and O win
   if xwin == 1 and owin == 2:
      return -1

#Checks if X or O won over the other
   if xwin == 1 and not(owin == 2):
      return 1
   elif owin == 2 and not(xwin == 1):
      return 2

#Returns 0("board is in play") if there are still unoccupied positions
   for position in T:
      if position == 0:
         return 0

#Returns 3("draw") if all positions are occupied and no player won yet
   drawcheck = True
   for position in T:
      if position == 0:
         drawcheck = False
   if drawcheck == True:
      return 3

#######################################################################

def genNonLoser(T,player):
   if analyzeBoard(T) != 0:
      return -1
   if player != 1 and player != 2:
      return -1
   nT = list(T)

   for position in range(0,9,1):
      if nT[position] == 0:
         nT[position] = 3 - player
         if analyzeBoard(nT) == 3 - player:
            return position
         else:
            nT[position] = 0
   return -1

#########################################################################

def genWinningMove(T,player):
   if analyzeBoard(T) != 0:
      return -1              
   if player != 1 and player != 2:
      return -1
   nT = list(T)
   for position in range(0,9,1):
      if nT[position] == 0:
         nT[position] = player
         if analyzeBoard(nT) == player:
            return position
         else:
            nT[position] = 0
   return -1

########################################################################

def genRandomMove(T,player):
   if analyzeBoard(T) != 0:
      return -1
   if player != 1 and player != 2:
      return -1
   nT = []
   for position in range(0,9,1):
      if T[position] == 0:
         nT = nT + [position]
   playerMove = nT[random.randint(0,len(nT)-1)]
   #print(playerMove)
   return playerMove

########################################################################

def genOpenMove(T,player):
   if analyzeBoard(T) != 0:
      return -1
   if player != 1 and player != 2:
      return -1
   for position in range(0,9,1):
      if T[position] == 0:
         return position
   return -1 
#print(analyzeBoard([1,1,0,2,2,0,0,0,0]))
#print(genOpenMove([1, 0, 0, 2, 1, 0, 2, 0, 0], 1))
