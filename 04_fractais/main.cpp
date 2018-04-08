
//FRACTAL DA ARVORE
//#include <lib/pen.h>
//void arvore(Pen& p, int lado){
//    float ang = 35;
//    float dec = 12;
//    lado -= (p.rand()% -3 - 2);
//    if(lado < 10)
//        return;
//    p.setColor(0,255,0);
//    p.walk(lado);
//    p.right(ang);
//    arvore(p, lado - dec);
//    p.left(ang);
//    arvore(p, lado - dec);
//    p.left(ang);
//    arvore(p, lado - dec);
//    p.right(ang);
//    p.walk(-lado);
//    p.setColor(120,60,20);
//}
//void fractal(){
//    Pen p(800, 600);
//    p.setXY(400, 590);
//    p.setHeading(90);
//    p.setSpeed(500);
//    int lado = 100;
//    arvore(p, lado);
//    p.wait();
//}
//int main(){
//    fractal();
//    return 0;
//}

/////////////////////////////////////////////////////////////////////////

//FRACTAL FLOCO DE NEVE

//#include <lib/pen.h>
//void floco_neve(Pen& p, int lado){
//    if(lado < 3)
//           return;
//    p.setColor(sf::Color::Green);
//    p.right(72);
//    p.walk(lado);
//    p.setColor(sf::Color::Blue);
//    floco_neve(p,lado/3);
//    p.walk(-lado);
//    p.right(72);
//    p.walk(lado);
//    p.setColor(sf::Color::Blue);
//    floco_neve(p,lado/3);
//    p.walk(-lado);
//    p.right(72);
//    p.walk(lado);
//    p.setColor(sf::Color::Blue);
//    floco_neve(p,lado/3);
//    p.walk(-lado);
//    p.right(72);
//    p.walk(lado);
//    p.setColor(sf::Color::Blue);
//    floco_neve(p,lado/3);
//    p.walk(-lado);
//    p.right(72);
//    p.walk(lado);
//    p.setColor(sf::Color::Blue);
//    floco_neve(p,lado/3);
//    p.walk(-lado);
//    p.setColor(sf::Color::Blue);
//}
//void fractal(){
//    Pen p(800, 600);
//    p.setXY(400, 300);
//    p.setHeading(0);
//    p.setSpeed(20);
//    int lado = 200;
//    floco_neve(p, lado);
//    p.wait();
//}
//int main(){
//    fractal();
//    return 0;
//}

/////////////////////////////////////////////////////////////////////////

//FRACTAL DA CIRCULOS

//#include <lib/pen.h>
//void circulos(Pen &p, int lado){
//    if(lado < 1)
//        return;
//    p.setColor(rand()%255, rand()%255 ,rand()%255);
//    p.circle(lado);
//    for(int i = 0; i < 6; i++){
//        p.right(60);
//        p.up();
//        p.setColor(rand()%255, rand()%255 ,rand()%255);
//        p.walk(lado);
//        p.down();
//        circulos(p, lado * 0.4 );
//        p.up();
//        p.walk(-lado);
//        p.down();
//    }
//}
//void fractal(){
//    Pen p(800, 600);
//    p.setXY(400, 300);
//    p.setHeading(90);
//    p.setSpeed(500);
//    int lado = 100;
//    circulos(p, lado);
//    p.wait();
//}
//int main(){
//    fractal();
//    return 0;
//}

//////////////////////////////////////////////////////////////////////////////

//FRACTAL DA TRIGO

//#include <lib/pen.h>
//void trigo(Pen &p, int lado){
//    if(lado < 0.1)
//        return;
//    for(int i = 0; i < 7; i++){
//        p.setColor(rand()%255, rand()%255, rand()%255);
//        p.walk(lado);
//        p.right(45);
//        trigo(p, lado/3.5);
//        p.left(90);
//        trigo(p, lado/3.5);
//        p.right(45);
//    }
//    p.setColor(rand()%255, rand()%255, rand()%255);
//    p.walk(-lado*7);
//}
//void fractal(){
//    Pen p(800, 600);
//    p.setXY(400, 580);
//    p.setHeading(90);
//    p.setSpeed(0);
//    int lado = 60;
//    trigo(p, lado);
//    p.wait();
//}
//int main(){
//    fractal();
//    return 0;
//}

//////////////////////////////////////////////////////////////////////////////////


//FRACTAL DA ESPIRAL

// #include <lib/pen.h>
// void espiral(Pen& p, int lado){
//    if(lado < 5)
//        return;
//    for(int i = 0; i < 1; i++){
//        p.setThickness(3);
//        p.setColor(rand()%255, rand()%255, rand()%255);
//        p.walk(lado);
//        p.right(90);
//        p.setColor(rand()%255, rand()%255, rand()%255);
//        p.walk(lado);
//        p.right(90);
//        p.setColor(rand()%255, rand()%255, rand()%255);
//        p.walk(lado);
//        p.right(90);
//        p.setColor(rand()%255, rand()%255, rand()%255);
//        p.walk(lado);
//        p.up();
//        p.setColor(rand()%255, rand()%255, rand()%255);
//        p.walk(lado);
//        p.rotate(60);
//        p.down();
       
//        espiral(p, lado - 5);
//    }
// }
// void fractal(){
//     Pen p(800, 600);
//     p.setXY(500, 150);
//     p.setHeading(90);
//     p.setSpeed(100);
//     int lado = 110;
//     espiral(p, lado);
//     p.wait();
// }
// int main(){
//     fractal();
//     return 0;
// }
