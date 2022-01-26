#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'countApplesAndOranges' function below.
 *
 * The function accepts following parameters:
 *  1. INTEGER s
 *  2. INTEGER t
 *  3. INTEGER a
 *  4. INTEGER b
 *  5. INTEGER_ARRAY apples
 *  6. INTEGER_ARRAY oranges
 */

void countApplesAndOranges(int s, int t, int a, int b, vector<int> apples, vector<int> oranges)
{
    int applesAccesible{}, orangesAccesible{};
    for (auto apple : apples)
    {
        if(apple+a >= s && apple+a <=t) applesAccesible++;
    }
    for (auto orange : oranges)
    {
        if (orange+b <= t && orange+b>s) orangesAccesible++;
    }
    std::cout<< applesAccesible <<std::endl;
    std::cout<< orangesAccesible <<std::endl;
}

int main()
{
    int s = 37455;
    int t = 87275;
    int a = 35609;
    int b = 89610;
    vector<int> apples = {19736, -68800, -68796,7942, 65753, 17354, -28647, 93058};
    vector<int> oranges = {62258, -32192, -44224, -30156, 40077, 45196, 69338};
    countApplesAndOranges(s, t, a, b, apples, oranges);

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
