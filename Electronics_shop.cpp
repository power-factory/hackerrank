#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/*
 * Complete the getMoneySpent function below.
 */
int getMoneySpent(vector<int> keyboards, vector<int> drives, int b)
{
    int mostExpensiveOrder{};
    for (int keyboard : keyboards)
    {
        for (int drive : drives)
        {
            int order = keyboard + drive;
            if (order <= b && order > mostExpensiveOrder)
            {
                mostExpensiveOrder = order;
            }
        }
    }
    if (mostExpensiveOrder == 0)
    {
        return -1;
    }
    else
        return mostExpensiveOrder;
}

int main()
{
    std::vector<int> keyboards = {4};
    std::vector<int> drives = {5};
    int b = 5;

    int moneySpent = getMoneySpent(keyboards, drives, b);

    return 0;
}

vector<string> split_string(string input_string)
{
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y)
                                      { return x == y and x == ' '; });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ')
    {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos)
    {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
