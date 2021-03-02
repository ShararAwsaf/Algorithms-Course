
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
2. In case of shift counts, only counting the mismatch shifts not the cases where a match happens


-------------------------------------------------------------------
                      Word-1: Government			  | 
-------------------------------------------------------------------
Comparison Criteria         | Brute Force | Horspool | Boyer-Moore|
-------------------------------------------------------------------
Matches                     | 33          | 33       | 33         | 
-------------------------------------------------------------------
Shifts                      | 3296548     | 395385   | 395385     |
-------------------------------------------------------------------
Running Time (ms)           | 12.653      | 5.784    | 7.075      |
-------------------------------------------------------------------
Shift Ratio(Shifts/Run Time)| 260534.89   | 68358.40 | 55884.81   |
-------------------------------------------------------------------

Matches: All 3 algorithms have same number of matches 33.

Shifts: Horspool + Boyer Moore requires least number of shifts. 2901163 less than Brute Force.

Running Time: Horspool requires least amount of time. 1.291 ms less than Boyer-Moore and 6.869 ms less than Brute force.

Shifts Rate: Shifts per running time is least for Boyer-Moore. It reduces shifts by 12473.59 compared to Horspool and 204650.08 compared to Brute Force.



-------------------------------------------------------------------
                      Word-2: excellence			  | 
-------------------------------------------------------------------
Comparison Criteria         | Brute Force | Horspool | Boyer-Moore|
-------------------------------------------------------------------
Matches                     | 96          | 96       | 96         | 
-------------------------------------------------------------------
Shifts                      | 3296485     | 388250   | 366810     |
-------------------------------------------------------------------
Running Time (ms)           | 17.043      | 3.659    | 6.243      |
-------------------------------------------------------------------
Shift Ratio(Shifts/Run Time)| 193421.64   | 106108.23| 58755.41   |
-------------------------------------------------------------------

Matches: All 3 algorithms have same number of matches 96.

Shifts: Boyer Moore requires least number of shifts. 21440 less than Horspool and 2929675 less than Brute Force.

Running Time: Horspool requires least amount of time. 2.584 ms less than Boyer-Moore and 13.384 ms less than Brute force.

Shifts Rate: Shifts per running time is least for Boyer-Moore. It reduces shifts by 47352.82 compared to Horspool and 134666.23 compared to Brute Force.




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
Shifts                      | 3296563     | 374411   | 372036     | 
-------------------------------------------------------------------
Running Time (ms)           | 17.687      | 3.080    | 6.786      |
-------------------------------------------------------------------
Shift Ratio(Shifts/Run Time)| 186383.39   | 121562.01| 54824.05   |
-------------------------------------------------------------------

Observation:

Matches: All 3 algorithms have same number of matches 17.

Shifts: Boyer Moore requires least number of shifts. 2375 less than Horspool and 2924527 less than Brute Force.

Running Time: Horspool requires least amount of time. 3.706 ms less than Boyer-Moore and 14.607 ms less than Brute force.

Shifts Rate: Shifts per running time is least for Boyer-Moore. It reduces shifts by 66738.05 compared to Horspool and 131559.34 compared to Brute Force.



-------------------------------------------------------------------
                      Word-5: onion			          | 
-------------------------------------------------------------------
Comparison Criteria         | Brute Force | Horspool | Boyer-Moore| 
-------------------------------------------------------------------
Matches                     | 0           | 0         | 0         | 
-------------------------------------------------------------------
Shifts                      | 3296586     | 734711   | 722272     | 
-------------------------------------------------------------------
Running Time (ms)           | 16.278      | 6.786    | 11.790     |
-------------------------------------------------------------------
Shift Ratio(Shifts/Run Time)| 202518.49   | 108268.64| 61261.41   |
-------------------------------------------------------------------

Observation:

Matches: All 3 algorithms have same number of matches 0.

Shifts: Boyer Moore requires least number of shifts. 12439 less than Horspool and 2574314 less than Brute Force.

Running Time: Horspool requires least amount of time. 5.004 ms less than Boyer-Moore and 9.492 ms less than Brute force.

