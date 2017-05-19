#include <vector>
#include <iostream>
#include <string>

std::vector<std::string>  reversed_tokenizer(const std::string & inp, const std::string & delim)
{
    std::vector<std::string>                rv;
    std::string::const_reverse_iterator     it_b, it_e;

    it_b=it_e=inp.rbegin();

    while (it_b!=inp.rend())
    {
        //  crawl from the back of the string towards the beginning 
        //  until all delimeters are encountered
        for (; delim.find(*it_b)!=std::string::npos && it_b!=inp.rend(); ++it_b);

        it_e = it_b;

        //  now crawl till characters word characters are still encountered
        for (; it_b!=inp.rend(); ++it_b)
        {
            if (delim.find(*it_b)!=std::string::npos) break;
        }

        //  it_b, it_e point to the beginning and the end of the word in the string,
        //  so use them to grab the word
        size_t pos_b = std::distance (it_b, inp.rend());
        size_t pos_e = std::distance (it_e, inp.rend());
            
        std::string word = inp.substr(pos_b, pos_e-pos_b);

        //  if the word is not empty string, push it to the list (i.e. vector) of words
        if (word.length()>0) 
            rv.emplace_back (word);
    }

    return rv;
}

void print_tokens (const std::vector<std::string> & tokens)
{
    for (auto & x : tokens)
        std::cout << x <<" ";

        std::cout << "\n";
}

int main()
{

    {
        auto rv = reversed_tokenizer ("fox   jumped     high, !!! another word", ", !");
        
        print_tokens (rv);
    }

    {
        auto rv = reversed_tokenizer ("      ", ", !");
        
        print_tokens (rv);
    }


    {
        auto rv = reversed_tokenizer ("singleword", ", !");
        
        print_tokens (rv);
    }

    {
        auto rv = reversed_tokenizer ("", ", !");
        
        print_tokens (rv);
    }

}

