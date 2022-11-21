#include <GL\glew.h>
#include <GL\freeglut.h>

struct Poly
{
    int all;
    float x1,x2,x3,x4, y1,y2,y3,y4, z1,z2,z3,z4;
    GLubyte r, g, b;
};

struct Triangle
{
    int all;
    float x1,x2,x3, y1,y2,y3, z1,z2,z3;
    GLubyte r, g, b;
};

struct Cube
{
    Poly C[6];

    Cube(float move_x, float move_y, float move_z, float scale_x, float scale_y, float scale_z)
    {
        C[0].x1 =-0.1f * scale_x + move_x; C[0].y1 =-0.1f * scale_y + move_y; C[0].z1 = 0.1f * scale_z + move_z;
        C[0].x2 =-0.1f * scale_x + move_x; C[0].y2 = 0.1f * scale_y + move_y; C[0].z2 = 0.1f * scale_z + move_z;  //front
        C[0].x3 = 0.1f * scale_x + move_x; C[0].y3 = 0.1f * scale_y + move_y; C[0].z3 = 0.1f * scale_z + move_z;
        C[0].x4 = 0.1f * scale_x + move_x; C[0].y4 =-0.1f * scale_y + move_y; C[0].z4 = 0.1f * scale_z + move_z;

        C[1].x1 =-0.1f * scale_x + move_x; C[1].y1 = 0.1f * scale_y + move_y; C[1].z1 =-0.1f * scale_z + move_z;
        C[1].x2 =-0.1f * scale_x + move_x; C[1].y2 =-0.1f * scale_y + move_y; C[1].z2 =-0.1f * scale_z + move_z;  //left side 
        C[1].x3 =-0.1f * scale_x + move_x; C[1].y3 =-0.1f * scale_y + move_y; C[1].z3 = 0.1f * scale_z + move_z;
        C[1].x4 =-0.1f * scale_x + move_x; C[1].y4 = 0.1f * scale_y + move_y; C[1].z4 = 0.1f * scale_z + move_z;

        C[2].x1 = 0.1f * scale_x + move_x; C[2].y1 =-0.1f * scale_y + move_y; C[2].z1 =-0.1f * scale_z + move_z;
        C[2].x2 = 0.1f * scale_x + move_x; C[2].y2 = 0.1f * scale_y + move_y; C[2].z2 =-0.1f * scale_z + move_z;  //right side
        C[2].x3 = 0.1f * scale_x + move_x; C[2].y3 = 0.1f * scale_y + move_y; C[2].z3 = 0.1f * scale_z + move_z;
        C[2].x4 = 0.1f * scale_x + move_x; C[2].y4 =-0.1f * scale_y + move_y; C[2].z4 = 0.1f * scale_z + move_z;

        C[3].x1 =-0.1f * scale_x + move_x; C[3].y1 =-0.1f * scale_y + move_y; C[3].z1 =-0.1f * scale_z + move_z;
        C[3].x2 =-0.1f * scale_x + move_x; C[3].y2 = 0.1f * scale_y + move_y; C[3].z2 =-0.1f * scale_z + move_z;  //back
        C[3].x3 = 0.1f * scale_x + move_x; C[3].y3 = 0.1f * scale_y + move_y; C[3].z3 =-0.1f * scale_z + move_z;
        C[3].x4 = 0.1f * scale_x + move_x; C[3].y4 =-0.1f * scale_y + move_y; C[3].z4 =-0.1f * scale_z + move_z;

        C[4].x1 =-0.1f * scale_x + move_x; C[4].y1 =-0.1f * scale_y + move_y; C[4].z1 = 0.1f * scale_z + move_z;
        C[4].x2 =-0.1f * scale_x + move_x; C[4].y2 =-0.1f * scale_y + move_y; C[4].z2 =-0.1f * scale_z + move_z;
        C[4].x3 = 0.1f * scale_x + move_x; C[4].y3 =-0.1f * scale_y + move_y; C[4].z3 =-0.1f * scale_z + move_z;
        C[4].x4 = 0.1f * scale_x + move_x; C[4].y4 =-0.1f * scale_y + move_y; C[4].z4 = 0.1f * scale_z + move_z;

        C[5].x1 =-0.1f * scale_x + move_x; C[5].y1 = 0.1f * scale_y + move_y; C[5].z1 = 0.1f * scale_z + move_z;
        C[5].x2 =-0.1f * scale_x + move_x; C[5].y2 = 0.1f * scale_y + move_y; C[5].z2 =-0.1f * scale_z + move_z;
        C[5].x3 = 0.1f * scale_x + move_x; C[5].y3 = 0.1f * scale_y + move_y; C[5].z3 =-0.1f * scale_z + move_z;
        C[5].x4 = 0.1f * scale_x + move_x; C[5].y4 = 0.1f * scale_y + move_y; C[5].z4 = 0.1f * scale_z + move_z;
        C[0].all = 6;

        for (int i = 0; i < C[0].all; i++)
        {
            C[i].r = rand() % 255;
            C[i].g = rand() % 255;
            C[i].b = rand() % 255;
        }
    }

