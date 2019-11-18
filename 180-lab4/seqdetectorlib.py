class seqdetector:
   def __init__(self):
      self.state=0

   def evolve(self,word):
      sequence = ["here","are","the","solutions","to","the","next","exam"]
      if word == sequence[self.state]:
         self.state = self.state + 1
      elif word == sequence[0]:
         self.state=1
      else:
         self.state=0

      if self.state != len(sequence):
         return False
      else:
         self.state=0
         return True
