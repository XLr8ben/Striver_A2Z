#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
using namespace std;

// Z 
// Y Z 
// X Y Z 
// W X Y Z 
// V W X Y Z 
// U V W X Y Z 
// T U V W X Y Z 
// S T U V W X Y Z 
// R S T U V W X Y Z 
// Q R S T U V W X Y Z 
// P Q R S T U V W X Y Z 
// O P Q R S T U V W X Y Z 
// N O P Q R S T U V W X Y Z 
// M N O P Q R S T U V W X Y Z 
// L M N O P Q R S T U V W X Y Z 
// K L M N O P Q R S T U V W X Y Z 
// J K L M N O P Q R S T U V W X Y Z 
// I J K L M N O P Q R S T U V W X Y Z 
// H I J K L M N O P Q R S T U V W X Y Z 
// G H I J K L M N O P Q R S T U V W X Y Z 
// F G H I J K L M N O P Q R S T U V W X Y Z 
// E F G H I J K L M N O P Q R S T U V W X Y Z 
// D E F G H I J K L M N O P Q R S T U V W X Y Z 
// C D E F G H I J K L M N O P Q R S T U V W X Y Z 
// B C D E F G H I J K L M N O P Q R S T U V W X Y Z 
// A B C D E F G H I J K L M N O P Q R S T U V W X Y Z 


// Approach
// The goal is to print a pattern of alphabets where each row starts with a letter that is progressively closer to 'A' as we move down. The last column always has the letter 'A' + N - 1, and in each row, we print an increasing sequence from a starting letter up to this last letter.

// Loop through each row i from 0 to N-1.
// For each row, determine the starting character:
// startChar = ('A' + N - 1) - i
// Print characters from startChar to ('A' + N - 1).
// Move to the next line after printing each row.

// Time Complexity: O(N2), as We print roughly N*(N+1)/2 characters.
// Space Complexity: O(1), as No extra space used apart from variables for iteration.

void Solution(int n){
    for(int i=0;i<n;i++){

        for(char j=('A'+n-1)-i;j<='A'+n-1;j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int n;
    cin>>n;

    Solution(26);

    return 0;
}
