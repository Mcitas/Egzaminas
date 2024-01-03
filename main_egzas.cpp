#include "head_egzas.h"

void simboliuPasalinimas(string& zodis) {
	string galutinis;
	for (char c : zodis) 
	{
		if (std::isalnum(c))
		{
			galutinis += std::tolower(c);
		}
	}
	if (galutinis != "")
	zodis = galutinis;
}

void count(string eil, map<string, int>& zodziai, map<string, vector<int>>& eilutes, int eil_sk) {
	stringstream ss(eil);
	string zodis;
	while (ss >> zodis) 
	{
		simboliuPasalinimas(zodis);
		zodziai[zodis]++;
		eilutes[zodis].push_back(eil_sk);
	}
}

void ieskotiURL(string failo_pav) {
	ifstream fd(failo_pav);
	ofstream fr("URL_rez.txt");
	regex urlRegex(R"((https?:\/\/[^\s]+)|(www\.[^\s]+)|(?:[^\.\/]+\.[^\.\/]+))");
	string eilutes;
	while (getline(fd, eilutes)) 
	{
		for (auto it = sregex_iterator(eilutes.begin(), eilutes.end(), urlRegex); it != sregex_iterator(); ++it)
		{
			string url = it->str();
			if (regex_match(url, regex(R"(https?:\/\/[^\s]+)")) || regex_match(url, regex(R"(www\.[^\s]+)")) ||
				regex_match(url, regex(R"(^[^\s]+\.(?:com|lt)$)")))
			{
				fr << url << endl;
			}
		}
	}

	fd.close();
	fr.close();
}

void WordCount() {
	map<string, int> zodziai;
	map<string, vector<int>> eilutes;
	string eil, failo_pav;
	int eil_sk = 0;
	cout << "Iveskite failo pavadinima: "; 
	cin >> failo_pav;
	ifstream fd(failo_pav);
	while (getline(fd, eil)) 
	{
		eil_sk++;
		count(eil, zodziai, eilutes, eil_sk);
	}
	fd.close();
	ieskotiURL(failo_pav);
	ofstream fr("Rezultatai.txt");
	for (const auto& pair : zodziai) 
	{
		if (pair.second > 1) 
		{
			fr << pair.first << ": " << pair.second << endl << "Eilutes, kuriose buvo rastas zodis " << pair.first << ": ";
			for (int i = 0; i < pair.second; i++) 
			{
				fr << eilutes[pair.first][i] << " ";
			}
			fr << endl;
		}
	}
	fr.close();

	cout << "Rezultatai isvesti i URL_rez.txt ir Rezultatai.txt";
}

int main() {
	WordCount();
	return 0;
}