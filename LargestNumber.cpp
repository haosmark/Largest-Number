// LargestNumber.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <algorithm>

// comparator to use for vector sorting.
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

    // create a copy of the input vecot and work with it
    auto temp(A);
    sort(temp.begin(), temp.end(), comparator);

    // generate the output result
    string result = "";
    for (auto item : temp)
    {
        result += to_string(item);
    }
    return result;
}

int main()
{
    // test 000
    vector<int> data { 0, 0, 0 };
    cout << largestNumber(data) << endl;

    // test 3 30 34 5 9
    data = { 3, 30, 34, 5, 9 };
    cout << largestNumber(data) << endl;
    return 0;
}

