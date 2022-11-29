#include <bits/stdc++.h>
#include <GL/freeglut.h>
using namespace std;

void triangle()
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1.0f, 0.0f, 0.0f);
    gluOrtho2D(-1.0, 1.0, -1.5, 1.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(0.0f, 1.0f);
    glVertex2f(1.0f, -1.0f);
    glEnd();
    glutSwapBuffers();
}



int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Triangle");
    // init();
    glutDisplayFunc(triangle);
    glutMainLoop();
    return 0;
}