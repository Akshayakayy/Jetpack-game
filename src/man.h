#include "main.h"

#ifndef MAN_H
#define MAN_H


class Man {
public:
    Man() {}
    Man(float x, float y, color_t color);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick(double,double);
    double speed;
private:
    VAO *object1, *object2, *object3, *object4;
};

class Jet {
public:
    Jet() {}
    Jet(float x, float y, color_t color);
    glm::vec3 position;
    glm::vec3 speed;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void rand_position();
    void tick(double x, double y);
    bounding_box_t bounding_box();
private:
    VAO *object;
};

#endif // MAN_H
