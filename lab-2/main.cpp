// g++ main.cpp -lGLEW -lGL -lglut -lglfw -lGLU -o main


#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cmath>
#include <GL/freeglut.h>
#include <iostream>
#include <vector>
#include <GL/glu.h>

struct Vertex
{
    float x, y, z;
};

struct Edge
{
    int start, end;
};

struct Conf
{
    Vertex vs[8];
    Edge edges[12];
};

class Figure
{
public:
    Figure() {}

    void Build()
    {
        glBegin(GL_LINES);
        for (Edge edge: conf.edges) {
            Vertex vstart = conf.vs[edge.start];
            Vertex vend = conf.vs[edge.end];
            glVertex3f(vstart.x, vstart.y, vstart.z);
            glVertex3f(vend.x, vend.y, vend.z);
        }
        glEnd();
    }

    void deleteInvise()
    {
        glBegin(GL_TRIANGLES);
        glVertex3f(conf.vs[0].x, conf.vs[0].y, conf.vs[0].z);
        glVertex3f(conf.vs[1].x, conf.vs[1].y, conf.vs[1].z);
        glVertex3f(conf.vs[2].x, conf.vs[2].y, conf.vs[2].z);
        glEnd();

        glBegin(GL_TRIANGLES);
        glVertex3f(conf.vs[0].x, conf.vs[0].y, conf.vs[0].z);
        glVertex3f(conf.vs[2].x, conf.vs[2].y, conf.vs[2].z);
        glVertex3f(conf.vs[3].x, conf.vs[3].y, conf.vs[3].z);
        glEnd();

        glBegin(GL_TRIANGLES);
        glVertex3f(conf.vs[0].x, conf.vs[0].y, conf.vs[0].z);
        glVertex3f(conf.vs[1].x, conf.vs[1].y, conf.vs[1].z);
        glVertex3f(conf.vs[4].x, conf.vs[4].y, conf.vs[4].z);
        glEnd();

        glBegin(GL_TRIANGLES);
        glVertex3f(conf.vs[0].x, conf.vs[0].y, conf.vs[0].z);
        glVertex3f(conf.vs[3].x, conf.vs[3].y, conf.vs[3].z);
        glVertex3f(conf.vs[4].x, conf.vs[4].y, conf.vs[4].z);
        glEnd();

        glBegin(GL_TRIANGLES);
        glVertex3f(conf.vs[1].x, conf.vs[1].y, conf.vs[1].z);
        glVertex3f(conf.vs[5].x, conf.vs[5].y, conf.vs[5].z);
        glVertex3f(conf.vs[2].x, conf.vs[2].y, conf.vs[2].z);
        glEnd();

        glBegin(GL_TRIANGLES);
        glVertex3f(conf.vs[1].x, conf.vs[1].y, conf.vs[1].z);
        glVertex3f(conf.vs[5].x, conf.vs[5].y, conf.vs[5].z);
        glVertex3f(conf.vs[4].x, conf.vs[4].y, conf.vs[4].z);
        glEnd();

        glBegin(GL_TRIANGLES);
        glVertex3f(conf.vs[6].x, conf.vs[6].y, conf.vs[6].z);
        glVertex3f(conf.vs[5].x, conf.vs[5].y, conf.vs[5].z);
        glVertex3f(conf.vs[2].x, conf.vs[2].y, conf.vs[2].z);
        glEnd();

        glBegin(GL_TRIANGLES);
        glVertex3f(conf.vs[6].x, conf.vs[6].y, conf.vs[6].z);
        glVertex3f(conf.vs[2].x, conf.vs[2].y, conf.vs[2].z);
        glVertex3f(conf.vs[3].x, conf.vs[3].y, conf.vs[3].z);
        glEnd();

        glBegin(GL_TRIANGLES);
        glVertex3f(conf.vs[6].x, conf.vs[6].y, conf.vs[6].z);
        glVertex3f(conf.vs[5].x, conf.vs[5].y, conf.vs[5].z);
        glVertex3f(conf.vs[4].x, conf.vs[4].y, conf.vs[4].z);
        glEnd();

        glBegin(GL_TRIANGLES);
        glVertex3f(conf.vs[6].x, conf.vs[6].y, conf.vs[6].z);
        glVertex3f(conf.vs[7].x, conf.vs[7].y, conf.vs[7].z);
        glVertex3f(conf.vs[4].x, conf.vs[4].y, conf.vs[4].z);
        glEnd();

        glBegin(GL_TRIANGLES);
        glVertex3f(conf.vs[6].x, conf.vs[6].y, conf.vs[6].z);
        glVertex3f(conf.vs[7].x, conf.vs[7].y, conf.vs[7].z);
        glVertex3f(conf.vs[3].x, conf.vs[3].y, conf.vs[3].z);
        glEnd();

        glBegin(GL_TRIANGLES);
        glVertex3f(conf.vs[7].x, conf.vs[7].y, conf.vs[7].z);
        glVertex3f(conf.vs[4].x, conf.vs[4].y, conf.vs[4].z);
        glVertex3f(conf.vs[3].x, conf.vs[3].y, conf.vs[3].z);
        glEnd();
    }

private:
    Conf conf = {{{-2,-2,0},
                {2,-2,0},
                {2,2,0},
                {-2,2,0},
                {-1,-1,3},
                {1,-1,3},
                {1,1,3},
                {-1,1,3}}, 
                {{0,1},
                {1,2},
                {2,3},
                {3,0},
                {0,4},
                {1,5},
                {2,6},
                {3,7},
                {4,5},
                {5,6},
                {6,7},
                {7,4}}};

};

