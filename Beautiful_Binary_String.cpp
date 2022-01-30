#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'beautifulBinaryString' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING b as parameter.
 */

int beautifulBinaryString(string b)
{
    size_t it = b.find("010");
    int counter{};
    while ((it != std::string::npos) && b.size() > 3)
    {

        b.erase(it, 2);
        it = b.find("010");
        counter++;
    }
    return counter;
}

int main()
{

    string b = "1110011110001100010100000011011101100001101010001111101101000010111111001110110000010110010011100010";

    int result = beautifulBinaryString(b);

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
