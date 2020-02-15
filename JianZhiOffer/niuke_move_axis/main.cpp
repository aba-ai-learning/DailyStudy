#include <iostream>
#include <map>
using namespace std;

bool is_int_string(string str)
{
    int length = str.size();
    if (length > 2 || length < 0)
    {
        return 0;
    }
    int value = 0;
    for (auto i = 0; i < length; i++)
    {
        if (str[i] < '0' || str[i] > '9')
        {
            return false;
        }
    }
    return true;
}
int main()
{
    string str;
    getline(cin, str);
    map<char, int> table;
    string word;
    int head = 0;
    for (auto i = 0; i < str.size(); i++)
    {
        if (str[i] == ';')
        {
            word = str.substr(head, i);
            head = i;
            if (word.size() > 0 && word.size() <= 3)
            {
                if (word[0] == 'A' || word[0] == 'D' || word[0] == 'W' || word[0] == 'S')
                {

                    int word_length = word.size();
                    int value = 0;
                    for (auto i = 1; i < word_length; i++)
                    {
                        if (word[i] >= '0' && word[i] <= '9')
                        {
                            value = value * 10 + word[i] - '0';
                        }
                        else
                        {
                            value = 0;
                            break;
                        }
                    }
                    if (value)
                    {
                        table.insert(std::pair<char, int>(word[0], value));
                    }
                }
            }
        }
    }
    int x = 0, y = 0;
    for (auto instruction : table)
    {
        if (instruction.first == 'A')
        {
            x -= instruction.second;
        }
        else if (instruction.first == 'D')
        {
            x += instruction.second;
        }
        else if (instruction.first == 'S')
        {
            y -= instruction.second;
        }
        else
        {
            y += instruction.second;
        }
    }

    cout << x << "," << y << endl;
    return 0;
}