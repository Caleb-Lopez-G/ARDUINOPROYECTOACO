#include <Keypad.h>
#include <LiquidCrystal.h>
int exam;

LiquidCrystal pantalla(12,11,10,A1,A2,A3,A4);

const byte filas = 4;
const byte columnas = 4;
char teclas[filas][columnas] = {
  {'1','2','3','+'},
  {'4','5','6','-'},
  {'7','8','9','*'},
  {'C','0','=','/'}
};
char tecla = 'n';
byte pinFilas[filas] = {9,8,7,6};
byte pinColumnas[columnas] = {5,4,3,2};

//Instanciamos el objeto de tipo Keypad
Keypad teclado = Keypad(makeKeymap(teclas), pinFilas, pinColumnas, filas, columnas);

void setup()
{
  Serial.begin(9600);
  pinMode(0, OUTPUT);
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  pantalla.begin(16, 2);
  pantalla.clear();
  pantalla.setCursor(0, 0);
  //pantalla.print("Resultados:"+exam);
   
}

void loop()
{
    tecla = teclado.getKey(); //Extraigo la tecla oprimida
    
    if(tecla)
    {
      pantalla.clear();
      pantalla.print("Tecla oprimida:");
      pantalla.setCursor(0, 1);
      pantalla.print(tecla);
      Serial.println("Tecla presionada: "+ String(tecla));
    }
    //SIMULACION DE COMO FUNCIONARIA SI SE COLOCARAN EXAMENES
      if(exam == 0){
      //Codigo para poder encender la luz
      digitalWrite(12, HIGH);
      delay(500);
      digitalWrite(12, LOW);
      delay(500);//Esperar el tiempo en segundos
      pantalla.print("No hay Resultados:");
      }
      else{
      pantalla.print("Hay Resultados:");
        if(tecla){
        exam=1;
          pantalla.print("su nota seria:"+exam);
        }
      }

}



