#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <unordered_set>

using namespace std;


// A function to return a list of all English anagrams of a given length of a
// given word. Also takes a list of all English words.
unordered_set<string> anagrams_n(string word, unordered_set<string> all_words, unsigned n)
{
  unordered_set<string> ret;

  do {
    if (all_words.find(word.substr(0, n)) != all_words.end()) {
      ret.insert(word.substr(0, n));
    }
  } while (next_permutation(word.begin(), word.end()));

  return ret;
}

/*
 * Iterate over the command line input word and generate all single-word
 * anagrams of exactly the same length.
 */
int main(int argc, char* argv[])
{
  // Verify command line
  if (argc != 2) {
    cerr << "Need exactly one command line argument: A word\n";
    return -1;
  }

  // Read in words file into set:
  unordered_set<string> all_words;
  ifstream file("/usr/share/dict/words");
  string s;
  while (getline(file, s)) {
    all_words.insert(s);
  }

  // Sort input word alphabetically for permutting
  string sorted_word(argv[1]);
  sort(begin(sorted_word), end(sorted_word));

  // Generate all anagrams:
  for (unsigned l = 2; l <= sorted_word.size(); ++l) {
    const auto& all_anagrams = anagrams_n(sorted_word, all_words, l);

    for (auto w : all_anagrams) {
      cout << w << endl;
    }
  }


  return 0;
}
