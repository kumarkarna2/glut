#include <GL/freeglut.h>
#include <bits/stdc++.h>
using namespace std;

void lines()
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    gluOrtho2D(0, 150, 0, 150);
    glBegin(GL_LINES);
    glVertex2i(0, 0);
    glVertex2i(100, 100);
    glVertex2i(10, 0);
    glVertex2i(110, 100);
    glEnd();
    glutSwapBuffers();
}
// void init()
// {
//     glClearColor(1.0, 1.0, 1.0, 0.0);
//     glClear(GL_COLOR_BUFFER_BIT);
//     glColor3f(1.0, 0.0, 0.0);
//     gluOrtho2D(0, 150, 0, 150);
// }
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("lines");
    // init();
    glutDisplayFunc(lines);
    glutMainLoop();
    return 0;
}
