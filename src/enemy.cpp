#include "enemy.h"
#include "main.h"

Enemy::Enemy(float x, float y, float a, float b, color_t color) {
    this->position = glm::vec3(0, 0, 0);
    this->rotation = 0;
    speed = 0.01;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices

    static GLfloat vertex_buffer_data[] = {
      x, y-0.15, 0.0f,
      x, y+0.15, 0.0f,
      a, b-0.15, 0.0f,
      a, b-0.15, 0.0f,
      a, b+0.15, 0.0f,
      x, y+0.15, 0.0f,
    };

    this->object = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, color, GL_FILL);
}

void Enemy::update(float x, float y, float a, float b, color_t color) {
  this->position = glm::vec3(0, 0, 0);
  this->rotation = 0;
  speed = 0.01;
  // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
  // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
  //printf("\n%f, %f,, %f, %f\n", x,y,a,b);

  GLfloat vertex_buffer_data[] = {
    x, y-0.15, 0.0f,
    x, y+0.15, 0.0f,
    a, b-0.15, 0.0f,
    a, b-0.15, 0.0f,
    a, b+0.15, 0.0f,
    x, y+0.15, 0.0f,
  };

  this->object = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, color, GL_FILL);
}

void Enemy::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    // glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(1, 0, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate);// * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}

void Enemy::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

void Enemy::tick(double x,double y) {
    //this->rotation += speed;
    this->position.x += x;
    this->position.y += y;
}

Enemy2::Enemy2(float x, float y, float a, float b, color_t color) {
    this->position = glm::vec3(0, 0, 0);
    this->rotation = 0;
    speed = 0.01;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices

    GLfloat vertex_buffer_data[] = {
      x, y-0.15, 0.0f,
      x, y+0.15, 0.0f,
      a, b-0.15, 0.0f,
      a, b-0.15, 0.0f,
      a, b+0.15, 0.0f,
      x, y+0.15, 0.0f,
    };

    this->object = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, color, GL_FILL);
}

void Enemy2::update(float x, float y, float a, float b, color_t color) {
  this->position = glm::vec3(0, 0, 0);
  this->rotation = 0;
  speed = 0.01;
  // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
  // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices

  GLfloat vertex_buffer_data[] = {
    x, y-0.15, 0.0f,
    x, y+0.15, 0.0f,
    a, b-0.15, 0.0f,
    a, b-0.15, 0.0f,
    a, b+0.15, 0.0f,
    x, y+0.15, 0.0f,
  };
  this->object = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, color, GL_FILL);
}

void Enemy2::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    // glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(1, 0, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate);// * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}

void Enemy2::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

void Enemy2::tick(double x,double y) {
    //this->rotation += speed;
    this->position.x += x;
    this->position.y += y;
}

Boomerang::Boomerang(float x, float y, color_t color) {
    this->position = glm::vec3(x, y, 0);
    this->rotation = 0;
    speed = 0.01;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices

    static GLfloat vertex_buffer_data[] = {
      0.6f, 0.0f, 0.0f,
      0.0f, 0.2f, 0.0f,
      0.6f, 0.2f, 0.0f,
      0.0f, 0.2f, 0.0f,
      0.6f, 0.0f, 0.0f,
      0.0f, 0.0f, 0.0f,
      0.0f, 0.6f, 0.0f,
      0.2f, 0.0f, 0.0f,
      0.2f, 0.6f, 0.0f,
      0.2f, 0.0f, 0.0f,
      0.0f, 0.6f, 0.0f,
      0.0f, 0.0f, 0.0f,
    };
    printf("inside\n");
    this->object = create3DObject(GL_TRIANGLES, 12, vertex_buffer_data, color, GL_FILL);
}

void Boomerang::draw(glm::mat4 VP) {
  Matrices.model = glm::mat4(1.0f);
  glm::mat4 translate = glm::translate (this->position);    // glTranslatef
  glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 0, 1));
  rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
  Matrices.model *= (translate * rotate);
  glm::mat4 MVP = VP * Matrices.model;
  glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
  draw3DObject(this->object);
}

void Boomerang::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

void Boomerang::tick(double x,double y) {
    //this->rotation += speed;
    this->position.x += x;
    this->position.y += y;
}

Dragon::Dragon(float x, float y, color_t color) {
    this->position = glm::vec3(x, y, 0);
    this->rotation = 0;
    speed = 0.01;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices

    static GLfloat vertex_buffer_data[] = {
      0.0f, 0.5f, 0.0f,
      2.5f, 0.0f, 0.0f,
      2.5f, 0.5f, 0.0f,
      2.5f, 0.0f, 0.0f,
      0.0f, 0.5f, 0.0f,
      0.0f, 0.0f, 0.0f,
    };
    this->object = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, color, GL_FILL);
}


void Dragon::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    // glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(1, 0, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate);// * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}

void Dragon::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

void Dragon::tick(double x,double y) {
    //this->rotation += speed;
    this->position.x += x;
    this->position.y += y;
}
