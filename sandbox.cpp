#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'sockMerchant' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER_ARRAY ar
 */

int sockMerchant(int n, vector<int> ar)
{
    std::map<int, int> pairs;
    int matchedPair{};
    for (auto element : ar)
    {
        if (pairs.find(element) != pairs.end())
        {
            pairs.at(element)++;
        }
        else
        {
            pairs.insert(std::pair<int, int>(element, 1));
        }
    }
    auto it = pairs.begin();
    while (it != pairs.end())
    {
        double pairQuantity = (double)(it->second) / 2;
        if (floor(pairQuantity) > 0)
        {
            auto currentPair = it->second / 2;
            matchedPair += currentPair;
        }
        it++;
    }
    return matchedPair;
}

int main()
{
    int n = 9;
    std::vector<int> ar = {10, 20, 20, 10, 10, 30, 50, 10, 20};

    int result = sockMerchant(n, ar);

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}

vector<string> split(const string &str)
{
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos)
    {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
