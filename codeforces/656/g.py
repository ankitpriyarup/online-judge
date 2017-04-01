#kitten
def main():
 f,i,t=map(int, input().split())
 p=[0]*i
 for _ in range(f):
  likes=input()
  for j in range(i):
   if likes[j]=='Y':
    p[j]+=1
 print(sum(1 for j in p if j>=t))
main()
