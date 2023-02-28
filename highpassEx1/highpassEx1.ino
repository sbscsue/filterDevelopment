void setup() {
  Serial.begin(9600);
  Serial.println("start");
}

void loop() {
  float t = millis() / 1000.0;
  float original = sin(2*PI*2*t) + cos(2*PI*50*t) + sin(2*PI*200*t);

  float filterd = filt(original);

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
