#include <GL/freeglut.h>
#include <bits/stdc++.h>
using namespace std;

void bresenham()
{
    int x1 = 200, y1 = 300, x2 = 400, y2 = 500;
    int dx, dy, p, x, y;
    dx = x2 - x1;
    dy = y2 - y1;
    x = x1;
    y = y1;
    p = 2 * dy - dx;
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    while (x < x2)
    {
        x++;
        (p < 0) ? p = p + 2 * dy : (p = p + 2 * (dy - dx) & y++);
        // if (p < 0)
        // {
        //     p = p + 2 * dy;
        // }
        // else
        // {
        //     y++;
        //     p = p + 2 * (dy - dx);
        // }
        glBegin(GL_POINTS);
        glVertex2i(x, y);
        glEnd();
    }
    glutSwapBuffers();
}
void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 0.0f, 0.0f);
    // glMatrixMode(GL_PROJECTION);
    // glLoadIdentity();
    gluOrtho2D(100, 600, 100, 600);
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Bresenham");
    init();
    glutDisplayFunc(bresenham);
    glutMainLoop();
    return 0;
}
