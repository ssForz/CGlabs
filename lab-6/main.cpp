// g++ main.cpp -lGLEW -lGL -lglut -lglfw -lGLU -o main
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cmath>
#include <GL/freeglut.h>
#include <iostream>
#include <vector>
#include <GL/glu.h>

#include <unistd.h>



using namespace std;

struct Vertex
{
    float x, y, z;
};

struct d2Vertex
{
    float x,y;
};


class Figure
{
public:
    Figure() {}
    Figure(int precision)
        : _precision(precision){}
    void Build()
    {
        float startP = 0.5;
        float endP = 2;
        vector<d2Vertex> approx;
        for (int i = 1; i <= _precision; ++i) {
            float savex = startP + ((endP - startP) / _precision) * i;
            float savey = 1 / savex;
            approx.push_back({savex, savey});
        }
        float len;
        float vx;
        float vy;
        float vz;
        glBegin(GL_QUADS);
        vx = pivot[0].x;
        vy = pivot[0].y;
        vz = pivot[0].z;
        len = sqrt(vx*vx + vy*vy + vz*vz);
        glNormal3f(-(vx/len), -(vy/len), vz/len);
        glVertex3f(pivot[0].x, pivot[0].y, pivot[0].z);
        vx = pivot[1].x;
        vy = pivot[1].y;
        vz = pivot[1].z;
        len = sqrt(vx*vx + vy*vy + vz*vz);
        glNormal3f(-(vx/len), -(vy/len), vz/len);
        glVertex3f(pivot[1].x, pivot[1].y, pivot[1].z);
        vx = pivot[4].x;
        vy = pivot[4].y;
        vz = pivot[4].z;
        len = sqrt(vx*vx + vy*vy + vz*vz);
        glNormal3f(-(vx/len), -(vy/len), vz/len);
        glVertex3f(pivot[4].x, pivot[4].y, pivot[4].z);
        vx = pivot[3].x;
        vy = pivot[3].y;
        vz = pivot[3].z;
        len = sqrt(vx*vx + vy*vy + vz*vz);
        glNormal3f(-(vx/len), -(vy/len), vz/len);
        glVertex3f(pivot[3].x, pivot[3].y, pivot[3].z);
        vx = pivot[0].x;
        vy = pivot[0].y;
        vz = pivot[0].z;
        len = sqrt(vx*vx + vy*vy + vz*vz);
        glNormal3f((vx/len), (vy/len), vz/len);
        glVertex3f(pivot[0].x, pivot[0].y, pivot[0].z);
        vx = pivot[2].x;
        vy = pivot[2].y;
        vz = pivot[2].z;
        len = sqrt(vx*vx + vy*vy + vz*vz);
        glNormal3f((vx/len), (vy/len), vz/len);
        glVertex3f(pivot[2].x, pivot[2].y, pivot[2].z);
        vx = pivot[5].x;
        vy = pivot[5].y;
        vz = pivot[5].z;
        len = sqrt(vx*vx + vy*vy + vz*vz);
        glNormal3f((vx/len), (vy/len), vz/len);
        glVertex3f(pivot[5].x, pivot[5].y, pivot[5].z);
        vx = pivot[3].x;
        vy = pivot[3].y;
        vz = pivot[3].z;
        len = sqrt(vx*vx + vy*vy + vz*vz);
        glNormal3f((vx/len), (vy/len), vz/len);
        glVertex3f(pivot[3].x, pivot[3].y, pivot[3].z);
        glEnd();
        float savex = 0.5f;
        float savey = 2.0f;
        for (size_t i = 0; i < approx.size(); ++i) {
            glBegin(GL_TRIANGLES);
            vx = 0;
            vy = 0;
            vz = -1;
            len = sqrt(vx*vx + vy*vy + vz*vz);
            glNormal3f((vy/len), (vy/len), vz/len);
            glVertex3f(pivot[0].x, pivot[0].y, pivot[0].z);
            vx = savex;
            vy = savey;
            vz = -1;
            len = sqrt(vx*vx + vy*vy + vz*vz);
            glNormal3f((vx/len), (vy/len), vz/len);
            glVertex3f(savex, savey, 0);
            vx = approx[i].x;
            vy = approx[i].y;
            vz = -1;
            len = sqrt(vx*vx + vy*vy + vz*vz);
            glNormal3f((vy/len), (vx/len), vz/len);
            glVertex3f(approx[i].x, approx[i].y, 0);
            glEnd();

            vx = approx[i].x;
            vy = approx[i].y;
            vz = 0;
            len = sqrt(vx*vx + vy*vy + vz*vz);
            glBegin(GL_QUADS);
            glNormal3f((vx/len), (vy/len), vz/len);
            glVertex3f(approx[i].x, approx[i].y, 0);
            vz = 5;
            len = sqrt(vx*vx + vy*vy + vz*vz);
            glNormal3f((vx/len), (vy/len), vz/len);
            glVertex3f(approx[i].x, approx[i].y, 5);
            vx = savex;
            vy = savey;
            vz = 5;
            len = sqrt(vx*vx + vy*vy + vz*vz);
            glNormal3f((vx/len), (vy/len), vz/len);
            glVertex3f(savex, savey, 5);
            vx = savex;
            vy = savey;
            vz = 0;
            len = sqrt(vx*vx + vy*vy + vz*vz);
            glNormal3f((vx/len), (vy/len), vz/len);
            glVertex3f(savex, savey, 0);
            glEnd();

            glBegin(GL_TRIANGLES);
            vx = pivot[3].x;
            vy = pivot[3].y;
            vz = pivot[3].z;
            len = sqrt(vx*vx + vy*vy + vz*vz);
            glNormal3f((vx/len), (vy/len), vz/len);
            glVertex3f(pivot[3].x, pivot[3].y, pivot[3].z);
            vx = savex;
            vy = savey;
            vz = 5;
            len = sqrt(vx*vx + vy*vy + vz*vz);
            glNormal3f((vx/len), (vy/len), vz/len);
            glVertex3f(savex, savey, 5);
            vx = approx[i].x;
            vy = approx[i].y;
            vz = 5;
            len = sqrt(vx*vx + vy*vy + vz*vz);
            glNormal3f((vx/len), (vy/len), vz/len);
            glVertex3f(approx[i].x, approx[i].y, 5);
            glEnd();

            savex = approx[i].x;
            savey = approx[i].y;
        }
    }

