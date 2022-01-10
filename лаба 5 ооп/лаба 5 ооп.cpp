

#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

class literature
{
public:
    literature() {
        printf("literature()\n");
    }

    literature(literature& book) {
        printf("literature(literature& book)\n");
    }

    literature(literature* book) {
        printf("literature(literature* book)\n");
    }

    virtual void style() {
        printf("This is some style\n");
    }

   /* void style() {
        printf("Some style\n");
    }*/

    void mark() {
        printf("mark: %d\n", str());
    }

    virtual int str() {
        printf("literature: int str()\n");
        return 0;
    }

    /*void mark() {
        printf("mark: %d\n", str());
    }

    int str() {
        printf("literature: int str()\n");
        return 0;
    }*/

    virtual string classname() {
        return "literature";
    }

    virtual bool isA(string classname) {
        if (classname == "literature") {
            return true;
        }
        else return false;

    }

};

class Classic : public literature
{
public:

    Classic() {
        printf("Classic()\n");
    }

    Classic(Classic& book) {
        printf("Classic(Classic& book)\n");
    }

    Classic(Classic* book) {
        printf("Classic(Classic* book)\n");
    }
    void style() {
        printf("This is Classic");
    }
    
    int str(){
        printf("Classic: int str()\n");
        return 1;
    }

    string classname() {
        return "Classic";
    }

    bool isA(string classname) {
        if (classname == "Classic") {
            return true;
        }
        else return false;

    }
  
};

class Fantasy : public literature
{
public:
    Fantasy()
    {
        printf("Fantasy()\n");
    }

    Fantasy(Fantasy& book) {
        printf("Fantasy(Fantasy& book)\n");
    }

    Fantasy(Fantasy* book) {
        printf("Fantasy(Fantasy* book)\n");
    }

   void style() {
        printf("This is Fantsy\n");
   }

   string classname() {
       return "Fantasy";
   }

   bool isA(string classname) {
       if (classname == "Fantsy") {
           return true;
       }
       else return false;

   }

};


void search1(literature book) {
    printf("search1: look in (literature book)\n");
    book.style();
}

void search2(literature* book) {
    printf("search2: look in (literature* book)\n");
    book->style();
}

void search3(literature& book) {
    printf("search3: look in (literature& book)\n");
    book.style();
}



int main()
{
    //TEST 1
    /*printf("\nbook\n");
    literature* book = new literature();
    book->style();
    printf("\nbook2\n");
    literature* book2 = new Fantasy();
    book2->style();
    printf("\nbook3\n");
    literature* book3 = new Classic();
    book3->style();*/

    //TEST 2
   /* printf("\nbook\n");
    literature* book = new literature();
    search1(*book);
    search2(book);
    search3(*book);*/
    
    //TEST 3
    /*Classic* Idiot = new Classic();
    Idiot->mark();*/
    

    //creating an array of the library and filling it randomly
    const int n = 10;
    literature* library[n];
    int j = 0;
    for (int i = 0; i < n; i++) {
        srand(time(0));
        j = rand() % 3;
        switch (j)
        {
        case 0:
        {
            library[i] = new Classic();
            break;
        }
        case 1:
        {
            library[i] = new Fantasy();
            break;
        }
        default:
            library[i] = new literature();
            break;
        }

    }

    // безопасный вариант приведения вручную
    /*for (int i = 0; i < n; i++) {
        if (library[i]->classname() == "Classic") {
            ((Classic*)library[i])->style();
        }
        else 
        if (library[i]->classname() == "Fantasy") {
                ((Fantasy*)library[i])->style();
        }
        else library[i]->style();
        
    }*/


    // безопасный вариант приведения dynamic_cast
    /*for (int i = 0; i < n; ++i) {
        if (Classic* b = (dynamic_cast<Classic*>(library[i]))) {
            b->style();
        }else if (Fantasy* c = (dynamic_cast<Fantasy*>(library[i]))) {
            c->style();
        }
        else library[i]->style();
    }*/
    



    return 0;
}

