/*
g++ -IC:\GLFW\include -L. ventana.cpp -o programa.exe  -lglfw3 

SET GLFW_INCLUDE=C:\GLFW\include
SET GLFW_LIB=C:\GLFW\lib-vc2019\glfw3dll.lib
cl /Ehsc /I %GLFW_INCLUDE% ventana.cpp %GLFW_LIB%
*/

#define GLFW_DLL
#define GLFW_INCLUDE_NONE	
#include <GLFW/glfw3.h>
#include <iostream>

const int WIDTH = 800;
const int HEIGHT = 600;

// función de eventos de teclado

/*
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS){
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}

}
*/
int main()
{
	if (!glfwInit())
	{
		std::cerr << "error al iniciar GLFW" << std::endl;
		return -1;
	}
		
// configuración de opengl (3.3-> major, minor)
/*
glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
*/

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
/*
if(glewInit() != GLEW_OK)
{
	std::cerr << "error al iniciar glew" << std::endl;
	return -1;

}
*/

// funcion para eventos de teclado


//glfwSetKeyCallback(window, key_callback);


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


