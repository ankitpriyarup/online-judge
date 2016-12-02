import sys

TIME = 2503
def dist(speed, duration, rest):
    # how far can you go in TIME seconds
    cycle = duration + rest
    num_full_cycles = TIME / cycle
    ans = num_full_cycles * (speed * duration)

    remainder = TIME % cycle
    if remainder >= duration:
        ans += speed * duration
    else:
        ans += speed * remainder

    return ans

def main():
    reindeer = []
    fin = open('14.in', 'r')
    for line in fin.readlines():
        words = line.strip().split()
        name = words[0]
        speed = int(words[3])
        duration = int(words[6])
        rest = int(words[-2])
        reindeer.append({"name": name, "speed": speed, "duration": duration, "rest": rest, "pos": 0, "points": 0, "resting": False, "remaining": duration})
    fin.close()

    for second in xrange(1, TIME + 1):
        best_pos = 0
        for deer in reindeer:
            if deer["resting"]:
                deer["remaining"] -= 1
                if deer["remaining"] == 0:
                    deer["resting"] = False
                    deer["remaining"] = deer["duration"]
            else:
                deer["pos"] += deer["speed"]
                deer["remaining"] -= 1
                if deer["remaining"] == 0:
                    deer["remaining"] = deer["rest"]
                    deer["resting"] = True

            best_pos = max(best_pos, deer["pos"])

        for deer in reindeer:
            if deer["pos"] == best_pos:
                deer["points"] += 1

    ans1 = 0
    ans2 = 0
    for deer in reindeer:
        ans1 = max(ans1, deer["pos"])
        ans2 = max(ans2, deer["points"])

    print "Part 1", ans1
    print "Part 2", ans2

if __name__ == '__main__':
    main()
