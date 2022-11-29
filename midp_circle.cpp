#include <GL/freeglut.h>
#include <bits/stdc++.h>
using namespace std;
int xc = 300, yc = 200, r = 80;
void plot(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x + xc, y + yc);
    glEnd();
}
void center()
{
    glBegin(GL_POINTS);
    glVertex2i(xc, yc);
    glEnd();
}

void midPoint()
{

    glColor3f(1.0f, 0.0f, 1.0f);
    center();
    int x = 0, y = r;
    int p = 1 - r;
    glColor3f(1.0f, 0.0f, 0.2f);

    plot(x, y);

    while (x < y)
    {
        x++;
        (p < 0) ? p = p + 2 * x + 1 : ((p = p + 2 * (x - y) + 1) & y--);
        // if (p < 0)
        // {
        //     p = p + 2 * x + 1;
        // }
        // else
        // {
        //     y--;
        //     p = p + 2 * (x - y) + 1;
        // }

        plot(x, y);
        plot(x, -y);
        plot(-x, y);
        plot(-x, -y);
        plot(y, x);
        plot(-y, x);
        plot(y, -x);
        plot(-y, -x);
    }
    glutSwapBuffers();
}

void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 0.0f, 1.0f);
    // glMatrixMode(GL_PROJECTION);
    // glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Mid point circle with center");
    init();
    glutDisplayFunc(midPoint);
    glutMainLoop();

    return 0;
}
