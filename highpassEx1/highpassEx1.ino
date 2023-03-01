void setup() {
  Serial.begin(115200);
  Serial.println("start");
}

void loop() {
  float t = millis() / 1000.0;

  float signal1 = sin(2*PI*2*t);
  float signal2 = sin(2*PI*50*t);
  
  float original = signal1 + signal2;
  float filterd = filt(original);

  delay(1);

  Serial.print(signal1);
  Serial.print(" ");
  Serial.print(signal2);
  Serial.print(" ");
  Serial.print(original);
  Serial.print(" ");
  Serial.print(filterd);
  Serial.println();
}


//100hz highpass

//filter 계수
#define N 2+1

//x coefficients
#define a1 0.52188555
#define a2 0

//y coefficients
#define b1 0.76094278
#define b2 -0.76094278

//buffer setting 
float y[N];
float x[N];

float filt(float xn){
  //initalize 
  x[0] = x[1];
  x[1] = x[2];
  
  y[0] = y[1];
  y[1] = y[2];

  //x input
  x[2] = xn;
  //filtering
  y[2] = -a1*y[1] + b1*x[2] + b2*x[1];

  return y[2];  
}
