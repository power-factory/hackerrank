#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'cutTheSticks' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

vector<int> cutTheSticks(vector<int> arr)
{
    std::vector<int> numberOfSticks{};
    numberOfSticks.push_back(arr.size());
    while (!std::equal(arr.begin() + 1, arr.end(), arr.begin()))
    {
        int minimal{INT_MAX};
        for (int element : arr)
        {
            if (element < minimal)
            {
                minimal = element;
            }
        }

        auto it = std::find(arr.begin(), arr.end(), minimal);
        while(it != arr.end()){
            arr.erase(it);
            it = std::find(arr.begin(), arr.end(), minimal);
        }
        for (int i = 0; i < arr.size(); i++)
        {
            arr[i] = arr[i] - minimal;
        }
        numberOfSticks.push_back(arr.size());
    }
    return numberOfSticks;
}

int main()
{


    vector<int> arr = {5, 4, 4, 2, 2, 8};


    vector<int> result = cutTheSticks(arr);

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
