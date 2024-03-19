// g++ main.cpp -lGLEW -lGL -lglfw -lglut -lGLU -o main
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GL/glu.h>
#include <iostream>
#include <vector>

using namespace std;


void framebufferSizeCallback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

vector<pair<GLfloat, GLfloat>> controlPoints;

vector<int> weight;

vector<int> bin3Newton = {1, 5, 10, 10, 5, 1};

void mouseButtonCallback(GLFWwindow *window, int button, int action, int mods)
{
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
    {
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);

        int width, height;
        glfwGetWindowSize(window, &width, &height);

        // Преобразуем координаты курсора в координаты OpenGL
        xpos = xpos / width;
        ypos = 1.0 - ypos / height;

        if (controlPoints.size() < 5)
        {
            controlPoints.push_back({(GLfloat)xpos, (GLfloat)ypos});
        }
    }
}

void display()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Рисуем точки управления
    glColor3f(0.5f, 0.0f, 0.0f);
    glPointSize(5.0f);
    glBegin(GL_POINTS);
    for (const auto point : controlPoints)
    {
        glVertex2f(point.first, point.second);
    }
    glEnd();

    // Рисуем точки управления
    glColor3f(0.0f, 0.5f, 0.0f);
    glBegin(GL_LINES);
    int en = 0;
    for (const auto point : controlPoints) {
        if (en == 4) {
            break;
        }
        en++;
        glVertex2f(point.first, point.second);
    }
    int ch = 0;
    for (const auto point : controlPoints) {
        if (ch == 0) {
            ch++;
            continue;
        }
        glVertex2f(point.first, point.second);
    }
    glEnd();


    // Рисуем точки управления
    if (controlPoints.size() == 5)
    {
        glColor3f(1.0f, 0.0f, 0.5f);
        glBegin(GL_LINE_STRIP);
        for (double t = 0; t <= 1; t += 0.001)
        {
            double allx1 = (controlPoints[0].first * weight[0] * bin3Newton[0] * (1 - t) * (1 - t) * (1 - t) * (1 - t) * (1 - t)) +
            (controlPoints[1].first * weight[1] * bin3Newton[1] * t * (1 - t) * (1 - t) * (1 - t) * (1 - t)) +
            (controlPoints[2].first * weight[2] * bin3Newton[2] * t * t * (1 - t) * (1 - t) * (1 - t)) +
            (controlPoints[3].first * weight[3] * bin3Newton[3] * t * t * t * (1 - t) * (1 - t)) + 
            (controlPoints[4].first * weight[4] * bin3Newton[4] * t * t * t * t * (1 - t));
            
            double allx2 = (weight[0] * bin3Newton[0] * (1 - t) * (1 - t) * (1 - t) * (1 - t) * (1 - t)) +
            (weight[1] * bin3Newton[1] * t * (1 - t) * (1 - t) * (1 - t) * (1 - t)) +
            (weight[2] * bin3Newton[2] * t * t * (1 - t) * (1 - t) * (1 - t)) +
            (weight[3] * bin3Newton[3] * t * t * t * (1 - t) * (1 - t)) + 
            (weight[4] * bin3Newton[4] * t * t * t * t * (1 - t));

            double ally1 = (controlPoints[0].second * weight[0] * bin3Newton[0] * (1 - t) * (1 - t) * (1 - t) * (1 - t) * (1 - t)) +
            (controlPoints[1].second * weight[1] * bin3Newton[1] * t * (1 - t) * (1 - t) * (1 - t) * (1 - t)) +
            (controlPoints[2].second * weight[2] * bin3Newton[2] * t * t * (1 - t) * (1 - t) * (1 - t))+
            (controlPoints[3].second * weight[3] * bin3Newton[3] * t * t * t * (1 - t) * (1 - t)) + 
            (controlPoints[4].second * weight[4] * bin3Newton[4] * t * t * t * t * (1 - t));
            
            double ally2 = (weight[0] * bin3Newton[0] * (1 - t) * (1 - t) * (1 - t) * (1 - t) * (1 - t)) +
            (weight[1] * bin3Newton[1] * t * (1 - t) * (1 - t) * (1 - t) * (1 - t)) +
            (weight[2] * bin3Newton[2] * t * t * (1 - t) * (1 - t) * (1 - t)) +
            (weight[3] * bin3Newton[3] * t * t * t * (1 - t) * (1 - t)) + 
            (weight[4] * bin3Newton[4] * t * t * t * t * (1 - t));

            double x =  allx1 / allx2;
            double y = ally1 / ally2;
            cout<<"x: "<<x<<", y: "<<y<<endl;
            
            glVertex2d(x, y);
        }
        glEnd();
    }

    glFlush();
}

int main(int argc, char **argv)
{
    cout<<"Введите 5 весов для точек"<<endl;
    for (int i = 0; i < 5; ++i) {
        int w;
        cin>>w;
        weight.push_back(w);
    }
    if (!glfwInit())
    {
        cerr << "ERROR GLFW" << std::endl;
        return -1;
    }

    GLFWwindow *window = glfwCreateWindow(800, 600, "NURB-кривая", nullptr, nullptr);
    if (!window)
    {
        cerr << "ERROR GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);

    glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);
    glfwSetMouseButtonCallback(window, mouseButtonCallback);

    while (!glfwWindowShouldClose(window))
    {
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        framebufferSizeCallback(window, width, height);
        display();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}