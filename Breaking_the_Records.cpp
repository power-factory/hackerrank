#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'breakingRecords' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY scores as parameter.
 */

vector<int> breakingRecords(vector<int> scores)
{
    int max{scores.at(0)}, min{scores.at(0)}, maxCount{1}, minCount{1};
    std::vector<int> output;
    for (int score : scores)
    {
        if (score > max)
        {
            max = score;
            maxCount++;
        }
        else if (score < min)
        {
            min = score;
            minCount++;
        }
    }
    output.push_back(maxCount);
    output.push_back(minCount);
    return output;
}

int main()
{

    vector<int> scores = {10, 5, 20, 20, 4, 5, 2, 25, 1};
    vector<int> result = breakingRecords(scores);

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
