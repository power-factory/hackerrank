#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'gameOfThrones' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string gameOfThrones(string s)
{
    std::string result = "NO";
    std::unordered_map<char, int> letterOccurence;
    for (char letter : s)
    {
        //This can be greately simplified using C++20 function std::unordered_map::contains

        if (letterOccurence.find(letter) != letterOccurence.end())
        {
            auto it = letterOccurence.find(letter);
            //it->second = (it->second)++;
            int tmp = letterOccurence[letter];
            letterOccurence[letter] = tmp+1;
        }
        else{
            std::pair<char,int> tmp = {letter,1};
            letterOccurence.insert(tmp);
        }
    }
    // We should have now hash map containing occurence of chars in string
    std::vector<int> evenLetters;
    std::vector<int> oddLetters;

    for (auto element : letterOccurence){
        if((element.second % 2) == 0){
            evenLetters.push_back(element.second);
        }
        else if((element.second % 2) == 1){
            oddLetters.push_back(element.second);
        }
    }
    if(oddLetters.size() >1){
        return "NO";
    }

    return "YES";
}

int main()
{


    string s = "cdcdcdcdeeeef";

    string result = gameOfThrones(s);

    return 0;
}
