#include <iostream>
using namespace std;

string binary_addition(string a, string b)
{
    string ans = "";
    int carry = 0;
    int l1 = a.size() - 1, l2 = b.size() - 1;
    while (l1 >= 0 || l2 >= 0 || carry)
    {
        // Compute sum of last digits and carry
        carry += ((l1 >= 0) ? a[l1] - '0' : 0);
        carry += ((l2 >= 0) ? b[l2] - '0' : 0);
        ans = char(carry % 2/*base*/ + '0') + ans;
        carry /= 2;//base
        l1--;
        l2--;
    }
    return ans;
}

string binary_multiply(string a, string b)
{
    int l1 = a.length(), l2 = b.length();
    string ans = "0", temp;

    for (int i = l1 - 1; i >= 0; i--)
    {
        // traversing in a and checking the set bits in a
        //For those i with a[i]=1, it will generate the number b<<i
        if (a[i] == '1')
        {
            temp = b;
            for (int j = i + 1; j < a.length(); j++)
                temp += '0';
            ans = binary_addition(ans, temp);
        }
    }

    return ans;
}

int main()
{
    string a, b;
    cin >> a >> b;
    cout << binary_multiply(a, b);
    return 0;
}