volatile int  count_vo1 = 0;
volatile int  count_vo2 = 0;

long starttime = 0;

void sum_counts_vo1() {
  count_vo1++;
}

void sum_counts_vo2() {
  count_vo2++;
}

void setup() {

  attachInterrupt(0 , sum_counts_vo1 , RISING );
  attachInterrupt(1, sum_counts_vo2 , RISING );

  starttime = millis();

  Serial.begin( 9600 );
  Serial.println("start");

  delay( 1000 );
}


void loop() {
  long  endtime = 0;

  do {
    endtime = millis();
  } while ( endtime - starttime < 2000 );
  
  starttime = millis();
  Serial.println("-------------------------");
  Serial.print( "V(OUT1)=" );
  Serial.print( count_vo1 );
  Serial.print( "," );
  Serial.print( "V(OUT2)=" );
  Serial.print( count_vo2 );
  Serial.print( "," );
  Serial.print( "PM2.5=" );
  Serial.println( count_vo1-count_vo2 );

  //Initialization
  count_vo1 = 0;
  count_vo2 = 0;


}
