//==============================================
// Name:          Majd Homsi
// Date:          2021-02-03
// Student Number: 113692206
// Email:          mhomsi1@myseneca.ca
// Section:        NAA
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//==============================================

#ifndef SDDS_cstring_H
#define SDDS_cstring_H

namespace sdds
{
	void strCpy(char* des, const char* src);
	void strnCpy(char* des, const char* src, int len);
	int strCmp(const char* s1, const char* s2);
	int strnCmp(const char* s1, const char* s2, int len);
	int strLen(const char* s);
	const char* strStr(const char* str1, const char* str2);
	void strCat(char* des, const char* src);

}
#endif