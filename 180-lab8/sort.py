def bubbleSort(array):
   if type(array) != list:
      return [False, array]
   if len(array) == 0:
      return [False, array]
   for i in range(0,len(array),1):
      if type(array[i]) != int and type(array[i]) != float:
         return [False, array]

   arraymod=list(array)
   n=len(arraymod)
   swapped = True
   
   while swapped == True:
      swapped = False
      for i in range(1,n,1):
         if arraymod[i-1] > arraymod[i]:
            temp = arraymod[i]
            arraymod[i]=arraymod[i-1]
            arraymod[i-1]=temp
            swapped = True

   return[True, arraymod]

