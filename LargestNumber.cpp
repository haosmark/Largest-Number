// LargestNumber.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <algorithm>

// comparator to use for sorting
static bool comparator(int a, int b)
{
    auto sa = to_string(a);
    auto sb = to_string(b);

    auto first = stoi(sa + sb);
    auto second = stoi(sb + sa);

    if (first - second > 0)
    {
        return true;
    }
    return false;
}

string largestNumber(const vector<int> &A) 
{
    // validate for 000000 input
    auto sum = 0;
    for (auto item : A)
    {
        sum += item;
    }
    if (sum == 0)
    {
        return "0";
    }

    auto temp(A);
    sort(temp.begin(), temp.end(), comparator);
    string result = "";

    for (auto item : temp)
    {
        result += to_string(item);
    }


    return result;
}

int main()
{
    vector<int> data { 0, 0, 0 };
    cout << largestNumber(data) << endl;
    return 0;
}

