#include <GL/glew.h>
#include <GLFW/glfw3.h>
#if defined(__APPLE__)
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#endif

#include <iostream>
#include <chrono>
using namespace std::chrono;
 

int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK)
    {
        std::cout << "Failed to initialize GLEW" << std::endl;
        return -1;
    }

    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    
    glViewport(0, 0, width, height);

    // мерехтимо зеленим кольором 
    //(я не знаю як малювати без шейдерів, для шейдерів є https://github.com/g0vnocoders/balash-newß )
    float color = 0;
    bool direction = true;
    auto prev = high_resolution_clock::now();
    while(!glfwWindowShouldClose(window))
    {
        auto now = high_resolution_clock::now();
        if(color>1 || color<0){
            color=direction?1:0;
            direction = !direction;
        }
        
        color += (duration_cast<milliseconds>(now - prev).count()/1000.0f) * (direction?1.0f:-1.0f);
        prev = now;
        
        glClearColor(0.0f, color, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}