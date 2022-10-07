Given two strings str1 and str2, the task is to find the length of the shortest string that has both str1 and str2 as subsequences.
Input:   str1 = "geek",  str2 = "eke"
Output: 5
Explanation: 
String "geeke" has both string "geek" 
and "eke" as subsequences.

Input:   str1 = "AGGTAB",  str2 = "GXTXAYB"
Output:  9
Explanation: 
String "AGXGTXAYB" has both string 
"AGGTAB" and "GXTXAYB" as subsequences.

This problem is closely related to longest common subsequence problem. Below are steps.
1) Find Longest Common Subsequence (lcs) of two given strings. For example, lcs of “geek” and “eke” is “ek”. 
2) Insert non-lcs characters (in their original order in strings) to the lcs found above, and return the result. So “ek” becomes “geeke” which is shortest common 
supersequence.
Let us consider another example, str1 = “AGGTAB” and str2 = “GXTXAYB”. LCS of str1 and str2 is “GTAB”. Once we find LCS, we insert characters of both strings in
order and we get “AGXGTXAYB”
How does this work? 
We need to find a string that has both strings as subsequences and is shortest such string. If both strings have all characters different, then result is sum of 
lengths of two given strings. If there are common characters, then we don’t want them multiple times as the task is to minimize length. Therefore, we first find 
the longest common subsequence, take one occurrence of this subsequence and add extra characters. 

Length of the shortest supersequence  
= (Sum of lengths of given two strings) 
- (Length of LCS of two given strings) 

// code

#include <bits/stdc++.h>
using namespace std;

// Utility function to get max
// of 2 integers
int max(int a, int b) { return (a > b) ? a : b; }

// Returns length of LCS for
// X[0..m - 1], Y[0..n - 1]
int lcs(char* X, char* Y, int m, int n);

int shortestSuperSequence(char* X, char* Y)
{
	int m = strlen(X), n = strlen(Y);

	int l = lcs(X, Y, m, n);

	return (m + n - l);
}


int lcs(char* X, char* Y, int m, int n)
{
	int L[m + 1][n + 1];
	int i, j;

	for (i = 0; i <= m; i++) {
		for (j = 0; j <= n; j++) {
			if (i == 0 || j == 0)
				L[i][j] = 0;

			else if (X[i - 1] == Y[j - 1])
				L[i][j] = L[i - 1][j - 1] + 1;

			else
				L[i][j] = max(L[i - 1][j], L[i][j - 1]);
		}
	}

	// L[m][n] contains length of LCS
	// for X[0..n - 1] and Y[0..m - 1]
	return L[m][n];
}

// Driver code
int main()
{
	char X[] = "AGGTAB";
	char Y[] = "GXTXAYB";

	cout << "Length of the shortest supersequence is "
		<< shortestSuperSequence(X, Y) << endl;

	return 0;
}
