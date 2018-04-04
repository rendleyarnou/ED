
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

//FRACTAL DO TRIANGULO

//#include <lib/pen.h>
//void triangulo(Pen& p, int lado){
//    if(lado < 5)
//        return;
//    for(int i = 0; i < 3; i++){
//        p.setThickness(1);
//        p.setColor(rand()%255, rand()%255, rand()%255);
//        p.walk(lado);
//        p.right(120);
//        triangulo(p, lado/2);
//    }
//}
//void fractal(){

//    Pen p(800, 600);
//    p.setXY(700, 580);
//    p.setHeading(180);
//    p.setSpeed(50);
//    int lado = 600;
//    triangulo(p, lado);
//    p.wait();
//}
//int main(){
//    fractal();
//    return 0;
//}

/////////////////////////////////////////////////////////////////////////

//FRACTAL DA ROTACAO

//#include <lib/pen.h>
//void embua(Pen& p, int lado){
//    if(lado < 2)
//        return;
//    p.setColor(sf::Color::Blue);
//    p.walk(lado);
//    p.right(90);
//    embua(p, lado - 2);
//    p.left(90);
//    p.setColor(sf::Color::Yellow);
//    p.walk(-lado);
//}
//void fractal(){
//    Pen p(800, 600);
//    p.setXY(700, 590);
//    p.setHeading(180);
//    p.setSpeed(100);
//    int lado = 580;
//    embua(p, lado);
//    p.wait();
//}
//int main(){
//    fractal();
//    return 0;
//}

/////////////////////////////////////////////////////////////////////////
