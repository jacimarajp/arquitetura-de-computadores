#include<iostream>
#include<string>
using namespace std;

long int endereco;
long int opcode,Rs,Rt,Rd,shamt;  //parametros de reconhecimento de uma instrucao
long int Banco_reg[26];
int vet[32];
string reg1,reg11,reg111;
int reg2,reg22,reg222, valor_aloc;;
int inst;
int var_on, funct = 0;
int i=0;



//void transf_binario(int num){  //transformar os numeros de decimal para binário

 //  if ((num != 1)||(num != 0))
  // {
	//do{
	//    vet[i] = num%2;
         //   num = num/2;
         //   i= i+1;
	 // }while(num!=1);
   //}
  // vet[i] = num;
 // }



void banco_de_regS(int op,string r1, string r2,string r3, int ind1, int ind2, int ind3, int valor,int f){  //função que irá indicar qual a posição e tipo do registrador

	if (op == 8 && ind1 < 8){
                Banco_reg[16+ind1]=valor;      
     
         } else if(op == 0 && f == 32 && ind1 < 8){
		Banco_reg[8+ind1] = Banco_reg[16+ind2] + Banco_reg[16+ind3];
         }else if(op == 0 && f == 32 && (ind1 == 8 || ind1 == 9)){
		Banco_reg[16+ind1] = Banco_reg[16+ind2] + Banco_reg[16+ind3];
         } else if(op == 0 && f == 34 && ind1 < 8){
		Banco_reg[16+ind1] = Banco_reg[8+ind2] - Banco_reg[8+ind3];
                } else  if(op == 0 && f == 34 && (ind1 == 8 || ind1 == 9)){
		Banco_reg[16+ind1] = Banco_reg[8+ind2] - Banco_reg[8+ind3];
         }

         

}
///////////////////////////////////////////////////main //////////////////////////////////////////////
int main ()
{
  do{
    cout << "Digite a instrução\n";   //usuário escolhe entre add, sub ou addi para realizar
    cout << "0 - addi\n";
    cout << "1 - add\n";
    cout << "2 - sub\n";
    cin >> inst;

    if(inst == 0){
       opcode = 8;
       cout << "Digite o registrador que irá receber o valor tipo e indice\n";
       cin >> reg1;   
       cin >> reg2;  
       cout << "Digite o valor que você que alocar\n"; 
       cin >> valor_aloc;
       banco_de_regS(opcode,reg1," "," ",reg2,0,0,valor_aloc,0);
       cout << "s" << reg2 << " = " << Banco_reg[16 + reg2]<<endl;
	opcode = 0;
       
      } else if(inst == 1){   // condicao para a operacao add
         funct = 32;
         opcode = 0;
         cout << "Digite o registrador que irá receber o valor tipo e indice, do resultado\n";
         cin >> reg1;   
         cin >> reg2;
         cout << "Digite o primeiro registrador\n";
         cin >> reg11;   
         cin >> reg22;
         cout << "Digite o segundo registrador\n";
         cin >> reg111;   
         cin >> reg222;
         banco_de_regS(opcode,reg1,reg11,reg111,reg2,reg22,reg222,0,funct);
         cout << reg1 << reg2 << " = " << Banco_reg[8 + reg2]<<endl;
       }else if(inst == 2){    // condicao para a operacao sub
         funct = 34;
         opcode = 0;
         cout << "Digite o registrador que irá receber o valor tipo e indice, do resultado\n";
         cin >> reg1;   
         cin >> reg2;
         cout << "Digite o primeiro registrador\n";
         cin >> reg11;   
         cin >> reg22;
         cout << "Digite o segundo registrador\n";
         cin >> reg111;   
         cin >> reg222;
         banco_de_regS(opcode,reg1,reg11,reg111,reg2,reg22,reg222,0,funct);
         cout << reg1 << reg2 << " = " << Banco_reg[16 + reg2]<<endl;
       }

	cout << "s" << 0 << " = " << Banco_reg[16] << endl;

       cout << "Deseja continuar? 1 (sim) , 0 (nao) \n";  //se o usuario digitar "off" ele sai da estrura de repeticao
       cin >> var_on;
    
  } while(var_on == 1);


 cout<< "bando de registradores"<< endl;
 int c = 0, p =0;
 for(int j =8; j<16; j++){
   cout << "t"<< c << " = " << Banco_reg[j]<<endl;
  c++;
  }
 for(int j =16; j<23; j++){
   cout << "s" << p << " = " << Banco_reg[j]<<endl;
  p++;
  }



 

  return 0; 
} 


