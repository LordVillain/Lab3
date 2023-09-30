#include <iostream>
#include <vector>

using namespace std;

int main()
{

    cout << "vvedite n i m: ";
    int n, m;
    cin >> n >> m;

    if (n < 1 || n > 10 || m < 1 || m > 10)
    {
        cout << "Nepravilno vvedeny razmer matrix";
        return 0;
    }

    vector <vector <int> > a(m, vector <int>(n, 0));

    cout << "matrica ishodnaya: \n";

    for (vector <int>& x : a)
    {
        for (int& y : x)
        {
            y = rand() % 201 - 100;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << a[j][i] << " ";
        }
        cout << "\n";
    }

    cout << "matrica s 10 gde i+j % 2 == 0: \n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ((i + j) % 2 == 0)
            {
                a[j][i] = 10;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << a[j][i] << " ";
        }
        cout << "\n";
    }

    vector <int> sum(m, 0);             //посчитали сумму для каждого столбца
    for (int j = 0; j < m; j++)
    {
        int cur_sum = 0;
        for (int i = 0; i < n; i++)
        {
            cur_sum += a[j][i];
        }
        sum[j] = cur_sum;
    }


    for (int i = 0; i < m; i++)          //sort
    {
        for (int j = 0; j < m - 1; j++)
        {
            if (sum[j] > sum[j + 1])
            {
                int b = sum[j];
                sum[j] = sum[j + 1];
                sum[j + 1] = b;
                vector <int> c = a[j];
                a[j] = a[j + 1];
                a[j + 1] = c;
            }
        }
    }

    cout << "1) poluchennaya matrica: \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << a[j][i] << " ";
        }
        cout << "\n";
    }

    cout << "2) ";
    bool f1 = 1;
    for (int i = 0; i < n; i++)
    {
        bool f = 1;
        for (int j = 0; j < m; j++)
        {
            if (a[j][i] < 0)
            {
                f = 0;
                break;
            }
        }
        if (f) {
            f1 = 0;
            cout << "stroka " << i + 1 << " top";
            break;
        }
    }
    if (f1) {
        cout << "strok takih net";
    }

    return 0;
}