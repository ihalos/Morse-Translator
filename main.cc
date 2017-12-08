#include <map>
#include <string>
#include <iterator>
#include <vector>
#include <algorithm>
#include <iostream>

//Initializes the morse table
void init_morse_table(std::map<char, std::string>& table)
{
  //Alphabet
  table['a'] = ".-";
  table['b'] = "-...";
  table['c'] = "-.-.";
  table['d'] = "-..";
  table['e'] = ".";
  table['f'] = "..-.";
  table['g'] = "--.";
  table['h'] = "....";
  table['i'] = "..";
  table['j'] = ".---";
  table['k'] = "-.-";
  table['l'] = ".-..";
  table['m'] = "--";
  table['n'] = "-.";
  table['o'] = "---";
  table['p'] = ".--.";
  table['q'] = "--.-";
  table['r'] = ".-.";
  table['s'] = "...";
  table['t'] = "-";
  table['u'] = "..-";
  table['v'] = "...-";
  table['w'] = ".--";
  table['x'] = "-..-";
  table['y'] = "-.--";
  table['z'] = "--..";

  //Numbers
  table['1'] = ".----";
  table['2'] = "..---";
  table['3'] = "...--";
  table['4'] = "....-";
  table['5'] = ".....";
  table['6'] = "-....";
  table['7'] = "--...";
  table['8'] = "---..";
  table['9'] = "----.";
  table['0'] = "----";
}

//Translates words to morse
std::vector<std::string> translate_to_morse(std::map<char, std::string> const& table,
					    std::vector<std::string> const& words)
{
  std::vector<std::string> result{};
  std::string morse_word{};

  for(auto & word : words)
    {
      for(auto c : word)
	{
	  morse_word.append(table.at(c));
	}
      result.push_back(morse_word);
      morse_word.clear();
    }

  return result;
}

int main()
{
  //Initialize map with all morse characters
  std::map<char, std::string> morse_table{};
  init_morse_table(morse_table);

  //Read all words from cin
  std::vector<std::string> words{std::istream_iterator<std::string>(std::cin),
      std::istream_iterator<std::string>()};

  //Convert all words to lower case
  std::for_each(begin(words), end(words),
		[](std::string& str){std::transform(begin(str),
						    end(str),
						    begin(str),
						    ::tolower);});

  //Translate the words to morse
  std::vector<std::string> morse_words {translate_to_morse(morse_table, words)};
  
  //Print the morse message
  std::copy(begin(morse_words),
	    end(morse_words),
	    std::ostream_iterator<std::string>(std::cout, " "));
  
  return 0;
}
