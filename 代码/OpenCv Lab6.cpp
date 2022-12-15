#include <GL/glut.h>
#include <windows.h>
#include <math.h>
const int n = 1000;
const GLfloat R = 0.5f;


//��ʼ���������ԣ���Դ���ԣ�����ģ��
void init()
{
	glClearColor(0.0, 0.0, 0.0, 1.0); //���ñ�����ɫ

	glColor3f(1.0, 0.0, 1.0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

	//Material Properties
	GLfloat matSpecular[] = { 1.0f, 0.0f, 0.0f, 1.0f };
	GLfloat matShininess[] = { 50.0f };
	GLfloat matAmbient[] = { 0.25f, 0.25f, 0.25f, 1.0f };
	GLfloat matDiffuse[] = { 0.5f, 0.5f, 0.5f, 1.0f };

	glMaterialfv(GL_FRONT, GL_SPECULAR, matSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, matShininess);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, matDiffuse);
	glMaterialfv(GL_FRONT, GL_AMBIENT, matAmbient);

	//Lighting Parameters

	//Enable Lighting
	glEnable(GL_LIGHTING);

	//Specify a single directional light
	GLfloat ambient1[] = { 0.5f,0.5f,0.5f };
	GLfloat diffuse1[] = { 0.5f,0.5f,0.5f };
	GLfloat specular1[] = { 1.0f,0.0f,0.0f };
	GLfloat position1[] = { 0.0f,0.0f,5.0f,0.0 };

	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient1);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse1);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular1);
	glLightfv(GL_LIGHT0, GL_POSITION, position1);

	glEnable(GL_LIGHT0);

	//Specify a single positional spotlight
	GLfloat ambient2[] = { 1.0f,1.0f,0.0f };
	GLfloat diffuse2[] = { 1.0f,0.0f,0.0f };
	GLfloat position2[] = { 1.0f,0.0f,5.0f,1.0 };
	GLfloat direction2[] = { 0.0f,0.0f,-5.0f };

	glLightfv(GL_LIGHT1, GL_AMBIENT, ambient2);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse2);
	glLightfv(GL_LIGHT1, GL_POSITION, position2);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, direction2);
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 15.0f);

	glEnable(GL_LIGHT1);

}


