#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'getTotalX' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY a
 *  2. INTEGER_ARRAY b
 */

int getMaxValue(std::vector<int> v)
{
    auto it = std::max_element(v.begin(), v.end());
    return *it;
}
int getMinValue(std::vector<int> v)
{
    auto it = std::min_element(v.begin(), v.end());
    return *it;
}


int getTotalX(vector<int> a, vector<int> b)
{
    int maxValue = getMaxValue(a);
    int minValue = getMinValue(b);
    int counter{};
    std::vector<int> combined = a;
    combined.insert(combined.end(), b.begin(), b.end());
    //combined - vector containg all of the numbers that needs to be checked
    for(int divisor = maxValue; divisor<= minValue;divisor++){
        bool flag = false;
        for(int element : a){
            if(divisor % element != 0) {flag = true;}
        }
        for(int element :b){
            if(element % divisor != 0) {flag = true;}
        }
        if (!flag){
            counter++;
        }
    }
    return counter;
}

int main()
{
    std::vector<int> arr = {2, 4};
    std::vector<int> brr = {16, 32, 96};
    int total = getTotalX(arr, brr);

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
