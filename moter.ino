void moter(int m1, int m2) {
  if (m1 > 0) {
    if (m1 > 255) {
      m1 = 255;
    }
    digitalWrite(M1F, HIGH);
    digitalWrite(M1R, LOW);
    analogWrite(M1S, m1);
    //Left m >>
  } else if (m1 < 0) {
    if (m1 < -255) {
      m1 = -255;
    }

    digitalWrite(M1F, LOW);
    digitalWrite(M1R, HIGH);
    analogWrite(M1S, m1 * (-1));
    //Left m <<
  } else if (m1 == 0) {
    digitalWrite(M1F, LOW);
    digitalWrite(M1R, LOW);
    analogWrite(M1S, m1);
  }

  if (m2 > 0) {
    if (m2 > 255) {
      m1 = 255;
    }
    digitalWrite(M2F, HIGH);
    digitalWrite(M2R, LOW);
    analogWrite(M2S, m2);
    //Right m >>
  } else if (m2 < 0) {
    if (m2 < -255) {
      m2 = -255;
    }
    digitalWrite(M2F, LOW);
    digitalWrite(M2R, HIGH);
    analogWrite(M2S, m2 * (-1));
    //Right m <<
  } else if (m2 == 0) {
    digitalWrite(M2F, LOW);
    digitalWrite(M2R, LOW);
    analogWrite(M2S, m2);
  }
}