//����A��a��ͼ��
void mydisplay() {
	glClear(GL_COLOR_BUFFER_BIT);

	//����A����
	glBegin(GL_POLYGON);  //ǰ1
	glColor3f(0.0, 1.0, 1.0);
	glVertex3f(-0.355, 0.5, 0);
	glVertex3f(-0.465, 0.5, 0);
	glVertex3f(-0.75, -0.4, 0);
	glVertex3f(-0.62, -0.4, 0);
	glVertex3f(-0.41, 0.35, 0);
	glVertex3f(-0.2, -0.4, 0);
	glVertex3f(-0.07, -0.4, 0);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //ǰ2
	glColor3f(0.0, 1.0, 1.0);
	glVertex3f(-0.52, 0.02, 0);
	glVertex3f(-0.55, -0.1, 0);
	glVertex3f(-0.27, -0.1, 0);
	glVertex3f(-0.3, 0.02, 0);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //��1
	glColor3f(0.0, 1.0, 1.0);
	glVertex3f(-0.355, 0.5, -0.25);
	glVertex3f(-0.465, 0.5, -0.25);
	glVertex3f(-0.75, -0.4, -0.25);
	glVertex3f(-0.62, -0.4, -0.25);
	glVertex3f(-0.41, 0.35, -0.25);
	glVertex3f(-0.2, -0.4, -0.25);
	glVertex3f(-0.07, -0.4, -0.25);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //��2
	glColor3f(0.0, 1.0, 1.0);
	glVertex3f(-0.52, 0.02, -0.25);
	glVertex3f(-0.55, -0.1, -0.25);
	glVertex3f(-0.27, -0.1, -0.25);
	glVertex3f(-0.3, 0.02, -0.25);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //��1
	glColor3f(0.0, 1.0, 1.0);
	glVertex3f(-0.465, 0.5, 0);
	glVertex3f(-0.465, 0.5, -0.25);
	glVertex3f(-0.75, -0.4, -0.25);
	glVertex3f(-0.75, -0.4, 0);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //��2
	glColor3f(0.0, 1.0, 1.0);
	glVertex3f(-0.355, 0.5, 0);
	glVertex3f(-0.355, 0.5, -0.25);
	glVertex3f(-0.07, -0.4, -0.25);
	glVertex3f(-0.07, -0.4, 0);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //��3
	glColor3f(0.0, 1.0, 1.0);
	glVertex3f(-0.41, 0.35, 0);
	glVertex3f(-0.41, 0.35, -0.25);
	glVertex3f(-0.62, -0.4, -0.25);
	glVertex3f(-0.62, -0.4, 0);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //��4
	glColor3f(0.0, 1.0, 1.0);
	glVertex3f(-0.41, 0.35, 0);
	glVertex3f(-0.41, 0.35, -0.25);
	glVertex3f(-0.2, -0.4, -0.25);
	glVertex3f(-0.2, -0.4, 0);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //��1
	glColor3f(0.0, 1.0, 1.0);
	glVertex3f(-0.465, 0.5, 0);
	glVertex3f(-0.465, 0.5, -0.25);
	glVertex3f(-0.355, 0.5, -0.25);
	glVertex3f(-0.355, 0.5, 0);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //��2
	glColor3f(0.0, 1.0, 1.0);
	glVertex3f(-0.75, -0.4, 0);
	glVertex3f(-0.75, -0.4, -0.25);
	glVertex3f(-0.62, -0.4, -0.25);
	glVertex3f(-0.62, -0.4, 0);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //��3
	glColor3f(0.0, 1.0, 1.0);
	glVertex3f(-0.07, -0.4, 0);
	glVertex3f(-0.07, -0.4, -0.25);
	glVertex3f(-0.2, -0.4, -0.25);
	glVertex3f(-0.2, -0.4, 0);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //��4
	glColor3f(0.0, 1.0, 1.0);
	glVertex3f(-0.52, 0.02, 0);
	glVertex3f(-0.52, 0.02, -0.25);
	glVertex3f(-0.3, 0.02, -0.25);
	glVertex3f(-0.3, 0.02, 0);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //��5
	glColor3f(0.0, 1.0, 1.0);
	glVertex3f(-0.55, -0.1, 0);
	glVertex3f(-0.55, -0.1, -0.25);
	glVertex3f(-0.27, -0.1, -0.25);
	glVertex3f(-0.27, -0.1, 0);
	glEnd();
	glFlush();

	//����a����
	glBegin(GL_POLYGON);  //ǰ1
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.5, 0.05, 0);
	glVertex3f(0.2, 0.05, 0);
	glVertex3f(0.22, -0.03, 0);
	glVertex3f(0.5, -0.03, 0);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //ǰ2
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.2, 0.05, 0);
	glVertex3f(0.22, -0.03, 0);
	glVertex3f(0.15, -0.07, 0);
	glVertex3f(0.07, -0.04, 0);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //ǰ3
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.15, -0.07, 0);
	glVertex3f(0.07, -0.04, 0);
	glVertex3f(0.07, -0.19, 0);
	glVertex3f(0.15, -0.16, 0);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //ǰ4
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.07, -0.19, 0);
	glVertex3f(0.15, -0.16, 0);
	glVertex3f(0.22, -0.2, 0);
	glVertex3f(0.2, -0.28, 0);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //ǰ5
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.5, -0.28, 0);
	glVertex3f(0.5, -0.2, 0);
	glVertex3f(0.22, -0.2, 0);
	glVertex3f(0.2, -0.28, 0);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //ǰ6
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.15, 0.23, 0);
	glVertex3f(0.15, 0.15, 0);
	glVertex3f(0.5, 0.15, 0);
	glVertex3f(0.58, 0.23, 0);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //ǰ7
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.5, 0.15, 0);
	glVertex3f(0.5, -0.28, 0);
	glVertex3f(0.58, -0.25, 0);
	glVertex3f(0.58, 0.23, 0);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //ǰ8
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.5, -0.28, 0);
	glVertex3f(0.56, -0.33, 0);
	glVertex3f(0.66, -0.33, 0);
	glVertex3f(0.58, -0.25, 0);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //��1
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.5, 0.05, -0.25);
	glVertex3f(0.2, 0.05, -0.25);
	glVertex3f(0.22, -0.03, -0.25);
	glVertex3f(0.5, -0.03, -0.25);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //��2
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.2, 0.05, -0.25);
	glVertex3f(0.22, -0.03, -0.25);
	glVertex3f(0.15, -0.07, -0.25);
	glVertex3f(0.07, -0.04, -0.25);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //��3
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.15, -0.07, -0.25);
	glVertex3f(0.07, -0.04, -0.25);
	glVertex3f(0.07, -0.19, -0.25);
	glVertex3f(0.15, -0.16, -0.25);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //��4
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.07, -0.19, -0.25);
	glVertex3f(0.15, -0.16, -0.25);
	glVertex3f(0.22, -0.2, -0.25);
	glVertex3f(0.2, -0.28, -0.25);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //��5
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.5, -0.28, -0.25);
	glVertex3f(0.5, -0.2, -0.25);
	glVertex3f(0.22, -0.2, -0.25);
	glVertex3f(0.2, -0.28, -0.25);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //��6
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.15, 0.23, -0.25);
	glVertex3f(0.15, 0.15, -0.25);
	glVertex3f(0.5, 0.15, -0.25);
	glVertex3f(0.58, 0.23, -0.25);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //��7
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.5, 0.15, -0.25);
	glVertex3f(0.5, -0.28, -0.25);
	glVertex3f(0.58, -0.25, -0.25);
	glVertex3f(0.58, 0.23, -0.25);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //��8
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.5, -0.28, -0.25);
	glVertex3f(0.56, -0.33, -0.25);
	glVertex3f(0.66, -0.33, -0.25);
	glVertex3f(0.58, -0.25, -0.25);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //��1
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.15, 0.23, -0.25);
	glVertex3f(0.15, 0.15, -0.25);
	glVertex3f(0.15, 0.15, 0);
	glVertex3f(0.15, 0.23, 0);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //��2
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.15, 0.15, -0.25);
	glVertex3f(0.15, 0.15, 0);
	glVertex3f(0.5, 0.15, 0);
	glVertex3f(0.5, 0.15, -0.25);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //��3
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.5, 0.15, -0.25);
	glVertex3f(0.5, 0.15, 0);
	glVertex3f(0.5, -0.28, 0);
	glVertex3f(0.5, -0.28, -0.25);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //��4
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.56, -0.33, -0.25);
	glVertex3f(0.56, -0.33, 0);
	glVertex3f(0.5, -0.28, 0);
	glVertex3f(0.5, -0.28, -0.25);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //��5
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.56, -0.33, -0.25);
	glVertex3f(0.56, -0.33, 0);
	glVertex3f(0.66, -0.33, 0);
	glVertex3f(0.66, -0.33, -0.25);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //��6
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.58, -0.25, -0.25);
	glVertex3f(0.58, -0.25, 0);
	glVertex3f(0.66, -0.33, 0);
	glVertex3f(0.66, -0.33, -0.25);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //��7
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.58, -0.25, -0.25);
	glVertex3f(0.58, -0.25, 0);
	glVertex3f(0.58, 0.23, 0);
	glVertex3f(0.58, 0.23, -0.25);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //��8
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.15, 0.23, -0.25);
	glVertex3f(0.15, 0.23, 0);
	glVertex3f(0.58, 0.23, 0);
	glVertex3f(0.58, 0.23, -0.25);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //��9
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.5, 0.05, -0.25);
	glVertex3f(0.5, 0.05, 0);
	glVertex3f(0.2, 0.05, 0);
	glVertex3f(0.2, 0.05, -0.25);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //��10
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.07, -0.04, -0.25);
	glVertex3f(0.07, -0.04, 0);
	glVertex3f(0.2, 0.05, 0);
	glVertex3f(0.2, 0.05, -0.25);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //��11
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.07, -0.04, -0.25);
	glVertex3f(0.07, -0.04, 0);
	glVertex3f(0.07, -0.19, 0);
	glVertex3f(0.07, -0.19, -0.25);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //��12
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.2, -0.28, -0.25);
	glVertex3f(0.2, -0.28, 0);
	glVertex3f(0.07, -0.19, 0);
	glVertex3f(0.07, -0.19, -0.25);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //��13
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.2, -0.28, -0.25);
	glVertex3f(0.2, -0.28, 0);
	glVertex3f(0.5, -0.28, 0);
	glVertex3f(0.5, -0.28, -0.25);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //��14
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.22, -0.2, -0.25);
	glVertex3f(0.22, -0.2, 0);
	glVertex3f(0.5, -0.2, 0);
	glVertex3f(0.5, -0.2, -0.25);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //��15
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.22, -0.2, -0.25);
	glVertex3f(0.22, -0.2, 0);
	glVertex3f(0.15, -0.16, 0);
	glVertex3f(0.15, -0.16, -0.25);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //��16
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.15, -0.07, -0.25);
	glVertex3f(0.15, -0.07, 0);
	glVertex3f(0.15, -0.16, 0);
	glVertex3f(0.15, -0.16, -0.25);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //��17
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.15, -0.07, -0.25);
	glVertex3f(0.15, -0.07, 0);
	glVertex3f(0.22, -0.03, 0);
	glVertex3f(0.22, -0.03, -0.25);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //��18
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.5, -0.03, -0.25);
	glVertex3f(0.5, -0.03, 0);
	glVertex3f(0.22, -0.03, 0);
	glVertex3f(0.22, -0.03, -0.25);
	glEnd();
	glFlush();

}


