//OOPS
//Access modifiers -> public, private, protected -> by default its private

//creation of object
/*
Hero shubham;
shubham.age=21;
shubham.sethealth(90);
cout<<sizeof(shubham)<<endl;
cout<<shubham.age<<endl;
shubham.gethealth();

//dynamic allocation
Hero *shubhi=new Hero;
(*shubhi).age=20;
(*shubhi).sethealth(70);
cout<<sizeof(shubhi)<<endl;
cout<<shubhi->age<<endl;
(*shubhi).gethealth(); // (*shubhi).age and shubhi->age gives same thing
//constructor -> produced automatically when you create object -> shubham.Hero()
*/

//Pillars of OOPS -> Encapsulation, Inheritance, Polymorphism, Abstraction
//Encapsulation -> all data members and functions are kept in private access modifier ->security increases, make class read only, code reusability
//Inheritance -> single, multi-level, multiple, hybrid, heirarchical
//single -> simple inheritance
//multi-level -> a inherits b and b inherits c.... 
//multiple -> c inherits a and b both
//heirarchical -> making a tree type of inheritance

//Example (How to inherit and create class)
/*
class Male : public Human{
    void sleep()
    {}

    int age()
    {}

    string name()
    {}
};
*/

/*
Male shubham;
shubham.age=21;
shubham.sethealth(100);
shubham.gethealth();
*/

//Inheritance ambiguity also called Diamond problem-> there are 2 classes A and B both have abc function in them now class C inherits A and B both, 
//now C calls abc (which will be called now abc from A class or abc from B class)? this is solved by scope resolution operator
//syntax-> shubham.A::abc(); shubham.B::abc();

//Polymorphism
//compile-time polymorphism -> function overloading -> change input arguments if name of function is same 
//                             operator overloading -> assigns new task to operators
//run-time polymorphism -> (Read more from youtube link then only you can understand this)

//Abstraction -> implementation hiding