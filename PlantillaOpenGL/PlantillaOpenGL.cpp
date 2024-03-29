// PlantillaOpenGL.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"

#include <stdio.h>
#include <stdlib.h>

#define GLEW_STATIC

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include <iostream>

#include "Shader.h"
#include "Vertice.h"
#include "Modelo.h"

using namespace std;

Shader *shader;
GLuint posicionID;
GLuint colorID;

Modelo *triangulo;
Modelo *cuadrado;

Modelo *aliencito;

void inicializarCuadrado() {
	cuadrado = new Modelo();
	Vertice v1 = {
		vec3(-0.8,0.8,0.0),
		vec4(0.4,0.7,0.1,1.0)
	};
	Vertice v2 = {
		vec3(-0.4,0.8,0.0),
		vec4(0.4,0.7,0.1,1.0)
	};
	Vertice v3 = {
		vec3(-0.4,0.5,0.0),
		vec4(0.4,0.7,0.1,1.0)
	};
	Vertice v4 = {
		vec3(-0.8,0.5,0.0),
		vec4(0.4,0.7,0.1,1.0)
	};
	cuadrado->vertices.push_back(v1);
	cuadrado->vertices.push_back(v2);
	cuadrado->vertices.push_back(v3);
	cuadrado->vertices.push_back(v4);
}

void inicializarTriangulo() {
	triangulo = new Modelo();
	Vertice v1 =
	{
		vec3(0.0f,0.3f,0.0f),
		vec4(1.0f,0.8f,0.0f,1.0f)
	};
	Vertice v2 =
	{
		vec3(-0.3f,-0.3f,0.0f),
		vec4(1.0f,0.8f,0.0f,1.0f)
	};
	Vertice v3 =
	{
		vec3(0.3f,-0.3f,0.0f),
		vec4(1.0f,0.8f,0.0f,1.0f)
	};

	triangulo->vertices.push_back(v1);
	triangulo->vertices.push_back(v2);
	triangulo->vertices.push_back(v3);
}

