class Button {
  float x = 0;
  float y = 0;
  float w = 0;
  float h = 0;

  boolean value = false;

  String label;

  public Button(String label, float x, float y, float w, float h) {
    this.label = label;
    this.x = x;
    this.y = y;
    this.w = w;
    this.h = h;
  }

  void draw() {
    stroke(255);
    if (value == true) {
      fill(255, 127);
    } 
    else {
      noFill();
    }

    rect(x, y, w, h);
    
    fill(255);
    stroke(255);
    textAlign(CENTER,CENTER);
    text(label,x+w/2,y+h/2);
  }

  void mousePressed() {
    if (mouseX > x && mouseX < x + w && mouseY > y && mouseY < y + h) {
      value = !value;
    }
  }
}

