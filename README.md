PImage road;
int roadWidth;
int roadHeight;
Objekt bilObjekt1;
Objekt bilObjekt2;
int point;
int x, y;
int x2, y2;
int turn =0;
boolean state = false;
boolean button = false;
int x3 = 630;
int y3 = 430;
int w = 10;
int h = 10;

//---------------------------------------------------------------   

void setup () {
  size(650, 450);
  background(0);
  strokeWeight(3);
  textSize(15);
  text("Tryk på 'shift' for at starte spillet", 225, 225); 
  text("Spiller 1 styrer med 'A' og 'S'", 100, 100);
  text("Spiller 2 styrer med 'K' og 'L'", 100, 525);

  road = loadImage ("road.png");
  roadWidth = 650/2;
  roadHeight= 450;
  bilObjekt1 = new Objekt();
  bilObjekt2 = new Objekt();
  point = 0;
  x=90;
  y = 370;
  x2=560;
  y2=370;
}

//---------------------------------------------------------------   

void draw () {
  background(100);

  image(road, 0, 0, roadWidth, roadHeight); //billede af vejen
  image(road, 325, 0, roadWidth, roadHeight);

  if (button) { //Knappen i nederste hjørne
    background(0);
    text("Spiller 1 styrer med 'A' og 'S'", 50, 125);
    text("Spiller 2 styrer med 'K' og 'L'", 400, 125);
    stroke(255);
  } else {
    //stroke(0);
  }


  rect(x3, y3, w, h);

  fill(255, 0, 0);
  rect(x, y, 20, 40);//(90, 370, 20, 40);
  text("point: "+point, 10, 20);
  text("Player 1", 250, 20);
  fill(0, 0, 255);
  rect(x2, y2, 20, 40);//(560, 370, 20, 40);
  text("Player 2", 580, 20);
  text("point: "+point, 350, 20);
  bilObjekt1.move(); 
  bilObjekt1.display();
  bilObjekt2.move();
  bilObjekt2.display();
  strokeWeight(5);
  line(650/2, 0, 650/2, 450);
}
void keyPressed() {
  if (key == 'a')
    x=x-10;

  if (key == 's')
    x=x+10;

  if (key == 'k')
    x2=x2-10;

  if (key == 'l')
    x2=x2+10;
}
//---------------------------------------------------------------   


class Objekt {
  color c; // Variabel
  float xposition; 
  float yposition;
  float xspeed;
  float xposition2; 
  float yposition2;
  float xspeed2;


  Objekt() {
    c = color(255);
    yposition = height/5;
    xposition = width/2;
    xspeed = 6;
    yposition2 = 560;
    xposition2 = 30;
    xspeed2 = 6;
  }
  void display() { // TIl at få forhindringerne frem
    //Selve objekterne
    ellipseMode(CENTER);
    stroke(0);
    fill(c);
    ellipse(yposition, xposition, 20, 20);
    ellipse(yposition2, xposition2, 20, 20);
  }

  void move() { // Funktionen der får forhindringerne til at bevæge sig
    xposition = xposition + xspeed;
    if (xposition > height) {
      xposition = 0;
    }

    xposition2 = xposition2 + xspeed2;
    if (xposition2 > height) {
      xposition2 = 0;
    }
  }
}
void mousePressed() {
  if (mouseX > x && mouseX < x3+w && mouseY > y3 && mouseY < y3+h) {
    button = !button;
  }
}
