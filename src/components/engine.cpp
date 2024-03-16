#include "../../include/engine.hpp"

GLFWwindow* Engine::initializeWindow()
{ 
    glfwWindowHint(GLFW_SAMPLES, 4); 
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); 
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); 
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); 

    GLFWwindow* window;
    window = glfwCreateWindow(1024, 768, "Collision Engine", NULL, NULL);
    if(window == NULL)
    {
        std::cerr << "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials" << std::endl;
        glfwTerminate();
        return nullptr;
    }
    glfwMakeContextCurrent(window); 
    glewExperimental = true; 
    if (glewInit() != GLEW_OK) 
    {
        std::cerr << "Failed to initialize GLEW" << std::endl;
        return nullptr;
    }

    return window;
}

int Engine::run()
{
    // Initialize GLFW
    glewExperimental = true;
    if(!glfwInit())
    {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    // Initialize window
    auto window = initializeWindow();
    if(window == nullptr)
        return -1;
 
    // Ensure we can capture the escape key being pressed below
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    do
    {
        // Clear the screen. It's not mentioned before Tutorial 02, but it can cause flickering, so it's there nonetheless.
        glClear(GL_COLOR_BUFFER_BIT);

        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();

    } // Check if the ESC key was pressed or the window was closed
    while(glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0);

    return 0;
}
