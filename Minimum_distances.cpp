#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'minimumDistances' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY a as parameter.
 */

int minimumDistances(vector<int> a)
{
    std::ptrdiff_t distance = std::distance(a.begin(), a.end());
    int diff{-1};
    for (int number : a)
    {
        std::vector<int>::iterator it = std::find(a.begin(), a.end(), number);
        std::vector<int>::iterator second_it = std::find(it+1, a.end(), number);
        if (second_it != std::end(a))
        {
            
            if (std::distance(it, second_it) < distance)
            {
                distance = std::distance(it, second_it);
                diff = distance;
            }
        }
    }
    return diff;
}

int main()
{

    std::vector<int> a = {1, 2, 3, 4, 10};
    int result = minimumDistances(a);


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
