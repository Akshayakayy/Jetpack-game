#include "man.h"
#include "main.h"

Man::Man(float x, float y, color_t color) {
    this->position = glm::vec3(x, y, 0);
    this->rotation = 0;
    speed = 0.01;
    const int n = 50;

    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    static GLfloat head_vertex_buffer_data[18] = {
      0.0f, 0.67f, 0.0f,
      0.0f, 0.0f, 0.0f,
      0.67f,  0.0f, 0.0f,
      0.0f, 0.67f, 0.0f,
      0.67f, 0.67f, 0.0f,
      0.67f,  0.0f, 0.0f,
    };

    static GLfloat jet_vertex_buffer_data[18] = {
      -0.2f, 0.7f, 0.0f,
      -0.2f, 0.2f, 0.0f,
      0.1f,  0.2f, 0.0f,
      -0.2f, 0.7f, 0.0f,
      0.1f, 0.7f, 0.0f,
      0.1f,  0.2f, 0.0f,
    };

    static GLfloat vertex_buffer_data[9*n];

  for (int i=0;i<n;++i){
	   vertex_buffer_data[9*i+18]=0.35+(0.3*cos(i*2*3.14159/n));
	   vertex_buffer_data[9*i+1+18]=0.9+(0.3*sin(i*2*3.14159/n));
	   vertex_buffer_data[9*i+2+18]=0.0;

	   vertex_buffer_data[9*i+3+18]=0.35+(0.3*cos((i+1)*2*3.14159/n));
	   vertex_buffer_data[9*i+4+18]=0.9+(0.3*sin((i+1)*2*3.14159/n));
	   vertex_buffer_data[9*i+5+18]=0.0;

	   vertex_buffer_data[9*i+6+18]=0.35;
	   vertex_buffer_data[9*i+7+18]=0.9;
	   vertex_buffer_data[9*i+8+18]=0.0;
   }

   static GLfloat funnel_vertex_buffer_data[9*n];

 for (int i=0;i<n;++i){
    funnel_vertex_buffer_data[9*i+18]=-0.05+(0.15*cos(i*2*3.14159/n));
    funnel_vertex_buffer_data[9*i+1+18]=0.25+(0.15*sin(i*2*3.14159/n));
    funnel_vertex_buffer_data[9*i+2+18]=0.0;

    funnel_vertex_buffer_data[9*i+3+18]=-0.05+(0.15*cos((i+1)*2*3.14159/n));
    funnel_vertex_buffer_data[9*i+4+18]=0.25+(0.15*sin((i+1)*2*3.14159/n));
    funnel_vertex_buffer_data[9*i+5+18]=0.0;

    funnel_vertex_buffer_data[9*i+6+18]=-0.05;
    funnel_vertex_buffer_data[9*i+7+18]=0.25;
    funnel_vertex_buffer_data[9*i+8+18]=0.0;
  }


    this->object1 = create3DObject(GL_TRIANGLES, 18, head_vertex_buffer_data, COLOR_BLUE, GL_FILL);
    this->object2 = create3DObject(GL_TRIANGLES, 3*n, vertex_buffer_data, color, GL_FILL);
    this->object3 = create3DObject(GL_TRIANGLES, 18, jet_vertex_buffer_data, COLOR_LBLUE, GL_FILL);
    this->object4 = create3DObject(GL_TRIANGLES, 3*n, funnel_vertex_buffer_data, COLOR_RED, GL_FILL);
}

void Man::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
  //  glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(1, 0, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate);// * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);

    draw3DObject(this->object1);
    draw3DObject(this->object2);
    draw3DObject(this->object4);
    draw3DObject(this->object3);
}

void Man::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

void Man::tick(double x,double y) {
    //this->rotation += speed;
    this->position.x += x;
    this->position.y += y;
}

Jet::Jet(float x, float y, color_t color) {
    this->position = glm::vec3(x, y, 0);
    this->rotation = 0;

    const int n = 50;

    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    static GLfloat vertex_buffer_data[9*n];

  for (int i=0;i<n;++i){
	   vertex_buffer_data[9*i]=(0.07*cos(i*2*3.14159/n));
	   vertex_buffer_data[9*i+1]=(0.07*sin(i*2*3.14159/n));
	   vertex_buffer_data[9*i+2]=0.0;

	   vertex_buffer_data[9*i+3]=(0.07*cos((i+1)*2*3.14159/n));
	   vertex_buffer_data[9*i+4]=(0.07*sin((i+1)*2*3.14159/n));
	   vertex_buffer_data[9*i+5]=0.0;

	   vertex_buffer_data[9*i+6]=0.0;
	   vertex_buffer_data[9*i+7]=-0.6;
	   vertex_buffer_data[9*i+8]=0.0;
   }

    this->object = create3DObject(GL_TRIANGLES, 3*n, vertex_buffer_data, color, GL_FILL);
}

void Jet::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 0, 1));
    rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}

void Jet::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

void Jet::rand_position() {
    float x = (rand()%1000)/500;
    float y = (rand()%1000)/500;
    this->position = glm::vec3(x, y, 0);
}

void Jet::tick(double x, double y) {
    this->position.x += x;
    this->position.y += y;
}

bounding_box_t Jet::bounding_box() {
    float x = this->position.x, y = this->position.y;
    bounding_box_t bbox = { x, y, 1, 1 };
    return bbox;
}
