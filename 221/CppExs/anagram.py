from itertools import permutations
import sys

# A function to return a list of all English anagrams of a given length of a
# given word. Also takes a list of all English words.
def anagrams_n(word, all_words, n):
    ret = []

    for chars in permutations(word):
        candidate = ''.join(chars)[:n]
        if (candidate in all_words and candidate not in ret):
            ret.append(candidate)

    return ret

##### Main
# Iterate over the command line input word and generate all single-word
# anagrams of exactly the same length

# Verify command line:
if len(sys.argv) != 2:
    print("Need exactly one command line argument: A word")
    sys.exit(-1)

# Read in words file into list:
with open("/usr/share/dict/words", "r") as f:
    all_words = { line.rstrip('\n') for line in f }

# Generate all anagrams:
for l in range(2, len(sys.argv[1]) + 1):
    print(anagrams_n(sys.argv[1], all_words, l))

sys.exit(0)
