#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'serviceLane' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY cases
 */

// This was tricky challange for me. It is due to fact that function description is wrong.
// Multiple people reported not pasing "width" as function argument. I modified it!

vector<int> serviceLane(int n, vector<int> width, vector<vector<int>> cases)
{
    std::vector<int> maximumVehicleWidth;
    for (auto pair : cases)
    {
        int enterIndex = pair[0];
        int exitIndex = pair[1];

        auto vehicleWidth = *std::min_element(width.begin() + enterIndex, width.begin() + exitIndex+1);
        maximumVehicleWidth.push_back(vehicleWidth);
    }
    return maximumVehicleWidth;
}

int main()
{
    int n = 5;
    int t{5};
    vector<int> width = {1, 2, 2, 2, 1};

    vector<vector<int>> cases = {{2, 3}, {1, 4}, {2, 4}, {2, 4}, {2, 3}};

    vector<int> result = serviceLane(n, width, cases);

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
