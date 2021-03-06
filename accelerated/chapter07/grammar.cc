#ifdef _MSC_VER
#pragma warning(disable : 4503) // `silence compiler complaints about generated names being too long'
#endif
#include <list>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>
#include <vector>
#include <iterator>
#include "split.h"
#include <time.h>

using std::cin;
using std::copy;
using std::cout;
using std::domain_error;
using std::endl;
using std::find;
using std::getline;
using std::istream;
using std::logic_error;
using std::map;
using std::rand;
using std::string;
using std::vector;
using std::list;
typedef vector<string> Rule;
typedef vector<Rule> Rule_collection;
typedef map<string, Rule_collection> Grammar;

// read a grammar from a given input stream
Grammar read_grammar(istream &in)
{
	Grammar ret;
	string line;

	// read the input
	while (getline(in, line))
	{
		cout << "Read line " << line << "\n";
		// `split' the input into words
		vector<string> entry = split(line);

		if (!entry.empty())
			// use the category to store the associated rule
			ret[entry[0]].push_back(
				Rule(entry.begin() + 1, entry.end()));
	}
	return ret;
}

void gen_aux(const Grammar &, const string &, vector<string> &);

int nrand(int);
bool bracketed(const string &);
vector<string> gen_sentence(const Grammar &g)
{
	cout << "Generting sentence ...\n";
	vector<string> ret;
	vector<string> tokens;
	tokens.push_back("<sentence>");
	while (!tokens.empty())
	{
		string token = tokens.back();
		tokens.pop_back();
		if (!bracketed(token))
		{
			ret.push_back(token);
		}
		else
		{
			Grammar::const_iterator it = g.find(token);
			if (it == g.end())
				throw logic_error("empty rule");
			const Rule_collection c = it->second;
			Rule::size_type n = nrand(c.size());
			const Rule r = c[n];
			for (Rule::const_reverse_iterator it = r.rbegin(); it != r.rend(); it++)
				tokens.push_back(*it);
		}
	}
	return ret;
}

template <class It>
void gen_sentence_it(const Grammar &g, It b)
{
	cout << "Generting sentence ...\n";
	vector<string> ret;
	vector<string> tokens;
	tokens.push_back("<sentence>");
	while (!tokens.empty())
	{
		string token = tokens.back();
		tokens.pop_back();
		if (!bracketed(token))
		{
			*b=token;
			b++;
		}
		else
		{
			Grammar::const_iterator it = g.find(token);
			if (it == g.end())
				throw logic_error("empty rule");
			const Rule_collection c = it->second;
			Rule::size_type n = nrand(c.size());
			const Rule r = c[n];
			for (Rule::const_reverse_iterator it = r.rbegin(); it != r.rend(); it++)
				tokens.push_back(*it);
		}
	}
}

bool bracketed(const string &s)
{
	return s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>';
}

void gen_aux(const Grammar &g, const string &word, vector<string> &ret)
{

	if (!bracketed(word))
	{
		cout << word << " is word\n";
		ret.push_back(word);
	}
	else
	{
		cout << word << " is rule!\n";
		// locate the rule that corresponds to `word'
		Grammar::const_iterator it = g.find(word);
		if (it == g.end())
			throw logic_error("empty rule");

		// fetch the set of possible rules
		const Rule_collection &c = it->second;

		// from which we select one at random
		const Rule &r = c[nrand(c.size())];

		// recursively expand the selected rule
		for (Rule::const_iterator i = r.begin(); i != r.end(); ++i)
			gen_aux(g, *i, ret);
	}
}

int main()
{
	srand(time(NULL));
	// generate the sentence
	vector<string> sentence;
	//sentence =  gen_sentence(read_grammar(cin));
	list<string> sentence_l;
	//gen_sentence_it(read_grammar(cin), std::back_inserter( sentence_l));
	//gen_sentence_it(read_grammar(cin), std::back_inserter(sentence));
	// write the first word, if any
	
	gen_sentence_it(read_grammar(cin), std::ostream_iterator<string>(cout, " "));
#ifdef _MSC_VER
	std::vector<string>::const_iterator it = sentence.begin();
#else
	list<string>::const_iterator it = sentence_l.begin();
#endif
	if (!sentence_l.empty())
	{
		cout << *it;
		++it;
	}

	// write the rest of the words, each preceded by a space
	while (it != sentence_l.end())
	{
		cout << " " << *it;
		++it;
	}

	cout << endl;
	return 0;
}

// return a random integer in the range `[0,' `n)'
int nrand(int n)
{
	if (n <= 0 || n > RAND_MAX)
		throw domain_error("Argument to nrand is out of range");

	const int bucket_size = RAND_MAX / n;
	int r;

	do
		r = rand() / bucket_size;
	while (r >= n);

	return r;
}
