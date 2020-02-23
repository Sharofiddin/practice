#ifdef _MSC_VER
#pragma warning(disable:4503)      // `silence compiler complaints about generated names being too long'
#endif

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>
#include <vector>

#include "split.h"
#include <time.h>

using std::istream;           using std::cin;
using std::copy;              using std::cout;
using std::endl;              using std::find;
using std::getline;           using std::logic_error;
using std::map;               using std::string;
using std::vector;            using std::domain_error;
using std::rand;

typedef vector<string> Rule;
typedef vector<Rule> Rule_collection;
typedef map<string, Rule_collection> Grammar;

// read a grammar from a given input stream
Grammar read_grammar(istream& in)
{
	Grammar ret;
	string line;

	// read the input
	while (getline(in, line)) {
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

void gen_aux(const Grammar&, const string&, vector<string>&);

int nrand(int);
bool bracketed(const string& );
vector<string> gen_sentence(const Grammar& g)
{
	cout << "Generting sentence ...\n";
	vector<string> ret;
	Grammar::const_iterator rules_it = g.find("<sentence>");
	Rule_collection rules = rules_it->second;
	if( rules_it != g.end()){
		cout << "Sentence rule is found\n";
	}	else {
		cout << "Sentence rule is not found\n";
	}
	for (int i = 0;  i < rules.size(); i++)
	{
		cout << "Analyzing rule " << *rules[i].begin()<<"\n";
		Rule rule = rules[i];
		for(Rule::iterator words_it = rule.begin(); words_it != rule.end(); ++words_it){
			cout <<"Analyzing word " << *words_it <<"\n";
			if(!bracketed(*words_it)){
				cout << *words_it << " is word\n";
				ret.push_back(*words_it);
			} else {
				bool isRuleExist = true;
				while(isRuleExist){
					cout << *words_it << " is rule\n";
					Grammar::const_iterator test_it = g.find(*words_it);
					if (test_it == g.end())
						throw logic_error("empty rule");
					// fetch the set of possible rules
					const Rule_collection& c = test_it->second;

					// from which we select one at random
					const Rule& r = c[nrand(c.size())];

					rules.push_back(r);
					cout << "Rule added to collection\n";
				}
			}
		}
	}

	
	return ret;
}

bool bracketed(const string& s)
{
	return s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>';
}

void gen_aux(const Grammar& g, const string& word, vector<string>& ret)
{

	if (!bracketed(word)) {
		cout << word << " is word\n";
		ret.push_back(word);
	} else {
		cout << word << " is rule!\n";
		// locate the rule that corresponds to `word'
		Grammar::const_iterator it = g.find(word);
		if (it == g.end())
			throw logic_error("empty rule");

		// fetch the set of possible rules
		const Rule_collection& c = it->second;

		// from which we select one at random
		const Rule& r = c[nrand(c.size())];

		// recursively expand the selected rule
		for (Rule::const_iterator i = r.begin(); i != r.end(); ++i)
			gen_aux(g, *i, ret);
	}
}

int main()
{
	// generate the sentence
	vector<string> sentence = gen_sentence(read_grammar(cin));

	// write the first word, if any
#ifdef _MSC_VER
	std::vector<string>::const_iterator it = sentence.begin();
#else
	vector<string>::const_iterator it = sentence.begin();
#endif
	if (!sentence.empty()) {
		cout << *it;
		++it;
	}

	// write the rest of the words, each preceded by a space
	while (it != sentence.end()) {
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

	do r = rand() / bucket_size;
	while (r >= n);

	return r;
}

