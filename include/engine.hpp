#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

namespace Engine
{
    GLFWwindow* initializeWindow();

    int run();
}