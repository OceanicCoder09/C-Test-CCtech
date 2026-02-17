#include<iostream>
#include<vector>
#include<string>

using namespace std;

class CADobj{
public:
    virtual void display() = 0;
    virtual CADobj* clone() = 0;
};

class Line : public CADobj{
    int x, y, z, w;
public:
    Line(int a, int b, int c, int d){
        x = a;
        y = b;
        z = c;
        w = d;
    }
    void display(){
        cout<<"LINE "<<x<<" "<<y<<" "<<z<<" "<<w<<endl;
    }
    CADobj* clone(){
        return new Line(x, y, z, w);
    }
};
//inheritance and polymorphism
class Circle : public CADobj{
    int x, y, r;
public:
    Circle(int a, int b, int c){
        x = a;
        y = b;
        r = c;
    }
    void display(){
        cout<<"CIRCLE "<<x<<" "<<y<<" "<<r<<endl;
    }
    CADobj* clone(){
        return new Circle(x, y, r);
    }
};
//inheritance and polymorphism
class Text : public CADobj{
    int x, y;
    string str;
public:
    Text(int a, int b, string s){
        x = a;
        y = b;
        str = s;
    }
    void display(){
        cout<<"TEXT "<<x<<" "<<y<<" "<<str<<endl;
    }
    CADobj* clone(){
        return new Text(x, y, str);
    }
};

class Documents{
public:
//implememt stl
    vector<CADobj*> objects;

    void add(CADobj* obj){
        objects.push_back(obj);
    }
    void deleteObj(){
        if(objects.size() > 0){
            delete objects[objects.size() - 1];
            objects.pop_back();
        }
    }
    void cloneObj(){
        if(objects.size() > 0){
            CADobj* cloned = objects[objects.size() - 1]->clone();
            objects.push_back(cloned);
        }
    }
    void ListAll(){
        if(objects.size() == 0){
            cout<<"No objects\n";
            return;
        }

        for(int i = 0; i <objects.size(); i++){
            objects[i]->display();
        }
    }
   void Exit(){
        for(int i = 0; i <objects.size(); i++){
            delete objects[i];
        }
        objects.clear();
    }
};

int main(){

    Documents doc;
    int c;
    while(true){

        cout<<"1. Add Line\n";
        cout<<"2. Add Circle\n";
        cout<<"3. Add Text\n";
        cout<<"4. Clone Object\n";
        cout<<"5. Delete Object\n";
        cout<<"6. List Objects\n";
        cout<<"7. Exit\n";
        
        cout<<"Choice: ";
        cin>>c;
        //take a input and compare with doc
        if(c==1){
            int x1, y1, x2, y2;
            cin>>x1>>y1>>x2>>y2;
            doc.add(new Line(x1,y1,x2,y2));
        }
        else if(c==2){
            int x, y, r;
            cin>>x>>y>>r;
            doc.add(new Circle(x,y,r));
        }
        else if(c==3){
            int x, y;
            string s;
            cin>>x>>y>>s;
            
            doc.add(new Text(x,y,s));
        }
        else if(c==4){
            doc.cloneObj();
        }
        else if(c==5){
            doc.deleteObj();
        }
        else if(c==6){
            doc.ListAll();
        }
        else if(c==7){
            doc.Exit();
            break;
        }
    }
    return 0;
}
