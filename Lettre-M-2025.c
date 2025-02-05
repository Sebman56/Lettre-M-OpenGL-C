/*************************************************************************
*** Animation de la lettre M en 3D, compilé sous VC++6 avec OpenGL **********************
*** Dessin d'une lettre M en 3D en 3D et rotation  de 2 M, 2 fois plus petit **************
*** avec un des petits M tourne en plus sur lui même *********************************
*** http://prographix.games-creators.org/doc_cat/94 ********************************
*** 
*** Compilation: gcc Lettre-M-2014.c -o Executable20181225-1  -L/usr/X11R6/lib -lGL -lGLU -lglut -lX11  -lXi -lm ***
****2eme méthode g++ gl.cpp -o gl -lGL -lGLU -lglut
****
**** Affichage des parois par les 04 fonctions jambes et  l'épaisseur de la lettre par EpaisseurBleu et EpaisseurDeux 
*************************************************************************/

/* #include <windows.h> */
/* #include <GL/gl.h> */
#include <GL/glut.h>
/* #include <math.h> */
/*
#define WIDTH 640
#define HEIGHT 480
*/
void Display();
void Reshape(int,int);
void Idle();
void Init();
void Creer_Cube();

int id_cube=0;
int angle=0;

/***************** */

void EpaisseurBleu ();
void EpaisseurDeux ();
void Alpha ();
void Jambe1Rouge();
void Jambe2Bleu ();
void Jambe3Verte();
void Jambe4Rose ();



/*************************************************************************/
int main(int argc, char *argv[ ])
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH); // mode double buffering + z-buffer

    glutInitWindowSize(640,480); //***************************************
    glutInitWindowPosition(0,0);
    glutCreateWindow("Scene 3D Animée");

    Init();

    glutDisplayFunc(Display);
    glutReshapeFunc(Reshape);
    glutIdleFunc(Idle);

    glutMainLoop();
    return 0;
}


void Init()//-
{//-
    glEnable(GL_DEPTH_TEST);//-
    Creer_Cube();//-
}//-
void Creer_Cube()
{
    id_cube=glGenLists(1);
    glNewList (id_cube,GL_COMPILE);
/*        Jambe1Rouge();
        Jambe2Bleu();
        Jambe3Verte();
        Jambe4Rose();
*/        EpaisseurBleu();
        EpaisseurDeux ();

    glEndList();

}

void Idle()
{
    angle+=1;     // Vitesse de rotation des petits "M"
    if (angle>360) angle=0;
    glutPostRedisplay();
}

void Display()
{
    glClearColor (0,0,0,0); /* selectionne la couleur noire (qui est celle par defaut) */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt (7,7,15,0,0,0,0,1,0);

    glCallList(id_cube);

    glPushMatrix();
    glRotated(angle,0,1,0);
    glTranslatef(0,0,-5);
    glScaled (0.5,0.5,0.5);
    glCallList(id_cube);
    glPopMatrix();
   
    glPushMatrix();
    glRotated(angle,0,1,0);
    glTranslatef(0,0,5);
    glRotated(angle,0,1,0);
    glScaled (0.5,0.5,0.5);
    glCallList(id_cube);
    glPopMatrix();

    glutSwapBuffers();
    glFlush();  
}

void Reshape (int w, int h)
{
    glViewport (0,0,w,h);
    glMatrixMode( GL_PROJECTION); /* Choisit la matrice de projection */
    glLoadIdentity();
    gluPerspective(45.0, (float)  w/h,1.,100.);
    glMatrixMode(GL_MODELVIEW);    /* on revient sur la matrice MODELVIEW */
    glLoadIdentity();
}

/****************************************************************************************************************************** */


/* *** Jame 1 rouge */
 void Jambe1Rouge()
{
    glBegin(GL_TRIANGLE_FAN);   /* Dessin du triangle Gauche Face Arrière */
        glColor3d(1,0,0);      // Rouge 
    glVertex3i (-1,1,-1);       // Angle interir moyen   
    glVertex3i (-2,-2,-1);    /* pt dr */
    glVertex3i (-4,-2,-1);    // Angle bas  exterieur
    glVertex3i (-2,3,-1);
    glVertex3i (-1,3,-1);    /* pt bas dr*/
    glVertex3i (0,2,-1);
    glVertex3i (0,0,-1);
    glEnd();
}

void Jambe2Bleu ()
{
    glBegin(GL_TRIANGLE_FAN);    /* Dessin du triangle Droit Face Arrière */
        glColor3d(0,0,3);    // Bleu 
    glVertex3i(1,1,-1);      /* pt bas */
    glVertex3i(2,-2,-1);    /* pt dr */
    glVertex3i(4,-2,-1);    // Aangle bas exterieur
    glVertex3i(2,3,-1);
    glVertex3i(1,3,-1);    /* pt bas dr */
    glVertex3i(0,2,-1);
    glVertex3i(0,0,-1);
    glEnd();
}


void Jambe3Verte()
{
    glBegin(GL_TRIANGLE_FAN);    /* Dessin du triangle Gauche Face Avant */
        glColor3d(0,2,0);  //Verte

    glVertex3i (-1,1,1);       // Angle interir moyen   
    glVertex3i (-2,-2,1);    /* pt dr */
    glVertex3i (-4,-2,1);    // Angle bas  exterieur
    glVertex3i (-2,3,1);
    glVertex3i (-1,3,1);    /* pt bas dr*/
    glVertex3i (0,2,1);
    glVertex3i (0,0,1);
    glEnd();
}


