#include "oc_shape.hpp"
// OpenGL Math library.. maybe replace this with own functions later?
#include <glm/glm.hpp>

namespace oc {

OCShape::OCShape() {
    std::cout << "Basic constructor for oc::OCShape called successfully! "<< std::endl;
}

OCShape::~OCShape() {
    std::cout << "OCShape destructor successfully executed!" << std::endl;
    delete [] p_vertex_buffer_data;
}

GLfloat* OCShape::GetVBuffer() {
    return p_vertex_buffer_data;
}


} // End of namespace oc
