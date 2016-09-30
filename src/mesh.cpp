#include "mesh.hpp"
#include <vector>
/*
#include "util.h"
#include "debugTimer.h"
#include <map>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <stdlib.h>
*/
namespace oc {
 
Mesh::Mesh(Vertex* vertices, unsigned int numVertices, unsigned int* indices, unsigned int numIndices )
{
    // m_drawCount = numVertices;
    // m_drawCount = numIndices;
    m_numIndices = numIndices;

    glGenVertexArrays(1, &m_vertexArrayObject); //allocate space for vertex array
    glBindVertexArray(m_vertexArrayObject); // Use input as VertexArray from now on

    std::vector<glm::vec3> positions;
    std::vector<glm::vec2> texCoords;

    positions.reserve(numVertices);
    texCoords.reserve(numVertices);

    for(unsigned int i = 0; i < numVertices ; i++ ) {
        positions.push_back(*vertices[i].GetPos());
        texCoords.push_back(*vertices[i].GetTextCoord());
    }

    glGenBuffers(NUM_BUFFERS, m_vertexArrayBuffers); // allocate space for Vertex buffers

    glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[POSITION_VB]);
    glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(positions[0]), &positions[0], GL_STATIC_DRAW); // Move data from RAM the GPU memory.. kind of. GL_STATIC_DRAW essentially says that we don't need to overwrite the data that much but we want to read it.

    glEnableVertexAttribArray(0); // enable space for an attribute array. In this case this will represent the position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0); // tell OpenGL how the data is constructed. (attribArray, numberOfData, type, normalize?, how many to skip to find next attrib, how much needed to start from beginning)

    glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[TEXCOORD_VB]);
    glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(texCoords[0]), &texCoords[0], GL_STATIC_DRAW);

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_vertexArrayBuffers[INDEX_VB]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, numIndices * sizeof(indices[0]), &indices[0], GL_STATIC_DRAW); // Move data from RAM the GPU memory.. kind of. GL_STATIC_DRAW essentially says that we don't need to overwrite the data that much but we want to read it.


    glBindVertexArray(0); // Don't use the previous VertexArray anymore
}

Mesh::~Mesh()
{
	//glDeleteBuffers(NUM_BUFFERS, m_vertexArrayBuffers);
	glDeleteVertexArrays(1, &m_vertexArrayObject);
}

void Mesh::Draw()
{
	glBindVertexArray(m_vertexArrayObject);

    // glDrawArrays(GL_TRIANGLES, 0, m_drawCount); // draw triangles from pos 0 in buffer to end
	glDrawElements(GL_TRIANGLES, m_numIndices, GL_UNSIGNED_INT, 0);
	//glDrawElementsBaseVertex(GL_TRIANGLES, m_numIndices, GL_UNSIGNED_INT, 0, 0);

	glBindVertexArray(0);
}

} // end namespace oc
