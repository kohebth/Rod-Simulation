#define KY_CLK 3
#define KY_DT 6
#define KY_SW 7

bool c, d, cLast = 0;

void ky040Setup() {
  attachInterrupt (digitalPinToInterrupt (KY_CLK), reelRotate, CHANGE); // pins as input
  pinMode (KY_DT, INPUT);
}
 
void reelRotate() {
  c = digitalRead(KY_CLK); // read clock
  d = digitalRead(KY_DT); // read data
  if (c != cLast) { // rotating
    cLast = c;
    if (c^d) {
      reel = min(3000, reel + 1);
    } else {
      reel = max(-3000, reel - 1);
    }
  }
}
