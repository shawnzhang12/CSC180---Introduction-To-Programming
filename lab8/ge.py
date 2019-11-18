def ge_fw(matrixin):
   #Error check 
   for i in range(0,len(matrixin)-1,1):
      if len(matrixin[i]) != len(matrixin[i+1]):
         return False
   for i in range(0,len(matrixin),1):
      for j in range(0,len(matrixin[i]),1):
         if type(matrixin[i][j]) != float and type(matrixin[i][j]) != int:
            return False
   t = 0
   k = 0
   skip = 0
   if len(matrixin) >= len(matrixin[0]):
      t = len(matrixin[0])
   else:
      t = len(matrixin)
   
   #Copy matrix
   matrix = []
   for i in matrixin:
      row = list(i)
      matrix += [row]

   #Forward step, includes check for zero columns 
   while k < t:
      if k+skip == t:
         break

      for i in range(0+k,len(matrix),1):
         if matrix[i][0+k+skip] != 0:
            temp = list(matrix[0+k])
            matrix[0+k] = matrix[i]
            matrix[i] = temp
            break

      # print(matrix)

      if matrix[0+k][0+k+skip] == 0:
         skip=skip+1
      else:
         for i in range(1+k,len(matrix),1):
            temp = matrix[i][0+k+skip];
            for j in range(0+k+skip,len(matrix[i]),1):
               matrix[i][j] = matrix[i][j] - ((matrix[0+k][j])*((temp/matrix[k][0+k+skip])))               
         k=k+1
         # print(k,skip)

   return matrix

def ge_bw(matrixin):
   if matrixin == False:
      return False
   
   matrix = []
   for i in matrixin:
      row = list(i)
      matrix += [row]

   length=len(matrix)
   first=0
   k=0
   for k in range(0,length,1):
      for j in range(0,len(matrix[0]),1):
         if matrix[length-1-k][j] != 0:
            first=j
            for d in range(first,len(matrix[0]),1):
               matrix[length-1-k][d] = (matrix[length-1-k][d])/(matrix[length-1-k][first])

      for i in range(0,length-1-k,1):
         for j in range(0,len(matrix[0]),1):
             matrix[i][j]=matrix[i][j]-matrix[i][j]*matrix[length-1-k][j]
    
   return matrix

