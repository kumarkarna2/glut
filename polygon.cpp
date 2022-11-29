#include <GL/freeglut.h>
#include <bits/stdc++.h>
using namespace std;

vector<int> x, y;
int n;

void polygon()
{
    glBegin(GL_POLYGON);
    for (int i = 0; i < n; i++)
    {
        // glVertex2i(x[i], y[i]);
        glVertex2i(x[(i + 1) % n], y[(i + 1) % n]);
    }
    glEnd();
    glutSwapBuffers();
}

void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 0.0f, 0.0f);
    gluOrtho2D(-1, 2, -1, 2);
}

int main(int argc, char *argv[])
{
    cout << "Enter number of edges in polygon"
         << "\n";
    cin >> n;
    int i = 0;
    while (i < n)
    {
        cout << "Enter x and y co-ordinates of vertex " << i + 1 << "\n";
        int a, b;
        cin >> a >> b;
        x.push_back(a);
        y.push_back(b);
        i++;
    }

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Polygon");
    init();
    glutDisplayFunc(polygon);
    glutMainLoop();
}
