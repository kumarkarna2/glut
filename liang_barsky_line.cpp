#include <bits/stdc++.h>
// #include <GL/freeglut.h>
using namespace std;

int main()
{
    float x1 = 300, y1 = 300, x2 = 300, y2 = 300;
    float xmin = 50, ymin = 50, xmax = 250, ymax = 250;
    float dx = x2 - x1, dy = y2 - y1;
    float t1 = 0, t2 = 1;
    float p[4], q[4];
    p[0] = -dx;
    p[1] = dx;
    p[2] = -dy;
    p[3] = dy;
    q[0] = x1 - xmin;
    q[1] = xmax - x1;
    q[2] = y1 - ymin;
    q[3] = ymax - y1;
    for (int i = 0; i < 4; i++)
    {
        if (p[i] == 0)
        {
            if (q[i] < 0)
            {
                cout << "Line is outside the window";
                return 0;
            }
        }
        else
        {
            float t = q[i] / p[i];
            if (p[i] < 0)
            {
                if (t > t1)
                    t1 = t;
            }
            else
            {
                if (t < t2)
                    t2 = t;
            }
        }
    }
    if (t1 < t2)
    {
        x1 = x1 + t1 * dx;
        y1 = y1 + t1 * dy;
        x2 = x1 + t2 * dx;
        y2 = y1 + t2 * dy;
        cout << "Line is inside the window";
    }
    else
        cout << "Line is outside the window";
    return 0;
}