void keyboard(unsigned char key, int x, int y)  //������Ӧ��q��w��t��y��o��p������ͼ�ε���ת��m��n�����ƹ��տ��أ�1��2������ͼ������ţ�0����ʾ�˳�
{
	switch (key) {
	case 'q':
		glRotatef(3.0f, 0.1, 0, 0);
		glutPostRedisplay();
		break;
	case 'w':
		glRotatef(-3.0f, 0.1, 0, 0);
		glutPostRedisplay();
		break;
	case 't':
		glRotatef(3.0f, 0, -0.05, 0);
		glutPostRedisplay();
		break;
	case 'y':
		glRotatef(3.0f, 0, 0.05, 0);
		glutPostRedisplay();
		break;
	case 'o':
		glRotatef(-3.0f, 0, 0, 0.05);
		glutPostRedisplay();
		break;
	case 'p':
		glRotatef(3.0f, 0, 0, 0.05);
		glutPostRedisplay();
		break;
	case 'm':
		glEnable(GL_LIGHTING);  //��������
		glutPostRedisplay();
		break;
	case 'n':
		glDisable(GL_LIGHTING);  //�رչ���
		glutPostRedisplay();
		break;
	case '1':  //�Ŵ�ͼ��
		glScalef(1.1, 1.1, 1.1);  //�Ŵ���
		glutPostRedisplay();
		break;
	case '2':  //��Сͼ��
		glScalef(0.9, 0.9, 0.9);  //��С����
		glutPostRedisplay();
		break;
	case '0':  //�˳�
		exit(0);
		break;
	}
}