    void drawCube()
    {
        for (int i = 0; i < C[0].all; i++)
        {
            glColor3ub(C[i].r, C[i].g, C[i].b);
            glVertex3f(C[i].x1, C[i].y1, C[i].z1);
            glVertex3f(C[i].x2, C[i].y2, C[i].z2);
            glVertex3f(C[i].x3, C[i].y3, C[i].z3);
            glVertex3f(C[i].x4, C[i].y4, C[i].z4);
        }
    }
};

struct Roof
{
    Poly P[3];
    Triangle T[2];

    Roof(float move_x, float move_y, float move_z, float scale_x, float scale_y, float scale_z)
    {
        P[0].x1 = 0.0f * scale_x + move_x; P[0].y1 = 0.1f * scale_y + move_y; P[0].z1 = 0.1f * scale_z + move_z;
        P[0].x2 = 0.0f * scale_x + move_x; P[0].y2 = 0.1f * scale_y + move_y; P[0].z2 =-0.1f * scale_z + move_z;
        P[0].x3 =-0.1f * scale_x + move_x; P[0].y3 = 0.0f * scale_y + move_y; P[0].z3 =-0.1f * scale_z + move_z;
        P[0].x4 =-0.1f * scale_x + move_x; P[0].y4 = 0.0f * scale_y + move_y; P[0].z4 = 0.1f * scale_z + move_z;

        P[1].x1 = 0.0f * scale_x + move_x; P[1].y1 = 0.1f * scale_y + move_y; P[1].z1 = 0.1f * scale_z + move_z;
        P[1].x2 = 0.0f * scale_x + move_x; P[1].y2 = 0.1f * scale_y + move_y; P[1].z2 =-0.1f * scale_z + move_z;
        P[1].x3 = 0.1f * scale_x + move_x; P[1].y3 = 0.0f * scale_y + move_y; P[1].z3 =-0.1f * scale_z + move_z;
        P[1].x4 = 0.1f * scale_x + move_x; P[1].y4 = 0.0f * scale_y + move_y; P[1].z4 = 0.1f * scale_z + move_z;

        P[2].x1 =-0.1f * scale_x + move_x; P[2].y1 = 0.0f * scale_y + move_y; P[2].z1 = 0.1f * scale_z + move_z;
        P[2].x2 =-0.1f * scale_x + move_x; P[2].y2 = 0.0f * scale_y + move_y; P[2].z2 =-0.1f * scale_z + move_z;
        P[2].x3 = 0.1f * scale_x + move_x; P[2].y3 = 0.0f * scale_y + move_y; P[2].z3 =-0.1f * scale_z + move_z;
        P[2].x4 = 0.1f * scale_x + move_x; P[2].y4 = 0.0f * scale_y + move_y; P[2].z4 = 0.1f * scale_z + move_z;
        P[0].all = 3;

        T[0].x1 = 0.1f * scale_x + move_x; T[0].y1 = 0.0f * scale_y + move_y; T[0].z1 = 0.1f * scale_z + move_z;
        T[0].x2 = 0.0f * scale_x + move_x; T[0].y2 = 0.1f * scale_y + move_y; T[0].z2 = 0.1f * scale_z + move_z;
        T[0].x3 =-0.1f * scale_x + move_x; T[0].y3 = 0.0f * scale_y + move_y; T[0].z3 = 0.1f * scale_z + move_z;

        T[1].x1 = 0.1f * scale_x + move_x; T[1].y1 = 0.0f * scale_y + move_y; T[1].z1 =-0.1f * scale_z + move_z;
        T[1].x2 = 0.0f * scale_x + move_x; T[1].y2 = 0.1f * scale_y + move_y; T[1].z2 =-0.1f * scale_z + move_z;
        T[1].x3 =-0.1f * scale_x + move_x; T[1].y3 = 0.0f * scale_y + move_y; T[1].z3 =-0.1f * scale_z + move_z;
        T[0].all = 2;


        for (int i = 0; i < P[0].all; i++)
        {
            P[i].r = rand() % 255;
            P[i].g = rand() % 255;
            P[i].b = rand() % 255;
        }

        for (int i = 0; i < T[0].all; i++)
        {
            T[i].r = rand() % 255;
            T[i].g = rand() % 255;
            T[i].b = rand() % 255;
        }
    }

