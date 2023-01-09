#include<iostream>
using namespace std;
void Combi(char a[], int reqLen, int s, int currLen, bool check[], int l)
/*
   Cadena (Nombre/Correo) : nayeli.leiva@epn.edu.ec
   Conjunto sin repetidos: nayeli.v@pduc
   Longitud Cadena : 23
   Longitud Conjunto : 13  

   TENER EN CUENTA PARA LOS DATOS.
*/
{
   if(currLen > reqLen)
   return;
   else if (currLen == reqLen) 
   {
      cout<<"\t";
      for (int i = 0; i < l; i++) {
         if (check[i] == true) {
            cout<<a[i]<<" ";
         }
      }
      cout<<"\n";
      return;
   }
   if (s == l) 
   {
      return;
   }
   check[s] = true;
   Combi(a, reqLen, s + 1, currLen + 1, check, l);
   check[s] = false;
   Combi(a, reqLen, s + 1, currLen, check, l);
}
int main() 
{
   int i,n;
   bool check[n];
   cout<<"Ingrese el numero de letras que tiene su nombre: ";
   cin>>n;
   char a[n];
   cout<<"\n";
   for(i = 0; i < n; i++) 
   {
      cout<<"Ingrese "<<i+1<<" letra: ";
      cin>>a[i];
      check[i] = false;
   }
   for(i = 1; i <= n; i++) 
   {
      cout<<"\nLas posibles combinaciones de longitud "<<i<<" para las letras dadas son:\n";
      Combi(a, i, 0, 0, check, n);
   }
   return 0;
}