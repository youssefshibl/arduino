 
#define aone A0
#define pone 8
float value=0.0;
float value2=0.0;
unsigned long res=0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pone,OUTPUT);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  value=analogRead(aone);
  value2=(value/1023)*5;
  res=(1000*value2)/(5-value2);
  Serial.print("the resistance:");
  Serial.println(res);
  if(res<1000){
    digitalWrite(pone,HIGH);
    
    } 
  else if(res>1000){
    digitalWrite(pone,LOW);
    }  
  delay(100);  
    
    
   
    
   
    

}
