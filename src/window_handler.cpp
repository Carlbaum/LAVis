#include "window_handler.hpp"

namespace oc {

WindowHandler::WindowHandler() {
    std::cout << "Basic constructor for oc::WindowHandler called successfully! "<< std::endl;
    InitializeWindow();
}

WindowHandler::~WindowHandler() {
    glfwDestroyWindow(window);
}

void WindowHandler::InitializeWindow() {
    // std::cout << "InitializeWindow called successfully! "<< std::endl;
    if (!glfwInit()) {
        std::cerr << "FAILED TO INITIALIZE GLFW! "<< std::endl;
        exit(EXIT_FAILURE);
    }
    // std::cout << "GLFW initialized successfully! "<< std::endl;
    // window = glfwCreateWindow(960, 600, "My Title", glfwGetPrimaryMonitor(), NULL);
    window = glfwCreateWindow(1200, 760, "LAVis", NULL, NULL);
    if (!window) {
        std::cerr << "FAILED TO CREATE A GLFW WINDOW! "<< std::endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window)) {
        float ratio;
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        ratio = width / (float) height;
        glViewport(0, 0, width, height);
        glClearColor(0.0f, 0.0f, 0.2f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glRotatef((float) glfwGetTime() * 50.f, 0.f, 0.f, 1.f);
        glBegin(GL_TRIANGLES);
        glColor3f(1.f, 0.f, 0.f);
        glVertex3f(-0.6f, -0.4f, 0.f);
        glColor3f(0.f, 1.f, 0.f);
        glVertex3f(0.6f, -0.4f, 0.f);
        glColor3f(0.f, 0.f, 1.f);
        glVertex3f(0.f, 0.6f, 0.f);
        glEnd();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

}
