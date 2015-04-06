english = ['', 'one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 
'nine', 'ten', 'eleven', 'twelve', 'thirteen', 'fourteen', 'fifteen', 'sixteen',
'seventeen', 'eighteen', 'nineteen', 'twenty']

def minutes(m):
    if m <= 20:
        return english[m]
    else:
        return english[20] + ' ' + english[m - 20]

H = int(raw_input())
M = int(raw_input())

hours = ['', 'one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 
'nine', 'ten', 'eleven', 'twelve', 'one']

if M == 0:
    print hours[H], 'o\' clock'
elif M == 1:
    print 'one minute past', hours[H]
elif M == 15:
    print 'quarter past', hours[H]
elif M == 30:
    print 'half past', hours[H]
elif M == 45:
    print 'quarter to', hours[H + 1]
elif M == 59:
    print 'one minute to', hours[H + 1]
elif M < 30:
    print minutes(M), 'minutes past', hours[H]
else:
    print minutes(60 - M), 'minutes to', hours[H + 1]