    void drawRoofQ()
    {
        for (int i = 0; i < P[0].all; i++)
        {
            glColor3ub(P[i].r, P[i].g, P[i].b);
            glVertex3f(P[i].x1, P[i].y1, P[i].z1);
            glVertex3f(P[i].x2, P[i].y2, P[i].z2);
            glVertex3f(P[i].x3, P[i].y3, P[i].z3);
            glVertex3f(P[i].x4, P[i].y4, P[i].z4);
        }
    }

    void drawRoofT()
    {
        for (int i = 0; i < T[0].all; i++)
        {
            glColor3ub(T[i].r, T[i].g, T[i].b);
            glVertex3f(T[i].x1, T[i].y1, T[i].z1);
            glVertex3f(T[i].x2, T[i].y2, T[i].z2);
            glVertex3f(T[i].x3, T[i].y3, T[i].z3);
        }
    }
};

Cube foundation = Cube(0.0f, -0.22f, 0, 3.0f, 0.2f, 3.0f);

Cube left_wall = Cube(-0.29f, 0, 0, 0.1f, 2, 3);
Cube right_wall = Cube(0.29f, 0, 0, 0.1f, 2, 3);
Cube back_wall = Cube(0,0,0.29f, 2.8f,2,0.1f);
Cube front_wall = Cube(-0.16f, 0, -0.29f, 1.2f, 2, 0.1f);
Cube front_wall2 = Cube(0.18f, 0, -0.29f, 1.0f, 2, 0.1f);
Cube front_wall3 = Cube(0.02f, 0.1f, -0.29f, 0.6f, 1, 0.1f);

Roof roof1 = Roof(0,0.2,0, 3.2, 2.5, 3.2);
Cube chimney = Cube(0.15f, 0.35f, 0.1f, 0.5f, 1, 0.5f);


void draw()
{
    glBegin(GL_QUADS);
    foundation.drawCube();
    left_wall.drawCube();
    right_wall.drawCube();
    back_wall.drawCube();
    front_wall.drawCube();
    front_wall2.drawCube();
    front_wall3.drawCube();
    roof1.drawRoofQ();
    chimney.drawCube();
    glEnd();
    
    glBegin(GL_TRIANGLES);
    roof1.drawRoofT();
    glEnd();
}


void keyboard(unsigned char key, int x, int y)
{
    if (key == 'r') 
    {
        glRotatef(2, -0.8f, 1, 0);
    }
    glutPostRedisplay();
}

void displayMe(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    glPointSize(3);
    glBegin(GL_POINTS);
    glVertex3f(0.0, 0.0, 0.0);
    glEnd();

    draw();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(500, 0);
    gluOrtho2D(-1, 1, 1, -1);
    glutCreateWindow("BadproG");
    glutDisplayFunc(displayMe);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}