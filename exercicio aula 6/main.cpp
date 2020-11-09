#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>

void desenhaCirculo(float raio, int num_linhas, bool preenchido)
{
	int i;
	GLfloat angulo;
	
	angulo = 2 * M_PI / num_linhas;
	
	if(preenchido)
		glBegin(GL_TRIANGLE_FAN);
	else glBegin(GL_LINE_LOOP);
	
	for(i = 1; i <= num_linhas; i++)
	{
		// comando que calcula as coord. da rotação e desenha as retas na tela    	
//        glVertex2f(-raio*sin(i * angulo) , raio*cos(i * angulo) );	// centro = (0,0), x = 0 e y = raio; 
		glVertex2f(raio*cos(i * angulo) , raio*sin(i * angulo) );		// centro = (0,0), x = raio e y = 0;  
	}
	glEnd(); 
}

float R,G,B;

void init(void);
void reshape(int w, int h);
void keyboard(unsigned char key, int x, int y);
void keyboard_special(int key, int x, int y);
void display(void);

int main(int argc, char** argv){
    glutInit(&argc, argv); // Passagens de parametros C para o glut
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); // Selecao do Modo do Display e do Sistema de cor utilizado
    glutInitWindowSize (512, 512);  // Tamanho da janela do OpenGL
    glutInitWindowPosition (100, 100); //Posicao inicial da janela do OpenGL
    glutCreateWindow ("Exercicio aula 6"); // Da nome para uma janela OpenGL
   
    init(); // Chama a funcao init();
    glutReshapeFunc(reshape); //funcao callback para redesenhar a tela
    glutDisplayFunc(display); //funcao callback de desenho
    glutKeyboardFunc(keyboard); //funcao callback do teclado
    glutSpecialFunc(keyboard_special);	//funcao callback do teclado especial
    glutMainLoop(); // executa o loop do OpenGL
    return 0; // retorna 0 para o tipo inteiro da funcao main();
}

void init(void){
    glClearColor(1.0, 1.0, 1.0, 1.0); //Limpa a tela com a cor branca;
    R = 0.0;
    G = 0.0;
    B = 0.0;
}

void reshape(int w, int h)
{
	// Reinicializa o sistema de coordenadas
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	// Definindo o Viewport para o tamanho da janela
	glViewport(0, 0, w, h);

    // glOrtho (0, 512, 0, 512, -1 ,1);  // Define o volume de projecao ortografica;
                                      // Nesse caso o ponto (0,0,0) se encontra no
                                      // canto inferior esquerdo da tela e o viewport
                                      // tem 0 a 512 pixel no eixo x, 0 a 512 pixel no
                                      // eixo y. Como sera trabalhado imagens 2D definimos
                                      // o eixo z com tamanho -1 a 1;

//   glOrtho (-256, 256, -256, 256, -1 ,1);  // Neste caso, continuamos com 512 pixels, porem o
                                            // centro dos eixos passa a se localizar no centro
                                            // da tela.

  glOrtho (-(w/2), (w/2),-(h/2),(h/2), -1 ,1); // Nesse caso, ficamos com a quantidade de pixels variavel,
                                                 // dependente da largura e altura da janela, e o
                                                 // centro dos eixos continua a se localizar no centro
                                                 // da tela.
   // muda para o modo GL_MODELVIEW (nao pretendemos alterar a projecao
   // quando estivermos desenhando na tela)
	glMatrixMode(GL_MODELVIEW);
}

// Funcao usada na funcao callback para controlar as teclas comuns (1 Byte) do teclado
void keyboard(unsigned char key, int x, int y){
    switch (key) { // key - variavel que possui valor ASCII da tecla precionada
        case 27: // codigo ASCII da tecla ESC
            exit(0); // comando pra finalizacao do programa
        break;
    }
}

//Funcao para controlar as teclas especiais (2 Byte) do teclado
void keyboard_special(int key, int x, int y){
   switch(key){
      case GLUT_KEY_F1:
         R=0.0; G=0.0; B=1.0;      /* F1: muda a cor para azul */
         glutPostRedisplay();
         break;

      case GLUT_KEY_F2:
         R=0.0; G=1.0; B=0.0;      /* F2: muda a cor para verde */
         glutPostRedisplay();
         break;

      case GLUT_KEY_F3:
         R=1.0; G=0.0; B=0.0;      /* F2: muda a cor para vermelho */
         glutPostRedisplay();
         break;

      default: 
      break;
   }
}

