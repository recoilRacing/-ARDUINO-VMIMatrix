#include <FastLED.h>

#define BRIGHTNESS  64
#define LED_TYPE    WS2811
#define COLOR_ORDER RGB
#define NUM_LEDS    12

#define TIMON    27
#define CARO     26
#define AMELIE   25
#define FINN     33
#define BENNO    32
#define MARLEEN  14

CRGB timon[NUM_LEDS];
CRGB caro[NUM_LEDS];
CRGB amelie[NUM_LEDS];
CRGB finn[NUM_LEDS];
CRGB benno[NUM_LEDS];
CRGB marleen[NUM_LEDS];

CRGBPalette16 currentPalette;
TBlendType    currentBlending;

extern CRGBPalette16 myRedWhiteBluePalette;
extern const TProgmemPalette16 myRedWhiteBluePalette_p PROGMEM;

// amelie, marleen, benno, timon, finn, caro
int vmi[11][6][3] = { {{0,0,0}, {255,0,0}, {0,255,0}, {0,0,0},   {0,0,0},   {0,0,0}}, //1
                    {{0,0,0},   {0,255,0}, {255,0,0}, {0,255,0}, {0,0,0},   {0,255,0}}, //2
                    {{0,0,0},   {0,0,0},   {0,255,0}, {255,0,0}, {0,0,0},   {0,0,0}}, //3
                    {{255,0,0}, {0,255,0}, {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0}}, //4
                    {{0,255,0}, {0,0,0},   {0,0,0},   {0,0,0},   {0,255,0}, {255,0,0}}, //5
                    {{0,0,0},   {0,0,0},   {0,0,0},   {0,255,0}, {255,0,0}, {0,0,0}}, //6
                    {{0,0,0},   {0,255,0}, {0,255,0}, {255,0,0}, {0,0,0},   {0,0,0}},   //7
                    {{0,255,0}, {0,0,0},   {0,0,0},   {255,0,0}, {0,0,0},   {0,0,0}},   //8
                    {{255,0,0}, {0,255,0}, {0,255,0},   {0,255,0}, {0,255,0}, {0,255,0}}, //9
                    {{0,255,0}, {0,0,0},   {0,0,0},   {0,255,0}, {0,0,0},   {255,0,0}},  //10
                    {{0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0},   {0,0,0}}};   //OFF

int button1 = 2; //Entwicklung des Boliden
int button2 = 4; // Aerodynamik
int button3 = 16; // Testfahrten
int button4 = 17; // Wettbewerbsregularien
int button5 = 5; // Kommunikation und Marketing
int button6 = 18; // Design
int button7 = 19; // Ressourcen und Fertigung
int button8 = 21; // Teambox
int button9 = 22; // Mündliche Präsi
int button10 = 23; //Nachhaltigkeit

int counter;
int buttonStatus;

void setup() {
  delay( 3000 ); // power-up safety delay
  FastLED.addLeds<LED_TYPE, TIMON, COLOR_ORDER>(timon, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.addLeds<LED_TYPE, CARO, COLOR_ORDER>(caro, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.addLeds<LED_TYPE, AMELIE, COLOR_ORDER>(amelie, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.addLeds<LED_TYPE, FINN, COLOR_ORDER>(finn, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.addLeds<LED_TYPE, BENNO, COLOR_ORDER>(benno, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.addLeds<LED_TYPE, MARLEEN, COLOR_ORDER>(marleen, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(  BRIGHTNESS );
  currentPalette = RainbowColors_p;
  currentBlending = LINEARBLEND;

  pinMode(button1, INPUT_PULLDOWN);
  pinMode(button2, INPUT_PULLDOWN);
  pinMode(button3, INPUT_PULLDOWN);
  pinMode(button4, INPUT_PULLDOWN);
  pinMode(button5, INPUT_PULLDOWN);
  pinMode(button6, INPUT_PULLDOWN);
  pinMode(button7, INPUT_PULLDOWN);
  pinMode(button8, INPUT_PULLDOWN);
  pinMode(button9, INPUT_PULLDOWN);
  pinMode(button10, INPUT_PULLDOWN);
  Serial.begin(9600);

  counter = 10;

    for (int i = 0; i < NUM_LEDS; i++){
    amelie[i].setRGB( 255, 255, 255);
    marleen[i].setRGB( 255, 255, 255);
    benno[i].setRGB( 255, 255, 255);
    timon[i].setRGB( 255, 255, 255);
    finn[i].setRGB( 255, 255, 255);
    caro[i].setRGB( 255, 255, 255);

    FastLED.show();
    delay(1000);
  }
}

 

void loop () {
  if(digitalRead(button1) == HIGH){
    illuminateRings(vmi[0]);
  } else if(digitalRead(button2) == HIGH){
    illuminateRings(vmi[1]);
  } else if(digitalRead(button3) == HIGH){
    illuminateRings(vmi[2]);
  } else if(digitalRead(button4) == HIGH){
    illuminateRings(vmi[3]);
  } else if(digitalRead(button5) == HIGH){
    illuminateRings(vmi[4]);
  } else if(digitalRead(button6) == HIGH){
    illuminateRings(vmi[5]);
  } else if(digitalRead(button7) == HIGH){
    illuminateRings(vmi[6]);
  } else if(digitalRead(button8) == HIGH){
    illuminateRings(vmi[7]);
  } else if(digitalRead(button9) == HIGH){
    illuminateRings(vmi[8]);
  } else if(digitalRead(button10) == HIGH){
    illuminateRings(vmi[9]);
  } else {
    counter++;
  }

  if (counter >= 300){
    illuminateRings(vmi[10]);
  }
  FastLED.show();
  delay(1000 / 100);
}

void illuminateRings(int vmi[6][3]){
  for (int i = 0; i < NUM_LEDS; i++){
    amelie[i].setRGB( vmi[0][0], vmi[0][1], vmi[0][2]);
    marleen[i].setRGB( vmi[1][0], vmi[1][1], vmi[1][2]);
    benno[i].setRGB( vmi[2][0], vmi[2][1], vmi[2][2]);
    timon[i].setRGB( vmi[3][0], vmi[3][1], vmi[3][2]);
    finn[i].setRGB( vmi[4][0], vmi[4][1], vmi[4][2]);
    caro[i].setRGB( vmi[5][0], vmi[5][1], vmi[5][2]);
  }
  counter = 0;
}