//==============================================
// Name:          Majd Homsi
// Date:          2021-02-03
// Student Number: 113692206
// Email:          mhomsi1@myseneca.ca
// Section:        NAA
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//==============================================

#include "cstring.h"

namespace sdds
{
	// Copies the srouce character string into the destination
	void strCpy(char* des, const char* src)
	{
		int i;
		for (i = 0; src[i]; i++)
		{
			des[i] = src[i]; // Copy the Characters
		}

		//Uses a null at the end of the string
		des[i] = '\0';
	}
	// Copies the source character string into the destination upto "len"
	// characters. The destination will be null terminated only if the number
	// of the characters copied is less than "len"
	void strnCpy(char* des, const char* src, int len)
	{
		int i;

		for (i = 0; src[i] != '\0'; i++)
		{
			// if ( i > len) 

			if (i < len)
			{
				des[i] = src[i];   // des will be equal src
			}
		}

		if (i < len)
		{
			des[i] = '\0'; // << This might cause the memeory to overload, there might be a better way out 
		}


	}

	// Compares two C-strings 
	// returns 0 i thare the same
	// return > 0 if s1 > s2
	// return < 0 if s1 < s2
	int strCmp(const char* s1, const char* s2)
	{
		int i = 0;

		//incriment i++ and we need *s1 to = to *s2 (adding a null terminator)

		while (s1[i] == s2[i] && s1[i] != '\0') i++;

		if (s1[i] > s2[i])
		{
			return 1;
		}
		else if (s1[i] < s2[i])
		{
			return -1;
		}
		else return 0;
	}

	// returns 0 i thare the same
	// return > 0 if s1 > s2
	// return < 0 if s1 < s2
	int strnCmp(const char* s1, const char* s2, int len)
	{
		int i = 0;

		// would need a while loop where s1 and s1 are equal to eachother, when s1 is not == to a null terminator

		while (s1[i] == s2[i] && s1[i] != '\0' && i < len - 1) i++;

		if (s1[i] > s2[i])
		{
			return 1;
		}
		// an else if that would detirmine that s1 i is less than s2 array i 
		else if (s1[i] < s2[i])
		{
			return -1;
		}
		else return 0;
	}

	// returns the lenght of the C-string in character
	//calculates the length between the characters--
	int strLen(const char* s)
	{
		int i; //The number of chars inside the C-String included
		for (i = 0; s[i] != '\0'; i++)
		{

		}
		return i;
	}
	//// returns the address of first occurance of "str2" in "str1"
	//// returns nullptr if no match is found
	const char* strStr(const char* str1, const char* str2)
	{
		char ch = str2[0];

		//resulting string

		while (*str1 != '\0')
		{
			// an if statment that would find the character string if *str1 would == to char
			if (*str1 == ch)

			{
				const char* t = str1;
				str1++;

				char ch1 = str2[1];

				while (*str1 != '\0') //Checks for the next Character on the list
				{
					if (*str1 == ch1)
					{
						return t; //return the const string initialized as a char
					}
					else
					{
						return nullptr;
					}
					str1++;
					str2++;
				}
			}
			str1++;
		}
		return str1;
	}

	// Concantinates "src" C-string to the end of "des"
	void strCat(char* des, const char* src)
	{
		int i, j;

		for (i = 0; des[i] != '\0'; i++); // This for loop will find the ending of des

		for (j = 0; src[j] != '\0'; j++, i++) // This For loop will append src
			des[i] = src[j];

		des[i] = '\0';	// The NULL terminator will terminate des by the end
	}

}
