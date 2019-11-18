#######XIAOEN (SHAWN) ZHANG, 1005154921
from tttlib import *
T = genBoard()
while True:
   printBoard(T)
   moveX = input("X move?")

#Same as: not(moveX == 0) or not(moveX == 1) or not(moveX == 2) ... or not (moveX == 8) 
   if not(moveX in ["0", "1", "2", "3", "4", "5", "6", "7", "8"]): 
      print("Invalid input")
      break
 
   if not(T[int(moveX)] == 1) and not(T[int(moveX)] == 2):
      T[int(moveX)] = 1
   else:
      print("Invalid input")
      break

   state = analyzeBoard(T)
   if state == 1:
      print("X won")
      printBoard(T)
      break
   elif state == 3:
      print("draw")
      printBoard(T)
      break
     
   printBoard(T)
   moveO = input("O move?")

   if not(moveX in ["0", "1", "2", "3", "4", "5", "6", "7", "8"]): 
      print("Invalid input")
      break

   if not(T[int(moveO)] == 1) and not(T[int(moveO)] == 2):
      T[int(moveO)] = 2
   else:
      print("Invalid input")
      break

   state = analyzeBoard(T)
   if state == 2:
      print("O won")
      printBoard(T)
      break
   elif state == 3:
      print("draw")
      printBoard(T)
      break
