#include <bits/stdc++.h>
#include <GL/freeglut.h>
using namespace std;

void bresenhamEllipse()
{
    int xc = 200, yc = 250;
    int rx = 150, ry = 50;
    int x = 0, y = ry;
    int d1 = (ry * ry) - (rx * rx * ry) + (0.25 * rx * rx);
    int dx = 2 * ry * ry * x;
    int dy = 2 * rx * rx * y;
    while (dx < dy)
    {
        x++;
        if (d1 < 0)
            d1 = d1 + dx + (ry * ry);
        else
        {
            y--;
            d1 = d1 + dx - dy + (ry * ry);
        }
        dx = 2 * ry * ry * x;
        dy = 2 * rx * rx * y;
        glBegin(GL_POINTS);
        glVertex2i(x + xc, y + yc);
        glVertex2i(-x + xc, y + yc);
        glVertex2i(x + xc, -y + yc);
        glVertex2i(-x + xc, -y + yc);
        glEnd();
    }
    int d2 = ((ry * ry) * ((x + 0.5) * (x + 0.5))) + ((rx * rx) * ((y - 1) * (y - 1))) - (rx * rx * ry * ry);
    while (y >= 0)
    {
        y--;
        if (d2 > 0)
            d2 = d2 - dy + (rx * rx);
        else
        {
            x++;
            d2 = d2 + dx - dy + (rx * rx);
        }
        dx = 2 * ry * ry * x;
        dy = 2 * rx * rx * y;
        glBegin(GL_POINTS);
        glVertex2i(x + xc, y + yc);
        glVertex2i(-x + xc, y + yc);
        glVertex2i(x + xc, -y + yc);
        glVertex2i(-x + xc, -y + yc);
        glEnd();
    }
    glutSwapBuffers();
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
    glutCreateWindow(" Bresenham Ellipse");
    init();
    glutDisplayFunc(bresenhamEllipse);
    glutMainLoop();
    return 0;
}
