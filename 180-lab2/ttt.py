#XIAOEN (SHAWN) ZHANG, 1005154921
from tttlib import *
T = genBoard()

while True:
   printBoard(T)
   moveX = input("X move?")
   if not (moveX in ["0", "1", "2", "3", "4", "5", "6", "7", "8"]):
      print("Invalid input")
      break

   if T[int(moveX)] != 1 and T[int(moveX)] != 2:
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

   moveO = genWinningMove(T,2)
   if moveO == -1:
      moveO = genNonLoser(T,2)
   if genNonLoser(T,2) == -1:
      moveO = genRandomMove(T,2)

   if not (moveO in range(0,9,1)):
      print("Invalid input")
      break

   if T[int(moveO)] != 1 and T[int(moveO)] != 2:
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
