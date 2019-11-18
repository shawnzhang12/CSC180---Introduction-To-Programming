def rule(val, L):
   sumlist = 0
   if val == 1:
      for i in L:
         sumlist += i
      if (sumlist == 2) or (sumlist == 3):
         return 1
      else:
         return 0
   else:
      for i in L:
         sumlist += i
      if sumlist == 3:
         return 1
      else:
         return 0