Shifts Rate: Shifts per running time is least for Boyer-Moore. It reduces shifts by 47007.23 compared to Horspool and 141257.08 compared to Brute Force.


-------------------------------------------------------------------
                      Word-6: inconvenience		          | 
-------------------------------------------------------------------
Comparison Criteria         | Brute Force | Horspool | Boyer-Moore| 
-------------------------------------------------------------------
Matches                     | 0           | 0        | 0          | 
-------------------------------------------------------------------
Shifts                      | 3296578     | 319629   | 298476     | 
-------------------------------------------------------------------
Running Time (ms)           | 16.279      | 3.154    | 5.37       |
-------------------------------------------------------------------
Shift Ratio(Shifts/Run Time)| 202504.95   | 101340.84| 55582.12   |
-------------------------------------------------------------------

Observation:

Matches: All 3 algorithms have same number of matches 0.

Shifts: Boyer Moore requires least number of shifts. 21153 less than Horspool and 2998102 less than Brute Force.

Running Time: Horspool requires least amount of time. 2.216 ms less than Boyer-Moore and 13.125 ms less than Brute force.

Shifts Rate: Shifts per running time is least for Boyer-Moore. It reduces shifts by 45758.72 compared to Horspool and 146922.83 compared to Brute Force.




-------------------------------------------------------------------
                      Word-7: FoodEngineering		          | 
-------------------------------------------------------------------
Comparison Criteria         | Brute Force | Horspool | Boyer-Moore| 
-------------------------------------------------------------------
Matches                     | 10          | 10       | 10         | 
-------------------------------------------------------------------
Shifts                      | 3296566     | 289006   | 286308     | 
-------------------------------------------------------------------
Running Time (ms)           | 12.274      | 2.409    | 4.794       |
-------------------------------------------------------------------
Shift Ratio(Shifts/Run Time)| 268581.23   | 119969.28| 59722.15   |
-------------------------------------------------------------------

Observation:

Matches: All 3 algorithms have same number of matches 10.

Shifts: Boyer Moore requires least number of shifts. 2698 less than Horspool and 3010258 less than Brute Force.

Running Time: Horspool requires least amount of time. 2.385 ms less than Boyer-Moore and 9.865 ms less than Brute force.

Shifts Rate: Shifts per running time is least for Boyer-Moore. It reduces shifts by 60247.13 compared to Horspool and 208859.08 compared to Brute Force.



-------------------------------------------------------------------
                      Word-8: PolytechnicalInstitute	          | 
-------------------------------------------------------------------
Comparison Criteria         | Brute Force | Horspool | Boyer-Moore| 
-------------------------------------------------------------------
Matches                     | 14          | 14       | 14         | 
-------------------------------------------------------------------
Shifts                      | 3296555     | 224025   | 217028     | 
-------------------------------------------------------------------
Running Time (ms)           | 12.253      | 2.354    | 4.147      |
-------------------------------------------------------------------
Shift Ratio(Shifts/Run Time)| 269040.64   | 95167.80 | 52333.74   |
-------------------------------------------------------------------

Observation:

Matches: All 3 algorithms have same number of matches 14.

Shifts: Boyer Moore requires least number of shifts. 6997 less than Horspool and 3079527 less than Brute Force.

Running Time: Horspool requires least amount of time. 1.793 ms less than Boyer-Moore and 9.899 ms less than Brute force.

Shifts Rate: Shifts per running time is least for Boyer-Moore. It reduces shifts by 42834.06 compared to Horspool and 216706.9 compared to Brute Force.



-------------------------------------------------------------------
                      Word-8: Qualification	                  | 
-------------------------------------------------------------------
Comparison Criteria         | Brute Force | Horspool | Boyer-Moore| 
-------------------------------------------------------------------
Matches                     | 3354        | 3354     | 3354       | 
-------------------------------------------------------------------
Shifts                      | 3293224     | 325415   | 325415     | 
-------------------------------------------------------------------
Running Time (ms)           | 13.761      | 3.415    | 5.807      |
-------------------------------------------------------------------
Shift Ratio(Shifts/Run Time)| 239315.75   | 95289.90 | 56038.40   |
-------------------------------------------------------------------

