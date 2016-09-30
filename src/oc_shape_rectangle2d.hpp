#ifndef OC_SHAPE_RECTANGLE2D_H_
#define OC_SHAPE_RECTANGLE2D_H_

#include <iostream>
#include <GL/glew.h>
// #include <GLFW/glfw3.h>
#include "oc_shape.hpp"

namespace oc {

class Rectangle2D : public OCShape {
public:
    Rectangle2D(float x1, float y1, float x2, float y2);
    ~Rectangle2D() ;
private:
};

} // end of namespace oc

#endif //OC_SHAPE_RECTANGLE2D_H_
