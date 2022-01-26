#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'gradingStudents' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY grades as parameter.
 */

vector<int> gradingStudents(vector<int> grades)
{
    std::vector<int> roundedGrades;
    for (int grade : grades)
    {
        if (grade >= 38)
        {
            
            float highestMultiplier = floor(grade / 5);
            int diff = ((highestMultiplier+1)*5)-grade;
            if (diff < 3 && diff != 0)
            {
                grade = (highestMultiplier + 1) * 5;
                roundedGrades.push_back(grade);
            }
            else
            {
                roundedGrades.push_back(grade);
            }
            
            
        }
        else
        {
            roundedGrades.push_back(grade);
        }
    }
    return roundedGrades;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));



    vector<int> grades;


    grades = {4, 73, 67, 38, 33};
    vector<int> result = gradingStudents(grades);

    for (size_t i = 0; i < result.size(); i++)
    {
        fout << result[i];

        if (i != result.size() - 1)
        {
            fout << "\n";
        }
    }

    fout << "\n";

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
