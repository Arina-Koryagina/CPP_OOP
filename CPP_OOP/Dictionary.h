#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cassert>
#include <iomanip>

using namespace std;

class Dictionary
{
	map<string, int> m;

	string normalize(string word)
	{
		transform(word.begin(), word.end(), word.begin(), [](unsigned char c){ return tolower(c); });

		while (!word.empty() && ispunct(word.front())) // ...hello... -> hello...
		{
			word.erase(word.begin());
		}
		while (!word.empty() && ispunct(word.back())) // hello... -> hello
		{
			word.pop_back();
		}

		return word;
	}

public:
	int& operator[](const string& key);

	void readFile(string path);
	void showStats() const;
	void showStats(size_t n) const;
	void saveStats();
};

int& Dictionary::operator[](const string& key)
{
	return m[key];
}

void Dictionary::readFile(string path)
{
	ifstream in(path);
	string word;
	if (in.is_open())
	{
		while (in >> word)
		{
			word = normalize(word);

			if (!word.empty())
			{
				m[word]++;
			}
		}
	}
	else
	{
		throw runtime_error("File \"" + path + "\" not found");
	}
	in.close();
}

void Dictionary::showStats() const
{
	for (auto elem : m)
	{
		cout << setw(15) << left << elem.first << " " << elem.second << endl;
	}
	cout << "Words: " << m.size() << endl;
}
void Dictionary::showStats(size_t n) const
{
	if (n == 0)
		throw invalid_argument("N must be greater than zero");

	n = min(n, m.size()); // if n > size, display size. noexcept

	vector<pair<string, int>> v(m.begin(), m.end());

	partial_sort(v.begin(), v.begin() + n, v.end(), //https://en.cppreference.com/cpp/algorithm/ranges/partial_sort
		[](const auto& a, const auto& b)
		{
			return a.second > b.second;
		}
	);

	for (size_t i = 0; i < n; i++)
	{
		cout << i + 1 << ". " << setw(15) << left << v[i].first << " " << v[i].second << endl;
	}
}

void Dictionary::saveStats()
{
	ofstream out("log.txt");
	if (out.is_open())
	{
		out << m.size() << endl;
		for (auto elem : m)
		{
			out << elem.first << ";" << elem.second << endl;
		}
	}
	else
	{
		throw runtime_error("Unable to open the file: \"log.txt\"");
	}
	out.close();
}