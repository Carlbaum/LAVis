#include "oc_shape.hpp"
#include "oc_shape_rectangle2d.hpp"
// OpenGL Math library.. maybe replace this with own functions later?
#include <glm/glm.hpp>


namespace oc {
//constructor
Rectangle2D::Rectangle2D(float x1, float y1, float x2, float y2) /*: OCShape() */{
    std::cout << "Basic constructor for oc::Rectangle2D called successfully! "<< std::endl;

    p_vertex_buffer_data = new GLfloat[12];
    p_vertex_buffer_data[0]  = x1;
    p_vertex_buffer_data[1]  = y1;
    p_vertex_buffer_data[2]  = 0;
    p_vertex_buffer_data[3]  = x1;
    p_vertex_buffer_data[4]  = y1;
    p_vertex_buffer_data[5]  = 0;
    p_vertex_buffer_data[6]  = x2;
    p_vertex_buffer_data[7]  = y1;
    p_vertex_buffer_data[8]  = 0;
    p_vertex_buffer_data[9]  = x2;
    p_vertex_buffer_data[10] = y1;
    p_vertex_buffer_data[11] = 0;

    // {
    //     x1, y1, 0.f,
    //     x1, y2, 0.f,
    //     x2, y2, 0.f,
    //     x2, y1, 0.f,
    // };
}

Rectangle2D::~Rectangle2D() {
    std::cout << "Rectangle2D destructor called" << std::endl;
}


} // End of namespace oc
