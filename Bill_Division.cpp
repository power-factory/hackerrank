#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'bonAppetit' function below.
 *
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY bill
 *  2. INTEGER k
 *  3. INTEGER b
 */

void bonAppetit(vector<int> bill, int k, int b)
{
    std::vector<int> annaBill = bill;
    annaBill.erase(annaBill.begin() + k);
    int fullSum = std::accumulate(bill.begin(), bill.end(), 0)/2;
    int annaSum = std::accumulate(annaBill.begin(), annaBill.end(), 0)/2;

    if (b == (annaSum))
    {
        cout << "Bon Appetit";
    }
    else
    {
        cout << (abs(b - annaSum));
    }
}

int main()
{
    std::vector<int> bill = {3, 10, 2, 9};
    int k{1}, b{12};

    bonAppetit(bill, k, b);

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
