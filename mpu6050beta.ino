#include <MPU6050_tockn.h>                                    // Download and install this library https://github.com/tockn/MPU6050_tockn
#include <Wire.h>

#define LeftB     2                                           // Left Button Pin
#define RightB    3                                           // Right Button Pin                                           // Mouse Enable Button Pin
//#include   <MPU6050.h>
//#include   <Wire.h>
MPU6050 mpu6050(Wire);
int X,Y,Z;                                                    // Data Variables for mouse co-ordinates
int OX,OY,OZ;                                                 // Angle Variables for calucating gyroscope zero error

void setup() {
   
  Serial.begin(9600);                                       // Initialise Serial communication
  Wire.begin();                                               // Initialise I2C communication
  mpu6050.begin();                                            // Initialise Gyro communication
  Serial.println("STRTM");                                    // Identifier "STARTM" for start mouse
  mpu6050.calcGyroOffsets(true);                              // Setting Gyro offsets
  mpu6050.update();                                           // Command to calculate the sensor data before using the get command
  OX = mpu6050.getAngleX();                                   
  OY = mpu6050.getAngleY();
  OZ = mpu6050.getAngleZ();

  pinMode(LeftB,INPUT);                                      
  pinMode(RightB,INPUT);
//  pinMode(MouseB,INPUT);

  if(OX < 0){                                                
    OX = OX *(-1);}
  else{
    OX = (OX-OX)-OX;}

  if(OY < 0){
    OY = (OY *(-1));}
  else{
    OY = ((OY-OY)-OY)+10;}

  if(OZ < 0){
    OZ = OZ *(-1);}
  else{
    OZ = (OZ-OZ)-OZ;}
}

void loop() {
  mpu6050.update();
  X = OX + mpu6050.getAngleX();                                    
  Y = OY + mpu6050.getAngleY();
  Z = OZ + mpu6050.getAngleZ();

                                                    
 
  if(digitalRead(LeftB) == HIGH){                                  
    delay(100);                                                     
    Serial.println("DATAB,L");                                     
  }
  if(digitalRead(RightB) == HIGH){                                  
    delay(100);                                                     
    Serial.println("DATAB,R");                                    
  }
   Serial.println("DATAL,"+String(X)+','+String(Y)+','+String(Z)); 
  
}
