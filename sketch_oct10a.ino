//Pino de dados do sensor
#define sensorPIN A0
#define pino_a A5
#define pinDigital 13

int pinRelay = 7;
int dado = 2;
int valorAnalogico;
int valora;
int valorDigital;float SaidaAnalogica = 0;
float Voltagem = 0;


void setup()
{
pinMode(pinDigital, INPUT);
pinMode(pinRelay, OUTPUT);
Serial.begin(9600); //Inicializa a serial
delay(1000); //Aguarda 1 segundo antes de acessar as informações do sensor
}

void loop()
{
valorAnalogico = analogRead(sensorPIN);
valorDigital = digitalRead(pinDigital);
float voltagem = SaidaAnalogica * (5.0 / 1023.0);

Serial.println("saida analogica umidade: ");
Serial.println(voltagem);
Serial.println("saida analogica sensor de chuva: ");
Serial.println(valora);
Serial.println("Saida digital: ");
Serial.println(valorDigital);

if(Serial.available() > 0){ //verifica se existe comunicação com a porta serial
dado = Serial.read();//lê os dados da porta serial
switch(dado){
case 1:
digitalWrite(pinRelay,HIGH); //liga o pino ledPin
break;
case 2:
digitalWrite(pinRelay,LOW); //desliga o pino ledPin
break;
}
}

if (valorAnalogico < 400)
{

}

if (valorAnalogico > 400 && valorAnalogico < 800 && valora < 500)
{
digitalWrite(pinRelay,LOW);
delay(2000);
digitalWrite(pinRelay,HIGH); 
}

if (valorAnalogico > 800 && valorAnalogico < 1024 && valora < 500)
{
digitalWrite(pinRelay,LOW);
delay(5000);
digitalWrite(pinRelay,HIGH); 
}
delay(1000);
}
