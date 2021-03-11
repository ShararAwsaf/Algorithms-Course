
 					[How to Run]
1)  make

2)  ./xmain <required: program name (p11/p12/p21/p22/p23)> <optional: filename> <optional: pattern> [NOTE: The arguments must be in order]

3) if no <filename> is provided, then the default file is ./data/data_4.txt for (p11/p12) and ./data/data_5.txt for (p21/p22/p23)

4) if no <pattern> is provided, the user is asked to type in a pattern after execution

5) Use make clean to remove .o and executable files

EXAMPLES OF RUNNING EACH PROGRAM:
-------------------------------------------------------------------
QUESTION        EXEC       PROGRAM       FILE NAME        PATTERN
-------------------------------------------------------------------
1.1)          ./xmain        p11    ./data/data_4.txt    789567555 
1.2)          ./xmain        p12    ./data/data_4.txt    789567555

2.1)          ./xmain        p21    ./data/data_5.txt    Government
2.2)          ./xmain        p22    ./data/data_5.txt    Government
2.3)          ./xmain        p23    ./data/data_4.txt    Government
-------------------------------------------------------------------

The output will contain the name of program, filename & input size, pattern & pattern size, total running time for all programs.

For the cases of 1.1, 1.2: Output will have number of anagrams and the anagrams that were found. The sort time and search time will be displayed for 1.2

For the cases of 2.1,2.2,2.3: Output will have number of matches, the pattern shifts.

Answer to Question(2.4):

        [Comparative analysis of the three string searching algorithms with 10 words]

NOTE: 
1. Data was generated based on ./data/data_52.txt
2. In case of shift counts, counting the matched & mismatch shifts not the cases where a match happens


-------------------------------------------------------------------
                      Word-1: Government			  | 
-------------------------------------------------------------------
Comparison Criteria         | Brute Force | Horspool | Boyer-Moore|
-------------------------------------------------------------------
Matches                     | 33          | 33       | 33         | 
-------------------------------------------------------------------
Shifts                      | 3296580     | 395417   | 395417     |
-------------------------------------------------------------------
Running Time (ms)           | 13.420      | 4.457    | 8.637      |
-------------------------------------------------------------------
Shift Ratio(Shifts/Run Time)| 245646.80   | 88718.20 | 45781.75   |
-------------------------------------------------------------------

Matches: All 3 algorithms have same number of matches 33.

Shifts: Horspool + Boyer Moore requires least number of shifts. 2901163 less than Brute Force.

Running Time: Horspool requires least amount of time. 4.18 ms less than Boyer-Moore and 8.963 ms less than Brute force.

Shifts Rate: Shifts per running time is least for Boyer-Moore. It reduces shifts by 42936.45 compared to Horspool and 199865.05 compared to Brute Force.



-------------------------------------------------------------------
                      Word-2: excellence			  | 
-------------------------------------------------------------------
Comparison Criteria         | Brute Force | Horspool | Boyer-Moore|
-------------------------------------------------------------------
Matches                     | 96          | 96       | 96         | 
-------------------------------------------------------------------
Shifts                      | 3296580     | 388345   | 366905     |
-------------------------------------------------------------------
Running Time (ms)           | 17.270      | 3.899    | 7.045      |
-------------------------------------------------------------------
Shift Ratio(Shifts/Run Time)| 190884.77   | 99601.18 | 52080.20   |
-------------------------------------------------------------------

Matches: All 3 algorithms have same number of matches 96.

Shifts: Boyer Moore requires least number of shifts. 21440 less than Horspool and 2929675 less than Brute Force.

Running Time: Horspool requires least amount of time. 3.146 ms less than Boyer-Moore and 13.371 ms less than Brute force.

Shifts Rate: Shifts per running time is least for Boyer-Moore. It reduces shifts by 47520.98 compared to Horspool and 138804.57 compared to Brute Force.




