class projectile:
   def __init__(self,pos,vel,acc,dt):
      self.x=pos
      self.v=vel
      self.a=acc
      self.dt=dt

   def evolve(self):
      self.x = self.x + self.v*self.dt
      self.v = self.v + self.a*self.dt
      return True

   def getpos(self):
      return self.x

def sim():
   while True:
      try:
         u=input("How many projectiles?")
         N=int(u)
         if (N <= 0):
            print("ERROR: must enter a positive integer!")
            continue
         else:
            break
      except:
         print("You typed in:", u, "but I wanted an integer!")

   projL = []
   for n in range(0,N,1):
      projL = projL + [projectile(20+n*10,0,-9.8,0.1)]
   for n in range(0,10,1):
      msg=""
      for proj in projL:
         proj.evolve()
         msg=msg+format(proj.getpos(),'.6f')+", "
      msg=msg[0:len(msg)-2]
      print(msg)

sim()
