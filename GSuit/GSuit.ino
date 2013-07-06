


int rut = A0; // Right Upper Thigh
int rlt = A1; // Right Lower Thigh
int rbc = A2; // Right Back Calf
int rfc = A4; // Right Front Calf
int lw = A5; // Left Waist
int lb = A6; // Left Butt
int lut = A7; // Left Upper Thigh
int llt = A8; // Left Lower Thigh
int lbc = A9; // Left Back Calf
int lfc = A10; // Left Front Calf
int rw = A11; // Right Waist
int rb = A12; // Right Butt


void setup(){
  Serial.begin(9600); 
  Serial.println("1, 2, 3, 4, 5, 6"); //THIS LINE IS AT THE TOP SO YOU CAN TELL WHICH COLUMN IS WHICH
}

void loop(){
   int rutRead = analogRead(rut);
   int rltRead = analogRead(rlt);
   int rbcRead = analogRead(rbc);
   int rfcRead = analogRead(rfc);
   int lwRead = analogRead(lw);
   int lbRead = analogRead(lb);
   int lutRead = analogRead(lut);
   int lltRead = analogRead(llt);
   int lbcRead = analogRead(lbc);
   int lfcRead = analogRead(lfc);
   int rwRead = analogRead(rw);
   int rbRead = analogRead(rb);
   
   Serial.print("RUT:");
   Serial.print(rutRead);
   Serial.print(", ");
   Serial.print("RLT:");
   Serial.print(rltRead);
   Serial.print(", ");
   Serial.print("RBC:");
   Serial.print(rbcRead);
   Serial.print(", ");
   Serial.print("RFC:");
   Serial.print(rfcRead);
   Serial.print(", ");
   Serial.print("LW:");
   Serial.print(lwRead);
   Serial.print(", ");
   Serial.print("LB:");
   Serial.print(lbRead);
   Serial.print(", ");
   Serial.print("LUT:");
   Serial.print(lutRead);
   Serial.print(", ");
   Serial.print("LLT:");
   Serial.print(lltRead);
   Serial.print(", ");
   Serial.print("LBC:");
   Serial.println(lbcRead);
   Serial.print(", ");
   Serial.print("LFC:");
   Serial.print(lfcRead);
   Serial.print(", ");
   Serial.print("RW:");
   Serial.print(rwRead);
   Serial.print(", ");
   Serial.print("RB:");
   Serial.print(rbRead);
   Serial.println(",");
   
   delay(100);
}
