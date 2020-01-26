#ifdef _MSC_VER
#pragma warning(disable:4503)      // `silence compiler complaints about generated names being too long'
#endif

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>
#include <list>
#include "split.h"
#include <time.h>

using std::istream;           using std::cin;
using std::copy;              using std::cout;
using std::endl;              using std::find;
using std::getline;           using std::logic_error;
using std::map;               using std::string;
using std::list;              using std::domain_error;
using std::rand;

typedef list<string> Rule;
typedef list<Rule> Rule_collection;
typedef map<string, Rule_collection> Grammar;

// read a grammar from a given input stream
Grammar read_grammar(istream& in)
{
	Grammar ret;
	string line;
	cout << "reading grammar ... \n";
	// read the input
	while (getline(in, line)) {
    cout << line << '\n';
		// `split' the input into words
		list<string> entry = split_to_list(line);
			cout << entry.size() << endl;
		if (!entry.empty())
			// use the category to store the associated rule
			cout << "first word of line: " << *entry.begin() << '\n';
			ret[*entry.begin()].push_back(
				Rule(++entry.begin(), entry.end()));
	}
		cout << "reading grammar is finished \n";
	return ret;
}

void gen_aux(const Grammar&, const string&, list<string>&);

int nrand(int);

list<string> gen_sentence(const Grammar& g)
{
	cout << "getting sentence...\n";
	list<string> ret;
	gen_aux(g, "<sentence>", ret);
	cout << "sentence is got\n";
	return ret;
}

bool bracketed(const string& s)
{
	return s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>';
}

void gen_aux(const Grammar& g, const string& word, list<string>& ret)
{

	cout << "gen_aux ...\n";
	if (!bracketed(word)) {
		ret.push_back(word);
	} else {
		// locate the rule that corresponds to `word'
		Grammar::const_iterator it = g.find(word);
		if (it == g.end())
			throw logic_error("empty rule");

		// fetch the set of possible rules
		const Rule_collection& c = it->second;

		int rand_num = nrand(c.size());
		Rule_collection::const_iterator rndRule = c.begin();
		for( Rule_collection::size_type sz = 0; sz < rand_num; sz++){
			rndRule++;
		}
		// from which we select one at random
		const Rule& r = *rndRule;

		// recursively expand the selected rule
		for (Rule::const_iterator i = r.begin(); i != r.end(); ++i)
			gen_aux(g, *i, ret);
	}

	cout << "gen_aux is finshed\n";
}

int main()
{
	// generate the sentence
	list<string> sentence = gen_sentence(read_grammar(cin));
	cout << "sentence is read";
	// write the first word, if any
#ifdef _MSC_VER
	std::vector<string>::const_iterator it = sentence.begin();
#else
	list<string>::const_iterator it = sentence.begin();
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

