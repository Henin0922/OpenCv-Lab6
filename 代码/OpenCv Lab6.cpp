#include <GL/glut.h>
#include <windows.h>
#include <math.h>
const int n = 1000;
const GLfloat R = 0.5f;


//初始化材质属性，光源属性，光照模型
void init()
{
	glClearColor(0.0, 0.0, 0.0, 1.0); //设置背景颜色

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


//构建A和a的图形
void mydisplay() {
	glClear(GL_COLOR_BUFFER_BIT);

	//构建A部分
	glBegin(GL_POLYGON);  //前1
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

	glBegin(GL_POLYGON);  //前2
	glColor3f(0.0, 1.0, 1.0);
	glVertex3f(-0.52, 0.02, 0);
	glVertex3f(-0.55, -0.1, 0);
	glVertex3f(-0.27, -0.1, 0);
	glVertex3f(-0.3, 0.02, 0);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //后1
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

	glBegin(GL_POLYGON);  //后2
	glColor3f(0.0, 1.0, 1.0);
	glVertex3f(-0.52, 0.02, -0.25);
	glVertex3f(-0.55, -0.1, -0.25);
	glVertex3f(-0.27, -0.1, -0.25);
	glVertex3f(-0.3, 0.02, -0.25);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //侧1
	glColor3f(0.0, 1.0, 1.0);
	glVertex3f(-0.465, 0.5, 0);
	glVertex3f(-0.465, 0.5, -0.25);
	glVertex3f(-0.75, -0.4, -0.25);
	glVertex3f(-0.75, -0.4, 0);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //侧2
	glColor3f(0.0, 1.0, 1.0);
	glVertex3f(-0.355, 0.5, 0);
	glVertex3f(-0.355, 0.5, -0.25);
	glVertex3f(-0.07, -0.4, -0.25);
	glVertex3f(-0.07, -0.4, 0);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //侧3
	glColor3f(0.0, 1.0, 1.0);
	glVertex3f(-0.41, 0.35, 0);
	glVertex3f(-0.41, 0.35, -0.25);
	glVertex3f(-0.62, -0.4, -0.25);
	glVertex3f(-0.62, -0.4, 0);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //侧4
	glColor3f(0.0, 1.0, 1.0);
	glVertex3f(-0.41, 0.35, 0);
	glVertex3f(-0.41, 0.35, -0.25);
	glVertex3f(-0.2, -0.4, -0.25);
	glVertex3f(-0.2, -0.4, 0);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //底1
	glColor3f(0.0, 1.0, 1.0);
	glVertex3f(-0.465, 0.5, 0);
	glVertex3f(-0.465, 0.5, -0.25);
	glVertex3f(-0.355, 0.5, -0.25);
	glVertex3f(-0.355, 0.5, 0);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //底2
	glColor3f(0.0, 1.0, 1.0);
	glVertex3f(-0.75, -0.4, 0);
	glVertex3f(-0.75, -0.4, -0.25);
	glVertex3f(-0.62, -0.4, -0.25);
	glVertex3f(-0.62, -0.4, 0);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //底3
	glColor3f(0.0, 1.0, 1.0);
	glVertex3f(-0.07, -0.4, 0);
	glVertex3f(-0.07, -0.4, -0.25);
	glVertex3f(-0.2, -0.4, -0.25);
	glVertex3f(-0.2, -0.4, 0);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //底4
	glColor3f(0.0, 1.0, 1.0);
	glVertex3f(-0.52, 0.02, 0);
	glVertex3f(-0.52, 0.02, -0.25);
	glVertex3f(-0.3, 0.02, -0.25);
	glVertex3f(-0.3, 0.02, 0);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //底5
	glColor3f(0.0, 1.0, 1.0);
	glVertex3f(-0.55, -0.1, 0);
	glVertex3f(-0.55, -0.1, -0.25);
	glVertex3f(-0.27, -0.1, -0.25);
	glVertex3f(-0.27, -0.1, 0);
	glEnd();
	glFlush();

	//构建a部分
	glBegin(GL_POLYGON);  //前1
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.5, 0.05, 0);
	glVertex3f(0.2, 0.05, 0);
	glVertex3f(0.22, -0.03, 0);
	glVertex3f(0.5, -0.03, 0);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //前2
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.2, 0.05, 0);
	glVertex3f(0.22, -0.03, 0);
	glVertex3f(0.15, -0.07, 0);
	glVertex3f(0.07, -0.04, 0);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //前3
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.15, -0.07, 0);
	glVertex3f(0.07, -0.04, 0);
	glVertex3f(0.07, -0.19, 0);
	glVertex3f(0.15, -0.16, 0);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //前4
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.07, -0.19, 0);
	glVertex3f(0.15, -0.16, 0);
	glVertex3f(0.22, -0.2, 0);
	glVertex3f(0.2, -0.28, 0);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //前5
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.5, -0.28, 0);
	glVertex3f(0.5, -0.2, 0);
	glVertex3f(0.22, -0.2, 0);
	glVertex3f(0.2, -0.28, 0);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //前6
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.15, 0.23, 0);
	glVertex3f(0.15, 0.15, 0);
	glVertex3f(0.5, 0.15, 0);
	glVertex3f(0.58, 0.23, 0);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //前7
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.5, 0.15, 0);
	glVertex3f(0.5, -0.28, 0);
	glVertex3f(0.58, -0.25, 0);
	glVertex3f(0.58, 0.23, 0);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //前8
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.5, -0.28, 0);
	glVertex3f(0.56, -0.33, 0);
	glVertex3f(0.66, -0.33, 0);
	glVertex3f(0.58, -0.25, 0);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //后1
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.5, 0.05, -0.25);
	glVertex3f(0.2, 0.05, -0.25);
	glVertex3f(0.22, -0.03, -0.25);
	glVertex3f(0.5, -0.03, -0.25);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //后2
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.2, 0.05, -0.25);
	glVertex3f(0.22, -0.03, -0.25);
	glVertex3f(0.15, -0.07, -0.25);
	glVertex3f(0.07, -0.04, -0.25);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //后3
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.15, -0.07, -0.25);
	glVertex3f(0.07, -0.04, -0.25);
	glVertex3f(0.07, -0.19, -0.25);
	glVertex3f(0.15, -0.16, -0.25);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //后4
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.07, -0.19, -0.25);
	glVertex3f(0.15, -0.16, -0.25);
	glVertex3f(0.22, -0.2, -0.25);
	glVertex3f(0.2, -0.28, -0.25);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //后5
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.5, -0.28, -0.25);
	glVertex3f(0.5, -0.2, -0.25);
	glVertex3f(0.22, -0.2, -0.25);
	glVertex3f(0.2, -0.28, -0.25);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //后6
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.15, 0.23, -0.25);
	glVertex3f(0.15, 0.15, -0.25);
	glVertex3f(0.5, 0.15, -0.25);
	glVertex3f(0.58, 0.23, -0.25);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //后7
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.5, 0.15, -0.25);
	glVertex3f(0.5, -0.28, -0.25);
	glVertex3f(0.58, -0.25, -0.25);
	glVertex3f(0.58, 0.23, -0.25);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //后8
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.5, -0.28, -0.25);
	glVertex3f(0.56, -0.33, -0.25);
	glVertex3f(0.66, -0.33, -0.25);
	glVertex3f(0.58, -0.25, -0.25);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //侧1
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.15, 0.23, -0.25);
	glVertex3f(0.15, 0.15, -0.25);
	glVertex3f(0.15, 0.15, 0);
	glVertex3f(0.15, 0.23, 0);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //侧2
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.15, 0.15, -0.25);
	glVertex3f(0.15, 0.15, 0);
	glVertex3f(0.5, 0.15, 0);
	glVertex3f(0.5, 0.15, -0.25);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //侧3
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.5, 0.15, -0.25);
	glVertex3f(0.5, 0.15, 0);
	glVertex3f(0.5, -0.28, 0);
	glVertex3f(0.5, -0.28, -0.25);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //侧4
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.56, -0.33, -0.25);
	glVertex3f(0.56, -0.33, 0);
	glVertex3f(0.5, -0.28, 0);
	glVertex3f(0.5, -0.28, -0.25);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //侧5
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.56, -0.33, -0.25);
	glVertex3f(0.56, -0.33, 0);
	glVertex3f(0.66, -0.33, 0);
	glVertex3f(0.66, -0.33, -0.25);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //侧6
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.58, -0.25, -0.25);
	glVertex3f(0.58, -0.25, 0);
	glVertex3f(0.66, -0.33, 0);
	glVertex3f(0.66, -0.33, -0.25);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //侧7
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.58, -0.25, -0.25);
	glVertex3f(0.58, -0.25, 0);
	glVertex3f(0.58, 0.23, 0);
	glVertex3f(0.58, 0.23, -0.25);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //侧8
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.15, 0.23, -0.25);
	glVertex3f(0.15, 0.23, 0);
	glVertex3f(0.58, 0.23, 0);
	glVertex3f(0.58, 0.23, -0.25);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //侧9
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.5, 0.05, -0.25);
	glVertex3f(0.5, 0.05, 0);
	glVertex3f(0.2, 0.05, 0);
	glVertex3f(0.2, 0.05, -0.25);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //侧10
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.07, -0.04, -0.25);
	glVertex3f(0.07, -0.04, 0);
	glVertex3f(0.2, 0.05, 0);
	glVertex3f(0.2, 0.05, -0.25);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //侧11
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.07, -0.04, -0.25);
	glVertex3f(0.07, -0.04, 0);
	glVertex3f(0.07, -0.19, 0);
	glVertex3f(0.07, -0.19, -0.25);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //侧12
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.2, -0.28, -0.25);
	glVertex3f(0.2, -0.28, 0);
	glVertex3f(0.07, -0.19, 0);
	glVertex3f(0.07, -0.19, -0.25);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //侧13
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.2, -0.28, -0.25);
	glVertex3f(0.2, -0.28, 0);
	glVertex3f(0.5, -0.28, 0);
	glVertex3f(0.5, -0.28, -0.25);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //侧14
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.22, -0.2, -0.25);
	glVertex3f(0.22, -0.2, 0);
	glVertex3f(0.5, -0.2, 0);
	glVertex3f(0.5, -0.2, -0.25);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //侧15
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.22, -0.2, -0.25);
	glVertex3f(0.22, -0.2, 0);
	glVertex3f(0.15, -0.16, 0);
	glVertex3f(0.15, -0.16, -0.25);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //侧16
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.15, -0.07, -0.25);
	glVertex3f(0.15, -0.07, 0);
	glVertex3f(0.15, -0.16, 0);
	glVertex3f(0.15, -0.16, -0.25);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //侧17
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.15, -0.07, -0.25);
	glVertex3f(0.15, -0.07, 0);
	glVertex3f(0.22, -0.03, 0);
	glVertex3f(0.22, -0.03, -0.25);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);  //侧18
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.5, -0.03, -0.25);
	glVertex3f(0.5, -0.03, 0);
	glVertex3f(0.22, -0.03, 0);
	glVertex3f(0.22, -0.03, -0.25);
	glEnd();
	glFlush();

}


