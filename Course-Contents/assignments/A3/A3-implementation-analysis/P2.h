# ifndef P2UTILS_H
# include "P2utils.h"
# endif

# ifndef TABLE_SIZE_CONST
# define TABLE_SIZE 256 // total ascii characters
# endif

// brute force string search
void p21(char* p, char* T);
int brute_force_string_search(char* P, char* T);

// Horsepool algorithm for string search
void p22(char* p, char* T);
void creatShiftTable(char* P, int* ShT, int ShTL);
int HorsPoolStringMatching(char* P, char* T);
void printTable(int* TB, int TBL);

// Boyer-Moore algorithm for string search
void p23(char* p, char* T);
void createGoodSuffixTable(char* P, int* GSTB, int GSTBL);
int search_right_most_suffix(char* to_search, int to_search_len, char* key, int key_len, char forbidden_char);
void get_prefix(char* P, int prefix_end, char* prefix);
void get_suffix(char* P, int PL, int suffix_start, char* suffix);
int BoyerMooreStringMatching(char* P, char* T);
void printGoodSuffixTable(int* TB, int TBL, char* P);
void printSuffix(char* s, int sl, int suffixStart);