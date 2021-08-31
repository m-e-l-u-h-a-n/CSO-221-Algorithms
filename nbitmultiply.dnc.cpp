#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int make_equal_length(string &str1, string &str2)
{
    int len1 = str1.size();
    int len2 = str2.size();
    if (len1 < len2)
    {
        for (int i = 0; i < len2 - len1; i++)
            str1 = '0' + str1;
        return len2;
    }
    else if (len1 > len2)
    {
        for (int i = 0; i < len1 - len2; i++)
            str2 = '0' + str2;
    }
    return len1;
}

string binary_addtion(string first, string second)
{
    string result;

    int length = make_equal_length(first, second);
    int carry = 0;

    for (int i = length - 1; i >= 0; i--)
    {
        int first_bit = first.at(i) - '0';
        int second_bit = second.at(i) - '0';

        int sum = ((first_bit + second_bit + carry) % 2) + '0';

        result = (char)sum + result;
        carry = ((first_bit + second_bit + carry) / 2);
    }

    if (carry)
        result = '1' + result;

    return result;
}

int multiply_single_bit(string a, string b)
{
    return (a[0] - '0') * (b[0] - '0');
}

long int multiply(string X, string Y)
{
    string xl, xr, yl, yr;
    long int prod1, prod3, prod2;
    int n = make_equal_length(X, Y);

    if (n == 0)
        return 0;
    if (n == 1)
        return multiply_single_bit(X, Y);

    int left = n / 2;
    int rt = (n - left);

    xl = X.substr(0, left);
    xr = X.substr(left, rt);

    yl = Y.substr(0, left);
    yr = Y.substr(left, rt);

    prod1 = multiply(xl, yl);
    prod2 = multiply(binary_addtion(xl, xr), binary_addtion(yl, yr));
    prod3 = multiply(xr, yr);

    prod2 -= (prod1 + prod3);
    prod1 *= pow(2, 2 * rt);
    prod2 *= pow(2, rt);

    return (prod1 + prod2 + prod3);
}

int main()
{
    string a, b;
    cin >> a >> b;
    cout << multiply(a, b) << '\n';
}