-------------------------------------------------------------------
                      Word-3: ssiss				  | 
-------------------------------------------------------------------
Comparison Criteria         | Brute Force | Horspool | Boyer-Moore|
-------------------------------------------------------------------
Matches                     | 1           | 1        | 1          | 
-------------------------------------------------------------------
Shifts                      | 3296585     | 714524   | 694391     |
-------------------------------------------------------------------
Running Time (ms)           | 17.043      | 5.836    | 10.846     |
-------------------------------------------------------------------
Shift Ratio(Shifts/Run Time)| 193427.51   | 122433.86| 64022.77   |
-------------------------------------------------------------------

Obervation:

Matches: All 3 algorithms have same number of matches 1.

Shifts: Boyer Moore requires least number of shifts. 20133 less than Horspool and 2602194 less than Brute Force.

Running Time: Horspool requires least amount of time. 5.01 ms less than Boyer-Moore and 11.207 ms less than Brute force.

Shifts Rate: Shifts per running time is least for Boyer-Moore. It reduces shifts by 58411.09 compared to Horspool and 129404.74 compared to Brute Force.



-------------------------------------------------------------------
                      Word-4: engineering			  | 
-------------------------------------------------------------------
Comparison Criteria         | Brute Force | Horspool | Boyer-Moore| 
-------------------------------------------------------------------
Matches                     | 17          | 17       | 17         | 
-------------------------------------------------------------------
Shifts                      | 3296579     | 374427   | 372052     | 
-------------------------------------------------------------------
Running Time (ms)           | 24.654      | 3.224    | 5.890      |
-------------------------------------------------------------------
Shift Ratio(Shifts/Run Time)| 186383.39   | 121562.01| 54824.05   |
-------------------------------------------------------------------

Observation:

Matches: All 3 algorithms have same number of matches 17.

Shifts: Boyer Moore requires least number of shifts. 2375 less than Horspool and 2924527 less than Brute Force.

Running Time: Horspool requires least amount of time. 2.666 ms less than Boyer-Moore and 21.430 ms less than Brute force.

Shifts Rate: Shifts per running time is least for Boyer-Moore. It reduces shifts by 66737.96 compared to Horspool and 131559.34 compared to Brute Force.



-------------------------------------------------------------------
                      Word-5: onion			          | 
-------------------------------------------------------------------
Comparison Criteria         | Brute Force | Horspool | Boyer-Moore| 
-------------------------------------------------------------------
Matches                     | 0           | 0         | 0         | 
-------------------------------------------------------------------
Shifts                      | 3296585     | 734710   | 722271     | 
-------------------------------------------------------------------
Running Time (ms)           | 16.293      | 7.149    | 11.653     |
-------------------------------------------------------------------
Shift Ratio(Shifts/Run Time)| 202518.49   | 108268.64| 61261.41   |
-------------------------------------------------------------------

Observation:

Matches: All 3 algorithms have same number of matches 0.

Shifts: Boyer Moore requires least number of shifts. 12439 less than Horspool and 2574314 less than Brute Force.

Running Time: Horspool requires least amount of time. 4.504 ms less than Boyer-Moore and 9.144 ms less than Brute force.

Shifts Rate: Shifts per running time is least for Boyer-Moore. It reduces shifts by 47007.23 compared to Horspool and 141257.08 compared to Brute Force.


-------------------------------------------------------------------
                      Word-6: inconvenience		          | 
-------------------------------------------------------------------
Comparison Criteria         | Brute Force | Horspool | Boyer-Moore| 
-------------------------------------------------------------------
Matches                     | 0           | 0        | 0          | 
-------------------------------------------------------------------
Shifts                      | 3296577     | 319628   | 298475     | 
-------------------------------------------------------------------
Running Time (ms)           | 15.672      | 3.168    | 5.533      |
-------------------------------------------------------------------
Shift Ratio(Shifts/Run Time)| 210348.20   | 100892.68| 53944.51   |
-------------------------------------------------------------------