class Output
{    
public:
    Output(int size) {
        if (!glfwInit()) {
            exit(EXIT_FAILURE);
        }
        window = glfwCreateWindow(size, size, "Правильная усеченная пирамида", NULL, NULL);
        if (!window)
        {
            glfwTerminate();
            exit(EXIT_FAILURE);
        }
        glfwMakeContextCurrent(window);

        glfwSetWindowUserPointer(window, this);

        glfwSetKeyCallback(window, keyCallback);
        glfwSetWindowSizeCallback(window, resizeCallback);
        figure = Figure();

    };

    void Go() {
        while(!glfwWindowShouldClose(window)) {
            Frame();
            glfwSwapBuffers(window);
            glfwPollEvents();
        }
        glfwDestroyWindow(window);
        glfwTerminate();
    };

    static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        Output* output = static_cast<Output*>(glfwGetWindowUserPointer(window));

        if (action == GLFW_PRESS || action == GLFW_REPEAT)
        {
            switch (key)
            {
            case GLFW_KEY_EQUAL:
                output->scaling -= 0.5f;
                break;

            case GLFW_KEY_MINUS:
                output->scaling += 0.5f;
                break;

            case GLFW_KEY_S:
                output->xAngle += 10.0f;
                if (output->xAngle > 360.0f)
                {
                    output->xAngle = 0.0f;
                }
                break;

            case GLFW_KEY_W:
                output->xAngle -= 10.0f;
                if (output->xAngle < 0.0f)
                {
                    output->xAngle = 360.0f;
                }
                break;

            case GLFW_KEY_D:
                output->yAngle += 10.0f;
                if (output->yAngle > 360.0f)
                {
                    output->yAngle = 0.0f;
                }
                break;

            case GLFW_KEY_A:
                output->yAngle -= 10.0f;
                if (output->yAngle < 0.0f)
                {
                    output->yAngle = 360.0f;
                }
                break;
            case GLFW_KEY_Z:
                output->zAngle -= 10.0f;
                if (output->zAngle < 0.0f)
                {
                    output->zAngle = 360.0f;
                }
                break;
            case GLFW_KEY_X:
                output->zAngle += 10.0f;
                if (output->zAngle > 360.0f)
                {
                    output->zAngle = 0.0f;
                }
                break;
            
            case GLFW_KEY_K:
                output->del = !output->del;
                break;

            default:
                break;
            }
        }
    }

    static void resizeCallback(GLFWwindow* window, int w, int h) {
        glViewport(0, 0, w, h);
        glMatrixMode(GL_PROJECTION);

        glLoadIdentity();

        float aspect = (float)w/(float)h;
        gluPerspective(45.0f, aspect, 1.0f, 100.0f);

        glMatrixMode(GL_MODELVIEW);
    };

    void Frame() {
        glLoadIdentity();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glTranslatef(0.0, 0.0, -scaling);

        glRotatef(xAngle, 1.0, 0.0, 0.0);
        glRotatef(yAngle, 0.0, 1.0, 0.0);
        glRotatef(zAngle, 0.0, 0.0, 1.0);

        GLfloat matAmbientAndDiffuse[] = {0.8f, 0.0f, 0.2f, 1.0f};
        glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, matAmbientAndDiffuse);
        glColor3f(0.0, 1.0, 1.0);
        glLineWidth(3.0);
        if (del) {
            figure.deleteInvise();
        } else {
            figure.Build();
        }
    };

private:
    GLFWwindow* window;
    Figure figure;
    bool del = false;
    float scaling = 5.0f;
    float xAngle = 0.0f;
    float yAngle = 0.0f;
    float zAngle = 0.0f;
    
};

int main()
{
    Output app(800);
    app.Go();
    return 0;
}