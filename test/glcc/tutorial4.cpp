#include <boost/test/unit_test.hpp>

#define GL3_PROTOTYPES 1
#include <GL3/gl3.h>

#include "../GL3Context.hpp"
#include "../utils.h"

#define SHADER_SOURCE(NAME, SOURCE)                                            \
	static const char* const NAME = "#version 150\n" #SOURCE                   \

SHADER_SOURCE(vertexsource,

		precision highp float;

		in vec3 in_Position;
		in vec3 in_Color;

		out vec3 geom_Color;

		void main(void)
		{
			gl_Position = vec4(in_Position, 1.0);
			geom_Color = in_Color;
		}
);

SHADER_SOURCE(geometrysource,

		precision highp float;

		uniform mat4 mvpmatrix;

		// Declare what type of incoming primitive our geometry shader is receiving
		layout(triangles) in;

		// Declare what type of primitives we are creating and the maximum amount of vertices we will output per use of the geometry shader.
		// We will be outputting 6 vertices per use of this shader, creating 2 triangles.
		layout(triangle_strip, max_vertices = 6) out;

		// Inputs to geometry shaders are always as arrays in the quantity of the incoming primitive
		// In our case this value is 3, since triangles have 3 vertices
		in vec3 geom_Color[3];
		out vec3 ex_Color;

		void main()
		{
			// simple iterator
			int i;

			// Create our original primitive
			for (i=0; i < gl_in.length(); i++)
			{
				gl_Position = mvpmatrix * gl_in[i].gl_Position;
				ex_Color = geom_Color[i];
				EmitVertex();
			}
			EndPrimitive();

			// Create a new primitive with negative x,y,z values
			for (i=0; i < gl_in.length(); i++)
			{
				gl_Position = mvpmatrix * vec4(-gl_in[i].gl_Position.xyz, 1.0);
				ex_Color = geom_Color[i];
				EmitVertex();
			}
			EndPrimitive();
		}
);

SHADER_SOURCE(fragmentsource,

		precision highp float;
		in vec3 ex_Color;
		out vec4 gl_FragColor;

		void main(void)
		{
			gl_FragColor = vec4(ex_Color, 1.0);
		}
);

BOOST_FIXTURE_TEST_SUITE(tutorial4, GL3Context)

