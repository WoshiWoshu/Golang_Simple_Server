int test(void)

{
     return 20;
}


int main (void)

{

     int (*pointeurSurFonction)(void);
     int nombre;


     pointeurSurFonction = test;     /*Initialisation*/
     nombre = (*pointeurSurFonction)();      /*Appel de la fonction*/
     return 0;

}
