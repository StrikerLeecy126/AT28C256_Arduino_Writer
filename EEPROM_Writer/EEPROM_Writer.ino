// I/O for EEPROM
#define IO_0 2
#define IO_1 3
#define IO_2 4
#define IO_3 5
#define IO_4 6
#define IO_5 7
#define IO_6 8
#define IO_7 9

// Address for shift register
#define ADDR 10 // Address Input
#define CLK 11  // Clokc Input
#define MR 12   // Master Reset (Active Low)

// Write Enable (Active LOW)
#define WE 13

void setup() {
  // Initialise Serial Comm.
  Serial.begin(9600);

  // Setup pinMode
  pinMode(IO_0, OUTPUT);
  pinMode(IO_1, OUTPUT);
  pinMode(IO_2, OUTPUT);
  pinMode(IO_3, OUTPUT);
  pinMode(IO_4, OUTPUT);
  pinMode(IO_5, OUTPUT);
  pinMode(IO_6, OUTPUT);
  pinMode(IO_7, OUTPUT);

  pinMode(ADDR, OUTPUT);
  pinMode(CLK, OUTPUT);
  pinMode(MR, OUTPUT);

  pinMode(WE, OUTPUT);


  // Define Data
  int Data_Num = 16; // Number of data
  int Address_Set[Data_Num] = {0x0000, 0x0001, 0x0002, 0x0003, 0x0004, 0x0005, 0x0006, 0x0007, 0x0008, 0x0009, 0x000a, 0x000b, 0x000c, 0x0000d, 0x000e, 0x000f}; // Address

  /* Data for 7-deg display
  int IO_Set[Data_Num] = {0x5f, 0x06, 0x3b, 0x2f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f, 0x77, 0x7c, 0x59, 0x3e, 0x79, 0x71}; // Data
  */
  
   int IO_Set[Data_Num] = {0x00, 0x01, 0x03, 0x07, 0x0f, 0x1f, 0x3f, 0x7f, 0xff, 0xfe, 0xfc, 0xf8, 0xf0, 0xe0, 0xc0, 0x80};

  Master_Reset();
  digitalWrite(MR, HIGH);
  for (int Loc = 0; Loc < sizeof(Address_Set) / 2; Loc++)
  {
    setADDR(Address_Set[Loc]);
    delay(10);
    setIO(IO_Set[Loc]);
    delayMicroseconds(10);
    Master_Reset();
  }

  Serial.println("Complete");

}

void loop() {
  // put your main code here, to run repeatedly:

}

// Function for Calculating Address
void setADDR(int Addr) {

  Serial.print("Current Address: ");
  for (int i = 0; i < 15; i++)
  {
    int Addr_Val = Addr & 0x01;
    Addr = Addr >> 1;
    digitalWrite(ADDR, Addr_Val >= 1 ? HIGH : LOW);

    delayMicroseconds(1);
    digitalWrite(CLK, LOW);
    delayMicroseconds(1);
    digitalWrite(CLK, HIGH);
    delayMicroseconds(1);
    digitalWrite(CLK, LOW);
    delayMicroseconds(1);
    Serial.print(Addr_Val);

  }
  Serial.println();
}


void setIO(int IO) {

  //int IO_Val[8] = {0, 0, 0, 0, 0, 0, 0，0};
  int pin[8] = {IO_0, IO_1, IO_2, IO_3, IO_4, IO_5, IO_6, IO_7};

  Serial.print("Current IO: ");

  for (int i = 0; i < 8; i++)
  {
    int IO_Val = IO & 0x01;
    IO = IO >> 1;
    digitalWrite(pin[i], IO_Val >= 1 ? HIGH : LOW);
    Serial.print(IO_Val);
  }

  Serial.println();
  delayMicroseconds(10);
  Pulse();

}

void Pulse() {
  digitalWrite(WE, HIGH);
  delayMicroseconds(1);
  digitalWrite(WE, LOW);
  delayMicroseconds(1);
  digitalWrite(WE, HIGH);
}

void Master_Reset() {
  digitalWrite(MR, HIGH);
  delayMicroseconds(1);
  digitalWrite(MR, LOW);
  delayMicroseconds(1);
  digitalWrite(MR, HIGH);
}