BOOST_AUTO_TEST_CASE(drawscene)
{
	GLuint vao, vbo[3]; /* Create handles for our Vertex Array Object and three Vertex Buffer Objects */

	GLfloat projectionmatrix[16]; /* Our projection matrix starts with all 0s */
	GLfloat modelmatrix[16]; /* Our model matrix  */
	/* An identity matrix we use to perform the equivalant of glLoadIdentity */
	const GLfloat identitymatrix[16] = IDENTITY_MATRIX4;

	/* The four vericies of a tetrahedron */
	const GLfloat tetrahedron[4][3] =
	{
		{	1.0, 1.0, 1.0}, /* index 0 */
		{	-1.0, -1.0, 1.0}, /* index 1 */
		{	-1.0, 1.0, -1.0}, /* index 2 */
		{	1.0, -1.0, -1.0} /* index 3 */
	};

	/* Color information for each vertex */
	const GLfloat colors[4][3] =
	{
		{	1.0, 0.0, 0.0}, /* red */
		{	0.0, 1.0, 0.0}, /* green */
		{	0.0, 0.0, 1.0}, /* blue */
		{	1.0, 1.0, 1.0} /* white */
	};

	const GLubyte tetraindicies[6] =
	{	0, 1, 2, 3, 0, 1};

	/* These are handles used to reference the shaders */
	GLuint vertexshader, fragmentshader, geometryshader;

	/* This is a handle to the shader program */
	GLuint shaderprogram;

	/* Allocate and assign a Vertex Array Object to our handle */
	glGenVertexArrays(1, &vao);

	/* Bind our Vertex Array Object as the current used object */
	glBindVertexArray(vao);

	/* Allocate and assign three Vertex Buffer Objects to our handle */
	glGenBuffers(3, vbo);

	/* Bind our first VBO as being the active buffer and storing vertex attributes (coordinates) */
	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);

	/* Copy the vertex data from tetrahedron to our buffer */
	/* 12 * sizeof(GLfloat) is the size of the tetrahedrom array, since it contains 12 GLfloat values */
	glBufferData(GL_ARRAY_BUFFER, 12 * sizeof(GLfloat), tetrahedron, GL_STATIC_DRAW);

	/* Specify that our coordinate data is going into attribute index 0, and contains three floats per vertex */
	glVertexAttribPointer((GLuint)0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	/* Enable attribute index 0 as being used */
	glEnableVertexAttribArray(0);

	/* Bind our second VBO as being the active buffer and storing vertex attributes (colors) */
	glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);

	/* Copy the color data from colors to our buffer */
	/* 12 * sizeof(GLfloat) is the size of the colors array, since it contains 12 GLfloat values */
	glBufferData(GL_ARRAY_BUFFER, 12 * sizeof(GLfloat), colors, GL_STATIC_DRAW);

	/* Specify that our color data is going into attribute index 1, and contains three floats per vertex */
	glVertexAttribPointer((GLuint)1, 3, GL_FLOAT, GL_FALSE, 0, 0);

	/* Enable attribute index 1 as being used */
	glEnableVertexAttribArray(1);

	/* Bind our third VBO as being the active buffer and storing vertex array indicies */
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo[2]);

	/* Copy the index data from tetraindicies to our buffer
	 * 6 * sizeof(GLubyte) is the size of the index array, since it contains 6 GLbyte values */
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(GLubyte), tetraindicies, GL_STATIC_DRAW);

	/* Assign our handles a "name" to new shader objects */
	vertexshader = glCreateShader(GL_VERTEX_SHADER);
	geometryshader = glCreateShader(GL_GEOMETRY_SHADER);
	fragmentshader = glCreateShader(GL_FRAGMENT_SHADER);

	/* Associate the source code buffers with each handle */
	glShaderSource(vertexshader, 1, (const GLchar**)&vertexsource, 0);
	glShaderSource(geometryshader, 1, (const GLchar**)&geometrysource, 0);
	glShaderSource(fragmentshader, 1, (const GLchar**)&fragmentsource, 0);

	/* Compile our shader objects */
	glCompileShader(vertexshader);
	glCompileShader(geometryshader);
	glCompileShader(fragmentshader);

	/* Assign our program handle a "name" */
	shaderprogram = glCreateProgram();

	/* Attach our shaders to our program */
	glAttachShader(shaderprogram, vertexshader);
	glAttachShader(shaderprogram, geometryshader);
	glAttachShader(shaderprogram, fragmentshader);

	/* Bind attribute 0 (coordinates) to in_Position and attribute 1 (colors) to in_Color */
	glBindAttribLocation(shaderprogram, 0, "in_Position");
	glBindAttribLocation(shaderprogram, 1, "in_Color");

	/* Link our program, and set it as being actively used */
	glLinkProgram(shaderprogram);
	glUseProgram(shaderprogram);

	/* Create our projection matrix with a 45 degree field of view
	 * a width to height ratio of 1 and view from .1 to 100 infront of us */
	perspective(projectionmatrix, 45.0, 1.0, 0.1, 100.0);

	/* Loop our display rotating our model more each time. */
	for (int i=0; i < 360; i++)
	{
		/* Load the identity matrix into modelmatrix. rotate the model, and move it back 5 */
		memcpy(modelmatrix, identitymatrix, sizeof(GLfloat) * 16);
		rotate(modelmatrix, (GLfloat)i * -1.0, X_AXIS);
		rotate(modelmatrix, (GLfloat)i * 1.0, Y_AXIS);
		rotate(modelmatrix, (GLfloat)i * 0.5, Z_AXIS);
		translate(modelmatrix, 0, 0, -5.0);

		/* multiply our modelmatrix and our projectionmatrix. Results are stored in modelmatrix */
		multiply4x4(modelmatrix, projectionmatrix);

		/* Bind our modelmatrix variable to be a uniform called mvpmatrix in our shaderprogram */
		glUniformMatrix4fv(glGetUniformLocation(shaderprogram, "mvpmatrix"), 1, GL_FALSE, modelmatrix);

		/* Make our background black */
		glClearColor(0.0, 0.0, 0.0, 1.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		/* Invoke glDrawElements telling it to draw a triangle strip using 6 indicies */
		glDrawElements(GL_TRIANGLE_STRIP, 6, GL_UNSIGNED_BYTE, 0);

		/* Swap our buffers to make our changes visible */
		swap_buffers(33);
	}

	/* Cleanup all the things we bound and allocated */
	glUseProgram(0);
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDetachShader(shaderprogram, vertexshader);
	glDetachShader(shaderprogram, geometryshader);
	glDetachShader(shaderprogram, fragmentshader);
	glDeleteProgram(shaderprogram);
	glDeleteShader(vertexshader);
	glDeleteShader(geometryshader);
	glDeleteShader(fragmentshader);
	glDeleteBuffers(3, vbo);
	glDeleteVertexArrays(1, &vao);
}

BOOST_AUTO_TEST_SUITE_END()
