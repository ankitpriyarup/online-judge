import sys
def main():
    tc = 1
    flip = {'major': {}, 'minor': {}}
    flip['A#'] = 'Bb'
    flip['Bb'] = 'A#'
    flip['C#'] = 'Db'
    flip['Db'] = 'C#'
    flip['D#'] = 'Eb'
    flip['Eb'] = 'D#'
    flip['F#'] = 'Gb'
    flip['Gb'] = 'F#'
    flip['G#'] = 'Ab'
    flip['Ab'] = 'G#'
    for line in sys.stdin:
        note, tone = line.strip().split()
        if note in flip:
            print('Case {}: {} {}'.format(tc, flip[note], tone))
        else:
            print('Case {}: UNIQUE'.format(tc))
        tc += 1 

main()
