#ifndef WINDOW_HANDLER_H_
#define WINDOW_HANDLER_H_

#include <iostream>
#define GLFW_INCLUDE_GLU
#include <GLFW/glfw3.h>

namespace oc {

class WindowHandler {
public:
    // constructor
    WindowHandler();
    // DESTRUCTOR
    ~WindowHandler();
    void StartWindowLoop();
    void Update();
    void Clear(float r, float g, float b, float a);
    bool IsClosed();
    GLFWwindow* GetWindowPointer() { return m_window; }


private:
    void InitializeWindow();
    bool m_isClosed;

    GLFWwindow* m_window;

    GLuint VertexArrayID;


}; // end of class

} // end of namespace oc

#endif //WINDOW_HANDLER_H_
