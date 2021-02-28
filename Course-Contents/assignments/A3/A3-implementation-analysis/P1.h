# ifndef P1UTILS_H
# include "P1utils.h"
# endif

// brute force anagram search
void p11(char* p, char** T, int TL);
int brute_force_anagram_search(char* P, char** T, int TL);
int sequential_search_anagram(char* t, char* p);


// presort anagram search
void p12(char* p, char** T, int TL);
int presort_anagram_search(char* P, char** T, int TL);

