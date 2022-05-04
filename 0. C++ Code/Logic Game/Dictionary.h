#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;


class Dictionary
{
public:

	Dictionary();
	~Dictionary() {}
	void SelectLanguage(int language) { m_language = language; }
	bool SearchWord(const vector<char>wordenter);

private:

	int m_language;
	vector<string> m_Catalan;
	vector<string> m_Spanish;
	vector<string> m_English;
};