void Jambe4Rose ()
{
    glBegin(GL_TRIANGLE_FAN);    /* Dessin du triangle Droit Face Arrière */
        glColor3d(1,0,3);    // Bleu 
    glVertex3i(1,1,1);      /* pt bas */
    glVertex3i(2,-2,1);    /* pt dr */
    glVertex3i(4,-2,1);    // Aangle bas exterieur
    glVertex3i(2,3,1);
    glVertex3i(1,3,1);    /* pt bas dr */
    glVertex3i(0,2,1);
    glVertex3i(0,0,1);
    glEnd();
}
/************************************************************************************************************************** */
/* *** Dessin de l'épaisseur de la lettre *******************************************/

void EpaisseurBleu ()
{
    glBegin(GL_QUAD_STRIP);  // On commence par l'arete du milieu bas  C'est  le centre 
        glColor3d(0,0,3);       // Couleur BLeu
/* Petite face interne*/
    glVertex3i(0,0,1);    // Angle arête milieu avant
    glVertex3i(0,0,-1);    // Angle arête milieu arrière

/* Grande Face interne*/
    glVertex3i(-1,1,1);    // Angle Arrière interieur haut,1,-1);    // Angle Arrière interieur haut
    glVertex3i(-1,1,-1);    // Angle Arrière interieur haut,1,-1);    // Angle Arrière interieur haut

        glColor3d(1,0,0);      // Rouge 
    
/* Plancher Lettre M*/
    glVertex3i(-2,-2,1);    // Angle Avant Bas interieur/* Vers la gauche */
    glVertex3i(-2,-2,-1);   // Angle Arrière Bas interieur
    glVertex3i(-4,-2,1);       // Angle Avant Extereur Bas// Exterieur bas avant
    glVertex3i(-4,-2,-1);      // Angle Arrière Exterieur  Bas  // Exterieur ba arriereur du M 
/* Coté exterieur */
    glVertex3i(-2,3,1);     // Angle Avant Exterieur haut
    glVertex3i(-2,3,-1);    // Angle Arrière Exterieur haut 
/* Plafond */
    glVertex3i(-1,3,1);     // Angle Avant Exterieur haut
    glVertex3i(-1,3,-1);    // Angle Arrière Exterieur haut 
/* Descente Vers le centre de la Lettre depusi l'exterieur*/
/* Arête milileu du "M", */
    glVertex3i(0,2,1);     // Angle Avant  milieu haut
    glVertex3i(0,2,-1);    // Angle Arrière milieu haut
}
/*Demi Lettre*/
void EpaisseurDeux ()
{
    glBegin(GL_QUAD_STRIP);  // On commence par l'arete du milieu bas  C'est  le centre 
        glColor3d(0,0,3);       // Couleur BLeu
/* Petite face interne*/
    glVertex3i(0,0,1);    // Angle arête milieu avant
    glVertex3i(0,0,-1);    // Angle arête milieu arrière

/* Grande Face interne*/
    glVertex3i(1,1,1);    // Angle Arrière interieur haut,1,-1);    // Angle Arrière interieur haut
    glVertex3i(1,1,-1);    // Angle Arrière interieur haut,1,-1);    // Angle Arrière interieur haut

        glColor3d(1,0,0);      // Rouge 
    
/* Plancher Lettre M*/
    glVertex3i(2,-2,1);    // Angle Avant Bas interieur/* Vers la gauche */
    glVertex3i(2,-2,-1);   // Angle Arrière Bas interieur
    glVertex3i(4,-2,1);       // Angle Avant Extereur Bas// Exterieur bas avant
    glVertex3i(4,-2,-1);      // Angle Arrière Exterieur  Bas  // Exterieur ba arriereur du M 
/* Coté exterieur */
    glVertex3i(2,3,1);     // Angle Avant Exterieur haut
    glVertex3i(2,3,-1);    // Angle Arrière Exterieur haut 
/* Plafond */
    glVertex3i(1,3,1);     // Angle Avant Exterieur haut
    glVertex3i(1,3,-1);    // Angle Arrière Exterieur haut 
/* Descente Vers le centre de la Lettre depusi l'exterieur*/
/* Arête milileu du "M", */
    glVertex3i(0,2,1);     // Angle Avant  milieu haut
    glVertex3i(0,2,-1);    // Angle Arrière milieu haut

    glEnd();
}









/*
    glVertex3i(-2,3,-1);
    glVertex3i(-1,3,1);

    glVertex3i(-1,3,-1);    /* Ici on va dessinner la moitié des faces */
//    glVertex3i(0,2,-1);    /* qui font l'épaisseur */
/*
    glVertex3i(1,3,1);
    glVertex3i(1,3,-1);

    glVertex3i(2,3,1);
    glVertex3i(2,3,-1);     
*/
//        glColor3d(8,2,2);
/*
    glVertex3i(4,-2,1);
    glVertex3i(4,-2,-1);

    glVertex3i(2,-2,1);
    glVertex3i(2,-2,-1);

    glVertex3i(0,0,1);
    glVertex3i(0,0,-1);
*/

void Alpha ()
{


    glBegin(GL_TRIANGLE_FAN);    /* Dessin du triangle Gauche Droit Face Avant */
    glVertex3i(1,1,1);        glColor3d(0,5,3);    /* pt bas */
    glVertex3i(2,-2,1);    /* pt dr */
    glVertex3i(4,-2,1);
    glVertex3i(1,3,1);
    glVertex3i(-1,3,1);
    glVertex3i(0,2,1);
    glVertex3i(0,2,1);
    glVertex3i(0,0,1);
    glEnd();
}