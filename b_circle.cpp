#include <GL/freeglut.h>
#include <bits/stdc++.h>
using namespace std;
int xc = 350, yc = 400;

void plot(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x + xc, y + yc);
    glEnd();
}

void bresenhamCircle()
{
    int r = 100;
    int x = 0, y = r;
    int d = 3 - 2 * r;
    plot(x, y);
    while (y >= x)
    {
        x++;
        (d > 0) ? (y--, d = d + 4 * (x - y) + 10) : (d = d + 4 * x + 6);
        // if (d > 0)
        // {
        //     y--;
        //     d = d + 4 * (x - y) + 10;
        // }
        // else
        //     d = d + 4 * x + 6;
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
    gluOrtho2D(0, 600, 0, 600);
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Bresenham Circle");
    init();
    glutDisplayFunc(bresenhamCircle);
    glutMainLoop();

    return 0;
}