void inicializarAliencito() {
	aliencito = new Modelo();
	//Patitas
	Vertice v1 = {
		vec3(-0.2f,-0.8f,0.0f),
		vec4(0.0f,0.3789f,0.9921f,1.0f)
	};
	Vertice v2 = {
		vec3(-0.1f,-0.8f,0.0f),
		vec4(0.0f,0.3789f,0.9921f,1.0f)
	};
	Vertice v3 = {
		vec3(-0.1f,-0.75f,0.0f),
		vec4(0.0f,0.3789f,0.9921f,1.0f)
	};
	Vertice v4 = {
		vec3(-0.2f,-0.75f,0.0f),
		vec4(0.0f,0.3789f,0.9921f,1.0f)
	};
	aliencito->vertices.push_back(v1);
	aliencito->vertices.push_back(v2);
	aliencito->vertices.push_back(v3);
	aliencito->vertices.push_back(v4);

	Vertice v5 = {
		vec3(-0.0f,-0.8f,0.0f),
		vec4(0.0f,0.3789f,0.9921f,1.0f)
	};
	Vertice v6 = {
		vec3(0.1f,-0.8f,0.0f),
		vec4(0.0f,0.3789f,0.9921f,1.0f)
	};
	Vertice v7 = {
		vec3(0.1f,-0.75f,0.0f),
		vec4(0.0f,0.3789f,0.9921f,1.0f)
	};
	Vertice v8 = {
		vec3(-0.0f,-0.75f,0.0f),
		vec4(0.0f,0.3789f,0.9921f,1.0f)
	};
	aliencito->vertices.push_back(v5);
	aliencito->vertices.push_back(v6);
	aliencito->vertices.push_back(v7);
	aliencito->vertices.push_back(v8);
	//
	Vertice v9 = {
		vec3(-0.25f,-0.75f,0.0f),
		vec4(0.0f,0.3789f,0.9921f,1.0f)
	};
	Vertice v10 = {
		vec3(-0.2f,-0.75f,0.0f),
		vec4(0.0f,0.3789f,0.9921f,1.0f)
	};
	Vertice v11 = {
		vec3(-0.2f,-0.6f,0.0f),
		vec4(0.0f,0.3789f,0.9921f,1.0f)
	};
	Vertice v12 = {
		vec3(-0.25f,-0.6f,0.0f),
		vec4(0.0f,0.3789f,0.9921f,1.0f)
	};
	aliencito->vertices.push_back(v9);
	aliencito->vertices.push_back(v10);
	aliencito->vertices.push_back(v11);
	aliencito->vertices.push_back(v12);

	Vertice v13 = {
		vec3(-0.35f,-0.75f,0.0f),
		vec4(0.0f,0.3789f,0.9921f,1.0f)
	};
	Vertice v14 = {
		vec3(-0.3f,-0.75f,0.0f),
		vec4(0.0f,0.3789f,0.9921f,1.0f)
	};
	Vertice v15 = {
		vec3(-0.3f,-0.55f,0.0f),
		vec4(0.0f,0.3789f,0.9921f,1.0f)
	};
	Vertice v16 = {
		vec3(-0.35f,-0.55f,0.0f),
		vec4(0.0f,0.3789f,0.9921f,1.0f)
	};
	aliencito->vertices.push_back(v13);
	aliencito->vertices.push_back(v14);
	aliencito->vertices.push_back(v15);
	aliencito->vertices.push_back(v16);
	//
	Vertice v17 = {
		vec3(0.1f,-0.75f,0.0f),
		vec4(0.0f,0.3789f,0.9921f,1.0f)
	};
	Vertice v18 = {
		vec3(0.15f,-0.75f,0.0f),
		vec4(0.0f,0.3789f,0.9921f,1.0f)
	};
	Vertice v19 = {
		vec3(0.15f,-0.6f,0.0f),
		vec4(0.0f,0.3789f,0.9921f,1.0f)
	};
	Vertice v20= {
		vec3(0.1f,-0.6f,0.0f),
		vec4(0.0f,0.3789f,0.9921f,1.0f)
	};
	aliencito->vertices.push_back(v17);
	aliencito->vertices.push_back(v18);
	aliencito->vertices.push_back(v19);
	aliencito->vertices.push_back(v20);

	Vertice v21 = {
		vec3(0.2f,-0.75f,0.0f),
		vec4(0.0f,0.3789f,0.9921f,1.0f)
	};
	Vertice v22 = {
		vec3(0.25f,-0.75f,0.0f),
		vec4(0.0f,0.3789f,0.9921f,1.0f)
	};
	Vertice v23 = {
		vec3(0.25f,-0.55f,0.0f),
		vec4(0.0f,0.3789f,0.9921f,1.0f)
	};
	Vertice v24 = {
		vec3(0.2f,-0.55f,0.0f),
		vec4(0.0f,0.3789f,0.9921f,1.0f)
	};
	aliencito->vertices.push_back(v21);
	aliencito->vertices.push_back(v22);
	aliencito->vertices.push_back(v23);
	aliencito->vertices.push_back(v24);
	//basesita
	Vertice v25 = {
		vec3(-0.25f,-0.65f,0.0f),
		vec4(0.0f,0.3789f,0.9921f,1.0f)
	};
	Vertice v26 = {
		vec3(0.15f,-0.65f,0.0f),
		vec4(0.0f,0.3789f,0.9921f,1.0f)
	};
	Vertice v27 = {
		vec3(0.15f,-0.6f,0.0f),
		vec4(0.0f,0.3789f,0.9921f,1.0f)
	};
	Vertice v28 = {
		vec3(-0.25f,-0.6f,0.0f),
		vec4(0.0f,0.3789f,0.9921f,1.0f)
	};
	aliencito->vertices.push_back(v25);
	aliencito->vertices.push_back(v26);
	aliencito->vertices.push_back(v27);
	aliencito->vertices.push_back(v28);

	//CUADRITOS
	Vertice v29 = {
		vec3(-0.25f,-0.6f,0.0f),
		vec4(0.0f,0.3789f,0.9921f,1.0f)
	};
	Vertice v30 = {
		vec3(0.15f,-0.6f,0.0f),
		vec4(0.0f,0.3789f,0.9921f,1.0f)
	};
	Vertice v31 = {
		vec3(0.15f,-0.4f,0.0f),
		vec4(0.0f,0.3789f,0.9921f,1.0f)
	};
	Vertice v32 = {
		vec3(-0.25f,-0.4f,0.0f),
		vec4(0.0f,0.3789f,0.9921f,1.0f)
	};
	aliencito->vertices.push_back(v29);
	aliencito->vertices.push_back(v30);
	aliencito->vertices.push_back(v31);
	aliencito->vertices.push_back(v32);

	Vertice v33 = {
		vec3(0.15f,-0.625f,0.0f),
		vec4(0.0f,0.3789f,0.9921f,1.0f)
	};
	Vertice v34 = {
		vec3(0.2f,-0.625f,0.0f),
		vec4(0.0f,0.3789f,0.9921f,1.0f)
	};
	Vertice v35 = {
		vec3(0.2f,-0.5f,0.0f),
		vec4(0.0f,0.3789f,0.9921f,1.0f)
	};
	Vertice v36 = {
		vec3(0.15f,-0.5f,0.0f),
		vec4(0.0f,0.3789f,0.9921f,1.0f)
	};
	aliencito->vertices.push_back(v33);
	aliencito->vertices.push_back(v34);
	aliencito->vertices.push_back(v35);
	aliencito->vertices.push_back(v36);

	Vertice v37 = {
		vec3(-0.25f,-0.625f,0.0f),
		vec4(0.0f,0.3789f,0.9921f,1.0f)
	};
	Vertice v38= {
		vec3(-0.3f,-0.625f,0.0f),
		vec4(0.0f,0.3789f,0.9921f,1.0f)
	};
	Vertice v39 = {
		vec3(-0.3f,-0.5f,0.0f),
		vec4(0.0f,0.3789f,0.9921f,1.0f)
	};
	Vertice v40 = {
		vec3(-0.25f,-0.5f,0.0f),
		vec4(0.0f,0.3789f,0.9921f,1.0f)
	};
	aliencito->vertices.push_back(v37);
	aliencito->vertices.push_back(v38);
	aliencito->vertices.push_back(v39);
	aliencito->vertices.push_back(v40);

	//ANTENAS1
	Vertice v41 = {
		vec3(-0.2f,-0.4f,0.0f),
		vec4(0.0f,0.3789f,0.9921f,1.0f)
	};
	Vertice v42 = {
		vec3(-0.15f,-0.4f,0.0f),
		vec4(0.0f,0.3789f,0.9921f,1.0f)
	};
	Vertice v43 = {
		vec3(-0.15f,-0.35f,0.0f),
		vec4(0.0f,0.3789f,0.9921f,1.0f)
	};
	Vertice v44 = {
		vec3(-0.2f,-0.35f,0.0f),
		vec4(0.0f,0.3789f,0.9921f,1.0f)
	};
	aliencito->vertices.push_back(v41);
	aliencito->vertices.push_back(v42);
	aliencito->vertices.push_back(v43);
	aliencito->vertices.push_back(v44);



	Vertice v45 = {
		vec3(-0.25f,-0.35f,0.0f),
		vec4(0.0f,0.3789f,0.9921f,1.0f)
	};
	Vertice v46 = {
		vec3(-0.2f,-0.35f,0.0f),
		vec4(0.0f,0.3789f,0.9921f,1.0f)
	};
	Vertice v47 = {
		vec3(-0.2f,-0.275f,0.0f),
		vec4(0.0f,0.3789f,0.9921f,1.0f)
	};
	Vertice v48 = {
		vec3(-0.25f,-0.275f,0.0f),
		vec4(0.0f,0.3789f,0.9921f,1.0f)
	};
	aliencito->vertices.push_back(v45);
	aliencito->vertices.push_back(v46);
	aliencito->vertices.push_back(v47);
	aliencito->vertices.push_back(v48);

	//ANTENAS2
	Vertice v49 = {
		vec3(0.1f,-0.4f,0.0f),
		vec4(0.0f,0.3789f,0.9921f,1.0f)
	};
	Vertice v50 = {
		vec3(0.05f,-0.4f,0.0f),
		vec4(0.0f,0.3789f,0.9921f,1.0f)
	};
	Vertice v51 = {
		vec3(0.05f,-0.35f,0.0f),
		vec4(0.0f,0.3789f,0.9921f,1.0f)
	};
	Vertice v52 = {
		vec3(0.1f,-0.35f,0.0f),
		vec4(0.0f,0.3789f,0.9921f,1.0f)
	};
	aliencito->vertices.push_back(v49);
	aliencito->vertices.push_back(v50);
	aliencito->vertices.push_back(v51);
	aliencito->vertices.push_back(v52);

	Vertice v53 = {
		vec3(0.15f,-0.35f,0.0f),
		vec4(0.0f,0.3789f,0.9921f,1.0f)
	};
	Vertice v54 = {
		vec3(0.1f,-0.35f,0.0f),
		vec4(0.0f,0.3789f,0.9921f,1.0f)
	};
	Vertice v55 = {
		vec3(0.1f,-0.275f,0.0f),
		vec4(0.0f,0.3789f,0.9921f,1.0f)
	};
	Vertice v56 = {
		vec3(0.15f,-0.275f,0.0f),
		vec4(0.0f,0.3789f,0.9921f,1.0f)
	};
	aliencito->vertices.push_back(v53);
	aliencito->vertices.push_back(v54);
	aliencito->vertices.push_back(v55);
	aliencito->vertices.push_back(v56);

	//OJOS
	Vertice v57 = {
		vec3(0.1f,-0.5f,0.0f),
		vec4(0.0f,0.0f,0.0f,1.0f)
	};
	Vertice v58 = {
		vec3(0.05f,-0.5f,0.0f),
		vec4(0.0f,0.0f,0.0f,1.0f)
	};
	Vertice v59 = {
		vec3(0.05f,-0.45f,0.0f),
		vec4(0.0f,0.0f,0.0f,1.0f)
	};
	Vertice v60 = {
		vec3(0.1f,-0.45f,0.0f),
		vec4(0.0f,0.0f,0.0f,1.0f)
	};
	aliencito->vertices.push_back(v57);
	aliencito->vertices.push_back(v58);
	aliencito->vertices.push_back(v59);
	aliencito->vertices.push_back(v60);

	Vertice v61 = {
		vec3(-0.2f,-0.5f,0.0f),
		vec4(0.0f,0.0f,0.0f,1.0f)
	};
	Vertice v62 = {
		vec3(-0.15f,-0.5f,0.0f),
		vec4(0.0f,0.0f,0.0f,1.0f)
	};
	Vertice v63 = {
		vec3(-0.15f,-0.45f,0.0f),
		vec4(0.0f,0.0f,0.0f,1.0f)
	};
	Vertice v64 = {
		vec3(-0.2f,-0.45f,0.0f),
		vec4(0.0f,0.0f,0.0f,1.0f)
	};
	aliencito->vertices.push_back(v61);
	aliencito->vertices.push_back(v62);
	aliencito->vertices.push_back(v63);
	aliencito->vertices.push_back(v64);


}