    void Animate(float move)
    {
        float startP = 0.5;
        float endP = 2;
        vector<d2Vertex> approx;
        for (int i = 1; i <= _precision; ++i) {
            float savex = startP + ((endP - startP) / _precision) * i;
            float savey = 1 / savex;
            approx.push_back({savex, savey});
        }
        float len;
        float vx;
        float vy;
        float vz;
        float mv = move;
        glBegin(GL_QUADS);
        vx = pivot[0].x;
        vy = pivot[0].y;
        vz = pivot[0].z;
        if (vz > 0) {
            vx += mv;
            vy += mv;
            vz += mv;
        }
        len = sqrt(vx*vx + vy*vy + vz*vz);
        glNormal3f(-(vx/len), -(vy/len), vz/len);
        glVertex3f(vx, vy, vz);
        vx = pivot[1].x;
        vy = pivot[1].y;
        vz = pivot[1].z;
        if (vz > 0) {
            vx += mv;
            vy += mv;
            vz += mv;
        }
        len = sqrt(vx*vx + vy*vy + vz*vz);
        glNormal3f(-(vx/len), -(vy/len), vz/len);
        glVertex3f(vx, vy, vz);
        vx = pivot[4].x;
        vy = pivot[4].y;
        vz = pivot[4].z;
        if (vz > 0) {
            vx += mv;
            vy += mv;
            vz += mv;
        }
        len = sqrt(vx*vx + vy*vy + vz*vz);
        glNormal3f(-(vx/len), -(vy/len), vz/len);
        glVertex3f(vx, vy, vz);
        vx = pivot[3].x;
        vy = pivot[3].y;
        vz = pivot[3].z;
        if (vz > 0) {
            vx += mv;
            vy += mv;
            vz += mv;
        }
        len = sqrt(vx*vx + vy*vy + vz*vz);
        glNormal3f(-(vx/len), -(vy/len), vz/len);
        glVertex3f(vx, vy, vz);
        vx = pivot[0].x;
        vy = pivot[0].y;
        vz = pivot[0].z;
        if (vz > 0) {
            vx += mv;
            vy += mv;
            vz += mv;
        }
        len = sqrt(vx*vx + vy*vy + vz*vz);
        glNormal3f((vx/len), (vy/len), vz/len);
        glVertex3f(vx, vy, vz);
        vx = pivot[2].x;
        vy = pivot[2].y;
        vz = pivot[2].z;
        if (vz > 0) {
            vx += mv;
            vy += mv;
            vz += mv;
        }
        len = sqrt(vx*vx + vy*vy + vz*vz);
        glNormal3f((vx/len), (vy/len), vz/len);
        glVertex3f(vx, vy, vz);
        vx = pivot[5].x;
        vy = pivot[5].y;
        vz = pivot[5].z;
        if (vz > 0) {
            vx += mv;
            vy += mv;
            vz += mv;
        }
        len = sqrt(vx*vx + vy*vy + vz*vz);
        glNormal3f((vx/len), (vy/len), vz/len);
        glVertex3f(vx, vy, vz);
        vx = pivot[3].x;
        vy = pivot[3].y;
        vz = pivot[3].z;
        if (vz > 0) {
            vx += mv;
            vy += mv;
            vz += mv;
        }
        len = sqrt(vx*vx + vy*vy + vz*vz);
        glNormal3f((vx/len), (vy/len), vz/len);
        glVertex3f(vx, vy, vz);
        glEnd();
        float savex = 0.5f;
        float savey = 2.0f;
        for (size_t i = 0; i < approx.size(); ++i) {
            glBegin(GL_TRIANGLES);
            vx = 0;
            vy = 0;
            vz = -1;
            len = sqrt(vx*vx + vy*vy + vz*vz);
            glNormal3f((vy/len), (vy/len), vz/len);
            glVertex3f(pivot[0].x, pivot[0].y , pivot[0].z);
            vx = savex;
            vy = savey;
            vz = -1;
            len = sqrt(vx*vx + vy*vy + vz*vz);
            glNormal3f((vx/len), (vy/len), vz/len);
            glVertex3f(savex, savey, 0);
            vx = approx[i].x;
            vy = approx[i].y;
            vz = -1;
            len = sqrt(vx*vx + vy*vy + vz*vz);
            glNormal3f((vy/len), (vx/len), vz/len);
            glVertex3f(approx[i].x, approx[i].y, 0);
            glEnd();

            vx = approx[i].x;
            vy = approx[i].y;
            vz = 0;
            glBegin(GL_QUADS);
            len = sqrt(vx*vx + vy*vy + vz*vz);
            glNormal3f((vx/len), (vy/len), vz/len);
            glVertex3f(vx, vy, vz);
            vx = approx[i].x;
            vy = approx[i].y;
            vz = 5;
            if (vz > 0) {
                vx += mv;
                vy += mv;
                vz += mv;
            }
            len = sqrt(vx*vx + vy*vy + vz*vz);
            glNormal3f((vx/len), (vy/len), vz/len);
            glVertex3f(vx, vy, vz);
            vx = savex;
            vy = savey;
            vz = 5;
            if (vz > 0) {
                vx += mv;
                vy += mv;
                vz += mv;
            }
            len = sqrt(vx*vx + vy*vy + vz*vz);
            glNormal3f((vx/len), (vy/len), vz/len);
            glVertex3f(vx, vy, vz);
            vx = savex;
            vy = savey;
            vz = 0;
            len = sqrt(vx*vx + vy*vy + vz*vz);
            glNormal3f((vx/len), (vy/len), vz/len);
            glVertex3f(vx, vy, vz);
            glEnd();

            glBegin(GL_TRIANGLES);
            vx = pivot[3].x;
            vy = pivot[3].y;
            vz = pivot[3].z;
            if (vz > 0) {
                vx += mv;
                vy += mv;
                vz += mv;
            }
            len = sqrt(vx*vx + vy*vy + vz*vz);
            glNormal3f((vy/len), (vx/len), vz/len);
            glVertex3f(vx, vy, vz);
            vx = savex;
            vy = savey;
            vz = 5;
            if (vz > 0) {
                vx += mv;
                vy += mv;
                vz += mv;
            }
            len = sqrt(vx*vx + vy*vy + vz*vz);
            glNormal3f((vy/len), (vx/len), vz/len);
            glVertex3f(vx, vy, vz);
            vx = approx[i].x;
            vy = approx[i].y;
            vz = 5;
            if (vz > 0) {
                vx += mv;
                vy += mv;
                vz += mv;
            }
            len = sqrt(vx*vx + vy*vy + vz*vz);
            glNormal3f((vy/len), (vx/len), vz/len);
            glVertex3f(vx, vy, vz);
            glEnd();

            savex = approx[i].x;
            savey = approx[i].y;
        }
    }


