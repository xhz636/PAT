#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main(void)
{
    int N, count = 0;
    double num, sum = 0;
    string str;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> str;
        int index = 0;
        char numstr[10];
        bool isnum = true;
        int point = 0;
        int j;
        for (j = 0; j < str.length(); j++)
        {
            if (str.at(j) == '-' || str.at(j) == '+')
            {
                if (j != 0)
                {
                    isnum = false;
                    break;
                }
                else
                    numstr[j] = str.at(j);
            }
            else if (str.at(j) >= '0' && str.at(j) <= '9')
                numstr[j] = str.at(j);
            else if (str.at(j) == '.')
            {
                if (point != 0)
                {
                    isnum = false;
                    break;
                }
                else
                {
                    point = j;
                    numstr[j] = str.at(j);
                }
            }
            else
            {
                isnum = false;
                break;
            }
            if (j > 5 && point == 0)
            {
                isnum = false;
                break;
            }
            else if (j > point + 2 && point != 0)
            {
                isnum = false;
                break;
            }
        }
        numstr[j] = '\0';
        if (!isnum)
            cout << "ERROR: " << str << " is not a legal number" << endl;
        else
        {
            sscanf(numstr, "%lf", &num);
            if (num < -1000 || num > 1000)
            {
                cout << "ERROR: " << str << " is not a legal number" << endl;
                continue;
            }
            sum += num;
            count++;
        }
    }
    if (count == 0)
        printf("The average of 0 numbers is Undefined\n");
    else
    {
        printf("The average of %d number%s is %.2f\n",
                count, count == 1 ? "" : "s", sum / count);
    }
    return 0;
}
