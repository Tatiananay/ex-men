#include<iostream>
#include<string.h>

#define USER "nayeli.leiva@epn.edu.ec"  //define el usuario
#define PASS "1750452334"               //define la contraseña
void nlloginnayeli (){     //procedimiento 
    string usuario, password;
    int contador=0;

    bool ingresa= false;
    do{
        cout<<"\t\tLOGIN DEL USUARIO";
    cout<<"\t\t-----------------"<<endl;
    cout<<"\tIngrese el usuario: "; 
    getline(cin,usuario);
    cout<<"\tpassword: ";
    getline(cin,password);

    if(usuario == USER && password == PASS){
        ingresa = true;
    }else{
        cout<<"el usuario y/o password son incorrectos"<<endl;
        contador++;
    }
    }while(ingresa == false && contador<3);
    if (ingresa==false){
        cout<<"Lo sentimos tu usuario y clave son incorrectos..! "<<endl<<"Gracias";
    }else{
        cout<<"\n\tBIENVENIDO: "<<USER;
    }
 //cin.get();
}

int main(){
    nlloginnayeli();  //llama al procedimiento 
    return 0;
}