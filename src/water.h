#include "main.h"

#ifndef WATER_H
#define WATER_H


class Water {
public:
    Water() {}
    Water(float x, float y, color_t color);
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

#endif // WATER_H