Observation:

Matches: All 3 algorithms have same number of matches 3354.

Shifts: Horspool + Boyer Moore requires least number of shifts. 2967809 less than Brute Force.

Running Time: Horspool requires least amount of time. 2.392 ms less than Boyer-Moore and 10.346 ms less than Brute force.

Shifts Rate: Shifts per running time is least for Boyer-Moore. It reduces shifts by 39251.5 compared to Horspool and 183277.35 compared to Brute Force.




-------------------------------------------------------------------
                      Word-9: off   		                  | 
-------------------------------------------------------------------
Comparison Criteria         | Brute Force | Horspool | Boyer-Moore| 
-------------------------------------------------------------------
Matches                     | 930         | 930      | 930        | 
-------------------------------------------------------------------
Shifts                      | 3295658     | 1129915  | 1126594    | 
-------------------------------------------------------------------
Running Time (ms)           | 17.554      | 9.353    | 16.880     |
-------------------------------------------------------------------
Shift Ratio(Shifts/Run Time)| 187743.99   | 120807.76| 66741.35   |
-------------------------------------------------------------------

Observation:

Matches: All 3 algorithms have same number of matches 930.

Shifts: Boyer Moore requires least number of shifts. 3321 less than Horspool and 2169064 less than Brute Force.

Running Time: Horspool requires least amount of time. 7.527 ms less than Boyer-Moore and 8.201 ms less than Brute force.

Shifts Rate: Shifts per running time is least for Boyer-Moore. It reduces shifts by 54066.41 compared to Horspool and 121002.64 compared to Brute Force.



-------------------------------------------------------------------
                     Word-10: throughextracurricular              | 
-------------------------------------------------------------------
Comparison Criteria         | Brute Force | Horspool | Boyer-Moore| 
-------------------------------------------------------------------
Matches                     | 7           | 7        | 7          | 
-------------------------------------------------------------------
Shifts                      | 3296562     | 215627   | 207225     | 
-------------------------------------------------------------------
Running Time (ms)           | 15.329      | 2.249    | 3.927      |
-------------------------------------------------------------------
Shift Ratio(Shifts/Run Time)| 215053.95   | 95876.83 | 52769.29   |
-------------------------------------------------------------------

Observation:

Matches: All 3 algorithms have same number of matches 7.

Shifts: Boyer Moore requires least number of shifts. 8402 less than Horspool and 3089337 less than Brute Force.

Running Time: Horspool requires least amount of time. 1.678 ms less than Boyer-Moore and 13.08 ms less than Brute force.

Shifts Rate: Shifts per running time is least for Boyer-Moore. It reduces shifts by 43107.54 compared to Horspool and 162284.66 compared to Brute Force.


Average Performance Horspool vs Brute Force:
Average performance for Brute Force (10 words) = 241852.64 shifts/ms
Average Performance for Horspool algorithm (10 words) = 122000.49 shifts/ms

Analysis of the results:

1. Correctness: All the algorithms produced correct results and thus can be used. However, their efficiencies vary depending on the shift counts.

2. Running Time: The Horspool algorithm had the least running time for all the patterns. It was faster than the Brute Force due to the fact that Brute Force performs 1 character advancement each step and thus there are several repeated comparisons whereas Horspool can perform multiple character shifts in a single step by using Shift Table Lookups. The lookup table since computed only once the shifts are O(1) lookups and is thus much faster and prevents many repeat character comparisons that are done in brute force.

3. Pattern Shifts: Horspools algorithm performs order of magnitude less number of shifts compared to the Brute Force algorithm and is particularly a lot faster for smaller patterns. The Horspools algorithm is very efficient in terms of running time though for longer patterns there are more shifts compared to Boyer Moore.


4. Shifting Ratio (Performance Parameter): Horspool is better than Brute Force as it has lower number of shifts per milisecond compared to the Brute Force implementation. The difference is more prominent during longer pattern sequence where the Horspools algorithm can take longer jumps and avoid repeated computations for failed attempts that are introduced in the brute force implementation. For longer patterns there is order of magnitude better performance by Horspool compared to shorter patterns where there is less performance improvement.
