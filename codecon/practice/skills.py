#Problem        : 2016 Qualifiers - SuperSkills
#Language       : Python 3
#Compiled Using : py_compile
#Version        : Python 3.4.3
#Input for your program will be provided from STDIN
#Print out all output from your program to STDOUT

import sys
from collections import *
import itertools

n = int(input())
skills = defaultdict(list)
for _ in range(n):
    name, lang = input().split()
    skills[name].append(lang)

m = int(input())
graph = defaultdict(list)
for _ in range(m):
    a, b = input().split()
    graph[a].append(b)
    graph[b].append(a)
    
me = input()
my_skills = set(skills[me])
all_skills = set(skills[me])
for friend in graph[me]:
    for skill in skills[friend]:
        all_skills.add(skill)

best = tuple(graph[me])
found = False
for sz in range(1, len(best)):
    if found:
        break

    for combo in itertools.combinations(graph[me], sz):
        cur_skills = set()
        for friend in combo:
            for skill in skills[friend]:
                cur_skills.add(skill)

        cur_skills |= my_skills

        if cur_skills == all_skills:
            if len(combo) < len(best):
                best = combo
                found = True
                break

ans = list(best)
ans.sort()
print(','.join(ans))