Observation:

Matches: All 3 algorithms have same number of matches 0.

Shifts: Boyer Moore requires least number of shifts. 21153 less than Horspool and 2998102 less than Brute Force.

Running Time: Horspool requires least amount of time. 2.365 ms less than Boyer-Moore and 12.504 ms less than Brute force.

Shifts Rate: Shifts per running time is least for Boyer-Moore. It reduces shifts by 46948.17 compared to Horspool and 156403.69 compared to Brute Force.




-------------------------------------------------------------------
                      Word-7: maintain		          | 
-------------------------------------------------------------------
Comparison Criteria         | Brute Force | Horspool | Boyer-Moore| 
-------------------------------------------------------------------
Matches                     | 137         | 137      | 137        | 
-------------------------------------------------------------------
Shifts                      | 3296582     | 499481   | 480152     | 
-------------------------------------------------------------------
Running Time (ms)           | 15.370      | 5.012    | 7.748      |
-------------------------------------------------------------------
Shift Ratio(Shifts/Run Time)| 86912.07    | 108815.89| 44116.64   |
-------------------------------------------------------------------

Observation:

Matches: All 3 algorithms have same number of matches 137.

Shifts: Boyer Moore requires least number of shifts. 19329 less than Horspool and 2816430 less than Brute Force.

Running Time: Horspool requires least amount of time. 2.736 ms less than Boyer-Moore and 10.358 ms less than Brute force.

Shifts Rate: Shifts per running time is least for Boyer-Moore. It reduces shifts by 64699.25 compared to Horspool and 42795.43 compared to Brute Force.



-------------------------------------------------------------------
                      Word-8: PolytechnicalInstitute	          | 
-------------------------------------------------------------------
Comparison Criteria         | Brute Force | Horspool | Boyer-Moore| 
-------------------------------------------------------------------
Matches                     | 14          | 14       | 14         | 
-------------------------------------------------------------------
Shifts                      | 3296568     | 224038   | 217041     | 
-------------------------------------------------------------------
Running Time (ms)           | 16.864      | 2.392    | 4.230      |
-------------------------------------------------------------------
Shift Ratio(Shifts/Run Time)| 195479.60   | 93661.37 | 51309.93   |
-------------------------------------------------------------------

Observation:

Matches: All 3 algorithms have same number of matches 14.

Shifts: Boyer Moore requires least number of shifts. 6997 less than Horspool and 3079527 less than Brute Force.

Running Time: Horspool requires least amount of time. 1.838 ms less than Boyer-Moore and 14.472 ms less than Brute force.

Shifts Rate: Shifts per running time is least for Boyer-Moore. It reduces shifts by 42351.44 compared to Horspool and 1874169.67 compared to Brute Force.



-------------------------------------------------------------------
                      Word-8: Qualification	                  | 
-------------------------------------------------------------------
Comparison Criteria         | Brute Force | Horspool | Boyer-Moore| 
-------------------------------------------------------------------
Matches                     | 3354        | 3354     | 3354       | 
-------------------------------------------------------------------
Shifts                      | 3296577     | 328768   | 328768     | 
-------------------------------------------------------------------
Running Time (ms)           | 12.232      | 3.883    | 5.856      |
-------------------------------------------------------------------
Shift Ratio(Shifts/Run Time)| 267297.01   | 84668.56 | 56142.08   |
-------------------------------------------------------------------

Observation:

Matches: All 3 algorithms have same number of matches 3354.

Shifts: Horspool + Boyer Moore requires least number of shifts. 2967809 less than Brute Force.

Running Time: Horspool requires least amount of time. 1.973 ms less than Boyer-Moore and 8.349 ms less than Brute force.

Shifts Rate: Shifts per running time is least for Boyer-Moore. It reduces shifts by 28526.48 compared to Horspool and 211154.93 compared to Brute Force.




