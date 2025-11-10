#include <stdio.h>  // This lets us use "scanf" (to read input) and "printf" (to print output).

int main() {        // Every C program starts here—like the "start" button.
    int L, R;       // Make two "boxes" in memory: one for L (start number), one for R (end number).
    scanf("%d %d", &L, &R);  // Read two numbers from keyboard, put them in L and R. (The & means "put it here".)
    int found = 0;  // A simple flag: 0 means "no good number yet", 1 means "found one!".
    for(int x = L; x <= R; x++) {  // Start at x = L, try each number up to R, add 1 each time.
        int temp = x;              // Copy x to "temp" so we can break it apart without messing up x.
        int mask = 0;              // A "flag number" to remember which digits we've seen (like 10 tiny switches, all off).
        int unique = 1;            // Start assuming this x has all unique digits (1 = yes).
        while(temp > 0) {          // Keep going until we've checked every digit in temp.
            int d = temp % 10;     // Grab the last digit (like 123 % 10 = 3).
            if(mask & (1 << d)) {  // Check if we've seen this digit before (using a bit "switch").
                unique = 0;        // Oops, repeat! Mark it as not unique.
                break;             // Stop checking this x—it's bad.
            }
            mask = mask | (1 << d); // Flip the "switch" for this digit so we remember it.
            temp = temp / 10;      // Remove the last digit (123 / 10 = 12).
        }
        if(unique) {               // If no repeats found...
            printf("%d\n", x);     // ...print this x and a new line.
            found = 1;             // Set flag to "yay, found it!".
            break;                 // Stop looking—we're done.
        }
    }
    if(found == 0) {           // If we checked everything and flag is still 0...
        printf("-1\n");        // ...print -1 and a new line.
    }
    return 0;                  // Tell the computer "all good, end program".
}