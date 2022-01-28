#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'pangrams' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string pangrams(string s)
{
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c)
                   { return std::tolower(c); });
    for (int i = 0; i < alphabet.size(); i++)
    {
        std::size_t found = s.find(alphabet[i]);
        std::cout<<alphabet[i]<<std::endl;
        if(found != std::string::npos){
            alphabet.erase(i,1);
            i--;
        }
    }
    if (alphabet.empty()){
        return "pangram";
    }
    else{
        return "not pangram";
    }
}

int main()
{


    string s = "We promptly judged antique ivory buckles for the next prize";

    string result = pangrams(s);

    return 0;
}
