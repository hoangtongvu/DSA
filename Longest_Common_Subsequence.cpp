#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;


int Lcs(string s1, int length1, string s2, int length2)
{
	if (length1 == 0 || length2 == 0) return 0;
	
	if (s1[length1 - 1] == s2[length2 - 1]) return 1 + Lcs(s1, length1 - 1, s2, length2 - 1);
	
	return max(Lcs(s1, length1 - 1, s2, length2), Lcs(s1, length1, s2, length2 - 1));

}




int main()
{
	string s1 = "AGGTAB";
	string s2 = "GXTXAYB";
	cout << Lcs(s1, s1.size(), s2, s2.size());

    return 0;
}