void dibujar() {
	//triangulo->dibujar(GL_TRIANGLES);
	//cuadrado->dibujar(GL_QUADS);
	aliencito->dibujar(GL_QUADS);
}

void actualizar() {

}

int main()
{
	//Declaramos apuntador de ventana
	GLFWwindow *window;
	
	//Si no se pudo iniciar glfw
	//terminamos ejcución
	if (!glfwInit()) {
		exit(EXIT_FAILURE);
	}
	//Si se pudo iniciar GLFW
	//entonces inicializamos la ventana
	window =
		glfwCreateWindow(1024, 768, "Ventana", 
			NULL, NULL);
	//Si no podemos iniciar la ventana
	//Entonces terminamos ejecucion
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	//Establecemos el contexto
	glfwMakeContextCurrent(window);

	//Una vez establecido  el contexto
	//Activamos funciones modernas
	glewExperimental = true;
	GLenum errorGlew = glewInit();
	if (errorGlew != GLEW_OK) {
		cout << 
			glewGetErrorString(errorGlew);
	}

	const GLubyte *versionGL =
		glGetString(GL_VERSION);
	cout << "Version OpenGL: "
		<< versionGL;

	//inicializarTriangulo();
	//inicializarCuadrado();
	inicializarAliencito();

	const char *rutaVertex = 
		"VertexShader.shader";
	const char *rutaFragment = 
		"FragmentShader.shader";

	shader = new Shader(rutaVertex, rutaFragment);

	//Mapeo de atributos
	posicionID =
		glGetAttribLocation(shader->getID(), "posicion");
	colorID =
		glGetAttribLocation(shader->getID(), "color");

	//Desenlazar el shader
	shader->desenlazar();

	//Establecer shader al modelo
	//triangulo->shader = shader;
	//inicializar el vertex array 
	//triangulo->inicializarVertexArray(posicionID, colorID);

	/*cuadrado->shader = shader;
	cuadrado->inicializarVertexArray(posicionID, colorID);*/

	aliencito->shader = shader;
	aliencito->inicializarVertexArray(posicionID, colorID);

	//Ciclo de dibujo (Draw loop)
	while (!glfwWindowShouldClose(window)) {
		//Esablecer region de dibujo
		glViewport(0, 0, 1024, 768);
		//Establece el color de borrado
		glClearColor(1, 0.2, 0.5, 1);
		//Borramos
		glClear(
			GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//Rutina de dibujo
		dibujar();
		actualizar();

		//Cambiar los buffers
		glfwSwapBuffers(window);
		//Reconocer si hay entradas
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();

    return 0;
}

