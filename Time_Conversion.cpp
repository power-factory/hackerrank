#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s)
{
    std::size_t it = s.find("AM");
    std::string militaryFormat = s.substr(0, 8);
    if (it != std::string::npos)
    {
        if (militaryFormat.substr(0, 2) == "12")
        {
            militaryFormat.replace(0, 2, "00");
        }
    }
    else
    {
        if (militaryFormat.substr(0, 2) != "12")
        {
            int hours = stoi(s.substr(0, 2)) + 12;
            militaryFormat.replace(0, 2, std::to_string(hours));
        }
    }
    return militaryFormat;
}

int main()
{

    string s = "12:45:54PM";

    string result = timeConversion(s);

    return 0;
}
