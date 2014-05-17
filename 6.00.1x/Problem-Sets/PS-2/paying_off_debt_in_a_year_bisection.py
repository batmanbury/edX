# MIT Problem Set 2: Paying Off Debt in a Year
# Bisection Search

balance = 320000
annualInterestRate = 0.2

monthlyInterestRate = annualInterestRate/12.0
resetBalance = balance

epsilon = 0.01
lower = resetBalance / 12.0
upper = (resetBalance * (1 + monthlyInterestRate)**12) / 12.0

payment = (lower + upper) / 2.0

while abs(resetBalance) > epsilon:
  resetBalance = balance
  for month in range(1,13):
    resetBalance -= payment
    resetBalance += resetBalance * monthlyInterestRate
  if resetBalance > 0:
    lower = payment
  else:
    upper = payment
  payment = (lower + upper) / 2.0
# print payment
  
print "Lowest Payment:", round(payment, 2)

'''
Monthly interest rate = (Annual interest rate) / 12.0
Monthly payment lower bound = Balance / 12
Monthly payment upper bound = (Balance x (1 + Monthly interest rate)**12) / 12.0

Test Case 1:
	      balance = 320000
	      annualInterestRate = 0.2

	      Result Your Code Should Generate:
	      -------------------
	      Lowest Payment: 29157.09
	      
Test Case 2:
              balance = 999999
              annualInterestRate = 0.18
          
              Result Your Code Should Generate:
              -------------------
              Lowest Payment: 90325.03
'''
