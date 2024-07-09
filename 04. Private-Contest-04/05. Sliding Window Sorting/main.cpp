// [Link]="https://www.hackerrank.com/contests/iiit-hyd-private-contest-4/challenges/sliding-window-sorting"
// Overall Time Complexity
// Reading Input: O(n)
// Building next_greater: O(n)
// Building min_suffix: O(n)
// Finding idx: O(n)
// Sorting the Segment: O(nlogn)
// Outputting the Result: O(n)
// Combining these, the overall time complexity of the algorithm is: O(nlogn) [This is efficient and optimal]

#include<bits/stdc++.h>
using namespace std;

int n = 0, k = 0;
// a slightly larger size is to avoid boundary issues like off-by-one errors
// you can even have an array size-of 200006 or 200004...
int P[200005], min_suffix[200005], next_greater[200005];


int main(void) {
	cin >> n >> k;
	
	// Loop through each index from 1 to n (inclusive) to read fiven P input
	for (int i = 1; i <= n; i++) { cin >> P[i]; }

	// Building the next_greater array, that helps to determine the position of the next element that is greater than or equal to the 
	// current element in the permutation P. This array is used later to identify the optimal position to sort a segment of length K, 
	// to maximize the lexicographical order of the permutation. If you implemented count_sort before it is the same analogy
	for (int i = n; i >= 1; i--) {
		if (P[i] < P[i + 1]) {
            next_greater[i] = next_greater[i + 1];
        } else { 
            next_greater[i] = i; 
        }
	}

	/* Building the min_suffix array, which helps keep track of the minimum value in suffix of the permutation P starting from a specific position's. 
	This is useful for determining if sorting a particular segment will result in a lexicographically larger permutation by ensuring that the element
	just before the segment is smaller than the minimum element in the suffix starting from the end of the segment. */
	/* Why to have length of n - k + 1? Starting at n - k + 1 is crucial because it represents the beginning of the last possible segment of length K 
	in the permutation P. */
	min_suffix[n - k + 1] = P[n - k + 1];

	/*	Loop starts from n - k + 2 because we have already initialized min_suffix[n - k + 1]. Need to fill the rest of the min_suffix array to capture the 
		minimum value from the current position to the end of the array. */
	for (int i = n - k + 2; i <= n; i++) {
        min_suffix[i] = min(min_suffix[i - 1], P[i]);
    }

	// Initialize idx to last possible starting pos. where a segment of length K can be sorted. 
	// This ensures that idx is valid even if no other starting position is found to be better.
	int idx = n - k + 1;

	for (int i = 1; i <= n - k; i++) {

		// 'i <= n - 2 * k + 1' condition ensures there is enough room to sort another segment of length K after the current one.
		// 'next_greater[i] >= i + k - 1' condition ensures that the segment starting at i remains non-decreasing up to i + k -1.
		if ((i <= n - 2 * k + 1) && (next_greater[i] >= i + k - 1)) {
			// If both conditions are met, idx is updated to the minimum of i and the current value of idx.
            idx = min(i, idx);
			// 'next_greater[i] >= n - k + 1' condition ensures that from position i, there is a non-decreasing sequence up to the end of the array.
			// 'P[n - k] < min_suffix[i + k - 1]' condition ensures that the element just before the segment is smaller than the minimum element in 
			// the suffix starting at i + k - 1.
        } else if ((next_greater[i] >= n - k + 1) && (P[n - k] < min_suffix[i + k - 1])) {
			// If both conditions are met, idx is updated to the minimum of i and the current value of idx.
            idx = min(i, idx);
        }
	}

	// Now, we succesfully found out the position of break (idx), simply performing sort will your answer...
	// P + idx is a pointer to the beginning of the segment to be sorted.
	// P + idx + k is a pointer to the position just after the end of the segment to be sorted.
	sort(P + idx, P + idx + k);

	for (int i = 1; i <= n; i++) {
        cout << P[i] << " ";
    }

	return 0;
}
