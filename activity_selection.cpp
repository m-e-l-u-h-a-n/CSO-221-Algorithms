#include <bits/stdc++.h>
using namespace std;

// n --> Total number of activities
// s[] --> An array that contains start time of all activities
// f[] --> An array that contains finish time of all activities
void printMaxActivities(int s[], int f[], int n)
{
    int i, j;

    cout << "Following activities are selected " << endl;

    // The first activity always gets selected
    i = 0;
    cout << " " << i;

    for (j = 1; j < n; j++)
    {

        if (s[j] >= f[i])
        {
            cout << " " << j;
            i = j;
        }
    }
}

int main()
{
    int s[] = {1, 3, 5, 7, 8, 11};
    int f[] = {3, 5, 8, 11, 10, 12};
    int n = sizeof(s) / sizeof(s[0]);
    printMaxActivities(s, f, n);
    return 0;
}