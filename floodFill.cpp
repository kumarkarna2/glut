#include <bits/stdc++.h>
#include <GL/freeglut.h>
using namespace std;

void floodFill()
{
    int x = 200, y = 200;
    int newColor = 0;
    int oldColor = 1;
    int stack[100][2];
    int top = -1;
    stack[++top][0] = x;
    stack[top][1] = y;
    while (top != -1)
    {
        x = stack[top][0];
        y = stack[top][1];
        top--;
        glBegin(GL_POINTS);
        glVertex2i(x, y);
        glEnd();
        glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, &oldColor);
        if (oldColor != newColor)
        {
            glBegin(GL_POINTS);
            glVertex2i(x, y);
            glEnd();
            stack[++top][0] = x + 1;
            stack[top][1] = y;
            stack[++top][0] = x - 1;
            stack[top][1] = y;
            stack[++top][0] = x;
            stack[top][1] = y + 1;
            stack[++top][0] = x;
            stack[top][1] = y - 1;
        }
    }
    glutSwapBuffers();
}

void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2i(100, 100);
    glVertex2i(300, 100);
    glVertex2i(300, 300);
    glVertex2i(100, 300);
    glEnd();
    floodFill();
}


void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 0.0f, 0.0f);
    gluOrtho2D(0, 500, 0, 500);
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Flood Fill");
    glutDisplayFunc(myDisplay);
    init();
    glutMainLoop();

    return 0;
}