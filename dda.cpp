#include <bits/stdc++.h>
#include <GL/freeglut.h>
using namespace std;

void display(void)
{
    float dx, dy, steps, x, y, k, Xin, Yin;
    float x1 = 200, y1 = 100, x2 = 300, y2 = 180;

    dx = x2 - x1;
    dy = y2 - y1;

    (abs(dx) > abs(dy)) ? steps = abs(dx) : steps = abs(dy);
    // if (abs(dx) > abs(dy))
    // {
    //     steps = abs(dx);
    // }
    // else
    // {
    //     steps = abs(dy);
    // }
    Xin = dx / steps;
    Yin = dy / steps;
    x = x1;
    y = y1;
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
    for (k = 0; k < steps; k++)
    {
        x = x + Xin;
        y = y + Yin;
        glBegin(GL_POINTS);
        glVertex2f(x, y);
        glEnd();
    }
    glutSwapBuffers();
}

void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 0.0f, 0.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 400, 0, 400);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("DDa");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}