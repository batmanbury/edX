# MIT Problem Set 2: Paying the Minimum

#balance = 4213.00
#annualInterestRate = 0.2
#monthlyPaymentRate = 0.04

monthlyInterestRate = annualInterestRate / 12.0
minimumMonthlyPayment = monthlyPaymentRate * (balance)
monthlyUnpaidBalance = (balance) - (minimumMonthlyPayment)
newBalance = (monthlyUnpaidBalance) + (monthlyInterestRate * monthlyUnpaidBalance)

totalPaid = 0.0

for month in range(1,13):
  print "Month:",month
  print "Minimum monthly payment:", minimumMonthlyPayment
  print "Remaining balance:", round(newBalance, 2)
  
  totalPaid += minimumMonthlyPayment
  minimumMonthlyPayment = round(monthlyPaymentRate * newBalance, 2)
  monthlyUnpaidBalance = round(newBalance - minimumMonthlyPayment, 2)
  newBalance = (monthlyUnpaidBalance) + (monthlyInterestRate * monthlyUnpaidBalance)

print "Total paid:",round(totalPaid, 2)
print "Remaining balance:", monthlyUnpaidBalance + minimumMonthlyPayment

'''
Monthly interest rate= (Annual interest rate) / 12.0
Minimum monthly payment = (Minimum monthly payment rate) x (Previous balance)
Monthly unpaid balance = (Previous balance) - (Minimum monthly payment)
Updated balance each month = (Monthly unpaid balance) + (Monthly interest rate x Monthly unpaid balance)

        Month: 1
        Minimum monthly payment: 168.52
        Remaining balance: 4111.89
	      Month: 2
	      Minimum monthly payment: 164.48
	      Remaining balance: 4013.2
	      Month: 3
	      Minimum monthly payment: 160.53
	      Remaining balance: 3916.89
	      Month: 4
	      Minimum monthly payment: 156.68
	      Remaining balance: 3822.88
	      Month: 5
	      Minimum monthly payment: 152.92
	      Remaining balance: 3731.13
	      Month: 6
	      Minimum monthly payment: 149.25
	      Remaining balance: 3641.58
	      Month: 7
	      Minimum monthly payment: 145.66
	      Remaining balance: 3554.19
	      Month: 8
	      Minimum monthly payment: 142.17
	      Remaining balance: 3468.89
	      Month: 9
	      Minimum monthly payment: 138.76
	      Remaining balance: 3385.63
	      Month: 10
	      Minimum monthly payment: 135.43
	      Remaining balance: 3304.38
	      Month: 11
	      Minimum monthly payment: 132.18
	      Remaining balance: 3225.07
	      Month: 12
	      Minimum monthly payment: 129.0
	      Remaining balance: 3147.67
	      Total paid: 1775.55
	      Remaining balance: 3147.67
'''
