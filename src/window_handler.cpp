//GLEW must be included before other openGL things
#include <GL/glew.h>
#include "window_handler.hpp"
// OpenGL Math library.. maybe replace this with own functions later?
#include <glm/glm.hpp>

// #include "oc_shape.hpp"
// #include "oc_shape_rectangle2d.hpp"

namespace oc {

WindowHandler::WindowHandler() {
    std::cout << "Basic constructor for oc::WindowHandler called successfully! "<< std::endl;
    // InitializeWindow();
    if ( !glfwInit() ) {
        std::cerr << "Failed to initialize GLFW\n" << std::endl;
        exit(EXIT_FAILURE);
    }

    glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //We don't want the old OpenGL

    // Open a window and create its OpenGL context
    m_window = glfwCreateWindow( 1024, 768, "LAVis", NULL, NULL);
    if( m_window == NULL ){
        std::cerr << "Failed to open GLFW window. \n\tIf you have an Intel GPU, they are not compatible with OpenGL 3.3.\n" << std::endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(m_window);
    // Initialize GLEW
    glewExperimental = true; // Needed in core profile
    if ( glewInit() != GLEW_OK ) {
        std::cerr << "Failed to initialize GLEW\n" << std::endl;
        exit(EXIT_FAILURE);
    }

    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);

    m_isClosed = false;
    std::cout << "Initialization complete, using OpenGL-version: " << glGetString(GL_VERSION) << std::endl;
}

WindowHandler::~WindowHandler() {
    glfwDestroyWindow(m_window);
    std::cout << "WindowHandler destructor successfully executed!" << std::endl;
}

void WindowHandler::StartWindowLoop() {
    // Ensure we can capture the escape key being pressed below
    glfwSetInputMode(m_window, GLFW_STICKY_KEYS, GL_TRUE);
    // oc::Rectangle2D panel1;

    do{
        // Draw nothing, see you in tutorial 2 !
        glClearColor(0.f, 0.f, 0.3f, 1.0f);

        // Swap buffers
        glfwSwapBuffers(m_window);
        glfwPollEvents();

    } // Check if the ESC key was pressed or the window was closed
    while( glfwGetKey(m_window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
           glfwWindowShouldClose(m_window) == 0 );
}

bool WindowHandler::IsClosed() {
    if( glfwGetKey(m_window, GLFW_KEY_ESCAPE ) == GLFW_PRESS || glfwWindowShouldClose(m_window) != 0) {
        // std::cout << "ESC was pressed!" << std::endl;
        m_isClosed = true;
    }
    // while( glfwGetKey(m_window, GLFW_KEY_ESCAPE ) != GLFW_PRESS && glfwWindowShouldClose(m_window) == 0) {

    return m_isClosed;
}

void WindowHandler::Update() {

    // Swap buffers
    glfwSwapBuffers(m_window);
    glfwPollEvents();
}

void WindowHandler::Clear(float r, float g, float b, float a) {
    glClearColor(r, g, b, a);
    glClear(GL_COLOR_BUFFER_BIT);
}

void WindowHandler::InitializeWindow() {
    // // std::cout << "InitializeWindow called successfully! "<< std::endl;
    // if ( !glfwInit() ) {
    //     std::cerr << "Failed to initialize GLFW\n" << std::endl;
    //     exit(EXIT_FAILURE);
    // }
    // // Make sure at least OpenGL 3.2 is running
    // glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    // glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    // glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    // glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // // std::cout << "GLFW initialized successfully! "<< std::endl;
    // // window = glfwCreateWindow(960, 600, "My Title", glfwGetPrimaryMonitor(), NULL);
    // m_window = glfwCreateWindow(1200, 760, "LAVis", NULL, NULL);
    // if (!m_window) {
    //     std::cerr << "FAILED TO CREATE A GLFW WINDOW! "<< std::endl;
    //     glfwTerminate();
    //     exit(EXIT_FAILURE);
    // }
    // glfwMakeContextCurrent(m_window);
    //
    // glewExperimental = GL_TRUE;
    // GLenum status = glewInit();
    //
    // if(status != GLEW_OK) {
    //     std::cerr << "GLEW failed to initialize!" << std::endl;
    // }
    // std::cout << "OpenGL-version: " << glGetString(GL_VERSION) << std::endl;

}

}
