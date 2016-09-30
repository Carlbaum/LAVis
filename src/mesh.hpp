#ifndef MESH_H
#define MESH_H

#include <glm/glm.hpp>
#include <GL/glew.h>
/*
#include <string>
#include <vector>
*/
namespace oc {

class Vertex
{
public:
	Vertex(const glm::vec3& pos) {
		this->pos = pos;
	}
	Vertex(const glm::vec3& pos, const glm::vec2& texCoord) {
		this->pos = pos;
        this->texCoord = texCoord;
	}

    inline glm::vec3* GetPos() { return &pos; }
    inline glm::vec2* GetTextCoord() { return &texCoord; }

protected:
private:
	glm::vec3 pos;
	glm::vec2 texCoord;
};

class Mesh
{
public:
	Mesh(Vertex* vertices, unsigned int numVertices, unsigned int* indices, unsigned int numIndices );

	void Draw();

	virtual ~Mesh();
protected:
private:
	Mesh(const Mesh& other);
	void operator=(const Mesh& other);

    enum{
        POSITION_VB,
        TEXCOORD_VB,

		INDEX_VB,

        NUM_BUFFERS
    };

	GLuint m_vertexArrayObject;
	GLuint m_vertexArrayBuffers[NUM_BUFFERS];
	unsigned int m_drawCount;
	unsigned int m_numIndices;
}; //end mesh class

} //end namespace

#endif // MESH_H
