#Name: Gagan Gupta 
#Date: 09/29/20
#Title: COEN 166L: Lab 2
#Description: Vacuum Agent with 2 squares

class Vacuum:
	def __init__(self, state):
		self.state=state
		self.cost=0
		self.actions=[]
	def suck(self):
		if self.state[2]=='L':
			self.actions.append("Suck on Left")
			self.state[0]='C'
		else:
			self.actions.append("Suck on Right")
			self.state[1]='C'
		self.cost = self.cost + 1

	def right(self):
		if self.state[2]=='L':
			self.actions.append("Move to Right")
			self.state[2]='R'
		self.cost = self.cost + 1

	def left(self):
		if self.state[2]=='R':
			self.actions.append("Move to Left")
			self.state[2]='L'
		self.cost = self.cost + 1

	def runActions(self):
		if self.state[0]=='D' and self.state[2]=='L':
			self.suck()
			self.runActions()
		if self.state[1]=='D' and self.state[2]=='R':
			self.suck()
			self.runActions()
		if self.state[1]=='D' and self.state[2]=='L':
			self.right()
			self.runActions()
		if self.state[0]=='D' and self.state[2]=='R':
			self.left()
			self.runActions()

def main():
	state=['','','']
	while state[0]!='C' and state[0]!='D':
		print("Status of Left side: ")
		state[0] = str(input())
	while state[1] != 'C' and state[1] != 'D':
		print("Status of Right side: ")
		state[1] = str(input())
	while state[2]!='L' and state[2]!='R':
		print("Location of Vacuum: ")
		state[2] = str(input())
	x=Vacuum(state)
	x.runActions()
	print("List of Actions: ",x.actions)
	print("Ending Location of Vacuum: ",x.state[2])
	print("Cost of the State inputted: ",x.cost)

if __name__ == "__main__":
    main()