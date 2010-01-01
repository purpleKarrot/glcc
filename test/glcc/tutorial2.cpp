#include <boost/test/unit_test.hpp>
#include "../GL3Context.hpp"

#include <glcc/program.hpp>

#define SHADER_SOURCE(NAME, SOURCE)                                            \
	static const char* const NAME = "#version 150\n" #SOURCE                   \

SHADER_SOURCE(vertexsource,

		in vec2 in_Position;
		in vec3 in_Color;
		out vec3 ex_Color;

		void main(void)
		{
			gl_Position = vec4(in_Position.x, in_Position.y, 0.0, 1.0);
			ex_Color = in_Color;
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

BOOST_FIXTURE_TEST_SUITE(tutorial2, GL3Context)

BOOST_AUTO_TEST_CASE(drawscene)
{
	int i; /* Simple iterator */
	GLuint vao, vbo[2]; /* Create handles for our Vertex Array Object and two Vertex Buffer Objects */

	/* We're going to create a simple diamond made from lines */
	const GLfloat diamond[4][2] =
	{
		{	0.0, 1.0}, /* Top point */
		{	1.0, 0.0}, /* Right point */
		{	0.0, -1.0}, /* Bottom point */
		{	-1.0, 0.0} /* Left point */
	};

	const GLfloat colors[4][3] =
	{
		{	1.0, 0.0, 0.0}, /* Red */
		{	0.0, 1.0, 0.0}, /* Green */
		{	0.0, 0.0, 1.0}, /* Blue */
		{	1.0, 1.0, 1.0} /* White */
	};

	/* This is a handle to the shader program */
	gl::program shaderprogram;

	/* Allocate and assign a Vertex Array Object to our handle */
	glGenVertexArrays(1, &vao);

	/* Bind our Vertex Array Object as the current used object */
	glBindVertexArray(vao);

	/* Allocate and assign two Vertex Buffer Objects to our handle */
	glGenBuffers(2, vbo);

	/* Bind our first VBO as being the active buffer and storing vertex attributes (coordinates) */
	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);

	/* Copy the vertex data from diamond to our buffer */
	/* 8 * sizeof(GLfloat) is the size of the diamond array, since it contains 8 GLfloat values */
	glBufferData(GL_ARRAY_BUFFER, 8 * sizeof(GLfloat), diamond, GL_STATIC_DRAW);

	/* Specify that our coordinate data is going into attribute index 0, and contains two floats per vertex */
	glVertexAttribPointer((GLuint) 0, 2, GL_FLOAT, GL_FALSE, 0, 0);

	/* Enable attribute index 0 as being used */
	glEnableVertexAttribArray(0);

	/* Bind our second VBO as being the active buffer and storing vertex attributes (colors) */
	glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);

	/* Copy the color data from colors to our buffer */
	/* 12 * sizeof(GLfloat) is the size of the colors array, since it contains 12 GLfloat values */
	glBufferData(GL_ARRAY_BUFFER, 12 * sizeof(GLfloat), colors, GL_STATIC_DRAW);

	/* Specify that our color data is going into attribute index 1, and contains three floats per vertex */
	glVertexAttribPointer((GLuint) 1, 3, GL_FLOAT, GL_FALSE, 0, 0);

	/* Enable attribute index 1 as being used */
	glEnableVertexAttribArray(1);

	/* Attach our shaders to our program */
	shaderprogram.attach(gl::shader::vertex, vertexsource);
	shaderprogram.attach(gl::shader::fragment, fragmentsource);

	/* Bind attribute index 0 (coordinates) to in_Position and attribute index 1 (color) to in_Color */
	glBindAttribLocation(shaderprogram.name, 0, "in_Position");
	glBindAttribLocation(shaderprogram.name, 1, "in_Color");

	/* Link our program, and set it as being actively used */
	shaderprogram.link();
	shaderprogram.use();

	/* Loop our display increasing the number of shown vertexes each time.
	 * Start with 2 vertexes (a line) and increase to 3 (a triangle) and 4 (a diamond) */
	for (i = 2; i <= 4; i++)
	{
		/* Make our background black */
		glClearColor(0.0, 0.0, 0.0, 1.0);
		glClear(GL_COLOR_BUFFER_BIT);

		/* Invoke glDrawArrays telling that our data is a line loop and we want to draw 2-4 vertexes */
		glDrawArrays(GL_LINE_LOOP, 0, i);

		/* Swap our buffers to make our changes visible */
		swap_buffers(2000);
	}

	/* Cleanup all the things we bound and allocated */
	glUseProgram(0);
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDeleteBuffers(2, vbo);
	glDeleteVertexArrays(1, &vao);
}

BOOST_AUTO_TEST_SUITE_END()
