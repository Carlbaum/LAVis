#ifndef OC_SHAPE_H_
#define OC_SHAPE_H_

#include <iostream>
// #include <GLFW/glfw3.h>
#include <GL/glew.h>

namespace oc {

class OCShape {
public:
    // constructor
    OCShape();
    // DESTRUCTOR
    ~OCShape();

    GLfloat* GetVBuffer();
private:
    int testPriv;

protected:
    int testProt;
    GLfloat* p_vertex_buffer_data;

}; // end of class

} // end of namespace oc

#endif //OC_SHAPE_H_