void primeiroPredio()
{
	R=1.0; G=0.0; B=0.0;
    glColor3f(R, G, B);
	glBegin(GL_TRIANGLES);
       glVertex2f(-150, 50);
       glVertex2f(-200, -50);
       glVertex2f(-100, -50);
    glEnd();
    
    R=0.0; G=0.0; B=1.0;
    glColor3f(R, G, B);
    glBegin(GL_QUADS);
       glVertex2f(-200, -300);
       glVertex2f(-100, -300);
       glVertex2f(-100, -50);
       glVertex2f(-200, -50);
    glEnd();
    
    R=0.0; G=1.0; B=0.0;
    glColor3f(R, G, B);
    glTranslatef(-150,-100, 0);
    desenhaCirculo(40,30,true);
    
    R=0.0; G=0.0; B=0.0;
    glColor3f(R, G, B);
    glTranslatef(51, 229, 0);
	glBegin(GL_LINES);
       glVertex2f(-50, -80);
       glVertex2f(-50, 0);
    glEnd();
    
    R=0.0; G=0.0; B=0.0;
    glColor3f(R, G, B);
    glTranslatef(25, 25, 0);
	glBegin(GL_LINES);
       glVertex2f(-100, -50);
       glVertex2f(-50, -50);
    glEnd();
}

void segundoPredio()
{
	R=1.0; G=0.0; B=0.0;
	glTranslatef(223, -104, 0);
    glColor3f(R, G, B);
	glBegin(GL_TRIANGLES);
       glVertex2f(-150, 100);
       glVertex2f(-250, -100);
       glVertex2f(-50, -100);
    glEnd();
    
    R=1.0; G=1.0; B=0.0;
    glTranslatef(0,0, 0);
    glColor3f(R, G, B);
    glBegin(GL_QUADS);
       glVertex2f(-250, -350);
       glVertex2f(-50, -350);
       glVertex2f(-50, -100);
       glVertex2f(-250, -100);
    glEnd();
    
    R=0.0; G=0.0; B=0.0;
    glTranslatef(0,-150, 0);
    glColor3f(R, G, B);
    glBegin(GL_QUADS);
       glVertex2f(-200, -200);
       glVertex2f(-100, -200);
       glVertex2f(-100, -50);
       glVertex2f(-200, -50);
    glEnd();
    
    R=0.0; G=0.0; B=0.0;
    glColor3f(R, G, B);
    glTranslatef(-99, 327, 0);
	glBegin(GL_LINES);
       glVertex2f(-50, -80);
       glVertex2f(-50, 0);
    glEnd();
    
    R=0.0; G=0.0; B=0.0;
    glColor3f(R, G, B);
    glTranslatef(25, 25, 0);
	glBegin(GL_LINES);
       glVertex2f(-100, -50);
       glVertex2f(-50, -50);
    glEnd();
}

void terceiroPredio()
{
	glTranslatef(224, -250, 0);
	R=1.0; G=0.0; B=0.0;
    glColor3f(R, G, B);
	glBegin(GL_TRIANGLES);
       glVertex2f(-150, 50);
       glVertex2f(-200, -50);
       glVertex2f(-100, -50);
    glEnd();
    
    R=0.0; G=0.0; B=1.0;
    glColor3f(R, G, B);
    glBegin(GL_QUADS);
       glVertex2f(-200, -300);
       glVertex2f(-100, -300);
       glVertex2f(-100, -50);
       glVertex2f(-200, -50);
    glEnd();
    
    R=0.0; G=1.0; B=0.0;
    glColor3f(R, G, B);
    glTranslatef(-150,-100, 0);
    desenhaCirculo(40,30,true);
    
    R=0.0; G=0.0; B=0.0;
    glColor3f(R, G, B);
    glTranslatef(51, 229, 0);
	glBegin(GL_LINES);
       glVertex2f(-50, -80);
       glVertex2f(-50, 0);
    glEnd();
    
    R=0.0; G=0.0; B=0.0;
    glColor3f(R, G, B);
    glTranslatef(25, 25, 0);
	glBegin(GL_LINES);
       glVertex2f(-100, -50);
       glVertex2f(-50, -50);
    glEnd();
}

// Funcao usada na funcao callback para desenhar na tela
void display(void){
	//Limpa o Buffer de Cores e reinicia a matriz
    glClear(GL_COLOR_BUFFER_BIT); 
	glLoadIdentity();

	primeiroPredio();
	segundoPredio();
	terceiroPredio();

    // Funcao criada para desenhar circulos
//    desenhaCirculo(100,30,true);

    glFlush(); // manda o OpenGl renderizar as primitivas

}