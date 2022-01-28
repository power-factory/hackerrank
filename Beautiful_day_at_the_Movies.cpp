#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'beautifulDays' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER i
 *  2. INTEGER j
 *  3. INTEGER k
 */
int reverseDay(int i)
{
    std::string i_to_string = std::to_string(i);
    std::string reversed_i;
    for (std::string::reverse_iterator rit = i_to_string.rbegin(); rit != i_to_string.rend(); ++rit)
    {
        reversed_i.push_back(*rit);
    }
    return stoi(reversed_i);
}

int beautifulDays(int i, int j, int k)
{
    int counterBeautifulDays{};
    for (int day = i; day <= j; day++)
    {
        std::cout<<std::abs(day - reverseDay(day))<<std::endl;
        if (std::abs(day-reverseDay(day)) % k == 0)
        {
            counterBeautifulDays++;
        }
    }
    return counterBeautifulDays;
}



int main()
{
    int i{13}, j{45}, k{3};

    int result = beautifulDays(i, j, k);

    //cout <<reverseDay(12)<<std::endl;
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
