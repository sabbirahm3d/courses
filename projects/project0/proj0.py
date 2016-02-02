class Country():

	# Public Variables:
	'''
	string name;
	long population;
	float primaryCompletionFemale;
	float primaryCompletionMale;
	float primaryCompletionTotal;
	float educationGDPSpent;
	float youthLitRateFem;
	float youthLitRateMale;
	'''

	# Constructor

	def __init__(self):

		self.name = ""
		self.population = 0
		self.primaryCompletionFemale = 0
		self.primaryCompletionMale = 0
		self.primaryCompletionTotal = 0
		self.educationGDPSpent = 0
		self.youthLitRateFem = 0
		self.youthLitRateMale = 0


	# Getters

	def GetName(self):

		return self.name


	def GetPopulation(self):

		return self.population


	def GetPrimaryCompFem(self):

		return self.primaryCompletionFemale


	def GetPrimaryCompMale(self):

		return self.primaryCompletionMale


	def GetPrimaryCompTotal(self):

		return self.primaryCompletionTotal


	def GetEduGDP(self):

		return self.educationGDPSpent


	def GetYouthLitFem(self):

		return self.youthLitRateFem


	def GetYouthLitMale(self):

		return self.youthLitRateMale


	# Setters

	def SetName(self, param):

		self.name = param


	def SetPopulation(self, param):

		self.population = param


	def SetPrimaryCompFem(self, param):

		self.primaryCompletionFemale = param


	def SetPrimaryCompMale(self, param):

		self.primaryCompletionMale = param


	def SetPrimaryCompTotal(self, param):

		self.primaryCompletionTotal = param


	def SetEduGDP(self, param):

		self.educationGDPSpent = param


	def SetYouthLitFem(self, param):

		self.youthLitRateFem = param


	def SetYouthLitMale(self, param):

		self.youthLitRateMale = param


yo = Country()
yo.SetPrimaryCompFem(999)
print yo.GetPrimaryCompFem()