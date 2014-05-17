# MIT Problem Set 2: Paying Off Debt in a Year
# Iterative

balance = 3329
annualInterestRate = 0.2

resetBalance = balance
payment = 0

while resetBalance > 0:
  payment += 10
  resetBalance = balance
  for month in range(1,13):
    resetBalance -= payment
    resetBalance += resetBalance * (annualInterestRate/12)
  
print "Lowest Payment:", payment

'''
Monthly interest rate = (Annual interest rate) / 12.0
Monthly unpaid balance = (Previous balance) - (Minimum monthly payment)
Updated balance each month = (Monthly unpaid balance) + (Monthly interest rate x Monthly unpaid balance)


Test Case 1:
        balance = 3329
	      annualInterestRate = 0.2

	      Result Your Code Should Generate:
	      -------------------
	      Lowest Payment: 310
'''
