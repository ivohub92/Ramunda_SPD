// C++ code
//

//Define de LEDs
#define c 5
#define d 6
#define e 7
#define g 8
#define f 9
#define a 10
#define b 11

//Define de pantalla LED seleccionada
#define UNIDAD A4
#define DECENA A5


//Define de Botones
#define BOTONSUMA 2
#define BOTONRESET 3
#define BOTONRESTA 4


int timedisplayon = 10;
int apagado = 0;
int contador = 0;

int lectura_boton_suma = 0;
int lectura_boton_resta = 0;
int lectura_boton_reset = 0;



int suma = 1;
int sumaPrevia = 1;
int resta = 1;
int restaPrevia = 1;
int reset = 1;
int resetPrevio = 1;


void setup()
{
  //Botones (SUMA, RESET, RESTA)
  pinMode(BOTONRESTA, INPUT_PULLUP);
  pinMode(BOTONRESET, INPUT_PULLUP);
  pinMode(BOTONSUMA, INPUT_PULLUP);
  
  //LEDS
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  
  
  //PANTALLAS
  pinMode(UNIDAD, OUTPUT);
  pinMode(DECENA, OUTPUT);
  
  Serial.begin(9600);
    
  
}



void loop()
{
  
  int presiono = botonPresionado();
  
  if (presiono == BOTONSUMA){
    	contador++;
  }
 
  else if (presiono == BOTONRESTA)
  {
  		contador--;
  
  }
  
  else if (presiono == BOTONRESET){
  
  contador = 0;
    
  }
  
  printContador(contador);
  
}



//Mostrar numero


void printDigit(int digit){
  
  /*
  GFEDCBA
0 0111111
1 0000110
2 1011011
3 1001111
4 1100110
5 1101101
6 1111101
7 0000111
8 1111111
9 1101111

*/
  
  
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,LOW);

  

  switch(digit){
  
  case 1:
  
    digitalWrite(a,LOW);
    digitalWrite(b,HIGH);
    digitalWrite(c,HIGH);
    digitalWrite(d,LOW);
    digitalWrite(e,LOW);
    digitalWrite(f,LOW);
    digitalWrite(g,LOW);
    
    break;
  
  case 2:
  
    digitalWrite(a,HIGH);
    digitalWrite(b,HIGH);
    digitalWrite(c,LOW);
    digitalWrite(d,HIGH);
    digitalWrite(e,HIGH);
    digitalWrite(f,LOW);
    digitalWrite(g,HIGH);
    
    break;
  
  case 3:
  
    digitalWrite(a,HIGH);
    digitalWrite(b,HIGH);
    digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);
    digitalWrite(e,LOW);
    digitalWrite(f,LOW);
    digitalWrite(g,HIGH);
    break;
  
  case 4:
  
    digitalWrite(a,LOW);
    digitalWrite(b,HIGH);
    digitalWrite(c,HIGH);
    digitalWrite(d,LOW);
    digitalWrite(e,LOW);
    digitalWrite(f,HIGH);
    digitalWrite(g,HIGH);
    
    break;
  
   case 5:
  
    digitalWrite(a,HIGH);
    digitalWrite(b,LOW);
    digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);
    digitalWrite(e,LOW);
    digitalWrite(f,HIGH);
    digitalWrite(g,HIGH);
    
    break;
  
  
   case 6:
  
    digitalWrite(a,HIGH);
    digitalWrite(b,LOW);
    digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);
    digitalWrite(e,HIGH);
    digitalWrite(f,HIGH);
    digitalWrite(g,HIGH);
    
    break;
  
   case 7:
  
    digitalWrite(a,HIGH);
    digitalWrite(b,HIGH);
    digitalWrite(c,HIGH);
    digitalWrite(d,LOW);
    digitalWrite(e,LOW);
    digitalWrite(f,LOW);
    digitalWrite(g,LOW);
    
    break;
  
   case 8:
  
    digitalWrite(a,HIGH);
    digitalWrite(b,HIGH);
    digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);
    digitalWrite(e,HIGH);
    digitalWrite(f,HIGH);
    digitalWrite(g,HIGH);
    
    break;
  
   case 9:
  
    digitalWrite(a,HIGH);
    digitalWrite(b,HIGH);
    digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);
    digitalWrite(e,LOW);
    digitalWrite(f,HIGH);
    digitalWrite(g,HIGH);
    
    break;
  }
 
  
  
}


//Funcion de encendido de pantallas

void prendePantalla(int digito)
{
  
  if(digito == UNIDAD){
    
    digitalWrite(UNIDAD, LOW);
    digitalWrite(DECENA, HIGH);
    delay(timedisplayon);
  
  }
  
  else if(digito == DECENA){
    
    digitalWrite(UNIDAD, HIGH);
    digitalWrite(DECENA, LOW);
    delay(timedisplayon);
  
  }
  
  else{
  
    digitalWrite(UNIDAD, HIGH);
    digitalWrite(DECENA, HIGH);
  
  }


}

//Funcion para detectar el encendido de pantallas

void printContador(int contador){
  
  prendePantalla(apagado);
  printDigit(contador/10); //???
  prendePantalla(DECENA);
  prendePantalla(apagado);
  printDigit(contador - 10*((int)contador/10)); //???
  prendePantalla(UNIDAD);

}

//Funcion del estado del boton

int botonPresionado(void)
{
  
  /*
  En el caso de los botones
  boton = 1 significa boton no presionado
  boton = 0 siginifica boton presionado
  */

  lectura_boton_suma = digitalRead(BOTONSUMA);
  lectura_boton_resta = digitalRead(BOTONRESTA);
  lectura_boton_reset = digitalRead(BOTONRESET);
    
   if(lectura_boton_suma)
    sumaPrevia = 1;
   if(lectura_boton_resta)
    restaPrevia = 1;
   if(lectura_boton_reset)
    resetPrevio = 1;
  
  
  if(lectura_boton_suma == 0 && lectura_boton_suma!= sumaPrevia)
  {
    sumaPrevia = lectura_boton_suma;
      
    return BOTONSUMA;
  }
  
  if(lectura_boton_resta == 0 && lectura_boton_resta != restaPrevia)
  {
    restaPrevia = lectura_boton_resta;
      
    return BOTONRESTA;
  }
  
  if(lectura_boton_reset == 0 && lectura_boton_reset != resetPrevio)
  {
    resetPrevio = lectura_boton_reset;
      
    return BOTONRESET;
  }
  
 
    return 0;
    
}