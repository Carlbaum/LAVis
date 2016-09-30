#include <iostream>
#include <GL/glew.h>
#include "window_handler.hpp"
#include "oc_shape.hpp"
#include "oc_shape_rectangle2d.hpp"
#include "mesh.hpp"
#include "shader.hpp"
#include "load_shaders.hpp"

int main() {
    std::cout << "\nLAVis to the rescue!\n" << std::endl;
    int win_width = 1024, win_height = 768;
    oc::WindowHandler wh;

    //------- OpenGL 3.3 - First triangle beginner tutorial -------////http://www.opengl-tutorial.org/beginners-tutorials/tutorial-2-the-first-triangle/
    //--------------------------- START ---------------------------//

    // oc::Rectangle2D rect(-1,1,0,0);

    float rect_x1 = -0.5f, rect_x2 = 0.f, rect_y1 = 0.5f, rect_y2 = 0.0f;
    oc::Vertex vertices[] = { oc::Vertex(glm::vec3(rect_x1, rect_y1, 0.0f)),
                              oc::Vertex(glm::vec3(rect_x1, rect_y2, 0.0f)),
                              oc::Vertex(glm::vec3(rect_x2, rect_y2, 0.0f)),
                              oc::Vertex(glm::vec3(rect_x2, rect_y1, 0.0f)), };
    unsigned int indices[] = { 0, 1, 2,
                               0, 2, 3 };

    oc::Mesh panel1( vertices, sizeof(vertices)/sizeof(vertices[0]), indices, sizeof(indices)/sizeof(indices[0]) );
    // oc::Shader basicShader("../res/basicShader");
    std::cout << "number of vertices: " << sizeof(vertices)/sizeof(vertices[0]) << std::endl;
    // Create and compile our GLSL program from the shaders
    GLuint programID = LoadShaders( "../res/basicShader.vs", "../res/basicShader.fs" );
    GLFWcursor* cursor = glfwCreateStandardCursor(GLFW_CROSSHAIR_CURSOR);
    while( !wh.IsClosed() ) {
        wh.Clear(0.0f, 0.15f, 0.3f, 1.0f);

        // basicShader.Bind();
        glUseProgram(programID);
        panel1.Draw();
        // Get mouse position
        double xpos, ypos;
        glfwGetCursorPos(wh.GetWindowPointer(), &xpos, &ypos);
        xpos = xpos*2.0f/win_width-1;
        ypos = -(ypos*2.0f/win_height-1);
        if(xpos >= rect_x1 && xpos <= rect_x2 && ypos <= rect_y1 && ypos >= rect_y2) {
            std::cout << "MOUSE OVER GUI\n\t xpos = " << xpos << ",  ypos = " << ypos << std::endl;
            glfwSetCursor(wh.GetWindowPointer(), cursor);
        }
        // else {
        //     std::cout << "MOUSE NOT OVER GUI\n\t xpos = " << xpos << ",  ypos = " << ypos << std::endl;
        // }
        wh.Update();
    }



    return 0;
}
