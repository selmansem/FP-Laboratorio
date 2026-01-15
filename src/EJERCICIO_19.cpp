#include <iostream>

using namespace std;

int main()
{
    const int MAX = 1000;
    int v1[MAX] = {1, 2, 1, 1, 7, 2};

    int pos, pos_sig, util_v;

    while (pos < util_v)
    {
        pos_sig = pos + 1;
        while (pos_sig < util_v)
        {
            if (v1[pos] == v1[pos_sig])
            {
                for (int i = pos_sig; i < util_v - 1; i++)
                {
                    v1[i] = v1[i + 1];
                }
                util_v--;
            }
            else
            {
                pos_sig++;
            }
        }
        pos++;
    }
}