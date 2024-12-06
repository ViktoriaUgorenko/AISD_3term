#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    int n;

    while (true)
    {
        cout << "введите длину последовательности:" << endl;
        cin >> n;

        if (cin.get() != (int)'\n')
        {
            cout << "\nданные введены неверно, попробуйте ещё раз:(" << endl;
            cin.clear();
            cin.ignore(32767, '\n');
            continue;
        }
        else {
            break;
        }
    }

    int elOfPosled[1000];
    int maxLenPodpOfEveryEL[1000];
    int next[1000];

    cout << "введите массив:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i << " элемент: ";
        cin >> elOfPosled[i];

        if (cin.get() != (int)'\n')
        {
            cout << "\nданные введены неверно, начните сначала:(" << endl;
            cin.clear();
            cin.ignore(32767, '\n');
            i = -1;
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        int maxLenPodp = 0;
        int indNextElOfPodp = -1;

        for (int j = i + 1; j < n; j++)
        {
            if (elOfPosled[j] > elOfPosled[i])
            {
                if (maxLenPodpOfEveryEL[j] >= maxLenPodp)
                {
                    maxLenPodp = maxLenPodpOfEveryEL[j];
                    indNextElOfPodp = j;
                }
            }
        }
        next[i] = indNextElOfPodp;
        maxLenPodpOfEveryEL[i] = maxLenPodp + 1;
    }



    int max = 0;
    int indStartOfMaxPodp = -1;

    for (int i = 0; i < n; i++)
    {
        if (maxLenPodpOfEveryEL[i] > max)
        {
            max = maxLenPodpOfEveryEL[i];
            indStartOfMaxPodp = i;
        }
    }

    cout << "максимальная длина: " << max << endl;
    for (int i = indStartOfMaxPodp; i != -1; i = next[i])
        cout << elOfPosled[i] << " ";

    return 0;
}