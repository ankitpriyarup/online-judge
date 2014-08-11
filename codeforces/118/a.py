s = raw_input()
s = s.lower()
for c in "aeiouy":
    s = s.replace(c, "")
if len(s) > 0:
    print "." + ".".join(list(s))
else:
    print ""
