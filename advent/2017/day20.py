from collections import *
from functools import reduce
import copy
import itertools
import random
import sys

def dist(particle):
    pos = particle[0]

    return sum(abs(x) for x in pos)

def add(a, b):
    return tuple(x + y for x, y in zip(a, b))

def update(pos, vel, acc):
    new_vel = add(vel, acc)
    new_pos = add(pos, new_vel)

    return (new_pos, new_vel, acc)

def main():
    particles = []
    for line in sys.stdin:
        chunks = line.split(', ')
        particle = []
        for chunk in chunks:
            eq = chunk.index('=')
            coords = tuple(int(coord.strip('<>')) for coord in chunk[eq+1:-1].split(','))
            particle.append(coords)

        particles.append(tuple(particle))

    for _ in range(20000):
        particles = [update(*particle) for particle in particles]
        c = Counter(particle[0] for particle in particles)
        particles = [p for p in particles if c[p[0]] == 1]

        min_ind = min(range(len(particles)), key=lambda i:dist(particles[i]))
        print(min_ind,len(particles))

main()
