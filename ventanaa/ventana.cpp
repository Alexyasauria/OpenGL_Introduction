/*
g++ -o programa ventana.cpp -IC:\GLFW\include -IC:\GLEW\include -LC:\GLFW\lib-mingw-w64 -LC:\GLEW\lib\release\Win32 -lglfw3 -lglew32 -lopengl32 -L. -L"C:\Program Files (x86)\Windows Kits\10\Lib\10.0.22000.0\um\x64" -lgdi32 -luser32 -lgdi32 -lshell32

*/

//#define GLFW_DLL
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

const int WIDTH = 800;
const int HEIGHT = 600;

// función de eventos de teclado

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS){
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}
}
int main()
{
	if (!glfwInit())
	{
		std::cerr << "error al iniciar GLFW" << std::endl;
		return -1;
	}
		
// configuración de opengl (3.3-> major, minor)

glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


//crear una ventana

GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "SUPERJUEGO",nullptr,nullptr);
if(!window)
{
	std::cerr << "error al crear la ventana de GLFW" << std::endl;
	glfwTerminate();
	return -1;

}

// hacer a la ventana el contexto actual
glfwMakeContextCurrent(window);


// Inicializar GLEW

if(glewInit() != GLEW_OK)
{
	std::cerr << "error al iniciar glew" << std::endl;
	return -1;

}

// funcion para eventos de teclado

glfwSetKeyCallback(window, key_callback);


// CICLO DE LA VENTANA AHORA SÍ

while(!glfwWindowShouldClose(window))
{
// lógica de actualización
// parte de renderizar

// intercambio de buffers
	glfwSwapBuffers(window);

// comprobar eventos de entrada
	glfwPollEvents();


}
glfwDestroyWindow(window);
glfwTerminate();
return 0;
}


