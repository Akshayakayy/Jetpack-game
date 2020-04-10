#include "main.h"

#ifndef SCENE_H
#define SCENE_H


class Platform {
public:
    Platform() {}
    Platform(float x, float y, color_t color);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick(double,double);
    double speed;
private:
    VAO *object;
};

class Wall {
public:
    Wall() {}
    Wall(float x, float y, color_t color);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick(double,double);
    double speed;
private:
    VAO *object;
};

class Walldesign {
public:
    Walldesign() {}
    Walldesign(float x, float y, color_t color);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick(double,double);
    double speed;
private:
    VAO *object;
};

#endif // SCENE_H
