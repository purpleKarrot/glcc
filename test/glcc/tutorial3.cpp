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

		uniform mat4 mvpmatrix;

		out vec3 ex_Color;

		void main(void)
		{
			gl_Position = mvpmatrix * vec4(in_Position, 1.0);
			ex_Color = in_Color;
		}
);

SHADER_SOURCE(fragmentsource,

		precision highp float;

		in vec3 ex_Color;
		out vec4 gl_FragColor;

		void main(void)
		{
			gl_FragColor = vec4(ex_Color,1.0);
		}
);

BOOST_FIXTURE_TEST_SUITE(tutorial3, GL3Context)

BOOST_AUTO_TEST_CASE(drawscene)
{
	int i; /* Simple iterator */
	GLuint vao, vbo[2]; /* Create handles for our Vertex Array Object and two Vertex Buffer Objects */
	GLfloat projectionmatrix[16]; /* Our projection matrix starts with all 0s */
	GLfloat modelmatrix[16]; /* Our model matrix  */
	/* An identity matrix we use to perform the equivalant of glLoadIdentity */
	const GLfloat identitymatrix[16] = IDENTITY_MATRIX4;

	/* Verticies to make 4 triangles in the shape of a tetrahedron */
	const GLfloat tetrahedron[12][3] =
	{
		{	1.0, 1.0, 1.0},
		{	-1.0, -1.0, 1.0},
		{	-1.0, 1.0, -1.0},
		{	1.0, 1.0, 1.0},
		{	-1.0, -1.0, 1.0},
		{	1.0, -1.0, -1.0},
		{	1.0, 1.0, 1.0},
		{	-1.0, 1.0, -1.0},
		{	1.0, -1.0, -1.0},
		{	-1.0, -1.0, 1.0},
		{	-1.0, 1.0, -1.0},
		{	1.0, -1.0, -1.0}
	};

	/* Color information for each triangle */
	const GLfloat colors[12][3] =
	{
		{	1.0, 0.0, 0.0},
		{	1.0, 0.0, 0.0},
		{	1.0, 0.0, 0.0},
		{	0.0, 1.0, 0.0},
		{	0.0, 1.0, 0.0},
		{	0.0, 1.0, 0.0},
		{	0.0, 0.0, 1.0},
		{	0.0, 0.0, 1.0},
		{	0.0, 0.0, 1.0},
		{	1.0, 1.0, 1.0},
		{	1.0, 1.0, 1.0},
		{	1.0, 1.0, 1.0}
	};

	/* These are handles used to reference the shaders */
	GLuint vertexshader, fragmentshader;

	/* This is a handle to the shader program */
	GLuint shaderprogram;

	/* Allocate and assign a Vertex Array Object to our handle */
	glGenVertexArrays(1, &vao);

	/* Bind our Vertex Array Object as the current used object */
	glBindVertexArray(vao);

	/* Allocate and assign two Vertex Buffer Objects to our handle */
	glGenBuffers(2, vbo);

	/* Bind our first VBO as being the active buffer and storing vertex attributes (coordinates) */
	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);

	/* Copy the vertex data from tetrahedron to our buffer */
	/* 36 * sizeof(GLfloat) is the size of the tetrahedrom array, since it contains 36 GLfloat values */
	glBufferData(GL_ARRAY_BUFFER, 36 * sizeof(GLfloat), tetrahedron, GL_STATIC_DRAW);

	/* Specify that our coordinate data is going into attribute index 0, and contains three floats per vertex */
	glVertexAttribPointer((GLuint)0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	/* Enable attribute index 0 as being used */
	glEnableVertexAttribArray(0);

	/* Bind our second VBO as being the active buffer and storing vertex attributes (colors) */
	glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);

	/* Copy the color data from colors to our buffer */
	/* 36 * sizeof(GLfloat) is the size of the colors array, since it contains 36 GLfloat values */
	glBufferData(GL_ARRAY_BUFFER, 36 * sizeof(GLfloat), colors, GL_STATIC_DRAW);

	/* Specify that our color data is going into attribute index 1, and contains three floats per vertex */
	glVertexAttribPointer((GLuint)1, 3, GL_FLOAT, GL_FALSE, 0, 0);

	/* Enable attribute index 1 as being used */
	glEnableVertexAttribArray(1);

	/* Assign our handles a "name" to new shader objects */
	vertexshader = glCreateShader(GL_VERTEX_SHADER);
	fragmentshader = glCreateShader(GL_FRAGMENT_SHADER);

	/* Associate the source code buffers with each handle */
	glShaderSource(vertexshader, 1, (const GLchar**)&vertexsource, 0);
	glShaderSource(fragmentshader, 1, (const GLchar**)&fragmentsource, 0);

	/* Compile our shader objects */
	glCompileShader(vertexshader);
	glCompileShader(fragmentshader);

	/* Assign our program handle a "name" */
	shaderprogram = glCreateProgram();

	/* Attach our shaders to our program */
	glAttachShader(shaderprogram, vertexshader);
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
	for (i=0; i < 360; i++)
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

		/* Invoke glDrawArrays telling that our data consists of individual triangles */
		glDrawArrays(GL_TRIANGLES, 0, 12);

		/* Swap our buffers to make our changes visible */
		swap_buffers(33);
	}

	/* Cleanup all the things we bound and allocated */
	glUseProgram(0);
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDetachShader(shaderprogram, vertexshader);
	glDetachShader(shaderprogram, fragmentshader);
	glDeleteProgram(shaderprogram);
	glDeleteShader(vertexshader);
	glDeleteShader(fragmentshader);
	glDeleteBuffers(2, vbo);
	glDeleteVertexArrays(1, &vao);
}

BOOST_AUTO_TEST_SUITE_END()
