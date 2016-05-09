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

private:
    void InitializeWindow();
    GLFWwindow* window;


}; // end of class

} // end of namespace oc

#endif //WINDOW_HANDLER_H_
