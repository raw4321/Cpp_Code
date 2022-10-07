// Longest Common Subsequence


LCS Problem Statement: Given two sequences, find the length of longest subsequence present in both of them. A subsequence is a sequence that appears in the same 
relative order, but not necessarily contiguous. For example, “abc”, “abg”, “bdf”, “aeg”, ‘”acefg”, .. etc are subsequences of “abcdefg”. 

In order to find out the complexity of brute force approach, we need to first know the number of possible different subsequences of a string with length n, i.e., 
find the number of subsequences with lengths ranging from 1,2,..n-1. Recall from theory of permutation and combination that number of combinations with 1 element 
are nC1. Number of combinations with 2 elements are nC2 and so forth and so on. We know that nC0 + nC1 + nC2 + … nCn = 2n. So a string of length n has 2n-1 different 
possible subsequences since we do not consider the subsequence with length 0. This implies that the time complexity of the brute force approach will be O(n * 2n).
  Note that it takes O(n) time to check if a subsequence is common to both the strings. This time complexity can be improved using dynamic programming.

It is a classic computer science problem, the basis of diff (a file comparison program that outputs the differences between two files), and has applications in 
bioinformatics

Examples: 
LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3. 
LCS for input Sequences “AGGTAB” and “GXTXAYB” is “GTAB” of length 4. 
  
// C++ program to find length of the
// shortest supersequence
#include <bits/stdc++.h>
using namespace std;


int max(int a, int b) { return (a > b) ? a : b; }

int lcs(char* X, char* Y, int m, int n);

int shortestSuperSequence(char* X, char* Y)
{
	int m = strlen(X), n = strlen(Y);

	// find lcs
	int l = lcs(X, Y, m, n);

	// Result is sum of input string
	// lengths - length of lcs
	return (m + n - l);
}

// Returns length of LCS
// for X[0..m - 1], Y[0..n - 1]
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


	return L[m][n];
}


int main()
{
	char X[] = "AGGTAB";
	char Y[] = "GXTXAYB";

	cout << "Length of the shortest supersequence is "
		<< shortestSuperSequence(X, Y) << endl;

	return 0;
}