    void setPrecision(int precision)
    {
        _precision = (precision < Min) ? Min : precision;
    }

    int getPrecision()
    {
        return _precision;
    }
private:
    vector<Vertex> pivot = {{0, 0, 0}, {2, 0.5, 0}, {0.5, 2, 0}, {0, 0, 5}, {2, 0.5, 5}, {0.5, 2, 5}};
    int _precision;
    static const int Min = 2;

};

class Output
{    
public:
    Output(int size) {
        if (!glfwInit()) {
            exit(EXIT_FAILURE);
        }
        window = glfwCreateWindow(size, size, "Цилиндр с сектором гиперболы", NULL, NULL);
        if (!window)
        {
            glfwTerminate();
            exit(EXIT_FAILURE);
        }
        glfwMakeContextCurrent(window);

        glfwSetWindowUserPointer(window, this);

        glfwSetKeyCallback(window, keyCallback);
        glfwSetWindowSizeCallback(window, resizeCallback);

        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);
        inputData();
        glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
        glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
        glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
        glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

        figure = Figure(3);

    };

    void Go() {
        while(!glfwWindowShouldClose(window)) {
            if (anim) {
                move = 0.05;
                while(anim) {
                    Frame();
                    glfwSwapBuffers(window);
                    glfwPollEvents();
                    sleep(0.1);
                }
                anim = false;
            }
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
            int precision = output->figure.getPrecision();
            switch (key)
            {
            case GLFW_KEY_V:
                output->lightPos[0] -= 10.0f;
                if (output->lightPos[0] < -360.0f)
                {
                    output->lightPos[0] = 360.0f;
                }
                break;

            case GLFW_KEY_B:
                output->lightPos[0] += 10.0f;
                if (output->lightPos[0] > 360.0f)
                {
                    output->lightPos[0] = -360.0f;
                }
                break;
            case GLFW_KEY_E:
                output->figure.setPrecision(precision + 1);
                break;

            case GLFW_KEY_Q:
                output->figure.setPrecision(precision - 1);
                break;

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
            case GLFW_KEY_J:
                output->anim = (!output->anim);
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
        setMaterial();
        setLighting();
        glLoadIdentity();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

        glTranslatef(0.0, 0.0, -scaling);
        glRotatef(xAngle, 1.0, 0.0, 0.0);
        glRotatef(yAngle, 0.0, 1.0, 0.0);
        glRotatef(zAngle, 0.0, 0.0, 1.0);
        if (!anim) {
        // glEnable(GL_COLOR_MATERIAL);
        // glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT);
        // GLfloat matAmbientAndDiffuse[] = {0.8f, 0.2f, 0.2f, 1.0f};
        // glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, matAmbientAndDiffuse);
            figure.Build();
        } else {
                figure.Animate(move);
                move += 0.05;
            }
        };

    void inputData()
    {
        cout << "4 значения для Ambient (0 : 1): ";
        for (int i = 0; i < 4; i++)
            cin >> ambient[i];

        cout << "4 значения для Diffuse (0 : 1): ";
        for (int i = 0; i < 4; i++)
            cin >> diffuse[i];

        std::cout << "4 значения для Specular (0 : 1): ";
        for (int i = 0; i < 4; i++)
            cin >> specular[i];

        cout << "Значение для Shininess (0 : 128): ";
        cin >> shininess;
    }

    void setLighting()
    {
        float lightPos[4] = {lightPos[0], 10.0f, 2.5f, 1.0f};
        glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
    }

    void setMaterial()
    {
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
        glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
    }

private:
    float ambient[4];
    float diffuse[4];
    float specular[4];
    float shininess;
    float lightPos[4] = {50.0f, 20.0f, 0.0f, 1.0f};

    GLFWwindow* window;
    Figure figure;
    bool anim = false;
    float move;
    float scaling = 15.0f;
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

// В контексте компьютерной графики, особенно в контексте освещения и материалов, Ambient, Diffuse, Specular и Shininess - это четыре ключевых компонента, которые определяют, как объект воспринимает и отражает свет. Вот их краткое описание:

// Ambient (Окружающее освещение):

// Это фоновое освещение, которое равномерно освещает все объекты в сцене. Оно не зависит от позиции источника света.
// Ambient освещение обычно используется для имитации неяркого и рассеянного света в сцене, который распределен равномерно.

// Diffuse (Рассеянное освещение):

// Описывает основное освещение, которое приходит от источника света и рассеивается на объекте.
// Этот тип освещения не имеет направленного блеска и равномерно освещает поверхности объектов.
// Хорошим примером рассеянного света является свет, который освещает лунную поверхность. Он равномерно рассеивается и не создает ярких бликов.

// Specular (Зеркальное отражение):

// Отражает световые блики на поверхности объекта.
// Отражение света зависит от угла, под которым свет падает на объект, и угла, под которым наблюдатель смотрит на объект.
// Этот компонент создает блеск или яркие блики на объектах, что делает их более реалистичными.

// Shininess (Блеск):

// Этот параметр определяет "резкость" или "мягкость" блеска, который создается компонентом Specular.
// Низкое значение Shininess создает широкий и рассеянный блеск, в то время как высокое значение создает узкий и концентрированный блеск.
// Обычно представлено в диапазоне от 0 (матовое) до 128 (очень блестящее).
// Когда источник света освещает объект, эти параметры материала взаимодействуют с светом, чтобы определить, какой конечный цвет должен быть показан на экране. Они взаимодействуют в сочетании, чтобы создать сложный и реалистичный образ освещенных объектов в компьютерной графике.

// 0.2 0.2 0.8 1.0
// 0.0 0.0 1.0 1.0
// 1.0 1.0 1.0 1.0
// 50