import sys

def isValid(email):
    return len(email) == 5 + len('@hogwarts.com') \
            and email == email.lower() \
            and all(x in 'abcdefghijklmnopqrstuvwxyz' for x in email[:5]) \
            and email.endswith('@hogwarts.com')

if __name__ == "__main__":
    s = input().strip()
    result = isValid(s)

    print('Yes' if result else 'No')
