#include<bits/stdc++.h>

using namespace std;

class ComplexNumber{
    private:
        int real;
        int imag;
    public:
        ComplexNumber(){
            real = 0;
            imag = 0;
        }
        ComplexNumber(int r, int i){
            real = r;
            imag = i;
        }
        void setReal(const int r){
            real = r;
        }
        void setImag(const int i){
            imag = i;
        }

        int getReal() const{
            return real;
        }
        int getImag() const{
            return imag;
        }
        void print(){
            if(imag>0)
                cout<<real<<" + "<<imag<<"i\n";
            else
                cout<<real<<" - "<<imag<<"i\n";
        }

        void add(const ComplexNumber &c1){
            real += c1.real;
            imag += c1.imag;
        }

        void operator+(ComplexNumber &c1){
            real += c1.real;
            imag += c1.imag; 
        }
};



int main(){
    ComplexNumber c1(5,3);
    ComplexNumber c2;
    c2.setImag(4);
    c2.setReal(3);
    ComplexNumber c3(c2);
    c1.print();
    c2.print();
    c3.print();
    cout<<endl;
    c3.setImag(-1);
    c2.print();
    c3.print();
    c1.add(c2);
    cout<<endl;
    c1.print();
    return 0;

}