void Special(int key, int x, int y)  //������Ӧ�����������ͼ�ε�ƽ���ƶ�
{
	switch (key)
	{

	case GLUT_KEY_LEFT:  //����ƽ��
		glTranslatef(-0.1f, 0.0f, 0.0f);
		glutPostRedisplay();
		break;
	case GLUT_KEY_RIGHT:  //����ƽ��
		glTranslatef(0.1f, 0.0f, 0.0f);
		glutPostRedisplay();
		break;
	case GLUT_KEY_UP:  //����ƽ��
		glTranslatef(0.0f, 0.1f, 0.0f);
		glutPostRedisplay();
		break;
	case GLUT_KEY_DOWN:  //����ƽ��
		glTranslatef(0.0f, -0.1f, 0.0f);
		glutPostRedisplay();
		break;
	}
}


//ʹͼ�ε�������״�ͱ��� ������Ϊ���ڱ����ĸı��Ӱ�죬����ʹͼ�����ǳ����ڴ��ڵ�����
void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)//������ڵĿ��С�ڸ߶�
		glOrtho(-2.5, 2.5, -2.5 * (GLfloat)h / (GLfloat)w, 2.5 * (GLfloat)h / (GLfloat)w, -10.0, 10.0);
	else//������ڵĸ߶�С�ڿ��
		glOrtho(-2.5 * (GLfloat)w / (GLfloat)h, 2.5 * (GLfloat)w / (GLfloat)h, -2.5, 2.5, -10.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 800);  //���г��򣬴��ڴ�СΪ800*800 
	glutInitWindowPosition(0, 0);
	glutCreateWindow("����˵����q w t y o p��������ת,m n�����ƹ��տ��أ�1 2���������ţ����������ƽ���ƶ���0 ��Ϊ�˳�!");
	glutDisplayFunc(mydisplay);
	init();
	glutKeyboardFunc(keyboard);
	glutReshapeFunc(reshape);
	glutSpecialFunc(Special);
	glutMainLoop();
	return 0;
}




