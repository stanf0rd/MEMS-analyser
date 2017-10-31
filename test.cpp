#include "stdafx.h"
#include <stdlib.h>
#include <GL/glut.h>

bool Cone=false , ConeSelected=false,
Cube=false, CubeSelected=false,
Sphere=false, SphereSelected=false,
Teapot=false, TeapotSelected =false,
Torus=false, TorusSelected=false;
static float XSphere=0, YSphere=-1.5 ,ZSphere=0;

void init(void) 
{
    GLfloat blankMaterial[] = {1.0, 0.0, 0.0};
    GLfloat whiteDiffuseLight[] = {30}; 
    glClearColor (0.0, 0.1, 0.2, 0.0);
    glClearDepth(1.0);
    glShadeModel (GL_FLAT);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, blankMaterial);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, blankMaterial);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS,  whiteDiffuseLight);
}


    void display(void)
    {
      glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
      glEnable(GL_DEPTH_TEST);

      //Drawing Cube
       if(Cube)
        {
        glPushMatrix();
        glColor3f(0, 1, 0);
        glTranslatef(-3,0,-3);
        glRotatef(20, 1,0,0);
        glutSolidCube(2);
        glPopMatrix() ;
        }

      //drawing cone
       if(Cone)
      {
        glPushMatrix();
        glColor3f (1.0, 0.0, 1.0);
        glTranslatef(0,2,0);
        glRotatef(50, 1,0,0);
        glutSolidCone(.5,1,10,10);
        glPopMatrix() ;
       }

      //Drawing Solid Sphere
      if(Sphere)
      { 
       glPushMatrix();
       glTranslatef(XSphere,YSphere,ZSphere);
       glutSolidSphere(.5, 20, 20);
       glPopMatrix();
       glDisable(GL_DEPTH_TEST);
   }
   glColor3f (1.0f, 1.0f, 1.0f);

   //drawing Torus
   if(Torus)
   {
        glPushMatrix();
        glColor3f (1.0, 1.0, 1.0);
        glTranslatef(2,2,0);
        glRotatef(60, 1,0,0);
        glutSolidTorus(.2,.5,40,30);
        glPopMatrix() ;
   }

   //Drawing teapot
   if(Teapot)
   {
       glPushMatrix ();
       glTranslatef (2.0, 0.0, 0.0);
       glutSolidTeapot(.5);
       glPopMatrix ();
   }


glFlush();
glutSwapBuffers();



}

void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   gluLookAt (0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void keyboard (unsigned char key, int x, int y)
{int modifiers = glutGetModifiers();

   switch (key) {
       case 'A':
               Teapot=Cone=Sphere=Cube=Torus=true;
               glutPostRedisplay();
               break;
        case 'D':
               Teapot=Cone=Sphere=Cube=Torus=false;
               glutPostRedisplay();
               break;
        case 'S':
                Teapot=Cone=Cube=Torus=false;
                Sphere=true;
                TeapotSelected=ConeSelected=CubeSelected=TorusSelected=false;
                SphereSelected=true;

               break;       
      case 27:
         exit(0);
         break;
      default:
         break;
   }
}


void MyMouse(int button, int state, int x, int y)
{

switch (button)
{
    case GLUT_LEFT_BUTTON:

        if(state == GLUT_UP)
        {
            if (SphereSelected)
            {
                Cone=Cube=Torus=Teapot=false;
                Sphere=true;
                XSphere=x;
                YSphere=y;
                ZSphere=1;
                glutPostRedisplay();
            }

        }
    break;
    }
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB|GLUT_DEPTH);
   glutInitWindowSize (900, 900); 
   glutInitWindowPosition (0, 100);
   glutCreateWindow ("Scene Modeling and Interaction");
   init (); 
   glutDisplayFunc(display); 
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);
   glutMouseFunc(MyMouse);
   glutMainLoop();
   return 0;
}