-------------------------------------------------------------------
                      Word-9: off   		                  | 
-------------------------------------------------------------------
Comparison Criteria         | Brute Force | Horspool | Boyer-Moore| 
-------------------------------------------------------------------
Matches                     | 930         | 930      | 930        | 
-------------------------------------------------------------------
Shifts                      | 3295687     | 1130844  | 1127523    | 
-------------------------------------------------------------------
Running Time (ms)           | 17.163      | 9.362    | 16.342     |
-------------------------------------------------------------------
Shift Ratio(Shifts/Run Time)| 192022.78   | 120790.86| 68995.41   |
-------------------------------------------------------------------

Observation:

Matches: All 3 algorithms have same number of matches 930.

Shifts: Boyer Moore requires least number of shifts. 3321 less than Horspool and 2168164 less than Brute Force.

Running Time: Horspool requires least amount of time. 6.980 ms less than Boyer-Moore and 7.801 ms less than Brute force.

Shifts Rate: Shifts per running time is least for Boyer-Moore. It reduces shifts by 51795.45 compared to Horspool and 123027.37 compared to Brute Force.



-------------------------------------------------------------------
                     Word-10: throughextracurricular              | 
-------------------------------------------------------------------
Comparison Criteria         | Brute Force | Horspool | Boyer-Moore| 
-------------------------------------------------------------------
Matches                     | 7           | 7        | 7          | 
-------------------------------------------------------------------
Shifts                      | 3296590     | 215633   | 207231     | 
-------------------------------------------------------------------
Running Time (ms)           | 18.999      | 3.030    | 3.792      |
-------------------------------------------------------------------
Shift Ratio(Shifts/Run Time)| 173513.87   | 71166.01 | 54649.53   |
-------------------------------------------------------------------

Observation:

Matches: All 3 algorithms have same number of matches 7.

Shifts: Boyer Moore requires least number of shifts. 8402 less than Horspool and 3089359 less than Brute Force.

Running Time: Horspool requires least amount of time. 0.762 ms less than Boyer-Moore and 15.969 ms less than Brute force.

Shifts Rate: Shifts per running time is least for Boyer-Moore. It reduces shifts by 16216.48 compared to Horspool and 118564.34 compared to Brute Force.


Average Performance Horspool vs Brute Force:

Performance was measured as average shift rate obtained from 10 words

Average performance for Brute Force (10 words) = 2144434.49/10 = 214443.449 shifts/ms
Average Performance for Horspool's algorithm (10 words) = 1120579.26/10 = 112057.926 shifts/ms

Analysis of the results:

1. Correctness: All three algorithms produced correct results and thus can be used. However, their efficiencies vary depending on the shift counts.

2. Running Time: The Horspool algorithm had the least running time for all the patterns. It was faster than the Brute Force due to the fact that Brute Force performs 1 character advancement each step and thus there are several repeated comparisons. Horspool however, can perform multiple character shifts in a single step by using Shift Table Lookups. The lookup table since computed only once at the beginning the shifts are O(1) table lookups and is thus much faster and prevents many repeat character comparisons that are done in brute force.

3. Pattern Shifts: Horspool's algorithm performs order of magnitude less number of shifts compared to the Brute Force algorithm and is particularly a lot faster for smaller patterns. The Horspool's algorithm is very efficient in terms of running time though for longer patterns there are more shifts compared to Boyer Moore.


4. Shifting Ratio (Performance Parameter): Horspool's algorithm is better than Brute Force as it has lower number of shifts per milisecond compared to the Brute Force implementation. The difference is more prominent during longer pattern sequence where the Horspool's algorithm can take longer jumps and avoid repeated computations for failed attempts. Such attempts are repeated in the brute force implementation causing it to be much slower and requiring more shifts. For longer patterns there is order of magnitude better performance by Horspool's algorithm compared to shorter patterns where there is less performance improvement.
