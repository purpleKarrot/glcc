#ifndef _UTILS_H_
#define _UTILS_H_

#define EMPTY_MATRIX4  { 0.0, 0.0, 0.0, 0.0,\
                         0.0, 0.0, 0.0, 0.0,\
                         0.0, 0.0, 0.0, 0.0,\
                         0.0, 0.0, 0.0, 0.0 }

#define IDENTITY_MATRIX4 { 1.0, 0.0, 0.0, 0.0,\
                           0.0, 1.0, 0.0, 0.0,\
                           0.0, 0.0, 1.0, 0.0,\
                           0.0, 0.0, 0.0, 1.0 }

enum AXIS
{
	X_AXIS, Y_AXIS, Z_AXIS
};

/* Multiply 4x4 matrix m1 by 4x4 matrix m2 and store the result in m1 */
void multiply4x4(GLfloat *m1, GLfloat *m2);

/* Generate a perspective view matrix using a field of view angle fov,
 * window aspect ratio, near and far clipping planes */
void perspective(GLfloat *matrix, GLfloat fov, GLfloat aspect, GLfloat nearz,
		GLfloat farz);

/* Perform translation operations on a matrix */
void translate(GLfloat *matrix, GLfloat x, GLfloat y, GLfloat z);

/* Rotate a matrix by an angle on a X, Y, or Z axis specified by the AXIS enum*/
void rotate(GLfloat *matrix, GLfloat angle, AXIS axis);

#endif /* _UTILS_H_ */
