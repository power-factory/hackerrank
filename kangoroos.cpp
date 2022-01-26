#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'kangaroo' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. INTEGER x1
 *  2. INTEGER v1
 *  3. INTEGER x2
 *  4. INTEGER v2
 */

string kangaroo(int x1, int v1, int x2, int v2)
{
    if (((x2 >= x1) && (v2 > v1)) || ((x1 >= x2) && (v1 > v2)))
    {
        return "NO";
    }
    else
    {
        int distance1{x1}, distance2{x2};
        int step{0};
        while ((distance1 != distance2) && step < 10000)
        {
            distance1 = distance1 + v1;
            distance2 = distance2 + v2;
            step++;
        }
        if ((x1 + step * v1) == (x2 + step * v2))
        {
            return "YES";
        }
        else
        {
            return "NO";
        }
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));


    int x1 = 2081;

    int v1 = 8403;

    int x2 = 9107;

    int v2 = 8400;

    string result = kangaroo(x1, v1, x2, v2);

    fout << result << "\n";

    fout.close();

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
