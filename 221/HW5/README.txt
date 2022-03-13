Jackson Darling, HW5 - Griddle Pie

1. 
gridpi(10) = 3.520000
gridpi(100) = 3.181200
gridpi(500) = 3.149376
gridpi(1000) = 3.135544
gridpi(10000) = 3.141990

2.
The complxity of gridpi is (On^2) because of the nested for-loop needed for N^2 number of points
 for N=10: 0m0.010s
 for N=100: 0m0.008s
 for N=1000: 0m0.108s

This (roughly) follows the compexity (On^2). The difference between N=10 and N=100 is negligible; the differece between N=100 and N=1000 roughly follows the model. 
For experimentation, I ran the program with N=10000 and got... 0m0.05s. I believe that the variability is too high. 

3. 
For the constant expression:
 for N=10: 0m0.008s and pi = 3.5200000
 for N=100: 0m0.010s and pi = 3.181200
 for N=1000: 0m0.008s and pi = 3.145544 

 The compile time was *slightly* higher than the non-constant function but the runtime is much fast (especially as N grows larger).
 Using constant allows the compiler to evaluate the function at compile time and increases performance during run time operation.
 