void keyboard(unsigned char key, int x, int y)  //键盘响应：q、w、t、y、o、p键控制图形的旋转；m、n键控制光照开关；1、2键控制图像的缩放；0键表示退出
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
		glEnable(GL_LIGHTING);  //开启光照
		glutPostRedisplay();
		break;
	case 'n':
		glDisable(GL_LIGHTING);  //关闭光照
		glutPostRedisplay();
		break;
	case '1':  //放大图形
		glScalef(1.1, 1.1, 1.1);  //放大倍数
		glutPostRedisplay();
		break;
	case '2':  //缩小图形
		glScalef(0.9, 0.9, 0.9);  //缩小倍数
		glutPostRedisplay();
		break;
	case '0':  //退出
		exit(0);
		break;
	}
}

void Special(int key, int x, int y)  //键盘响应：方向键控制图形的平行移动
{
	switch (key)
	{

	case GLUT_KEY_LEFT:  //向左平移
		glTranslatef(-0.1f, 0.0f, 0.0f);
		glutPostRedisplay();
		break;
	case GLUT_KEY_RIGHT:  //向右平移
		glTranslatef(0.1f, 0.0f, 0.0f);
		glutPostRedisplay();
		break;
	case GLUT_KEY_UP:  //向上平移
		glTranslatef(0.0f, 0.1f, 0.0f);
		glutPostRedisplay();
		break;
	case GLUT_KEY_DOWN:  //向下平移
		glTranslatef(0.0f, -0.1f, 0.0f);
		glutPostRedisplay();
		break;
	}
}


//使图形的整体形状和比例 不会因为窗口比例的改变而影响，并且使图像总是出现在窗口的中心
void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)//如果窗口的宽度小于高度
		glOrtho(-2.5, 2.5, -2.5 * (GLfloat)h / (GLfloat)w, 2.5 * (GLfloat)h / (GLfloat)w, -10.0, 10.0);
	else//如果窗口的高度小于宽度
		glOrtho(-2.5 * (GLfloat)w / (GLfloat)h, 2.5 * (GLfloat)w / (GLfloat)h, -2.5, 2.5, -10.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 800);  //运行程序，窗口大小为800*800 
	glutInitWindowPosition(0, 0);
	glutCreateWindow("操作说明：q w t y o p键控制旋转,m n键控制光照开关，1 2键控制缩放，方向键控制平行移动，0 键为退出!");
	glutDisplayFunc(mydisplay);
	init();
	glutKeyboardFunc(keyboard);
	glutReshapeFunc(reshape);
	glutSpecialFunc(Special);
	glutMainLoop();
	return 0;
}




