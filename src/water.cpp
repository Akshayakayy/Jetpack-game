#include "water.h"
#include "main.h"
#include "stdlib.h"

Water::Water(float x, float y, color_t color) {
    this->position = glm::vec3(x, y, 0);
    this->rotation = 0;

    const int n = 50;

    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    static GLfloat vertex_buffer_data[9*n];

  for (int i=0;i<n;++i){
	   vertex_buffer_data[9*i]=(0.2*cos(i*2*3.14159/n));
	   vertex_buffer_data[9*i+1]=(0.2*sin(i*2*3.14159/n));
	   vertex_buffer_data[9*i+2]=0.0;

	   vertex_buffer_data[9*i+3]=(0.2*cos((i+1)*2*3.14159/n));
	   vertex_buffer_data[9*i+4]=(0.2*sin((i+1)*2*3.14159/n));
	   vertex_buffer_data[9*i+5]=0.0;

	   vertex_buffer_data[9*i+6]=0.0;
	   vertex_buffer_data[9*i+7]=0.0;
	   vertex_buffer_data[9*i+8]=0.0;
   }

    this->object = create3DObject(GL_TRIANGLES, 3*n, vertex_buffer_data, color, GL_FILL);
}

void Water::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 0, 1));
    rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}

void Water::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

void Water::rand_position() {
    float x = (rand()%1000)/500;
    float y = (rand()%1000)/500;
    this->position = glm::vec3(x, y, 0);
}

void Water::tick(double x, double y) {
    this->position.x += x;
    this->position.y += y;
}

bounding_box_t Water::bounding_box() {
    float x = this->position.x, y = this->position.y;
    bounding_box_t bbox = { x, y, 1, 1 };
    return bbox;
}
