
Objekt oneObjekt1;
Objekt oneObjekt2;

void setup () {
  size(650, 350);
  oneObjekt1 = new Objekt();
  oneObjekt2 = new Objekt();
  frameRate(60);
}

void draw () {
  background(215);
  line(650/2, 0, 650/2, 350);
  rect(90, 310, 40, 15);
  rect(500, 310, 40, 15);
  text("Player 1", 250, 10);
  text("Player 2", 350, 10);

  oneObjekt1.move(); 
  oneObjekt1.display();
  oneObjekt2.move();
  oneObjekt2.display();
}

class Objekt {
  color c; // Variabel
  float xposition;
  float yposition;
  float xspeed;


  Objekt() {
    c = color(175);
    yposition = height/2;
    xposition = width/2;
    xspeed = 1;
  }
  void display() { // FuNKTion
    //Selve objekterne
    ellipseMode(CENTER);
    stroke(0);
    fill(c);
    ellipse(yposition, xposition, 10, 10);
  }

  void move() { // Function.
    xposition = xposition + xspeed;
    if (xposition > height) {
      xposition = 0;
    }
  }
}
