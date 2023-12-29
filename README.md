# Automatic-trashcan

## Objective
The primary objective of this project was to develop a functional prototype of an automatic trashcan using an Arduino and other components. The aim was to demonstrate understanding of both Arduino basics and engineering principles. This project also serves as an example of how technology can be applied to enhance everyday tasks, reflecting the integration of both computer science and engineering.

---

## Design

The body of the trashcan was made using cardboard. Inside, there is an Arduino board, which takes input from an ultrasonic and infrared sensor to control a servo motor, which lifts or lowers the flap on the trashcan.

### Code

This loop controls the opening and closing of the flap
```c++
void loop() {

  //if the ultrasonic sensor detects an object closer than 30 cm or the boolean open is true, the servo will rotate to 160 degrees, opening the trashcan flap.
  if(uss.dist() < 30 || open){ //uss - ultrasonic sensor
    myservo.write(160); // myservo - servo motor
    delay(60);
    
  }
  //else the servo rotates back to 0 degrees
  else if(!open && uss.dist() > 30){
    
    myservo.write(0);
    delay(60);
    
  }

  //if the IR sensor recieves a signal, the boolean open inverts.
  if (rec.decode(&results)){ //rec - IR reciever
    
      open = !open;
      delay(60);
      rec.resume();
    
  }
}
```
### Components
- Arduino UNO
- Infrared Receiver VS 1838 38kHz
- SG90 servo motor
- RCWL 1401 ultrasonic sensor

### Schematics
![image_2023-06-25_195846691](https://github.com/MananM2m/Automatic-trashcan/assets/129023574/1d684850-ce7c-44fa-913a-f5ab95e0818d)
![image_2023-06-25_195818396](https://github.com/MananM2m/Automatic-trashcan/assets/129023574/1b2fc5fe-a8cd-474d-8aef-cf5166cbd046)

---

## Final prototype



https://github.com/MananM2m/Automatic-trashcan/assets/129023574/946e39cc-dd19-40e2-acec-81ba5b74452e 

https://github.com/MananM2m/Automatic-trashcan/assets/129023574/178a085c-fded-40bf-b25d-1e0cc375d607

![IMG_4455 (1)-min](https://github.com/MananM2m/Automatic-trashcan/assets/129023574/838edab2-f288-4625-96b0-c5a53aecd42d)







