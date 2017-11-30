all_notes = ['A', 'A#', 'B', 'C', 'C#', 'D', 'D#', 'E', 'F', 'F#', 'G', 'G#']
scales = []

for i in range(len(all_notes)):
    scale = []
    for shift in [0, 2, 4, 5, 7, 9, 11]:
        scale.append(all_notes[(i + shift) % len(all_notes)])

    scales.append(scale)

def main():
    n = int(input())
    notes = input().split()
    out = []
    for i in range(len(all_notes)):
        if all(note in scales[i] for note in notes):
            out.append(all_notes[i])

    if out:
        print(' '.join(out))
    else:
        print('none')

main()
