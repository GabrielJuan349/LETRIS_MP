#include "Dictionary.h"

Dictionary::Dictionary(){
	
	string word;

	ifstream doc1,doc2,doc3;

	doc1.open("./data/Dictionaries/Catalan.dic");
	doc2.open("./data/Dictionaries/Spanish.dic");
	doc3.open("./data/Dictionaries/English.dic");


	if (doc1.is_open()) {

		while (!doc1.eof())
		{
			doc1 >> word;
			m_Catalan.push_back(word);
			
		}
		doc1.close();
	}

	if (doc2.is_open()) {

		while (!doc2.eof())
		{
			doc2 >> word;
			m_Spanish.push_back(word);

		}
		doc2.close();
	}

	if (doc3.is_open()) {

		while (!doc3.eof())
		{
			doc3 >> word;
			m_English.push_back(word);

		}
		doc3.close();
	}
}

bool Dictionary::SearchWord(const vector<char>wordenter) {

	std::string word(wordenter.begin(), wordenter.end());

	cout << word << endl;

	string wordfound;
	bool trobat = false;
	

	switch (m_language)
	{	
	case 0: {//catalan
		vector<string>::iterator arrfin = m_Catalan.end();
		vector<string>::iterator i = m_Catalan.begin();

		while ((i != arrfin) && (!trobat)) {

			wordfound = (*i);

			if (word == wordfound) {
				trobat = true;
			}
			else {
				trobat = false;
				i++;
			}
			
		}
		break;
	}
	case 1:{ //castellano

		vector<string>::iterator arrfin = m_Spanish.end();
		vector<string>::iterator i = m_Spanish.begin();

		while ((i != arrfin) && (!trobat)) {

			wordfound = (*i);

			if (word == wordfound) {
				trobat = true;
			}
			else {
				trobat = false;
				i++;
			}
		}
		break;

	} 
	case 2:{ //ingles

		vector<string>::iterator arrfin = m_English.end();
		vector<string>::iterator i = m_English.begin();

		while ((i != arrfin) && (!trobat)) {

			wordfound = (*i);

			if (word == wordfound) {
				trobat = true;
			}
			else {
				trobat = false;
				i++;
			}
		}
		break;
}
	default:
		break;
	}

	return trobat;
}